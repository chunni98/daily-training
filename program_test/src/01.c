/****************************************************************************
* @file        : src/01.c
* @brief       : 韩信点兵
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-02 14:03:08 创建文件
****************************************************************************/

#include "01.h"


size_t get_result(int32_t a, int32_t b, int32_t c)
{
    if(a > 3 || b > 5 || c > 7) return -1;
    for (size_t i = 10; i < 101; ++ i){
        if( i % 3 == a && i % 5 == b && i % 7 == c) {
            return i;
        }

    }
    return -1;
}
