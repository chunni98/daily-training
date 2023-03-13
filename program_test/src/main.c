/****************************************************************************
 * @file        : src/main.c
 * @brief       :
 * @author      : shachi
 * @email       : shachi1758@outlook.com
 * @details     :
 * @version     : 0.1.0
 * @history     :
 *      2023-03-02 14:02:59 创建文件
 ****************************************************************************/

#include "01.h"
#include "02.h"
#include "03.h"
#include "04.h"
#include "05.h"
#include "klogger.h"
#include <stdbool.h>
#include <stdio.h>

int main(int argc, const char* argv[])
{
    // kdebug("第一题---------------\n");
    // kdebug("%zu\n", get_result(2, 4, 5));
    // kdebug("第二题---------------\n");
    // kdebug("烙饼总时间是：%zu\n", func02(30, 5, 1));
    // kdebug("第三题----------------\n");
    // int a = 17, b = 8;
    // kdebug("%d 转成 %d 进制是 %s\n", a, b, dec2any(a, b));
    // kdebug("第四题----------------\n");
    // char str[10][20] = { 0 };
    // size_t i = 0;
    // while (true) {
    //     printf("input date: \n");
    //     scanf("%s",&str[i]);
    //     i++;
    //     if(str[i-1][0] == 'y') break;
    // }
    // for(size_t j = 0; j < i; j++) {
    //     printf("%d\n",get_days(str[j]));
    // }
    kdebug("第五题----------------\n");
    kdebug("100分是 %c,57.2 分是 %c\n",get_grade(100.0),get_grade(57.2));


    return 0;
}
