#include "../ui.h"
#include "MQTT.h"

void on_message(struct mosquitto *obj, void *arg, const struct mosquitto_message *msg)
{
    printf("主题：%s\n", msg->topic);
    printf("消息：%s\n", (char *)msg->payload);
    printf("消息长度：%d\n", msg->payloadlen);
    printf("消息Qos:%d\n", msg->qos);
    printf("消息是否保留：%d\n", msg->retain);
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

int MQTT_push()
{
    // 1.初始化MQTT库
    mosquitto_lib_init();

    // 2.创建MQTT客户端对象
    struct mosquitto *pub_obj = mosquitto_new(NULL, true, NULL);
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
    int count = 0;
    while (1)
    {
        // 4.发布消息
        char pub_msg[50];
        sprintf(pub_msg, "Hello, MQTT! %d", count++);
        ret = mosquitto_publish(pub_obj, NULL, "IntelligentHome", strlen(pub_msg), pub_msg, 0, false);
        if (ret != MOSQ_ERR_SUCCESS)
        {
            printf("发布消息失败！\n");
        }
        else
        {
            printf("发布消息成功！\n");
        }
        sleep(5);
    }
    // 5.释放MQTT客户端对象
    mosquitto_destroy(pub_obj);
    printf("释放MQTT客户端对象！\n");
    return 0;
}