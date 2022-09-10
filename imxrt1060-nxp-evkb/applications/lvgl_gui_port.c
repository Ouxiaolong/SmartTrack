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
    lv_obj_t * obj = lv_event_get_target(e);        // ��ȡ�����¼��Ĳ���(����)
    lv_event_code_t code = lv_event_get_code(e);    // ��ȡ��ǰ����(����)�������¼�����
    lv_obj_t * label = lv_event_get_user_data(e);   // ��ȡ����¼�ʱ���ݵ��û�����

    switch(code){
        case LV_EVENT_PRESSED:
            color = lv_obj_get_style_bg_color(obj, LV_PART_MAIN);

            if(BG_RED == lv_color_to32(color))
            {
                lv_obj_set_style_bg_color(obj, lv_color_hex(BG_GREEN), 0);  // ͨ��������ʽ(˽����ʽ)���ñ���ɫ
                lv_label_set_text(label, "GREEN");
                printf("LV_EVENT_PRESSED, BG is GREEN\n");
            }
            else
            {
                lv_obj_set_style_bg_color(obj, lv_color_hex(BG_RED), 0);  // ͨ��������ʽ(˽����ʽ)���ñ���ɫ
                lv_label_set_text(label, "RED");
                printf("LV_EVENT_PRESSED, BG is RED\n");
            }

            break;
        case LV_EVENT_LONG_PRESSED:
            lv_label_set_text(label, "LV_EVENT_LONG_PRESSED");
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x4cbe37), 0);  // ͨ��������ʽ(˽����ʽ)���ñ���ɫ
            printf("LV_EVENT_LONG_PRESSED\n");
            break;
        default:
            //printf("NONE\n");
            break;
    }
}

void lvgl_lv_user_gui_interface_init(void)
{
    /* ������������(����) */
    lv_obj_t * obj = lv_obj_create(lv_scr_act());
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(obj,100, 100);
    lv_obj_set_style_bg_color(obj, lv_color_hex(BG_RED), 0);  // ͨ��������ʽ(˽����ʽ)���ñ���ɫ

    /* ����label����(����) */
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "RED");   // ����labelչʾ������
    lv_obj_center(label);               // ���������丸��������Ķ��룬����ĸ���������Ļ��lv_scr_act()

    // Ϊobj1����¼��ص����������е��¼����Ͷ��ܴ����ûص�����
    lv_obj_add_event_cb(obj, my_event_cb, LV_EVENT_ALL, label);
}
