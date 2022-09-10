/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"

void setup_scr_screen1(lv_ui *ui)
{

	//Write codes screen1
	ui->screen1 = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen1_main_main_default
	static lv_style_t style_screen1_main_main_default;
	lv_style_reset(&style_screen1_main_main_default);
	lv_style_set_bg_color(&style_screen1_main_main_default, lv_color_make(0x40, 0x35, 0x35));
	lv_style_set_bg_opa(&style_screen1_main_main_default, 248);
	lv_obj_add_style(ui->screen1, &style_screen1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_img_next
	ui->screen1_img_next = lv_img_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_img_next, 240, 235);
	lv_obj_set_size(ui->screen1_img_next, 25, 25);

	//Write style state: LV_STATE_DEFAULT for style_screen1_img_next_main_main_default
	static lv_style_t style_screen1_img_next_main_main_default;
	lv_style_reset(&style_screen1_img_next_main_main_default);
	lv_style_set_img_recolor(&style_screen1_img_next_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen1_img_next_main_main_default, 0);
	lv_style_set_img_opa(&style_screen1_img_next_main_main_default, 249);
	lv_obj_add_style(ui->screen1_img_next, &style_screen1_img_next_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen1_img_next, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen1_img_next,&_next_25x25);
	lv_img_set_pivot(ui->screen1_img_next, 0,0);
	lv_img_set_angle(ui->screen1_img_next, 0);

	//Write codes screen1_btn_next
	ui->screen1_btn_next = lv_btn_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_btn_next, 240, 235);
	lv_obj_set_size(ui->screen1_btn_next, 22, 22);

	//Write style state: LV_STATE_DEFAULT for style_screen1_btn_next_main_main_default
	static lv_style_t style_screen1_btn_next_main_main_default;
	lv_style_reset(&style_screen1_btn_next_main_main_default);
	lv_style_set_radius(&style_screen1_btn_next_main_main_default, 50);
	lv_style_set_bg_color(&style_screen1_btn_next_main_main_default, lv_color_make(0x17, 0x16, 0x16));
	lv_style_set_bg_grad_color(&style_screen1_btn_next_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen1_btn_next_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_btn_next_main_main_default, 1);
	lv_style_set_shadow_color(&style_screen1_btn_next_main_main_default, lv_color_make(0x19, 0x1a, 0x1a));
	lv_style_set_shadow_opa(&style_screen1_btn_next_main_main_default, 0);
	lv_style_set_border_color(&style_screen1_btn_next_main_main_default, lv_color_make(0x45, 0x49, 0x4a));
	lv_style_set_border_width(&style_screen1_btn_next_main_main_default, 2);
	lv_style_set_border_opa(&style_screen1_btn_next_main_main_default, 0);
	lv_obj_add_style(ui->screen1_btn_next, &style_screen1_btn_next_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen1_btn_next_label = lv_label_create(ui->screen1_btn_next);
	lv_label_set_text(ui->screen1_btn_next_label, "");
	lv_obj_set_style_text_color(ui->screen1_btn_next_label, lv_color_make(0x12, 0x12, 0x12), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen1_btn_next, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen1_btn_next_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes screen1_cont_header
	ui->screen1_cont_header = lv_obj_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_cont_header, 0, 0);
	lv_obj_set_size(ui->screen1_cont_header, 480, 25);

	//Write style state: LV_STATE_DEFAULT for style_screen1_cont_header_main_main_default
	static lv_style_t style_screen1_cont_header_main_main_default;
	lv_style_reset(&style_screen1_cont_header_main_main_default);
	lv_style_set_radius(&style_screen1_cont_header_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_cont_header_main_main_default, lv_color_make(0x0c, 0x0d, 0x0d));
	lv_style_set_bg_grad_color(&style_screen1_cont_header_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_cont_header_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_cont_header_main_main_default, 39);
	lv_style_set_border_color(&style_screen1_cont_header_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen1_cont_header_main_main_default, 0);
	lv_style_set_border_opa(&style_screen1_cont_header_main_main_default, 255);
	lv_style_set_pad_left(&style_screen1_cont_header_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_cont_header_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_cont_header_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_cont_header_main_main_default, 0);
	lv_obj_add_style(ui->screen1_cont_header, &style_screen1_cont_header_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_logo
	ui->screen1_label_logo = lv_label_create(ui->screen1_cont_header);
	lv_obj_set_pos(ui->screen1_label_logo, 0, 5);
	lv_obj_set_size(ui->screen1_label_logo, 140, 15);
	lv_label_set_text(ui->screen1_label_logo, "Smart Track");
	lv_label_set_long_mode(ui->screen1_label_logo, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_logo, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_logo_main_main_default
	static lv_style_t style_screen1_label_logo_main_main_default;
	lv_style_reset(&style_screen1_label_logo_main_main_default);
	lv_style_set_radius(&style_screen1_label_logo_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_logo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_logo_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_logo_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_logo_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_logo_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_logo_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_logo_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_logo_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_logo_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_logo_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_logo_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_logo, &style_screen1_label_logo_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_hum
	ui->screen1_label_hum = lv_label_create(ui->screen1_cont_header);
	lv_obj_set_pos(ui->screen1_label_hum, 340, 5);
	lv_obj_set_size(ui->screen1_label_hum, 50, 15);
	lv_label_set_text(ui->screen1_label_hum, "56%");
	lv_label_set_long_mode(ui->screen1_label_hum, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_hum, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_hum_main_main_default
	static lv_style_t style_screen1_label_hum_main_main_default;
	lv_style_reset(&style_screen1_label_hum_main_main_default);
	lv_style_set_radius(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_hum_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_hum_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_hum_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_hum_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_hum_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_pad_left(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_hum_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_hum_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_hum, &style_screen1_label_hum_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_temp
	ui->screen1_label_temp = lv_label_create(ui->screen1_cont_header);
	lv_obj_set_pos(ui->screen1_label_temp, 410, 5);
	lv_obj_set_size(ui->screen1_label_temp, 50, 15);
	lv_label_set_text(ui->screen1_label_temp, "25C");
	lv_label_set_long_mode(ui->screen1_label_temp, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_temp, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_temp_main_main_default
	static lv_style_t style_screen1_label_temp_main_main_default;
	lv_style_reset(&style_screen1_label_temp_main_main_default);
	lv_style_set_radius(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_temp_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_temp_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_temp_main_main_default, lv_color_make(0xff, 0xfa, 0xfa));
	lv_style_set_text_font(&style_screen1_label_temp_main_main_default, &lv_font_simsun_15);
	lv_style_set_text_letter_space(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_pad_left(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_temp_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_temp_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_temp, &style_screen1_label_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_meter
	ui->screen1_meter = lv_meter_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_meter, 38, 35);
	lv_obj_set_size(ui->screen1_meter, 150, 150);

	//add scale screen1_meter_scale_1
	lv_meter_scale_t *screen1_meter_scale_1 = lv_meter_add_scale(ui->screen1_meter);
	lv_meter_set_scale_ticks(ui->screen1_meter, screen1_meter_scale_1, 41, 2, 10, lv_color_make(0xff, 0x00, 0x00));
	lv_meter_set_scale_major_ticks(ui->screen1_meter, screen1_meter_scale_1, 8, 5, 15, lv_color_make(0xff, 0xff, 0x00), 10);
	lv_meter_set_scale_range(ui->screen1_meter, screen1_meter_scale_1, 0, 100, 300, 90);

	//add needle line for screen1_meter_scale_1
	lv_meter_indicator_t *screen1_meter_scale_1_ndline_0;
	screen1_meter_scale_1_ndline_0 = lv_meter_add_needle_line(ui->screen1_meter, screen1_meter_scale_1, 2, lv_color_make(0x00, 0x00, 0x00), -20);
	lv_meter_set_indicator_value(ui->screen1_meter, screen1_meter_scale_1_ndline_0, 30);

	//Write style state: LV_STATE_DEFAULT for style_screen1_meter_main_main_default
	static lv_style_t style_screen1_meter_main_main_default;
	lv_style_reset(&style_screen1_meter_main_main_default);
	lv_style_set_bg_color(&style_screen1_meter_main_main_default, lv_color_make(0x2b, 0x27, 0x27));
	lv_style_set_bg_grad_color(&style_screen1_meter_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen1_meter_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_meter_main_main_default, 255);
	lv_obj_add_style(ui->screen1_meter, &style_screen1_meter_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_screen1_meter_main_ticks_default
	static lv_style_t style_screen1_meter_main_ticks_default;
	lv_style_reset(&style_screen1_meter_main_ticks_default);
	lv_style_set_text_color(&style_screen1_meter_main_ticks_default, lv_color_make(0xff, 0x00, 0x00));
	lv_style_set_text_font(&style_screen1_meter_main_ticks_default, &lv_font_simsun_12);
	lv_obj_add_style(ui->screen1_meter, &style_screen1_meter_main_ticks_default, LV_PART_TICKS|LV_STATE_DEFAULT);

	//Write codes screen1_cont_info
	ui->screen1_cont_info = lv_obj_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_cont_info, 271, 38);
	lv_obj_set_size(ui->screen1_cont_info, 182, 182);

	//Write style state: LV_STATE_DEFAULT for style_screen1_cont_info_main_main_default
	static lv_style_t style_screen1_cont_info_main_main_default;
	lv_style_reset(&style_screen1_cont_info_main_main_default);
	lv_style_set_radius(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_cont_info_main_main_default, lv_color_make(0x2f, 0x36, 0x3c));
	lv_style_set_bg_grad_color(&style_screen1_cont_info_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_cont_info_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_border_color(&style_screen1_cont_info_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_border_opa(&style_screen1_cont_info_main_main_default, 255);
	lv_style_set_pad_left(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_cont_info_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_cont_info_main_main_default, 0);
	lv_obj_add_style(ui->screen1_cont_info, &style_screen1_cont_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_yaw_name
	ui->screen1_label_yaw_name = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_yaw_name, 20, 99);
	lv_obj_set_size(ui->screen1_label_yaw_name, 40, 20);
	lv_label_set_text(ui->screen1_label_yaw_name, "yaw");
	lv_label_set_long_mode(ui->screen1_label_yaw_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_yaw_name, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_yaw_name_main_main_default
	static lv_style_t style_screen1_label_yaw_name_main_main_default;
	lv_style_reset(&style_screen1_label_yaw_name_main_main_default);
	lv_style_set_radius(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_yaw_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_yaw_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_yaw_name_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_yaw_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_yaw_name_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_yaw_name_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_yaw_name_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_yaw_name, &style_screen1_label_yaw_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_yaw_data
	ui->screen1_label_yaw_data = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_yaw_data, 90, 99);
	lv_obj_set_size(ui->screen1_label_yaw_data, 40, 20);
	lv_label_set_text(ui->screen1_label_yaw_data, "123C");
	lv_label_set_long_mode(ui->screen1_label_yaw_data, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_yaw_data, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_yaw_data_main_main_default
	static lv_style_t style_screen1_label_yaw_data_main_main_default;
	lv_style_reset(&style_screen1_label_yaw_data_main_main_default);
	lv_style_set_radius(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_yaw_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_yaw_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_yaw_data_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_yaw_data_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_yaw_data_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen1_label_yaw_data_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_yaw_data_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_yaw_data, &style_screen1_label_yaw_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_roll_data
	ui->screen1_label_roll_data = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_roll_data, 90, 64);
	lv_obj_set_size(ui->screen1_label_roll_data, 40, 20);
	lv_label_set_text(ui->screen1_label_roll_data, "115C");
	lv_label_set_long_mode(ui->screen1_label_roll_data, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_roll_data, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_roll_data_main_main_default
	static lv_style_t style_screen1_label_roll_data_main_main_default;
	lv_style_reset(&style_screen1_label_roll_data_main_main_default);
	lv_style_set_radius(&style_screen1_label_roll_data_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_roll_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_roll_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_roll_data_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_roll_data_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_roll_data_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_roll_data_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen1_label_roll_data_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_roll_data_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_roll_data_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_roll_data_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_roll_data_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_roll_data, &style_screen1_label_roll_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_roll_name
	ui->screen1_label_roll_name = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_roll_name, 20, 64);
	lv_obj_set_size(ui->screen1_label_roll_name, 40, 20);
	lv_label_set_text(ui->screen1_label_roll_name, "roll");
	lv_label_set_long_mode(ui->screen1_label_roll_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_roll_name, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_roll_name_main_main_default
	static lv_style_t style_screen1_label_roll_name_main_main_default;
	lv_style_reset(&style_screen1_label_roll_name_main_main_default);
	lv_style_set_radius(&style_screen1_label_roll_name_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_roll_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_roll_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_roll_name_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_roll_name_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_roll_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_roll_name_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen1_label_roll_name_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_roll_name_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_roll_name_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_roll_name_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_roll_name_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_roll_name, &style_screen1_label_roll_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_pitch_data
	ui->screen1_label_pitch_data = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_pitch_data, 90, 29);
	lv_obj_set_size(ui->screen1_label_pitch_data, 40, 20);
	lv_label_set_text(ui->screen1_label_pitch_data, "120C");
	lv_label_set_long_mode(ui->screen1_label_pitch_data, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_pitch_data, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_pitch_data_main_main_default
	static lv_style_t style_screen1_label_pitch_data_main_main_default;
	lv_style_reset(&style_screen1_label_pitch_data_main_main_default);
	lv_style_set_radius(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_pitch_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_pitch_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_pitch_data_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_pitch_data_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_pitch_data_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_pitch_data_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_pitch_data_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_pitch_data, &style_screen1_label_pitch_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_pitch_name
	ui->screen1_label_pitch_name = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_pitch_name, 20, 29);
	lv_obj_set_size(ui->screen1_label_pitch_name, 40, 20);
	lv_label_set_text(ui->screen1_label_pitch_name, "pitch");
	lv_label_set_long_mode(ui->screen1_label_pitch_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_pitch_name, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_pitch_name_main_main_default
	static lv_style_t style_screen1_label_pitch_name_main_main_default;
	lv_style_reset(&style_screen1_label_pitch_name_main_main_default);
	lv_style_set_radius(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_pitch_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen1_label_pitch_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_pitch_name_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_pitch_name_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_screen1_label_pitch_name_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_pitch_name_main_main_default, 1);
	lv_style_set_pad_left(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_pitch_name_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_pitch_name, &style_screen1_label_pitch_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_pos_title
	ui->screen1_label_pos_title = lv_label_create(ui->screen1_cont_info);
	lv_obj_set_pos(ui->screen1_label_pos_title, 55, 1);
	lv_obj_set_size(ui->screen1_label_pos_title, 41, 19);
	lv_label_set_text(ui->screen1_label_pos_title, "POS");
	lv_label_set_long_mode(ui->screen1_label_pos_title, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_pos_title, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_pos_title_main_main_default
	static lv_style_t style_screen1_label_pos_title_main_main_default;
	lv_style_reset(&style_screen1_label_pos_title_main_main_default);
	lv_style_set_radius(&style_screen1_label_pos_title_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_pos_title_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_pos_title_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_pos_title_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_pos_title_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_pos_title_main_main_default, lv_color_make(0xfc, 0xfc, 0xfc));
	lv_style_set_text_font(&style_screen1_label_pos_title_main_main_default, &lv_font_simsun_14);
	lv_style_set_text_letter_space(&style_screen1_label_pos_title_main_main_default, 2);
	lv_style_set_pad_left(&style_screen1_label_pos_title_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_pos_title_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_pos_title_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_pos_title_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_pos_title, &style_screen1_label_pos_title_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_speed_name
	ui->screen1_label_speed_name = lv_label_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_label_speed_name, 22, 217);
	lv_obj_set_size(ui->screen1_label_speed_name, 79, 20);
	lv_label_set_text(ui->screen1_label_speed_name, "Speed");
	lv_label_set_long_mode(ui->screen1_label_speed_name, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_speed_name, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_speed_name_main_main_default
	static lv_style_t style_screen1_label_speed_name_main_main_default;
	lv_style_reset(&style_screen1_label_speed_name_main_main_default);
	lv_style_set_radius(&style_screen1_label_speed_name_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_speed_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_speed_name_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_speed_name_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_speed_name_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_speed_name_main_main_default, lv_color_make(0xfd, 0xec, 0xec));
	lv_style_set_text_font(&style_screen1_label_speed_name_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen1_label_speed_name_main_main_default, 1);
	lv_style_set_pad_left(&style_screen1_label_speed_name_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_speed_name_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_speed_name_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_speed_name_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_speed_name, &style_screen1_label_speed_name_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_speed_data
	ui->screen1_label_speed_data = lv_label_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_label_speed_data, 75, 208);
	lv_obj_set_size(ui->screen1_label_speed_data, 84, 37);
	lv_label_set_text(ui->screen1_label_speed_data, "32");
	lv_label_set_long_mode(ui->screen1_label_speed_data, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_speed_data, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_speed_data_main_main_default
	static lv_style_t style_screen1_label_speed_data_main_main_default;
	lv_style_reset(&style_screen1_label_speed_data_main_main_default);
	lv_style_set_radius(&style_screen1_label_speed_data_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_speed_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_speed_data_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_speed_data_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_speed_data_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_speed_data_main_main_default, lv_color_make(0xea, 0xe0, 0x57));
	lv_style_set_text_font(&style_screen1_label_speed_data_main_main_default, &lv_font_simsun_33);
	lv_style_set_text_letter_space(&style_screen1_label_speed_data_main_main_default, 1);
	lv_style_set_pad_left(&style_screen1_label_speed_data_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_speed_data_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_speed_data_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_speed_data_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_speed_data, &style_screen1_label_speed_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen1_label_speed_unit
	ui->screen1_label_speed_unit = lv_label_create(ui->screen1);
	lv_obj_set_pos(ui->screen1_label_speed_unit, 130, 218);
	lv_obj_set_size(ui->screen1_label_speed_unit, 79, 20);
	lv_label_set_text(ui->screen1_label_speed_unit, "km/h");
	lv_label_set_long_mode(ui->screen1_label_speed_unit, LV_LABEL_LONG_WRAP);
	lv_obj_set_style_text_align(ui->screen1_label_speed_unit, LV_TEXT_ALIGN_CENTER, 0);

	//Write style state: LV_STATE_DEFAULT for style_screen1_label_speed_unit_main_main_default
	static lv_style_t style_screen1_label_speed_unit_main_main_default;
	lv_style_reset(&style_screen1_label_speed_unit_main_main_default);
	lv_style_set_radius(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_style_set_bg_color(&style_screen1_label_speed_unit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_screen1_label_speed_unit_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_screen1_label_speed_unit_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_style_set_text_color(&style_screen1_label_speed_unit_main_main_default, lv_color_make(0xfd, 0xec, 0xec));
	lv_style_set_text_font(&style_screen1_label_speed_unit_main_main_default, &lv_font_simsun_12);
	lv_style_set_text_letter_space(&style_screen1_label_speed_unit_main_main_default, 1);
	lv_style_set_pad_left(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_style_set_pad_right(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_style_set_pad_top(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_style_set_pad_bottom(&style_screen1_label_speed_unit_main_main_default, 0);
	lv_obj_add_style(ui->screen1_label_speed_unit, &style_screen1_label_speed_unit_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_screen1(ui);
}