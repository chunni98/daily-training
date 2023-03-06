/****************************************************************************
* @file        : ./src/02.c
* @brief       : func02 的实现。
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-03 09:40:56 创建文件
****************************************************************************/

#include <stddef.h>

size_t func02(size_t sum, size_t k, size_t t)
{
    if(sum < 1 || k < 1 || t < 1) return -1;
   size_t total;    //< 总时间

if((sum * 2) % k) {
       total = ((sum * 2) / k + 1) * t;
   } else {
       total = (sum * 2) / k * t;
   }
   return total;
}
