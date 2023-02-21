// \file	: 05.c
// \brief	: 输入某年某月某日，判断这一天是这一年的第几天
// \author	: shachi
// \email	: shachi1758@outlook.com
// \details	: 
// \version	: 0.1.0
// \log	:
//		2023-02-20 14:52:15 创建文件

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

bool is_leap_year(int32_t year);

int main(int argc, char const *argv[])
{
    int32_t months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int32_t days = 0;

    printf("请输入年月日：\n");
    int32_t year;
    int32_t month;
    int32_t day;

    scanf("%d-%d-%d", &year, &month, &day);

    for (size_t i = 0; i < month -1 ; i++) {
        days += months[i];
    }
    days += day;

    if(month >= 2 && is_leap_year(year)){
        days += 1;
    }

    printf("days  = %d\n", days);

    return 0;
}

bool is_leap_year(int32_t year)
{
    if(year % 4 == 0 ) {
        if(year % 100 == 0){
            if(year % 400 == 0) {
                goto TRUE;
            } else {
                goto FALSE;
            }
        } else {
            goto TRUE;
        }
    } else {
        goto FALSE;
    }

TRUE:
    return true;

FALSE:
    return false;
}