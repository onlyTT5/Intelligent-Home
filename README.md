# 智能家居项目

从 Ubuntu 开发环境移植到 ARM 开发板的完整步骤

## 项目概述

本项目是基于 LVGL 图形库的智能家居控制系统，支持 MQTT 通信、天气显示、音乐播放等功能。

### 目标设备 (ARM 开发板)

- ARM Cortex-A 系列处理器
- Linux 系统 (支持 framebuffer)
- 触摸屏或其他输入设备
- 网络连接 (用于 MQTT 通信)

## 一、依赖库准备

### 1.1 FreeType 库 (ARM 版本)

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

### 1.2 OpenSSL 库 (ARM 版本)

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

### 1.3 cJSON 库 (ARM 版本)

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

### 1.4 Mosquitto 库 (ARM 版本)

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

## 二、项目编译

### 2.1 获取项目源码

```bash
# 克隆项目 (假设项目已经包含 LVGL 子模块)
git clone <your-project-repo>
cd Intelligent-Home/project
git submodule update --init --recursive
```

### 2.2 配置 Makefile

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

### 2.3 编译项目

```bash
# 清理并编译
make --file=Makefile-arm-mqtt clean
make --file=Makefile-arm-mqtt
```

## 三、开发板环境准备

### 3.1 传输依赖库到开发板

```bash
# 传输所有必要的库文件到开发板的 /lib 目录
scp -O /study/MQTT_lib/cJSON-master-arm/lib/libcjson.so.1.7.18 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/mosquitto-arm/lib/libmosquitto.so.1 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libssl.so.1.1 root@<BOARD_IP>:/lib/
scp -O /study/MQTT_lib/openssl-arm/lib/libcrypto.so.1.1 root@<BOARD_IP>:/lib/
```

### 3.2 在开发板上创建符号链接

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

### 3.3 传输可执行文件

```bash
# 创建目标目录并传输程序
ssh root@<你的IP>
make --file=Makefile-arm-mqtt send
```

### 3.4 执行main文件

```bash
# 执行main，打开响应的文件夹
./main
```

### 3.5 MPlayer库的移植

可参考：https://blog.csdn.net/nanfeibuyi/article/details/82657631

## 4、实现智能家居MQTT联通

```bash
# 打开文件夹
cd project-test
# 直接运行可执行文件
./build/bin/main
```

### project端

![0c1d4ede1eccf469116984fe8297dd98](https://gitee.com/liweihanNB/typora/raw/master/20250813153712582.jpg)

### project-test端（模拟一个房间）

![image-20250813153759006](https://gitee.com/liweihanNB/typora/raw/master/20250813153759066.png)

可根据在project开发端上点击上面的控件控制模拟房间上的设备。