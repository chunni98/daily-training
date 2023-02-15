// \file	: 02.c
// \brief	: 1234组成的无重复数字三位数
// \author	: shachi
// \email	: shachi1758@outlook.com
// \details	: 题目：有 1、2、3、4 个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
// \version	: 0.1.0
// \log	:
//		2023-02-15 09:12:07 创建文件
#include<stdio.h>
#include<stdint.h>

int main(int argc, char const *argv[])
{
    size_t count = 0;

    for (size_t i = 1; i < 5; i++){
        for (size_t j = 1; j < 5; j++){
            for (size_t k = 1; k < 5; k++){
                if(i != j && i != k && j != k){
                    printf("%d,",i * 100 + j * 10 + k);
                    ++count;
                }
            }
        }
    }
    printf("\n共有%d个不重复三位数。\n",count);
    
    
    return 0;
}
