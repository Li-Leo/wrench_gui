/**
 * @File:    demo_tos_evb_mx_plus.c
 * @Author:  MurphyZhao
 * @Date:    2018-09-29
 * 
 * Copyright (c) 2018-2019 MurphyZhao <d2014zjt@163.com>
 *               https://github.com/murphyzhao
 * All rights reserved.
 * License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * message:
 * This demo is base on TencentOSTiny EVB_MX+, reference
 *     https://github.com/Tencent/TencentOS-tiny
 * Hardware: TencentOSTiny EVB_MX+.
 * 
 * Change logs:
 * Date        Author       Notes
 * 2020-01-20  MurphyZhao   First add
 * 2020-02-14  MurphyZhao   Fix Key mismatch problem and fix grammar bug
*/

#include "stdio.h"
#include "stdbool.h"
#include "flexible_button.h"
#include "bsp.h"
#include "key.h"
#include "DemoActions.h"

#define ENUM_TO_STR(e) (#e)

typedef enum
{
    USER_BUTTON_MAIN = 0,
    USER_BUTTON_UP,
    USER_BUTTON_DOWN,

    USER_BUTTON_MAX
} user_button_t;

// static char *enum_event_string[] = {
//     ENUM_TO_STR(FLEX_BTN_PRESS_DOWN),
//     ENUM_TO_STR(FLEX_BTN_PRESS_CLICK),
//     ENUM_TO_STR(FLEX_BTN_PRESS_DOUBLE_CLICK),
//     ENUM_TO_STR(FLEX_BTN_PRESS_REPEAT_CLICK),
//     ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_START),
//     ENUM_TO_STR(FLEX_BTN_PRESS_SHORT_UP),
//     ENUM_TO_STR(FLEX_BTN_PRESS_LONG_START),
//     ENUM_TO_STR(FLEX_BTN_PRESS_LONG_UP),
//     ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD),
//     ENUM_TO_STR(FLEX_BTN_PRESS_LONG_HOLD_UP),
//     ENUM_TO_STR(FLEX_BTN_PRESS_MAX),
//     ENUM_TO_STR(FLEX_BTN_PRESS_NONE),
// };

// static char *enum_btn_id_string[] = {
//     ENUM_TO_STR(F1),
//     ENUM_TO_STR(F2),
//     ENUM_TO_STR(F3),
//     ENUM_TO_STR(F4),
//     ENUM_TO_STR(USER_BUTTON_MAX),
// };

static flex_button_t user_button[USER_BUTTON_MAX];
static uint16_t g_key_value;

static uint8_t common_btn_read(void *arg)
{
    uint8_t value = 1;

    flex_button_t *btn = (flex_button_t *)arg;

    switch (btn->id)
    {
    case USER_BUTTON_MAIN:
        value = GPIO_ReadInputDataBit(GPIO0, GPIO_Pin_10);
        break;
    case USER_BUTTON_UP:
        value = GPIO_ReadInputDataBit(GPIO0, GPIO_Pin_11);
        break;
    case USER_BUTTON_DOWN:
        value = GPIO_ReadInputDataBit(GPIO1, GPIO_Pin_3);
        break;

    default:
        break;
    }

    return value;
}

static bool flag_key_main_pressed;
static bool flag_key_up_pressed;
static bool flag_key_down_pressed;

static void common_btn_evt_cb(void *arg)
{
    // flex_button_t *btn = (flex_button_t *)arg;

    if (flex_button_event_read(&user_button[USER_BUTTON_MAIN]) == FLEX_BTN_PRESS_DOWN) {
        flag_key_main_pressed = true;
        g_key_value = KEY_VALUE_ENTER;
    }

    if (flex_button_event_read(&user_button[USER_BUTTON_UP]) == FLEX_BTN_PRESS_DOWN) {
        flag_key_up_pressed = true;
        g_key_value = KEY_VALUE_UP;

    }

    if (flex_button_event_read(&user_button[USER_BUTTON_DOWN]) == FLEX_BTN_PRESS_DOWN) {
        flag_key_down_pressed = true;
        g_key_value = KEY_VALUE_DOWN;
    }
}

bool main_key_is_pressed()
{
    return flag_key_main_pressed;
}

bool up_key_is_pressed()
{
    return flag_key_up_pressed;
}

bool down_key_is_pressed()
{
    return flag_key_down_pressed;
}

void main_key_trigger_reset()
{
    flag_key_main_pressed = false;
}

void up_key_trigger_reset()
{
    flag_key_up_pressed = false;
}

void down_key_trigger_reset()
{
    flag_key_down_pressed = false;
}

uint16_t key_get_key_code(void)
{
    return g_key_value;
}


void user_button_init(void)
{
    int i;

    memset(&user_button[0], 0x0, sizeof(user_button));

    for (i = 0; i < USER_BUTTON_MAX; i ++) {
        user_button[i].id = i;
        user_button[i].usr_button_read = common_btn_read;
        user_button[i].cb = common_btn_evt_cb;
        user_button[i].pressed_logic_level = 0;
        user_button[i].short_press_start_tick = FLEX_MS_TO_SCAN_CNT(1500);
        user_button[i].long_press_start_tick = FLEX_MS_TO_SCAN_CNT(3000);
        user_button[i].long_hold_start_tick = FLEX_MS_TO_SCAN_CNT(4500);

        flex_button_register(&user_button[i]);
    }
}


