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
int MQTT_send_device_control(const char *json_message);
void control_room_devices(const char *room_name, cJSON *room_obj);
void control_light(lv_obj_t *light_obj, lv_obj_t *slider_obj, lv_obj_t *value_obj, const char *state);
void control_curtain(lv_obj_t *curtain_obj, const char *state);
void control_music(lv_obj_t *speaker_obj, const char *state);
void control_air(lv_obj_t *air_text_obj, const char *state);