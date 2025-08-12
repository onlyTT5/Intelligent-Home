#include "./ui.h"
#include "MQTT.h"

/*
消息回调函数参数解析
obj:客户端对象地址
arg:mosquitto_new 创建客户端时传递的参数
msg:消息结构体
*/

struct mosquitto *pub_obj = NULL; // 全局发布客户端对象

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg)
{
    printf("主题：%s\n", msg->topic);
    printf("消息：%s\n", (char *)msg->payload);
    printf("消息长度：%d\n", msg->payloadlen);
    printf("消息Qos:%d\n", msg->qos);
    printf("消息是否保留：%d\n", msg->retain);

    char buf[1024] = {0};
    // 将消息内容转换为字符串
    snprintf(buf, sizeof(buf), "%s", (char *)msg->payload);

    cJSON *objs = cJSON_Parse(buf);
    if (objs == NULL)
        return; // 添加空指针检查

    
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

    // 4.启动事件处理线程
    mosquitto_loop_start(pub_obj);

    while (1)
    {
        sleep(1);
        int rand = random() % 100; // 快速产生随机数

        char buf[100] = {0};
        sprintf(buf, "温度: %d\n", rand);

        // 发布消息
        mosquitto_publish(pub_obj, NULL, "IntelligentHome", strlen(buf), buf, 0, false);
    }

    // 每当ui_heaterSlider发生改变，传送ui_heaterTemp
}

// 发送温度数据的函数
void MQTT_send_temperature(int temp_value)
{
    if (pub_obj == NULL)
    {
        printf("MQTT发布客户端未初始化！\n");
        return;
    }

    char buf[100] = {0};
    sprintf(buf, "热水器温度:%d", temp_value);

    // 发布消息到heater_temp主题
    int ret = mosquitto_publish(pub_obj, NULL, "heater_temp", strlen(buf), buf, 0, false);
    if (ret == MOSQ_ERR_SUCCESS)
    {
        printf("发送加热器温度: %d°C\n", temp_value);
    }
    else
    {
        printf("发送加热器温度失败！\n");
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