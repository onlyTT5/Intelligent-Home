#include "../ui.h"
#include "MQTT.h"

// 外部变量声明，用于访问各屏幕的UI组件
extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_light;
extern lv_obj_t *ui_curtain;
extern lv_obj_t *ui_loudSpeaker;
extern lv_obj_t *ui_airConditionerText;
extern lv_obj_t *ui_Slider;
extern lv_obj_t *ui_lightValue;

extern lv_obj_t *ui_Screen2;
extern lv_obj_t *ui_light1;
extern lv_obj_t *ui_curtain1;
extern lv_obj_t *ui_loudSpeaker1;
extern lv_obj_t *ui_airConditionerText1;
extern lv_obj_t *ui_Slider1;
extern lv_obj_t *ui_lightValue1;

extern lv_obj_t *ui_Screen3;
extern lv_obj_t *ui_light2;
extern lv_obj_t *ui_curtain2;
extern lv_obj_t *ui_loudSpeaker2;
extern lv_obj_t *ui_airConditionerText2;
extern lv_obj_t *ui_Slider2;
extern lv_obj_t *ui_lightValue2;

// 控制设备的函数
void control_light(lv_obj_t *light_obj, lv_obj_t *slider_obj, lv_obj_t *value_obj, const char *state)
{
    if (light_obj == NULL)
        return;

    if (strcmp(state, "on") == 0)
    {
        lv_image_set_src(light_obj, &ui_img_light_on_png);
        if (slider_obj)
        {
            lv_slider_set_value(slider_obj, 50, LV_ANIM_OFF);
        }
        if (value_obj)
        {
            lv_label_set_text(value_obj, "50%");
        }
    }
    else if (strcmp(state, "off") == 0)
    {
        lv_image_set_src(light_obj, &ui_img_light_off_png);
        if (slider_obj)
        {
            lv_slider_set_value(slider_obj, 0, LV_ANIM_OFF);
        }
        if (value_obj)
        {
            lv_label_set_text(value_obj, "0%");
        }
    }
}

void control_curtain(lv_obj_t *curtain_obj, const char *state)
{
    if (curtain_obj == NULL)
        return;

    if (strcmp(state, "on") == 0)
    {
        lv_image_set_src(curtain_obj, &ui_img_curtain_on_png);
    }
    else if (strcmp(state, "off") == 0)
    {
        lv_image_set_src(curtain_obj, &ui_img_curtain_off_png);
    }
}

void control_music(lv_obj_t *speaker_obj, const char *state)
{
    if (speaker_obj == NULL)
        return;

    if (strcmp(state, "on") == 0)
    {
        lv_image_set_src(speaker_obj, &ui_img_loudspeaker_on_png);
    }
    else if (strcmp(state, "off") == 0)
    {
        lv_image_set_src(speaker_obj, &ui_img_loudspeaker_off_png);
    }
}

void control_air(lv_obj_t *air_text_obj, const char *state)
{
    if (air_text_obj == NULL)
        return;

    if (strcmp(state, "on") == 0)
    {
        lv_label_set_text(air_text_obj, "25°C");
    }
    else if (strcmp(state, "off") == 0)
    {
        lv_label_set_text(air_text_obj, "OFF");
    }
    else if (strcmp(state, "increase") == 0)
    {
        lv_label_set_text(air_text_obj, "28°C");
    }
    else if (strcmp(state, "decrease") == 0)
    {
        lv_label_set_text(air_text_obj, "18°C");
    }
}

// 处理单个房间的设备控制
void control_room_devices(const char *room_name, cJSON *room_obj)
{
    lv_obj_t *light_obj = NULL, *curtain_obj = NULL, *speaker_obj = NULL, *air_text_obj = NULL;
    lv_obj_t *slider_obj = NULL, *value_obj = NULL;

    // 根据房间名选择对应的UI组件
    if (strcmp(room_name, "Living Room") == 0)
    {
        light_obj = ui_light;
        curtain_obj = ui_curtain;
        speaker_obj = ui_loudSpeaker;
        air_text_obj = ui_airConditionerText;
        slider_obj = ui_Slider;
        value_obj = ui_lightValue;
    }
    else if (strcmp(room_name, "Room 1") == 0)
    {
        light_obj = ui_light1;
        curtain_obj = ui_curtain1;
        speaker_obj = ui_loudSpeaker1;
        air_text_obj = ui_airConditionerText1;
        slider_obj = ui_Slider1;
        value_obj = ui_lightValue1;
    }
    else if (strcmp(room_name, "Room 2") == 0)
    {
        light_obj = ui_light2;
        curtain_obj = ui_curtain2;
        speaker_obj = ui_loudSpeaker2;
        air_text_obj = ui_airConditionerText2;
        slider_obj = ui_Slider2;
        value_obj = ui_lightValue2;
    }

    // 控制各个设备
    cJSON *light = cJSON_GetObjectItem(room_obj, "light");
    if (light && cJSON_IsString(light))
    {
        control_light(light_obj, slider_obj, value_obj, light->valuestring);
        printf("房间 %s：灯光设置为 %s\n", room_name, light->valuestring);
    }

    cJSON *curtain = cJSON_GetObjectItem(room_obj, "curtain");
    if (curtain && cJSON_IsString(curtain))
    {
        control_curtain(curtain_obj, curtain->valuestring);
        printf("房间 %s：窗帘设置为 %s\n", room_name, curtain->valuestring);
    }

    cJSON *music = cJSON_GetObjectItem(room_obj, "music");
    if (music && cJSON_IsString(music))
    {
        control_music(speaker_obj, music->valuestring);
        printf("房间 %s：音响设置为 %s\n", room_name, music->valuestring);
    }

    cJSON *air = cJSON_GetObjectItem(room_obj, "air");
    if (air && cJSON_IsString(air))
    {
        control_air(air_text_obj, air->valuestring);
        printf("房间 %s：空调设置为 %s\n", room_name, air->valuestring);
    }
}

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg)
{
    printf("主题：%s\n", msg->topic);
    printf("消息：%s\n", (char *)msg->payload);
    printf("消息长度：%d\n", msg->payloadlen);
    printf("消息Qos:%d\n", msg->qos);
    printf("消息是否保留：%d\n", msg->retain);

    // 解析JSON消息
    char *json_string = (char *)malloc(msg->payloadlen + 1);
    memcpy(json_string, msg->payload, msg->payloadlen);
    json_string[msg->payloadlen] = '\0';

    cJSON *json = cJSON_Parse(json_string);
    if (json == NULL)
    {
        printf("JSON解析失败\n");
        free(json_string);
        return;
    }

    // 处理各个房间的设备控制
    cJSON *living_room = cJSON_GetObjectItem(json, "Living Room");
    if (living_room)
    {
        control_room_devices("Living Room", living_room);
    }

    cJSON *room1 = cJSON_GetObjectItem(json, "Room 1");
    if (room1)
    {
        control_room_devices("Room 1", room1);
    }

    cJSON *room2 = cJSON_GetObjectItem(json, "Room 2");
    if (room2)
    {
        control_room_devices("Room 2", room2);
    }

    cJSON_Delete(json);
    free(json_string);
}

int MQTT_init()
{
    // 1.初始化MQTT库
    mosquitto_lib_init();

    // 2.创建MQTT客户端对象
    struct mosquitto *sub_obj = mosquitto_new(NULL, true, NULL);
    if (sub_obj == NULL)
    {
        printf("创建MQTT客户端对象失败！\n");
        return -1;
    }

    // 3.连接MQTT服务器
    int ret = mosquitto_connect(sub_obj, "120.26.0.201", 1883, 60);
    if (ret != MOSQ_ERR_SUCCESS)
    {
        printf("连接MQTT服务器失败！\n");
        return -1;
    }
    else
    {
        printf("连接MQTT服务器成功！\n");
    }

    // 4.订阅主题
    ret = mosquitto_subscribe(sub_obj, NULL, "IntelligentHome", 0);
    if (ret != MOSQ_ERR_SUCCESS)
    {
        printf("订阅主题失败！\n");
        return -1;
    }
    else
    {
        printf("订阅主题成功！\n");
    }

    // 5.设置消息回调函数 ，当有消息来临时，就会调用该函数
    mosquitto_message_callback_set(sub_obj, on_message);

    // 进入阻塞接收消息状态
    mosquitto_loop_forever(sub_obj, -1, 1);

    // 6.释放MQTT客户端对象
    mosquitto_destroy(sub_obj);
    printf("释放MQTT客户端对象！\n");
    return 0;
}

// 发送JSON格式的设备控制消息
int MQTT_send_device_control(const char *json_message)
{
    // 1.初始化MQTT库
    mosquitto_lib_init();

    // 2.创建MQTT客户端对象
    struct mosquitto *pub_obj = mosquitto_new("publisher_client", true, NULL);
    if (pub_obj == NULL)
    {
        printf("创建MQTT客户端对象失败！\n");
        return -1;
    }

    // 3.连接MQTT服务器
    int ret = mosquitto_connect(pub_obj, "120.26.0.201", 1883, 60);
    if (ret != MOSQ_ERR_SUCCESS)
    {
        printf("连接MQTT服务器失败！\n");
        mosquitto_destroy(pub_obj);
        return -1;
    }
    else
    {
        printf("连接MQTT服务器成功！\n");
    }

    // 4.发布JSON消息
    ret = mosquitto_publish(pub_obj, NULL, "IntelligentHome", strlen(json_message), json_message, 0, false);
    if (ret != MOSQ_ERR_SUCCESS)
    {
        printf("发布JSON消息失败！\n");
    }
    else
    {
        printf("发布JSON消息成功！\n");
        printf("发送的JSON:\n%s\n", json_message);
    }

    // 等待消息发送完成
    sleep(1);

    // 5.释放MQTT客户端对象
    mosquitto_destroy(pub_obj);
    mosquitto_lib_cleanup();

    return ret == MOSQ_ERR_SUCCESS ? 0 : -1;
}

int MQTT_push()
{
    // 不再自动发送消息，保留函数以备将来使用
    printf("MQTT push功能已禁用，不会自动发送消息\n");
    return 0;
}