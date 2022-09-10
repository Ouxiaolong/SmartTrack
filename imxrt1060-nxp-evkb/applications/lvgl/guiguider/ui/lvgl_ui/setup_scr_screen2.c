/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"

void setup_scr_screen2(lv_ui *ui)
{

	//Write codes screen2
	ui->screen2 = lv_obj_create(NULL);

	//Write style state: LV_STATE_DEFAULT for style_screen2_main_main_default
	static lv_style_t style_screen2_main_main_default;
	lv_style_reset(&style_screen2_main_main_default);
	lv_style_set_bg_color(&style_screen2_main_main_default, lv_color_make(0x40, 0x35, 0x35));
	lv_style_set_bg_opa(&style_screen2_main_main_default, 248);
	lv_obj_add_style(ui->screen2, &style_screen2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen2_img_previous
	ui->screen2_img_previous = lv_img_create(ui->screen2);
	lv_obj_set_pos(ui->screen2_img_previous, 240, 235);
	lv_obj_set_size(ui->screen2_img_previous, 24, 25);

	//Write style state: LV_STATE_DEFAULT for style_screen2_img_previous_main_main_default
	static lv_style_t style_screen2_img_previous_main_main_default;
	lv_style_reset(&style_screen2_img_previous_main_main_default);
	lv_style_set_img_recolor(&style_screen2_img_previous_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_screen2_img_previous_main_main_default, 0);
	lv_style_set_img_opa(&style_screen2_img_previous_main_main_default, 255);
	lv_obj_add_style(ui->screen2_img_previous, &style_screen2_img_previous_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->screen2_img_previous, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen2_img_previous,&_previous_24x25);
	lv_img_set_pivot(ui->screen2_img_previous, 0,0);
	lv_img_set_angle(ui->screen2_img_previous, 0);

	//Write codes screen2_btn_previous
	ui->screen2_btn_previous = lv_btn_create(ui->screen2);
	lv_obj_set_pos(ui->screen2_btn_previous, 240, 235);
	lv_obj_set_size(ui->screen2_btn_previous, 22, 22);

	//Write style state: LV_STATE_DEFAULT for style_screen2_btn_previous_main_main_default
	static lv_style_t style_screen2_btn_previous_main_main_default;
	lv_style_reset(&style_screen2_btn_previous_main_main_default);
	lv_style_set_radius(&style_screen2_btn_previous_main_main_default, 50);
	lv_style_set_bg_color(&style_screen2_btn_previous_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_screen2_btn_previous_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_screen2_btn_previous_main_main_default, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_screen2_btn_previous_main_main_default, 0);
	lv_style_set_shadow_color(&style_screen2_btn_previous_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_screen2_btn_previous_main_main_default, 0);
	lv_style_set_border_color(&style_screen2_btn_previous_main_main_default, lv_color_make(0x01, 0xa2, 0xb1));
	lv_style_set_border_width(&style_screen2_btn_previous_main_main_default, 2);
	lv_style_set_border_opa(&style_screen2_btn_previous_main_main_default, 11);
	lv_obj_add_style(ui->screen2_btn_previous, &style_screen2_btn_previous_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->screen2_btn_previous_label = lv_label_create(ui->screen2_btn_previous);
	lv_label_set_text(ui->screen2_btn_previous_label, "");
	lv_obj_set_style_text_color(ui->screen2_btn_previous_label, lv_color_make(0x00, 0x00, 0x00), LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->screen2_btn_previous, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->screen2_btn_previous_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_screen2(ui);
}