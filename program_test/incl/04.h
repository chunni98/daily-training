#ifndef _04_H
#define _04_H

#include <stdint.h>
#include <stdbool.h>

int32_t get_days(char *date);

static inline bool is_leap_year(int32_t year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0);
}

#endif //_04_H