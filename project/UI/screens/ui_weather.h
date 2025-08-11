#ifndef UI_WEATHER_H
#define UI_WEATHER_H
#include "lvgl/lvgl.h"
#ifdef __cplusplus
extern "C"
{
    #endif
    // 天气信息获取
    void ui_weather_fetch(void);
#ifdef __cplusplus
} /*extern "C"*/    
#endif
#endif