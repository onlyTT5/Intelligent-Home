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

int MQTT_init();

int MQTT_push();