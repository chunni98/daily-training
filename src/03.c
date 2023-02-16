// \file	: 03.c
// \brief	: 计算利润
// \author	: shachi
// \email	: shachi1758@outlook.com
// \details	: 
// \version	: 0.1.0
// \log	:
//		2023-02-16 20:20:00 创建文件

#include<stdio.h>

int main(int argc, char const *argv[])
{
    float bonus = 0;
    float profit = 0;

    float bonus1 = 10 * 0.1; 
    float bonus2 = bonus1 + 10 * 0.075;
    float bonus3 = bonus2 + 20 * 0.05;
    float bonus4 = bonus3 + 40 * 0.03;
    float bonus5 = bonus4 + 60 * 0.015;

    printf("Please input your profit(w):\n");
    scanf("%f", &profit);

    if(profit <= 10) {
        bonus = profit * 0.1;
    }else if(profit <= 20) {
        bonus = bonus1 + (profit-10) * 0.075;
    }else if(profit <= 40) {
        bonus = bonus2 + (profit - 20) * 0.05;
    }else if(profit <= 60) {
        bonus = bonus3 + (profit - 40) * 0.03;
    }else if(profit <= 100) {
        bonus = bonus4 + (profit - 60) * 0.015;
    }else{
        bonus = bonus5 + (profit - 100) * 0.01;

    }
    printf("bonus = %f", bonus);
    return 0;
}
