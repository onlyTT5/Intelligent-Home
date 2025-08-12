#include "MQTT.h"
#include "./ui.h"

// 全局变量，用于在MQTT回调和UI线程间传递数据
typedef struct
{
    char music_action[10];   // "next", "prev", "on", "off"
    char light_action[10];   // "on", "off"
    char curtain_action[10]; // "on", "off"
    char air_action[10];     // "on", "off"
    int need_update;         // 标记是否需要更新UI
} mqtt_ui_data_t;

static mqtt_ui_data_t g_mqtt_data = {0};

// UI更新定时器回调函数（运行在UI线程中，安全）
static void ui_update_timer_cb(lv_timer_t *timer)
{
    if (!g_mqtt_data.need_update)
    {
        return;
    }

    // 处理音乐控制
    if (strlen(g_mqtt_data.music_action) > 0)
    {
        if (strcmp(g_mqtt_data.music_action, "next") == 0)
        {
            nextSong(NULL, ui_next, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music_action, "prev") == 0)
        {
            prevSong(NULL, ui_last, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music_action, "on") == 0)
        {
            playSong(NULL, ui_play, ui_musicInfo, ui_songName, ui_singer);
        }
        else if (strcmp(g_mqtt_data.music_action, "off") == 0)
        {
            playSong(NULL, ui_play, ui_musicInfo, ui_songName, ui_singer);
        }
        memset(g_mqtt_data.music_action, 0, sizeof(g_mqtt_data.music_action));
    }

    // 处理灯光控制
    if (strlen(g_mqtt_data.light_action) > 0)
    {
        if (strcmp(g_mqtt_data.light_action, "on") == 0)
        {
            lightAllOn(NULL, ui_lightOnImg, ui_lightOffImg, ui_lightSliderValue, ui_lightSlider);
        }
        else if (strcmp(g_mqtt_data.light_action, "off") == 0)
        {
            lightAllOff(NULL, ui_lightOnImg, ui_lightOffImg, ui_lightSliderValue, ui_lightSlider);
        }
        memset(g_mqtt_data.light_action, 0, sizeof(g_mqtt_data.light_action));
    }

    // 处理窗帘控制
    if (strlen(g_mqtt_data.curtain_action) > 0)
    {
        if (strcmp(g_mqtt_data.curtain_action, "on") == 0)
        {
            curtainAllOn(NULL, ui_curtainOnImg, ui_curtainOffImg);
        }
        else if (strcmp(g_mqtt_data.curtain_action, "off") == 0)
        {
            curtainAllOff(NULL, ui_curtainOnImg, ui_curtainOffImg);
        }
        memset(g_mqtt_data.curtain_action, 0, sizeof(g_mqtt_data.curtain_action));
    }

    // 处理空调控制
    if (strlen(g_mqtt_data.air_action) > 0)
    {
        if (strcmp(g_mqtt_data.air_action, "on") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature, ui_temperatureText, 1); // 1表示开启
        }
        else if (strcmp(g_mqtt_data.air_action, "off") == 0)
        {
            airOnOffControl(NULL, ui_airTemperature, ui_temperatureText, 0); // 0表示关闭
        }
        else if (strcmp(g_mqtt_data.air_action, "increase") == 0)
        {
            increaseTemp(NULL, ui_airTemperature, ui_temperatureText);
        }
        else if (strcmp(g_mqtt_data.air_action, "decrease") == 0)
        {
            decreaseTemp(NULL, ui_airTemperature, ui_temperatureText);
        }
        memset(g_mqtt_data.air_action, 0, sizeof(g_mqtt_data.air_action));
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
            strncpy(g_mqtt_data.light_action, light, sizeof(g_mqtt_data.light_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (curtain != NULL)
        {
            printf("设置窗帘动作: %s\n", curtain);
            strncpy(g_mqtt_data.curtain_action, curtain, sizeof(g_mqtt_data.curtain_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (music != NULL)
        {
            printf("设置音乐动作: %s\n", music);
            strncpy(g_mqtt_data.music_action, music, sizeof(g_mqtt_data.music_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (air != NULL)
        {
            printf("设置空调动作: %s\n", air);
            strncpy(g_mqtt_data.air_action, air, sizeof(g_mqtt_data.air_action) - 1);
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
            strncpy(g_mqtt_data.light_action, light, sizeof(g_mqtt_data.light_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (curtain != NULL)
        {
            printf("设置窗帘动作: %s\n", curtain);
            strncpy(g_mqtt_data.curtain_action, curtain, sizeof(g_mqtt_data.curtain_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (music != NULL)
        {
            printf("设置音乐动作: %s\n", music);
            strncpy(g_mqtt_data.music_action, music, sizeof(g_mqtt_data.music_action) - 1);
            g_mqtt_data.need_update = 1;
        }

        if (air != NULL)
        {
            printf("设置空调动作: %s\n", air);
            strncpy(g_mqtt_data.air_action, air, sizeof(g_mqtt_data.air_action) - 1);
            g_mqtt_data.need_update = 1;
        }
    }

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

    // 初始化UI更新定时器
    mqtt_ui_timer_init();

    printf("MQTT客户端启动成功！\n");
    return 0;
}