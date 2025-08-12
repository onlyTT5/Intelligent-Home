#!/bin/bash

#=============================================================================
# 智能家居项目自动部署脚本
# 用途：自动化将项目部署到ARM开发板
# 作者：智能家居项目团队
# 日期：2025年8月12日
#=============================================================================

# 配置变量
BOARD_IP="192.168.7.122"
BOARD_USER="root"
PROJECT_DIR="/study/Intelligent-Home/project"
MQTT_LIB_DIR="/study/MQTT_lib"

# 颜色输出定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 日志函数
log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# 检查文件是否存在
check_file() {
    if [ ! -f "$1" ]; then
        log_error "文件不存在: $1"
        return 1
    fi
    return 0
}

# 检查开发板连接
check_board_connection() {
    log_info "检查开发板连接..."
    if ping -c 1 -W 2 $BOARD_IP > /dev/null 2>&1; then
        log_success "开发板连接正常"
        return 0
    else
        log_error "无法连接到开发板 $BOARD_IP"
        return 1
    fi
}

# 编译项目
compile_project() {
    log_info "编译项目..."
    cd $PROJECT_DIR
    
    # 清理之前的编译结果
    make --file=Makefile-arm-mqtt clean > /dev/null 2>&1
    
    # 编译项目
    if make --file=Makefile-arm-mqtt -j$(nproc); then
        log_success "项目编译成功"
        return 0
    else
        log_error "项目编译失败"
        return 1
    fi
}

# 部署库文件
deploy_libraries() {
    log_info "部署依赖库到开发板..."
    
    # 检查库文件是否存在
    local libs=(
        "$MQTT_LIB_DIR/cJSON-master-arm/lib/libcjson.so.1.7.18"
        "$MQTT_LIB_DIR/mosquitto-arm/lib/libmosquitto.so.1"
        "$MQTT_LIB_DIR/openssl-arm/lib/libssl.so.1.1"
        "$MQTT_LIB_DIR/openssl-arm/lib/libcrypto.so.1.1"
    )
    
    for lib in "${libs[@]}"; do
        if ! check_file "$lib"; then
            return 1
        fi
    done
    
    # 传输库文件
    log_info "传输 cJSON 库..."
    scp -O -q "$MQTT_LIB_DIR/cJSON-master-arm/lib/libcjson.so.1.7.18" $BOARD_USER@$BOARD_IP:/lib/
    
    log_info "传输 Mosquitto 库..."
    scp -O -q "$MQTT_LIB_DIR/mosquitto-arm/lib/libmosquitto.so.1" $BOARD_USER@$BOARD_IP:/lib/
    
    log_info "传输 OpenSSL 库..."
    scp -O -q "$MQTT_LIB_DIR/openssl-arm/lib/libssl.so.1.1" $BOARD_USER@$BOARD_IP:/lib/
    scp -O -q "$MQTT_LIB_DIR/openssl-arm/lib/libcrypto.so.1.1" $BOARD_USER@$BOARD_IP:/lib/
    
    log_success "库文件传输完成"
    return 0
}

# 创建符号链接
create_symlinks() {
    log_info "在开发板上创建符号链接..."
    
    ssh -q $BOARD_USER@$BOARD_IP << 'EOF'
cd /lib
# cJSON 符号链接
ln -sf libcjson.so.1.7.18 libcjson.so.1 2>/dev/null
ln -sf libcjson.so.1 libcjson.so 2>/dev/null

# Mosquitto 符号链接
ln -sf libmosquitto.so.1 libmosquitto.so 2>/dev/null

# OpenSSL 符号链接
ln -sf libssl.so.1.1 libssl.so 2>/dev/null
ln -sf libcrypto.so.1.1 libcrypto.so 2>/dev/null
EOF
    
    log_success "符号链接创建完成"
}

# 部署应用程序
deploy_application() {
    log_info "部署应用程序..."
    
    # 检查可执行文件是否存在
    if ! check_file "$PROJECT_DIR/build/bin/main"; then
        log_error "可执行文件不存在，请先编译项目"
        return 1
    fi
    
    # 创建目标目录
    ssh -q $BOARD_USER@$BOARD_IP "mkdir -p /study/Intelligent_home" 2>/dev/null
    
    # 传输可执行文件
    cd $PROJECT_DIR
    make --file=Makefile-arm-mqtt send > /dev/null 2>&1
    
    log_success "应用程序部署完成"
}

# 设置文件权限
setup_permissions() {
    log_info "设置文件权限..."
    
    ssh -q $BOARD_USER@$BOARD_IP << 'EOF'
# 设置可执行文件权限
chmod +x /study/Intelligent_home/main 2>/dev/null

# 设置设备文件权限
chmod 666 /dev/fb0 2>/dev/null
chmod 666 /dev/input/event* 2>/dev/null
EOF
    
    log_success "权限设置完成"
}

# 验证部署
verify_deployment() {
    log_info "验证部署结果..."
    
    # 检查库文件
    local lib_check=$(ssh -q $BOARD_USER@$BOARD_IP "ls /lib/lib*json* /lib/libmosquitto* /lib/libssl* /lib/libcrypto* 2>/dev/null | wc -l")
    
    if [ "$lib_check" -ge 8 ]; then
        log_success "库文件部署验证通过"
    else
        log_warning "库文件部署可能不完整"
    fi
    
    # 检查可执行文件
    if ssh -q $BOARD_USER@$BOARD_IP "test -x /study/Intelligent_home/main"; then
        log_success "可执行文件部署验证通过"
    else
        log_error "可执行文件部署失败"
        return 1
    fi
    
    return 0
}

# 创建启动脚本
create_startup_script() {
    log_info "创建启动脚本..."
    
    ssh -q $BOARD_USER@$BOARD_IP << 'EOF'
cat > /study/Intelligent_home/start.sh << 'SCRIPT_END'
#!/bin/bash

# 智能家居项目启动脚本

# 设置环境变量
export LV_LINUX_FBDEV_DEVICE=/dev/fb0

# 检查设备文件
if [ ! -c /dev/fb0 ]; then
    echo "错误：framebuffer 设备 /dev/fb0 不存在"
    exit 1
fi

if [ ! -c /dev/input/event0 ]; then
    echo "警告：输入设备 /dev/input/event0 不存在"
fi

# 启动程序
cd /study/Intelligent_home
echo "启动智能家居控制系统..."
./main
SCRIPT_END

chmod +x /study/Intelligent_home/start.sh
EOF
    
    log_success "启动脚本创建完成"
}

# 显示使用说明
show_usage() {
    echo "用法: $0 [选项]"
    echo ""
    echo "选项:"
    echo "  -c, --compile-only    仅编译项目，不部署"
    echo "  -d, --deploy-only     仅部署，不编译"
    echo "  -v, --verify-only     仅验证部署结果"
    echo "  -h, --help           显示此帮助信息"
    echo ""
    echo "默认：完整编译并部署"
}

# 主函数
main() {
    echo "======================================"
    echo "   智能家居项目自动部署脚本"
    echo "======================================"
    echo ""
    
    # 解析命令行参数
    case "${1:-}" in
        -c|--compile-only)
            log_info "仅编译模式"
            compile_project
            exit $?
            ;;
        -d|--deploy-only)
            log_info "仅部署模式"
            if ! check_board_connection; then
                exit 1
            fi
            deploy_libraries && create_symlinks && deploy_application && setup_permissions && create_startup_script
            exit $?
            ;;
        -v|--verify-only)
            log_info "仅验证模式"
            if ! check_board_connection; then
                exit 1
            fi
            verify_deployment
            exit $?
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        "")
            # 默认模式：完整部署
            ;;
        *)
            log_error "未知选项: $1"
            show_usage
            exit 1
            ;;
    esac
    
    # 执行完整部署流程
    log_info "开始完整部署流程..."
    
    # 1. 检查开发板连接
    if ! check_board_connection; then
        exit 1
    fi
    
    # 2. 编译项目
    if ! compile_project; then
        exit 1
    fi
    
    # 3. 部署库文件
    if ! deploy_libraries; then
        exit 1
    fi
    
    # 4. 创建符号链接
    create_symlinks
    
    # 5. 部署应用程序
    if ! deploy_application; then
        exit 1
    fi
    
    # 6. 设置权限
    setup_permissions
    
    # 7. 创建启动脚本
    create_startup_script
    
    # 8. 验证部署
    if verify_deployment; then
        echo ""
        echo "======================================"
        log_success "部署完成！"
        echo ""
        log_info "在开发板上运行程序："
        echo "  方式1: ssh $BOARD_USER@$BOARD_IP '/study/Intelligent_home/start.sh'"
        echo "  方式2: ssh $BOARD_USER@$BOARD_IP 'cd /study/Intelligent_home && ./main'"
        echo "======================================"
    else
        log_error "部署验证失败"
        exit 1
    fi
}

# 运行主函数
main "$@"
