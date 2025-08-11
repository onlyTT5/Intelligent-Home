#include "ui_weather.h"
#include "../ui.h"

// 定义天气数据的全局变量
char weather_str[64] = "晴"; // 默认值
char temp_str[32] = "23";    // 默认值

// 天气信息获取
void ui_weather_fetch(void)
{
    // 1.创建客户端通信对象
    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

    // 2.设置 HTTP 服务器地址信息
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;                         // IPV4 协议
    addr.sin_port = htons(80);                         // HTTP默认端口为  80
    addr.sin_addr.s_addr = inet_addr("120.77.134.57"); // 服务器IP

    // 2.连接服务器
    connect(tcp_socket, (struct sockaddr *)&addr, sizeof(addr));

    char Http_Request[512] = "GET /v3/weather/weatherInfo?key=6a1edf865110f3d7c628e88b2f31657d&city=440100 HTTP/1.1\r\nHost:restapi.amap.com\r\n\r\n";

    // 3.发送 HTTP 请求
    write(tcp_socket, Http_Request, strlen(Http_Request));

    // 4.读取服务器的应答数据
    char buffer[4096] = {0};

    read(tcp_socket, buffer, sizeof(buffer));

    char *tmp = strstr(buffer, "\r\n\r\n") + 4;

    cJSON *obj = cJSON_Parse(tmp);
    if (obj == NULL)
    {
        printf("parse json failed\n");
        close(tcp_socket);
        return;
    }

    // 获取lives数组
    cJSON *lives_array = cJSON_GetObjectItem(obj, "lives");
    if (lives_array == NULL || !cJSON_IsArray(lives_array))
    {
        printf("获取lives数组失败\n");
        cJSON_Delete(obj);
        close(tcp_socket);
        return;
    }

    // 获取数组大小
    int array_size = cJSON_GetArraySize(lives_array);
    cJSON *weather;
    cJSON *temperature;

    // 循环遍历lives数组中的每个元素
    for (int i = 0; i < array_size; i++)
    {
        cJSON *live_item = cJSON_GetArrayItem(lives_array, i);
        if (live_item == NULL)
            continue;
        weather = cJSON_GetObjectItem(live_item, "weather");
        temperature = cJSON_GetObjectItem(live_item, "temperature");

        // 保存天气和温度数据
        if (weather && cJSON_GetStringValue(weather))
        {
            strncpy(weather_str, cJSON_GetStringValue(weather), sizeof(weather_str) - 1);
            weather_str[sizeof(weather_str) - 1] = '\0';
        }
        if (temperature && cJSON_GetStringValue(temperature))
        {
            strncpy(temp_str, cJSON_GetStringValue(temperature), sizeof(temp_str) - 1);
            temp_str[sizeof(temp_str) - 1] = '\0';
        }
    }

    // 释放JSON对象内存
    cJSON_Delete(obj);

    // 5.关闭连接
    close(tcp_socket);
}