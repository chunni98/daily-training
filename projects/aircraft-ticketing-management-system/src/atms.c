/****************************************************************************
* @file        : ./src/atms.c
* @brief       :
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-02-27 18:08:57 创建文件
****************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "login.h"

int32_t Run()
{
    do{
        LoginMenu();

    }while(true);

    return 0;
}
