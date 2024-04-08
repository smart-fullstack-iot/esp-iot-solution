/*
 * SPDX-FileCopyrightText: 2022-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once
#include "sdkconfig.h"

#ifdef CONFIG_FORMAT_MJPEG_CAM1
#define FORMAT_MJPEG_CAM1     1
#endif

#ifdef CONFIG_UVC_CAM1_MULTI_FRAMESIZE
//If enable, add VGA and HVGA to list
#define UVC_CAM1_FRAME_MULTI     1
#endif

#define UVC_CAM1_FRAME_WIDTH     CONFIG_UVC_CAM1_FRAMESIZE_WIDTH
#define UVC_CAM1_FRAME_HEIGHT    CONFIG_UVC_CAM1_FRAMESIZE_HEIGT
#define UVC_CAM1_FRAME_RATE      CONFIG_UVC_CAM1_FRAMERATE

#ifdef CONFIG_UVC_MODE_BULK_CAM1
#define UVC_CAM1_BULK_MODE
#endif

#if CONFIG_UVC_SUPPORT_TWO_CAM
#ifdef CONFIG_FORMAT_MJPEG_CAM2
#define FORMAT_MJPEG_CAM2     1
#endif

#ifdef CONFIG_UVC_CAM2_MULTI_FRAMESIZE
//If enable, add VGA and HVGA to list
#define UVC_CAM2_FRAME_MULTI     1
#endif

#define UVC_CAM2_FRAME_WIDTH     CONFIG_UVC_CAM2_FRAMESIZE_WIDTH
#define UVC_CAM2_FRAME_HEIGHT    CONFIG_UVC_CAM2_FRAMESIZE_HEIGT
#define UVC_CAM2_FRAME_RATE      CONFIG_UVC_CAM2_FRAMERATE

#ifdef CONFIG_UVC_MODE_BULK_CAM2
#define UVC_CAM2_BULK_MODE
#endif
#endif

#ifndef UVC_CAM2_FRAME_WIDTH
#define UVC_CAM2_FRAME_WIDTH     UVC_CAM1_FRAME_WIDTH
#endif

#ifndef UVC_CAM2_FRAME_HEIGHT
#define UVC_CAM2_FRAME_HEIGHT    UVC_CAM1_FRAME_HEIGHT
#endif

#ifndef UVC_CAM2_FRAME_RATE
#define UVC_CAM2_FRAME_RATE      UVC_CAM1_FRAME_RATE
#endif

static const struct {
    int width;
    int height;
    int rate;
} UVC_FRAMES_INFO[2][4] = {{
        {UVC_CAM1_FRAME_WIDTH, UVC_CAM1_FRAME_HEIGHT, UVC_CAM1_FRAME_RATE},
        {640, 480, 15},
        {480, 320, 30},
        {320, 240, 30},
    }, {
        {UVC_CAM2_FRAME_WIDTH, UVC_CAM2_FRAME_HEIGHT, UVC_CAM2_FRAME_RATE},
        {640, 480, 15},
        {480, 320, 30},
        {320, 240, 30},
    }
};

#define UVC_FRAME_NUM 4
