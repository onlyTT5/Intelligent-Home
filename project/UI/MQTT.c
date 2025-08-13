#include "MQTT.h"
#include "./ui.h"

// 全局变量，用于在MQTT回调和UI线程间传递数据
typedef struct
{
    char music1_action[10]; // "next", "prev", "on", "off"
    char music2_action[10]; // "next", "prev", "on", "off"
    char music3_action[10]; // "next", "prev", "on", "off"

    char light1_action[10]; // "on", "off"
    char light2_action[10]; // "on", "off"
    char light3_action[10]; // "on", "off"

    char curtain1_action[10]; // "on", "off"
    char curtain2_action[10]; // "on", "off"
    char curtain3_action[10]; // "on", "off"

    char air1_action[10]; // "on", "off"
    char air2_action[10]; // "on", "off"
    char air3_action[10]; // "on", "off"

    int need_update; // 标记是否需要更新UI
} mqtt_ui_data_t;

static mqtt_ui_data_t g_mqtt_data = {0};

// UI更新定时器回调函数（运行在UI线程中，安全）
static void ui_update_timer_cb(lv_timer_t *timer)
{
    if (!g_mqtt_data.need_update)
    {
        return;
    }

    // 客厅的组建
    // 处理音乐控制
    if (strlen(g_mqtt_data.music1_action) > 0)
    {
        if (strcmp(g_mqtt_data.music1_action, "next") == 0)
        {
            nextSong(NULL, ui_next, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music1_action, "prev") == 0)
        {
            prevSong(NULL, ui_last, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music1_action, "on") == 0)
        {
            playSong(NULL, ui_play, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music1_action, "off") == 0)
        {
            playSong(NULL, ui_play, ui_musicInfo, ui_songName, ui_singer);
        }
        memset(g_mqtt_data.music1_action, 0, sizeof(g_mqtt_data.music1_action));
    }

    // 处理灯光控制
    if (strlen(g_mqtt_data.light1_action) > 0)
    {
        if (strcmp(g_mqtt_data.light1_action, "on") == 0)
        {
            lightAllOn(NULL, ui_lightOnImg, ui_lightOffImg, ui_lightSliderValue, ui_lightSlider);
        }
        else if (strcmp(g_mqtt_data.light1_action, "off") == 0)
        {
            lightAllOff(NULL, ui_lightOnImg, ui_lightOffImg, ui_lightSliderValue, ui_lightSlider);
        }
        memset(g_mqtt_data.light1_action, 0, sizeof(g_mqtt_data.light1_action));
    }

    // 处理窗帘控制
    if (strlen(g_mqtt_data.curtain1_action) > 0)
    {
        if (strcmp(g_mqtt_data.curtain1_action, "on") == 0 || strcmp(g_mqtt_data.curtain1_action, "open") == 0)
        {
            curtainAllOn(NULL, ui_curtainOnImg, ui_curtainOffImg);
        }
        else if (strcmp(g_mqtt_data.curtain1_action, "off") == 0 || strcmp(g_mqtt_data.curtain1_action, "close") == 0)
        {
            curtainAllOff(NULL, ui_curtainOnImg, ui_curtainOffImg);
        }
        memset(g_mqtt_data.curtain1_action, 0, sizeof(g_mqtt_data.curtain1_action));
    }

    // 处理空调控制
    if (strlen(g_mqtt_data.air1_action) > 0)
    {
        if (strcmp(g_mqtt_data.air1_action, "on") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature, ui_temperatureText, 1); // 1表示开启
        }
        else if (strcmp(g_mqtt_data.air1_action, "off") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature, ui_temperatureText, 0); // 0表示关闭
        }
        else if (strcmp(g_mqtt_data.air1_action, "increase") == 0)
        {
            increaseTemp(NULL, ui_airTemperature, ui_temperatureText);
        }
        else if (strcmp(g_mqtt_data.air1_action, "decrease") == 0)
        {
            decreaseTemp(NULL, ui_airTemperature, ui_temperatureText);
        }
        memset(g_mqtt_data.air1_action, 0, sizeof(g_mqtt_data.air1_action));
    }

    // 主卧的组建
    // 处理音乐控制
    if (strlen(g_mqtt_data.music2_action) > 0)
    {
        if (strcmp(g_mqtt_data.music2_action, "next") == 0)
        {
            nextSong(NULL, ui_next1, ui_musicInfo1, ui_songName1, ui_singer1);
        }
        else if (strcmp(g_mqtt_data.music2_action, "prev") == 0)
        {
            prevSong(NULL, ui_last1, ui_musicInfo1, ui_songName1, ui_singer1);
        }
        else if (strcmp(g_mqtt_data.music2_action, "on") == 0)
        {
            playSong(NULL, ui_play1, ui_musicInfo1, ui_songName1, ui_singer1);
        }
        else if (strcmp(g_mqtt_data.music2_action, "off") == 0)
        {
            playSong(NULL, ui_play1, ui_musicInfo1, ui_songName1, ui_singer1);
        }
        memset(g_mqtt_data.music2_action, 0, sizeof(g_mqtt_data.music2_action));
    }

    // 处理灯光控制
    if (strlen(g_mqtt_data.light2_action) > 0)
    {
        if (strcmp(g_mqtt_data.light2_action, "on") == 0)
        {
            lightAllOn(NULL, ui_lightOnImg1, ui_lightOffImg1, ui_lightSliderValue1, ui_lightSlider1);
        }
        else if (strcmp(g_mqtt_data.light2_action, "off") == 0)
        {
            lightAllOff(NULL, ui_lightOnImg1, ui_lightOffImg1, ui_lightSliderValue1, ui_lightSlider1);
        }
        memset(g_mqtt_data.light2_action, 0, sizeof(g_mqtt_data.light2_action));
    }

    // 处理窗帘控制
    if (strlen(g_mqtt_data.curtain2_action) > 0)
    {
        if (strcmp(g_mqtt_data.curtain2_action, "on") == 0 || strcmp(g_mqtt_data.curtain2_action, "open") == 0)
        {
            curtainAllOn(NULL, ui_curtainOnImg1, ui_curtainOffImg1);
        }
        else if (strcmp(g_mqtt_data.curtain2_action, "off") == 0 || strcmp(g_mqtt_data.curtain2_action, "close") == 0)
        {
            curtainAllOff(NULL, ui_curtainOnImg1, ui_curtainOffImg1);
        }
        memset(g_mqtt_data.curtain2_action, 0, sizeof(g_mqtt_data.curtain2_action));
    }

    // 处理空调控制
    if (strlen(g_mqtt_data.air2_action) > 0)
    {
        if (strcmp(g_mqtt_data.air2_action, "on") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature1, ui_temperatureText1, 1); // 1表示开启
        }
        else if (strcmp(g_mqtt_data.air2_action, "off") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature1, ui_temperatureText1, 0); // 0表示关闭
        }
        else if (strcmp(g_mqtt_data.air2_action, "increase") == 0)
        {
            increaseTemp(NULL, ui_airTemperature1, ui_temperatureText1);
        }
        else if (strcmp(g_mqtt_data.air2_action, "decrease") == 0)
        {
            decreaseTemp(NULL, ui_airTemperature1, ui_temperatureText1);
        }
        memset(g_mqtt_data.air2_action, 0, sizeof(g_mqtt_data.air2_action));
    }

    // 次卧的组建
    // 处理音乐控制
    if (strlen(g_mqtt_data.music3_action) > 0)
    {
        if (strcmp(g_mqtt_data.music3_action, "next") == 0)
        {
            nextSong(NULL, ui_next2, ui_musicInfo2, ui_songName2, ui_singer2);
        }
        else if (strcmp(g_mqtt_data.music3_action, "prev") == 0)
        {
            prevSong(NULL, ui_last2, ui_musicInfo2, ui_songName2, ui_singer2);
        }
        else if (strcmp(g_mqtt_data.music3_action, "on") == 0)
        {
            playSong(NULL, ui_play2, ui_musicInfo2, ui_songName2, ui_singer2);
        }
        else if (strcmp(g_mqtt_data.music3_action, "off") == 0)
        {
            playSong(NULL, ui_play2, ui_musicInfo2, ui_songName2, ui_singer2);
        }
        memset(g_mqtt_data.music3_action, 0, sizeof(g_mqtt_data.music3_action));
    }

    // 处理灯光控制
    if (strlen(g_mqtt_data.light3_action) > 0)
    {
        if (strcmp(g_mqtt_data.light3_action, "on") == 0)
        {
            lightAllOn(NULL, ui_lightOnImg2, ui_lightOffImg2, ui_lightSliderValue2, ui_lightSlider2);
        }
        else if (strcmp(g_mqtt_data.light3_action, "off") == 0)
        {
            lightAllOff(NULL, ui_lightOnImg2, ui_lightOffImg2, ui_lightSliderValue2, ui_lightSlider2);
        }
        memset(g_mqtt_data.light3_action, 0, sizeof(g_mqtt_data.light3_action));
    }

    // 处理窗帘控制
    if (strlen(g_mqtt_data.curtain3_action) > 0)
    {
        if (strcmp(g_mqtt_data.curtain3_action, "on") == 0 || strcmp(g_mqtt_data.curtain3_action, "open") == 0)
        {
            curtainAllOn(NULL, ui_curtainOnImg2, ui_curtainOffImg2);
        }
        else if (strcmp(g_mqtt_data.curtain3_action, "off") == 0 || strcmp(g_mqtt_data.curtain3_action, "close") == 0)
        {
            curtainAllOff(NULL, ui_curtainOnImg2, ui_curtainOffImg2);
        }
        memset(g_mqtt_data.curtain3_action, 0, sizeof(g_mqtt_data.curtain3_action));
    }

    // 处理空调控制
    if (strlen(g_mqtt_data.air3_action) > 0)
    {
        if (strcmp(g_mqtt_data.air3_action, "on") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature2, ui_temperatureText2, 1); // 1表示开启
        }
        else if (strcmp(g_mqtt_data.air3_action, "off") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature2, ui_temperatureText2, 0); // 0表示关闭
        }
        else if (strcmp(g_mqtt_data.air3_action, "increase") == 0)
        {
            increaseTemp(NULL, ui_airTemperature2, ui_temperatureText2);
        }
        else if (strcmp(g_mqtt_data.air3_action, "decrease") == 0)
        {
            decreaseTemp(NULL, ui_airTemperature2, ui_temperatureText2);
        }
        memset(g_mqtt_data.air3_action, 0, sizeof(g_mqtt_data.air3_action));
    }

    g_mqtt_data.need_update = 0;
}

// 初始化UI更新定时器
void mqtt_ui_timer_init()
{
    static lv_timer_t *ui_timer = NULL;
    if (ui_timer == NULL)
    {
        // 创建一个50ms的定时器，用于安全更新UI
        ui_timer = lv_timer_create(ui_update_timer_cb, 50, NULL);
    }
}
/*
消息回调函数参数解析
obj:客户端对象地址
arg:mosquitto_new 创建客户端时传递的参数
msg:消息结构体
*/

struct mosquitto *pub_obj = NULL; // 全局发布客户端对象

// MQTT发送设备控制消息函数
void MQTT_send_device_control(const char *room, const char *device, const char *action)
{
    if (pub_obj == NULL)
    {
        printf("MQTT发布客户端未初始化！\n");
        return;
    }

    // 构造JSON消息
    cJSON *json = cJSON_CreateObject();
    cJSON *room_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(room_obj, device, action);
    cJSON_AddItemToObject(json, room, room_obj);

    char *json_string = cJSON_Print(json);
    if (json_string != NULL)
    {
        printf("发送MQTT消息: %s\n", json_string);

        // 发布消息到IntelligentHome主题
        int ret = mosquitto_publish(pub_obj, NULL, "IntelligentHome", strlen(json_string), json_string, 0, false);
        if (ret != MOSQ_ERR_SUCCESS)
        {
            printf("发送MQTT消息失败，错误代码: %d\n", ret);
        }
        else
        {
            printf("MQTT消息发送成功！\n");
        }

        free(json_string);
    }

    cJSON_Delete(json);
}

// MQTT发送灯光亮度百分比消息函数
void MQTT_send_light_brightness(const char *room, int brightness)
{
    if (pub_obj == NULL)
    {
        printf("MQTT发布客户端未初始化！\n");
        return;
    }

    // 构造JSON消息，包含亮度百分比
    cJSON *json = cJSON_CreateObject();
    cJSON *room_obj = cJSON_CreateObject();

    // 将亮度作为数字添加到JSON中
    cJSON_AddNumberToObject(room_obj, "light_brightness", brightness);
    cJSON_AddItemToObject(json, room, room_obj);

    char *json_string = cJSON_Print(json);
    if (json_string != NULL)
    {
        printf("发送MQTT灯光亮度消息: %s\n", json_string);

        // 发布消息到IntelligentHome主题
        int ret = mosquitto_publish(pub_obj, NULL, "IntelligentHome", strlen(json_string), json_string, 0, false);
        if (ret != MOSQ_ERR_SUCCESS)
        {
            printf("发送MQTT灯光亮度消息失败，错误代码: %d\n", ret);
        }
        else
        {
            printf("MQTT灯光亮度消息发送成功！亮度: %d%%\n", brightness);
        }

        free(json_string);
    }

    cJSON_Delete(json);
}

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg)
{
    char buf[1024] = {0};
    snprintf(buf, sizeof(buf), "%s", (char *)msg->payload);

    cJSON *objs = cJSON_Parse(buf);
    cJSON *Living_Room_obj = cJSON_GetObjectItem(objs, "Living Room");
    cJSON *Room1_obj = cJSON_GetObjectItem(objs, "Room 1");
    cJSON *Room2_obj = cJSON_GetObjectItem(objs, "Room 2");
    if (Living_Room_obj != NULL)
    {
        printf("找到客厅\n");

        cJSON *Living_Room_light = cJSON_GetObjectItem(Living_Room_obj, "light");
        cJSON *Living_Room_light_brightness = cJSON_GetObjectItem(Living_Room_obj, "light_brightness");
        cJSON *Living_Room_curtain = cJSON_GetObjectItem(Living_Room_obj, "curtain");
        cJSON *Living_Room_music = cJSON_GetObjectItem(Living_Room_obj, "music");
        cJSON *Living_Room_air = cJSON_GetObjectItem(Living_Room_obj, "air");

        char *light = cJSON_GetStringValue(Living_Room_light);
        char *curtain = cJSON_GetStringValue(Living_Room_curtain);
        char *music = cJSON_GetStringValue(Living_Room_music);
        char *air = cJSON_GetStringValue(Living_Room_air);

        // 线程安全：只设置标志，不直接操作UI
        if (light != NULL)
        {
            printf("设置灯光动作: %s\n", light);
            strncpy(g_mqtt_data.light1_action, light, sizeof(g_mqtt_data.light1_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        // 处理灯光亮度
        if (Living_Room_light_brightness != NULL && cJSON_IsNumber(Living_Room_light_brightness))
        {
            int brightness = (int)cJSON_GetNumberValue(Living_Room_light_brightness);
            printf("收到客厅灯光亮度设置: %d%%\n", brightness);

            // 这里可以添加设置滑块值的逻辑
            // 但需要在UI线程中安全执行，暂时只打印日志
        }

        if (curtain != NULL)
        {
            printf("设置窗帘动作: %s\n", curtain);
            strncpy(g_mqtt_data.curtain1_action, curtain, sizeof(g_mqtt_data.curtain1_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (music != NULL)
        {
            printf("设置音乐动作: %s\n", music);
            strncpy(g_mqtt_data.music1_action, music, sizeof(g_mqtt_data.music1_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (air != NULL)
        {
            printf("设置空调动作: %s\n", air);
            strncpy(g_mqtt_data.air1_action, air, sizeof(g_mqtt_data.air1_action) - 1);
            g_mqtt_data.need_update = 1;
        }
    }

    if (Room1_obj != NULL)
    {
        printf("找到主卧\n");

        cJSON *Room1_light = cJSON_GetObjectItem(Room1_obj, "light");
        cJSON *Room1_curtain = cJSON_GetObjectItem(Room1_obj, "curtain");
        cJSON *Room1_music = cJSON_GetObjectItem(Room1_obj, "music");
        cJSON *Room1_air = cJSON_GetObjectItem(Room1_obj, "air");

        char *light = cJSON_GetStringValue(Room1_light);
        char *curtain = cJSON_GetStringValue(Room1_curtain);
        char *music = cJSON_GetStringValue(Room1_music);
        char *air = cJSON_GetStringValue(Room1_air);

        // 线程安全：只设置标志，不直接操作UI
        if (light != NULL)
        {
            printf("设置灯光动作: %s\n", light);
            strncpy(g_mqtt_data.light2_action, light, sizeof(g_mqtt_data.light2_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (curtain != NULL)
        {
            printf("设置窗帘动作: %s\n", curtain);
            strncpy(g_mqtt_data.curtain2_action, curtain, sizeof(g_mqtt_data.curtain2_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (music != NULL)
        {
            printf("设置音乐动作: %s\n", music);
            strncpy(g_mqtt_data.music2_action, music, sizeof(g_mqtt_data.music2_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (air != NULL)
        {
            printf("设置空调动作: %s\n", air);
            // 验证空调动作是否有效
            if (strcmp(air, "on") == 0 || strcmp(air, "off") == 0 ||
                strcmp(air, "increase") == 0 || strcmp(air, "decrease") == 0)
            {
                strncpy(g_mqtt_data.air2_action, air, sizeof(g_mqtt_data.air2_action) - 1);
                g_mqtt_data.need_update = 1;
            }
            else
            {
                printf("警告：主卧空调收到无效动作 '%s'，忽略处理\n", air);
            }
        }
    }

    if (Room2_obj != NULL)
    {
        printf("找到次卧\n");

        cJSON *Room2_light = cJSON_GetObjectItem(Room2_obj, "light");
        cJSON *Room2_curtain = cJSON_GetObjectItem(Room2_obj, "curtain");
        cJSON *Room2_music = cJSON_GetObjectItem(Room2_obj, "music");
        cJSON *Room2_air = cJSON_GetObjectItem(Room2_obj, "air");

        char *light = cJSON_GetStringValue(Room2_light);
        char *curtain = cJSON_GetStringValue(Room2_curtain);
        char *music = cJSON_GetStringValue(Room2_music);
        char *air = cJSON_GetStringValue(Room2_air);

        // 线程安全：只设置标志，不直接操作UI
        if (light != NULL)
        {
            printf("设置灯光动作: %s\n", light);
            strncpy(g_mqtt_data.light3_action, light, sizeof(g_mqtt_data.light3_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (curtain != NULL)
        {
            printf("设置窗帘动作: %s\n", curtain);
            strncpy(g_mqtt_data.curtain3_action, curtain, sizeof(g_mqtt_data.curtain3_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (music != NULL)
        {
            printf("设置音乐动作: %s\n", music);
            strncpy(g_mqtt_data.music3_action, music, sizeof(g_mqtt_data.music3_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (air != NULL)
        {
            printf("设置空调动作: %s\n", air);
            strncpy(g_mqtt_data.air3_action, air, sizeof(g_mqtt_data.air3_action) - 1);
            g_mqtt_data.need_update = 1;
        }
    }

    cJSON_Delete(objs);
}

int MQTT_push()
{
    // 1.初始化MQTT库（如果还没初始化的话）
    mosquitto_lib_init();

    // 2.创建MQTT客户端对象
    pub_obj = mosquitto_new(NULL, true, NULL);
    if (pub_obj == NULL)
    {
        printf("创建MQTT发布客户端对象失败！\n");
        return -1;
    }

    // 3.连接MQTT服务器
    int ret = mosquitto_connect(pub_obj, "120.26.0.201", 1883, 60);
    if (ret != MOSQ_ERR_SUCCESS)
    {
        printf("MQTT发布客户端连接服务器失败！\n");
        return -1;
    }
    else
    {
        printf("MQTT发布客户端连接服务器成功！\n");
    }

    // 4.启动事件处理
    mosquitto_loop_start(pub_obj);

    printf("MQTT发布客户端初始化成功！\n");

    // 保持线程活跃，处理网络事件
    while (1)
    {
        sleep(10); // 每10秒休眠，降低CPU使用率
    }

    return 0;
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
        printf("订阅主题接受端成功！\n");
    }

    // 5.设置消息回调函数 ，当有消息来临时，就会调用该函数
    mosquitto_message_callback_set(sub_obj, on_message);

    // 启动消息循环处理（非阻塞模式）
    mosquitto_loop_start(sub_obj);

    // 初始化UI更新定时器
    mqtt_ui_timer_init();

    printf("MQTT客户端启动成功！\n");
    return 0;
}