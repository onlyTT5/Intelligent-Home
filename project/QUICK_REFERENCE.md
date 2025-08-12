# 智能家居项目 - 快速参考卡片

## 📋 一键部署命令
```bash
# 完整编译和部署
./deploy.sh

# 仅编译
./deploy.sh --compile-only

# 仅部署
./deploy.sh --deploy-only

# 验证部署
./deploy.sh --verify-only
```

## 🔧 手动编译命令
```bash
# 清理和编译
make --file=Makefile-arm-mqtt clean
make --file=Makefile-arm-mqtt -j$(nproc)

# 发送到开发板
make --file=Makefile-arm-mqtt send
```

## 📡 开发板连接
```bash
# SSH 连接
ssh root@192.168.7.122

# 传输文件
scp -O <local_file> root@192.168.7.122:<remote_path>
```

## 🏃‍♂️ 运行程序
```bash
# 在开发板上运行
cd /study/Intelligent_home
./start.sh

# 或直接运行
./main
```

## 📁 重要路径
```bash
# 项目目录
/study/Intelligent-Home/project/

# 依赖库目录
/study/MQTT_lib/

# 开发板程序目录
/study/Intelligent_home/

# 开发板库目录
/lib/
```

## 🔍 故障排查
```bash
# 检查库依赖
ls -la /lib/lib*json* /lib/libmosquitto* /lib/libssl* /lib/libcrypto*

# 检查设备权限
ls -la /dev/fb0 /dev/input/event*

# 检查程序权限
ls -la /study/Intelligent_home/main

# 测试网络连接
ping <MQTT_SERVER_IP>
```

## 📊 系统要求
- **开发环境**: Ubuntu 18.04+, ARM 交叉编译器
- **开发板**: ARM Cortex-A, Linux, Framebuffer 支持
- **依赖**: LVGL 9.2.2, FreeType 2.13.2, OpenSSL 1.1.1w, cJSON 1.7.18, Mosquitto 2.0.18

## 🚨 常见错误解决
| 错误 | 解决方案 |
|------|----------|
| `file too short` | 重新传输库文件并创建符号链接 |
| `cannot find -lcjson` | 检查库路径和符号链接 |
| `Permission denied` | `chmod 666 /dev/fb0 /dev/input/event*` |
| 编译失败 | 检查交叉编译器路径和依赖库 |
| 无法连接开发板 | 检查网络和 SSH 配置 |
