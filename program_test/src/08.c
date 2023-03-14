/******************************************************************************
 *     Copyright:  (C) 2023 shachi
 *                 All rights reserved.
 *
 *      Filename:  ./src/08.c
 *   Description:  求两点距离
 *
 *       Version:  0.1.0
 *        Author:  shachi <shachi1758@outlook.com>
 *     ChangeLog:  1. 2023-03-14 09:51:15 创建文件
 *
******************************************************************************/
#include <math.h>
#include <inttypes.h>

float get_distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2)
{
    int32_t x = (x2 - x1) * (x2 - x1);
    int32_t y = (y2 - y1) * (y2 - y1);

    return sqrt(x + y);
}

