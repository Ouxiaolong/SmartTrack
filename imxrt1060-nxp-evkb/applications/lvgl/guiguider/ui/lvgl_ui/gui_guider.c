/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void setup_ui(lv_ui *ui)
{
	setup_scr_screen1(ui);
	lv_scr_load(ui->screen1);
}
