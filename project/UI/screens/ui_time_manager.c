#include "ui_time_manager.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

// 最大支持的时间标签数量
#define MAX_TIME_LABELS 10

// 时间标签注册结构
typedef struct
{
    lv_obj_t *time_label;
    lv_obj_t *date_label;
    bool in_use;
} time_label_pair_t;

// 全局变量
static lv_timer_t *global_time_timer = NULL;
static time_label_pair_t label_pairs[MAX_TIME_LABELS];
static int active_label_count = 0;

// 更新所有注册的时间和日期标签
static void update_all_time_labels(void)
{
    time_t now;
    struct tm *timeinfo;
    char time_str[10];
    char date_str[30];

    // 获取当前时间
    time(&now);
    timeinfo = localtime(&now);

    // 格式化时间 (HH:MM:SS)
    strftime(time_str, sizeof(time_str), "%H:%M:%S", timeinfo);

    // 格式化日期 (Month DD, Day, YYYY)
    strftime(date_str, sizeof(date_str), "%B %d", timeinfo);

    // 更新所有注册的标签
    for (int i = 0; i < MAX_TIME_LABELS; i++)
    {
        if (label_pairs[i].in_use)
        {
            if (label_pairs[i].time_label != NULL)
            {
                lv_label_set_text(label_pairs[i].time_label, time_str);
            }
            if (label_pairs[i].date_label != NULL)
            {
                lv_label_set_text(label_pairs[i].date_label, date_str);
            }
        }
    }
}

// 定时器回调函数
static void time_timer_cb(lv_timer_t *timer)
{
    update_all_time_labels();
}

// 初始化时间管理器
void ui_time_manager_init(void)
{
    // 初始化标签数组
    for (int i = 0; i < MAX_TIME_LABELS; i++)
    {
        label_pairs[i].time_label = NULL;
        label_pairs[i].date_label = NULL;
        label_pairs[i].in_use = false;
    }
    active_label_count = 0;

    // 如果定时器已存在，先清理
    if (global_time_timer != NULL)
    {
        lv_timer_del(global_time_timer);
        global_time_timer = NULL;
    }
}

// 清理时间管理器
void ui_time_manager_cleanup(void)
{
    // 删除定时器
    if (global_time_timer != NULL)
    {
        lv_timer_del(global_time_timer);
        global_time_timer = NULL;
    }

    // 清理标签数组
    for (int i = 0; i < MAX_TIME_LABELS; i++)
    {
        label_pairs[i].time_label = NULL;
        label_pairs[i].date_label = NULL;
        label_pairs[i].in_use = false;
    }
    active_label_count = 0;
}

// 注册时间和日期标签
void ui_time_manager_register_labels(lv_obj_t *time_label, lv_obj_t *date_label)
{
    // 查找空闲槽位
    for (int i = 0; i < MAX_TIME_LABELS; i++)
    {
        if (!label_pairs[i].in_use)
        {
            label_pairs[i].time_label = time_label;
            label_pairs[i].date_label = date_label;
            label_pairs[i].in_use = true;
            active_label_count++;

            // 如果这是第一个注册的标签对，创建定时器
            if (active_label_count == 1)
            {
                global_time_timer = lv_timer_create(time_timer_cb, 1000, NULL);

                // 立即更新一次时间
                update_all_time_labels();
            }
            break;
        }
    }
}

// 注销时间和日期标签
void ui_time_manager_unregister_labels(lv_obj_t *time_label, lv_obj_t *date_label)
{
    // 查找并移除标签对
    for (int i = 0; i < MAX_TIME_LABELS; i++)
    {
        if (label_pairs[i].in_use &&
            label_pairs[i].time_label == time_label &&
            label_pairs[i].date_label == date_label)
        {

            label_pairs[i].time_label = NULL;
            label_pairs[i].date_label = NULL;
            label_pairs[i].in_use = false;
            active_label_count--;

            // 如果没有活跃的标签了，删除定时器
            if (active_label_count == 0)
            {
                if (global_time_timer != NULL)
                {
                    lv_timer_del(global_time_timer);
                    global_time_timer = NULL;
                }
            }
            break;
        }
    }
}
