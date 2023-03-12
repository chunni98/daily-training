#ifndef _03_H
#define _03_H
/****************************************************************************
* @file        : ./incl/03.h
* @brief       : 进制转换
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-06 09:16:54 创建文件
****************************************************************************/
#include <stdint.h>


/**
 * @brief: 输入一个十进制数 dec，将它转换成 r 进制数输出。
 * @param1: dec，十进制数。
 * @param2: r，进制。(2 <= r <= 16，r != 10)
 *
 * @return: 转换后的字符串（储存于堆）。
 *          NULL，转换失败。
 */
char *dec2any(int32_t dec, int32_t r);

void reverse(char *s);

#endif // _03_H
