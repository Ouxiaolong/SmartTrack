/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *screen1;
	lv_obj_t *screen1_img_next;
	lv_obj_t *screen1_btn_next;
	lv_obj_t *screen1_btn_next_label;
	lv_obj_t *screen1_cont_header;
	lv_obj_t *screen1_label_logo;
	lv_obj_t *screen1_label_hum;
	lv_obj_t *screen1_label_temp;
	lv_obj_t *screen1_meter;
	lv_obj_t *screen1_cont_info;
	lv_obj_t *screen1_label_yaw_name;
	lv_obj_t *screen1_label_yaw_data;
	lv_obj_t *screen1_label_roll_data;
	lv_obj_t *screen1_label_roll_name;
	lv_obj_t *screen1_label_pitch_data;
	lv_obj_t *screen1_label_pitch_name;
	lv_obj_t *screen1_label_pos_title;
	lv_obj_t *screen1_label_speed_name;
	lv_obj_t *screen1_label_speed_data;
	lv_obj_t *screen1_label_speed_unit;
	lv_obj_t *screen2;
	lv_obj_t *screen2_img_previous;
	lv_obj_t *screen2_btn_previous;
	lv_obj_t *screen2_btn_previous_label;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen1(lv_ui *ui);
void setup_scr_screen2(lv_ui *ui);
LV_IMG_DECLARE(_previous_24x25);
LV_IMG_DECLARE(_next_25x25);

#ifdef __cplusplus
}
#endif
#endif