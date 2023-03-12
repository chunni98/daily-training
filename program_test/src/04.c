#include "../incl/04.h"
#include <stdio.h>

int32_t get_days(char* date)
{
    int32_t year;
    int32_t month;
    int32_t day;
    sscanf(date, "%d/%d/%d", &year, &month, &day);

    int arr[] = {
        0,
        31,
        59,
        90,
        120,
        151,
        181,
        212,
        243,
        273,
        304,
        334
    };
    int32_t days = 0;

    days = arr[month] + day;
    if(is_leap_year(year)) days += 1;

    return days;
}