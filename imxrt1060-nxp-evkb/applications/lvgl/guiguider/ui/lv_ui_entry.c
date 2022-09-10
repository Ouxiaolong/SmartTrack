/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author        Notes
 * 2022-05-13     Meco Man      First version
 */

#include <rtconfig.h>
#include <lvgl.h>

#include "gui_guider.h"
#include "events_init.h"

lv_ui guider_ui;

void lv_user_gui_init(void)
{
    setup_ui(&guider_ui);
    events_init(&guider_ui);
}
