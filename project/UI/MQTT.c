#include "MQTT.h"
#include "./ui.h"
/*
消息回调函数参数解析
obj:客户端对象地址
arg:mosquitto_new 创建客户端时传递的参数
msg:消息结构体
*/

struct mosquitto *pub_obj = NULL; // 全局发布客户端对象

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg)
{
    // printf("主题：%s\n", msg->topic);
    // printf("消息：%s\n", (char *)msg->payload);
    // printf("消息长度：%d\n", msg->payloadlen);
    // printf("消息Qos:%d\n", msg->qos);
    // printf("消息是否保留：%d\n", msg->retain);

    char buf[1024] = {0};
    // 将消息内容转换为字符串
    snprintf(buf, sizeof(buf), "%s", (char *)msg->payload);

    // printf("准备解析JSON: %s\n", buf);

    cJSON *objs = cJSON_Parse(buf);

    cJSON *Living_Room_obj = cJSON_GetObjectItem(objs, "Living Room");
    if (Living_Room_obj != NULL)
    {
        printf("找到客厅\n");

        cJSON *Living_Room_light = cJSON_GetObjectItem(Living_Room_obj, "light");
        cJSON *Living_Room_curtain = cJSON_GetObjectItem(Living_Room_obj, "curtain");
        cJSON *Living_Room_music = cJSON_GetObjectItem(Living_Room_obj, "music");
        cJSON *Living_Room_air = cJSON_GetObjectItem(Living_Room_obj, "air");

        char *light = cJSON_GetStringValue(Living_Room_light);
        char *curtain = cJSON_GetStringValue(Living_Room_curtain);
        char *music = cJSON_GetStringValue(Living_Room_music);
        char *air = cJSON_GetStringValue(Living_Room_air);

        // 灯光处理
        if (light != NULL && strcmp(light, "on") == 0)
        {
            lv_image_set_src(ui_lightOnImg, &ui_img_920086830);
            lv_image_set_src(ui_lightOffImg, &ui_img_light_png);
            lv_label_set_text(ui_lightSliderValue, "50%");
            lv_slider_set_value(ui_lightSlider, 50, LV_ANIM_OFF);
        }
        else if (light != NULL && strcmp(light, "off") == 0)
        {
            lv_image_set_src(ui_lightOnImg, &light_on);
            lv_image_set_src(ui_lightOffImg, &light_click);
            lv_label_set_text(ui_lightSliderValue, "0%");
            lv_slider_set_value(ui_lightSlider, 0, LV_ANIM_OFF);
        }

        // 窗帘处理
        if (curtain != NULL && strcmp(curtain, "on") == 0)
        {
            lv_image_set_src(ui_curtainOnImg, &ui_img_1611275694);
            lv_image_set_src(ui_curtainOffImg, &ui_img_1850939063);
        }
        else if (curtain != NULL && strcmp(curtain, "off") == 0)
        {
            lv_image_set_src(ui_curtainOnImg, &ui_img_1850939063);
            lv_image_set_src(ui_curtainOffImg, &ui_img_1611275694);
        }
    }

    // 释放JSON对象内存
    cJSON_Delete(objs);
}

int MQTT_push()
{
    // 1.初始化MQTT库
    mosquitto_lib_init();

    // 2.创建MQTT客户端对象
    pub_obj = mosquitto_new(NULL, true, NULL);
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
        return -1;
    }
    else
    {
        printf("连接MQTT服务器成功！\n");
    }
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

    // 启动消息循环处理（非阻塞模式）
    mosquitto_loop_start(sub_obj);

    printf("MQTT客户端启动成功！\n");
    return 0;
}