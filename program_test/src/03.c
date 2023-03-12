/****************************************************************************
* @file        : ./src/03.c
* @brief       : 进制转换
* @author      : shachi
* @email       : shachi1758@outlook.com
* @details     :
* @version     : 0.1.0
* @history     :
*      2023-03-06 09:25:49 创建文件
****************************************************************************/

#include <stddef.h>
#include <string.h>
#include <malloc.h>
#include "03.h"

char *dec2any(int32_t dec, int32_t r)
{
    if(r < 2 || r > 16 || r == 10) {
        return NULL;
    }

    char arr[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char *ans = (char *) malloc (sizeof(char) * 50);

    size_t count = 0;

    while (dec > 0)
    {
        ans[count] = arr[dec % r];
        dec = dec / r;
        ++count;
    }

    ans[count] = 0;
    reverse(ans);

   return ans;
}

void reverse(char *s)
{
	int i, l, t;
	l = strlen(s);
	for(i = 0;i < l/2;i++)
	{
		t = s[i];
		s[i] = s[l - i - 1];
		s[l - i - 1] = t;
	}
}