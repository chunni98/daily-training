// \file	: 06.c
// \brief	: 输入三个整数 x,y,z，请把这三个数由小到大输出。
// \author	: shachi
// \email	: shachi1758@outlook.com
// \details	: 
// \version	: 0.1.0
// \log	:
//		2023-02-21 17:36:40 创建文件

#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    printf("please input x,y,z:\n");
    int32_t x, y, z;

    scanf("%d,%d,%d", &x, &y, &z);

    printf("max = %d\n",x > y ? x > z ? x : y > z ? y : z : y > z ? y : z);

    return 0;
}

