# 智能家居项目

基于 LVGL 的智能家居控制系统，支持 MQTT 通信、天气显示、音乐播放等功能。

## 📚 文档索引

### 🚀 快速开始
- **[快速参考卡片](QUICK_REFERENCE.md)** - 常用命令和故障排查
- **[移植指南](PORTING_GUIDE.md)** - 完整的从 Ubuntu 到 ARM 开发板移植步骤

### 🛠️ 自动化工具
- **[自动部署脚本](deploy.sh)** - 一键编译和部署到开发板

### 📋 功能说明
- **[房间切换功能](README_房间切换功能.md)** - 房间切换功能的详细实现说明

## 🏗️ 项目结构
```
project/
├── main.c              # 主程序入口
├── Makefile-arm-mqtt   # ARM 交叉编译 Makefile
├── UI/                 # 用户界面相关代码
│   ├── ui.c/.h        # UI 主文件
│   ├── MQTT.c/.h      # MQTT 通信模块
│   ├── screens/       # 各个屏幕界面
│   ├── components/    # UI 组件
│   ├── images/        # 图像资源
│   └── fonts/         # 字体文件
├── lvgl/              # LVGL 图形库
├── freetype_tmp/      # FreeType 字体库
├── build/             # 编译输出目录
├── deploy.sh          # 自动部署脚本
├── PORTING_GUIDE.md   # 移植指南
└── QUICK_REFERENCE.md # 快速参考
```

## 🚀 快速开始

### 1. 一键部署（推荐）
```bash
# 给脚本执行权限
chmod +x deploy.sh

# 完整编译并部署到开发板
./deploy.sh
```

### 2. 手动编译
```bash
# 清理和编译
make --file=Makefile-arm-mqtt clean
make --file=Makefile-arm-mqtt -j$(nproc)

# 发送到开发板
make --file=Makefile-arm-mqtt send
```

### 3. 在开发板上运行
```bash
# SSH 连接到开发板
ssh root@192.168.7.122

# 运行程序
cd /study/Intelligent_home
./start.sh  # 或直接运行 ./main
```

## 📊 系统要求

### 开发环境
- Ubuntu 18.04 或更高版本
- ARM 交叉编译工具链
- 必要的开发库和工具

### 目标设备
- ARM Cortex-A 系列处理器
- Linux 系统（支持 framebuffer）
- 触摸屏或其他输入设备
- 网络连接（MQTT 通信）

## 🔧 依赖库版本
- **LVGL**: 9.2.2
- **FreeType**: 2.13.2
- **OpenSSL**: 1.1.1w
- **cJSON**: 1.7.18
- **Mosquitto**: 2.0.18

## 📡 通信协议
- **MQTT**: 用于智能家居设备通信
- **HTTP**: 用于天气数据获取
- **Touch Events**: 触摸屏交互

## 🎨 功能特性
- 🏠 **智能家居控制**: 灯光、窗帘、空调等设备控制
- 🌤️ **天气显示**: 实时天气信息显示
- 🎵 **音乐播放**: 音乐播放控制界面
- 📱 **触摸交互**: 支持触摸屏操作
- 🔄 **房间切换**: 不同房间的设备控制

## 🆘 获取帮助
如果遇到问题，请按以下顺序查阅：
1. [快速参考卡片](QUICK_REFERENCE.md) - 查看常见问题解决方案
2. [移植指南](PORTING_GUIDE.md) - 查看详细的配置和故障排查
3. 运行 `./deploy.sh --help` - 查看部署脚本帮助

## 📝 更新日志
- **2025-08-12**: 创建完整的移植文档和自动化部署脚本
- **2025-08-12**: 解决库依赖和链接问题，成功移植到 ARM 开发板

---
*智能家居项目团队 © 2025*
