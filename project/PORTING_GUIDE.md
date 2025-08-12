# 智能家居项目移植指南
从 Ubuntu 开发环境移植到 ARM 开发板的完整步骤

## 项目概述
本项目是基于 LVGL 图形库的智能家居控制系统，支持 MQTT 通信、天气显示、音乐播放等功能。

## 系统要求

### 开发环境 (Ubuntu)
- Ubuntu 18.04 或更高版本
- ARM 交叉编译工具链
- 必要的开发库和工具

### 目标设备 (ARM 开发板)
- ARM Cortex-A 系列处理器
- Linux 系统 (支持 framebuffer)
- 触摸屏或其他输入设备
- 网络连接 (用于 MQTT 通信)

## 一、开发环境准备

### 1.1 安装 ARM 交叉编译工具链
```bash
# 安装 ARM 交叉编译器
sudo apt update
sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf

# 或者使用专用的 ARM 工具链 (如项目中使用的)
# 下载并安装到 /usr/local/arm/5.4.0/
```

### 1.2 安装必要的开发工具
```bash
sudo apt install build-essential cmake git
sudo apt install pkg-config autoconf automake libtool
```

## 二、依赖库准备

### 2.1 FreeType 库 (ARM 版本)
```bash
# 下载 FreeType 源码
wget https://download.savannah.gnu.org/releases/freetype/freetype-2.13.2.tar.xz
tar -xf freetype-2.13.2.tar.xz
cd freetype-2.13.2

# 配置并编译 ARM 版本
./configure --host=arm-linux-gnueabihf --prefix=/path/to/freetype_tmp --without-harfbuzz --without-bzip2 --without-png
make
make install
```

### 2.2 OpenSSL 库 (ARM 版本)
```bash
# 下载 OpenSSL 源码
wget https://www.openssl.org/source/openssl-1.1.1w.tar.gz
tar -xf openssl-1.1.1w.tar.gz
cd openssl-1.1.1w

# 配置并编译 ARM 版本
./Configure linux-armv4 --cross-compile-prefix=arm-linux-gnueabihf- --prefix=/study/MQTT_lib/openssl-arm
make
make install

# 创建符号链接
cd /study/MQTT_lib/openssl-arm/lib/
ln -sf libssl.so.1.1 libssl.so
ln -sf libcrypto.so.1.1 libcrypto.so
```

### 2.3 cJSON 库 (ARM 版本)
```bash
# 下载 cJSON 源码
git clone https://github.com/DaveGamble/cJSON.git
cd cJSON
mkdir build-arm && cd build-arm

# 使用 CMake 交叉编译
cmake .. -DCMAKE_C_COMPILER=arm-linux-gnueabihf-gcc \
         -DCMAKE_INSTALL_PREFIX=/study/MQTT_lib/cJSON-master-arm \
         -DENABLE_CJSON_UTILS=OFF \
         -DENABLE_CJSON_TEST=OFF
make
make install

# 创建符号链接
cd /study/MQTT_lib/cJSON-master-arm/lib/
ln -sf libcjson.so.1.7.18 libcjson.so.1
ln -sf libcjson.so.1 libcjson.so
```

### 2.4 Mosquitto 库 (ARM 版本)
```bash
# 下载 Mosquitto 源码
wget https://mosquitto.org/files/source/mosquitto-2.0.18.tar.gz
tar -xf mosquitto-2.0.18.tar.gz
cd mosquitto-2.0.18

# 修改配置以进行交叉编译
# 编辑 config.mk 文件，设置交叉编译器和库路径
make CROSS_COMPILE=arm-linux-gnueabihf- \
     CPPFLAGS="-I/study/MQTT_lib/openssl-arm/include" \
     LDFLAGS="-L/study/MQTT_lib/openssl-arm/lib"

# 手动安装到指定目录
mkdir -p /study/MQTT_lib/mosquitto-arm/{lib,include}
cp lib/libmosquitto.so.1 /study/MQTT_lib/mosquitto-arm/lib/
cp include/*.h /study/MQTT_lib/mosquitto-arm/include/

# 创建符号链接
cd /study/MQTT_lib/mosquitto-arm/lib/
ln -sf libmosquitto.so.1 libmosquitto.so
```

## 三、项目编译

### 3.1 获取项目源码
```bash
# 克隆项目 (假设项目已经包含 LVGL 子模块)
git clone <your-project-repo>
cd Intelligent-Home/project
git submodule update --init --recursive
```

### 3.2 配置 Makefile
确保 `Makefile-arm-mqtt` 中的路径正确：
```makefile
CC = arm-linux-gcc  # 或您的交叉编译器路径

# 包含路径
CFLAGS += -I./UI
CFLAGS += -I./freetype_tmp/include/freetype2
CFLAGS += -I/study/MQTT_lib/cJSON-master-arm/include
CFLAGS += -I/study/MQTT_lib/mosquitto-arm/include
CFLAGS += -I/study/MQTT_lib/openssl-arm/include

# 库路径和链接
LDFLAGS = -lm -L./freetype_tmp/lib -lfreetype \
          -L/study/MQTT_lib/openssl-arm/lib \
          -L/study/MQTT_lib/cJSON-master-arm/lib \
          -L/study/MQTT_lib/mosquitto-arm/lib \
          -lcjson -lssl -lcrypto -lmosquitto -lpthread
```

### 3.3 编译项目
```bash
# 清理并编译
make --file=Makefile-arm-mqtt clean
make --file=Makefile-arm-mqtt -j$(nproc)
```

## 四、开发板环境准备

### 4.1 传输依赖库到开发板
```bash
# 传输所有必要的库文件到开发板的 /lib 目录
scp -O /study/MQTT_lib/cJSON-master-arm/lib/libcjson.so.1.7.18 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/mosquitto-arm/lib/libmosquitto.so.1 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libssl.so.1.1 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libcrypto.so.1.1 root@<BOARD_IP>:/lib/
```

### 4.2 在开发板上创建符号链接
```bash
# 通过 SSH 连接到开发板
ssh root@<BOARD_IP>

# 创建库文件符号链接
cd /lib
ln -sf libcjson.so.1.7.18 libcjson.so.1
ln -sf libcjson.so.1 libcjson.so
ln -sf libmosquitto.so.1 libmosquitto.so
ln -sf libssl.so.1.1 libssl.so
ln -sf libcrypto.so.1.1 libcrypto.so
```

### 4.3 传输可执行文件
```bash
# 创建目标目录并传输程序
ssh root@<BOARD_IP> "mkdir -p /study/Intelligent_home"
make --file=Makefile-arm-mqtt send
```

## 五、开发板配置

### 5.1 显示设备配置
```bash
# 确保 framebuffer 设备可用
ls /dev/fb*  # 应该显示 /dev/fb0

# 检查分辨率设置
cat /sys/class/graphics/fb0/virtual_size
```

### 5.2 输入设备配置
```bash
# 检查触摸屏或其他输入设备
ls /dev/input/event*  # 找到对应的事件设备

# 在程序中配置正确的设备路径 (main.c)
lv_evdev_set_calibration(touch, 0, 0, 800, 480);  # 根据屏幕分辨率调整
```

### 5.3 网络配置
确保开发板能够连接到 MQTT 服务器：
```bash
# 测试网络连接
ping <MQTT_SERVER_IP>

# 测试 MQTT 连接 (如果安装了 mosquitto 客户端)
mosquitto_sub -h <MQTT_SERVER_IP> -t test/topic
```

## 六、运行程序

### 6.1 设置环境变量
```bash
# 设置显示设备
export LV_LINUX_FBDEV_DEVICE=/dev/fb0

# 如果使用触摸屏，确保权限正确
chmod 666 /dev/input/event0
```

### 6.2 启动程序
```bash
cd /study/Intelligent_home
./main
```

## 七、故障排除

### 7.1 库依赖问题
如果出现 "file too short" 或库找不到的错误：
```bash
# 检查库文件完整性
ls -la /lib/lib*json* /lib/libmosquitto* /lib/libssl* /lib/libcrypto*

# 重新传输损坏的库文件
# 确保符号链接正确
```

### 7.2 显示问题
```bash
# 检查 framebuffer 设备权限
ls -la /dev/fb0

# 设置正确的权限
chmod 666 /dev/fb0
```

### 7.3 触摸屏问题
```bash
# 检查输入设备
cat /proc/bus/input/devices

# 测试触摸事件
hexdump /dev/input/event0
```

## 八、自动化脚本

### 8.1 部署脚本 (deploy.sh)
```bash
#!/bin/bash

BOARD_IP="192.168.7.122"
BOARD_USER="root"

echo "Deploying libraries..."
scp -O /study/MQTT_lib/cJSON-master-arm/lib/libcjson.so.1.7.18 $BOARD_USER@$BOARD_IP:/lib/
scp -O /study/MQTT_lib/mosquitto-arm/lib/libmosquitto.so.1 $BOARD_USER@$BOARD_IP:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libssl.so.1.1 $BOARD_USER@$BOARD_IP:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libcrypto.so.1.1 $BOARD_USER@$BOARD_IP:/lib/

echo "Creating symbolic links..."
ssh $BOARD_USER@$BOARD_IP "cd /lib && ln -sf libcjson.so.1.7.18 libcjson.so.1 && ln -sf libcjson.so.1 libcjson.so"
ssh $BOARD_USER@$BOARD_IP "cd /lib && ln -sf libmosquitto.so.1 libmosquitto.so"
ssh $BOARD_USER@$BOARD_IP "cd /lib && ln -sf libssl.so.1.1 libssl.so && ln -sf libcrypto.so.1.1 libcrypto.so"

echo "Deploying application..."
make --file=Makefile-arm-mqtt send

echo "Setting permissions..."
ssh $BOARD_USER@$BOARD_IP "chmod +x /study/Intelligent_home/main"
ssh $BOARD_USER@$BOARD_IP "chmod 666 /dev/fb0 /dev/input/event0"

echo "Deployment complete!"
```

### 8.2 启动脚本 (start.sh - 在开发板上)
```bash
#!/bin/bash

export LV_LINUX_FBDEV_DEVICE=/dev/fb0

cd /study/Intelligent_home
./main
```

## 九、注意事项

1. **交叉编译工具链版本**：确保所有库都使用相同版本的交叉编译器编译
2. **库版本兼容性**：注意 OpenSSL 版本与 Mosquitto 的兼容性
3. **文件权限**：确保开发板上的设备文件有正确的读写权限
4. **网络配置**：确保 MQTT 服务器地址和端口配置正确
5. **屏幕分辨率**：根据实际硬件调整屏幕分辨率和触摸校准参数

## 十、版本信息

- LVGL: 9.2.2
- FreeType: 2.13.2
- OpenSSL: 1.1.1w
- cJSON: 1.7.18
- Mosquitto: 2.0.18

---

*创建日期：2025年8月12日*
*作者：智能家居项目团队*
