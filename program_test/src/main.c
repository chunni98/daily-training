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
#include "klogger.h"


int main(int argc, const char* argv[])
{
    kdebug("第一题---------------\n");
    kdebug("%zu\n",get_result(2,4,5));
    kdebug("第二题---------------\n");
    kdebug("烙饼总时间是：%zu\n",func02(30,5,1));

    return 0;
}
