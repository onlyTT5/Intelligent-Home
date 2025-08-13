#include "./ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// 添加MQTT库头文件
#include <mosquitto.h>
#include <pthread.h>
#include "cJSON.h"
#include "screens/ui_Screen1.h"
#include "ui_events.h"

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg);

// MQTT发送设备控制消息函数
void MQTT_send_device_control(const char *room, const char *device, const char *action);

int MQTT_init();

int MQTT_push();

void mqtt_ui_timer_init();