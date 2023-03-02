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
#include "klogger.h"


int main(int argc, const char* argv[])
{
    kdebug("%zu\n",get_result(2,4,5));

    return 0;
}
