#ifndef UI_TIME_MANAGER_H
#define UI_TIME_MANAGER_H

#include "lvgl/lvgl.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // 时间管理器函数声明
    void ui_time_manager_init(void);
    void ui_time_manager_cleanup(void);
    void ui_time_manager_register_labels(lv_obj_t *time_label, lv_obj_t *date_label);
    void ui_time_manager_unregister_labels(lv_obj_t *time_label, lv_obj_t *date_label);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /* UI_TIME_MANAGER_H */
