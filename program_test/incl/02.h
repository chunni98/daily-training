#ifndef _02_H
#define _02_H
/****************************************************************************
* @file        : ./incl/02.h
* @brief       : 兰州烧饼
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-03 09:14:04 创建文件
****************************************************************************/

#include <stddef.h>
/**
 * @brief: 计算烙完所有饼需要多少时间。
 * @param1: sum，总煎饼个数。
 * @param2: k，一次能煎k饼。
 * @param3: t，煎一面需要时间。
 *
 * 烙饼问题公式：总时间 = ((sum * 2) / k )* t。
 *
 * @return: 总时间。
 *
 */
size_t func02(size_t sum, size_t k, size_t t);

#endif // _02_H
