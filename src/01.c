// \file	: 01.c
// \brief	: 十六进制转为十进制
// \author	: shachi
// \email	: shachi1758@outlook.com
// \details	: 
// \version	: 0.1.0
// \log	:
//		2023-02-14 20:09:17 创建文件

#include<stdio.h>
#include<stdint.h>

int main(int argc, char const *argv[])
{
    char arr[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int32_t dividend  = 372;
    int32_t remainder = 0;
    char ans[50] = {0};
    int32_t i = 0;

    while(dividend != 0){
       remainder = dividend % 16;
       ans[i] = arr[remainder];
       dividend = dividend / 16;
       i++;
    }
    ans[i] = '\0';

    int len = strlen(ans);
    printf("%d is 0x",372);
    for(size_t i = 0; i < len; ++ i){
        printf("%c", ans[len - i -1]);
    } 
    printf("\n");
    return 0;
}
