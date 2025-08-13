#include "../ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// 添加MQTT库头文件
#include <mosquitto.h>
#include <pthread.h>
#include "cJSON.h"

int MQTT_init();
int MQTT_push();