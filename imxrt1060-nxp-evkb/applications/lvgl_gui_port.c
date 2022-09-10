/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-08-02     BruceOu      first version
 */
#include "lvgl_gui_port.h"
#define BG_GREEN    0xFF00FF00
#define BG_RED      0xFFFF0000

static void my_event_cb(lv_event_t * e)
{
    lv_color_t color;
    lv_obj_t * obj = lv_event_get_target(e);        // 获取触发事件的部件(对象)
    lv_event_code_t code = lv_event_get_code(e);    // 获取当前部件(对象)触发的事件代码
    lv_obj_t * label = lv_event_get_user_data(e);   // 获取添加事件时传递的用户数据

    switch(code){
        case LV_EVENT_PRESSED:
            color = lv_obj_get_style_bg_color(obj, LV_PART_MAIN);

            if(BG_RED == lv_color_to32(color))
            {
                lv_obj_set_style_bg_color(obj, lv_color_hex(BG_GREEN), 0);  // 通过本地样式(私有样式)设置背景色
                lv_label_set_text(label, "GREEN");
                printf("LV_EVENT_PRESSED, BG is GREEN\n");
            }
            else
            {
                lv_obj_set_style_bg_color(obj, lv_color_hex(BG_RED), 0);  // 通过本地样式(私有样式)设置背景色
                lv_label_set_text(label, "RED");
                printf("LV_EVENT_PRESSED, BG is RED\n");
            }

            break;
        case LV_EVENT_LONG_PRESSED:
            lv_label_set_text(label, "LV_EVENT_LONG_PRESSED");
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x4cbe37), 0);  // 通过本地样式(私有样式)设置背景色
            printf("LV_EVENT_LONG_PRESSED\n");
            break;
        default:
            //printf("NONE\n");
            break;
    }
}

void lvgl_lv_user_gui_interface_init(void)
{
    /* 创建基础部件(对象) */
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(obj,100, 100);
    lv_obj_set_style_bg_color(obj, lv_color_hex(BG_RED), 0);  // 通过本地样式(私有样式)设置背景色

    /* 创建label部件(对象) */
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "RED");   // 设置label展示的文字
    lv_obj_center(label);               // 将对象与其父对象的中心对齐，这里的父对象是屏幕：lv_scr_act()

    // 为obj1添加事件回调函数，所有的事件类型都能触发该回调函数
    lv_obj_add_event_cb(obj, my_event_cb, LV_EVENT_ALL, label);
}
