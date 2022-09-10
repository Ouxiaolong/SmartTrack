/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

static void screen1_btn_next_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen2))
			setup_scr_screen2(&guider_ui);
		lv_scr_load_anim(guider_ui.screen2, LV_SCR_LOAD_ANIM_OVER_LEFT, 5, 0, true);
	}
		break;
	default:
		break;
	}
}

void events_init_screen1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen1_btn_next, screen1_btn_next_event_handler, LV_EVENT_ALL, NULL);
}

static void screen2_img_previous_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen2))
			setup_scr_screen2(&guider_ui);
		lv_scr_load_anim(guider_ui.screen2, LV_SCR_LOAD_ANIM_OVER_LEFT, 5, 0, true);
	}
		break;
	default:
		break;
	}
}

static void screen2_btn_previous_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
		if (!lv_obj_is_valid(guider_ui.screen1))
			setup_scr_screen1(&guider_ui);
		lv_scr_load_anim(guider_ui.screen1, LV_SCR_LOAD_ANIM_OVER_RIGHT, 5, 0, true);
	}
		break;
	default:
		break;
	}
}

void events_init_screen2(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen2_img_previous, screen2_img_previous_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen2_btn_previous, screen2_btn_previous_event_handler, LV_EVENT_ALL, NULL);
}
