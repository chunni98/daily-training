#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const* argv[])
{
    int32_t i = 0;
    while (i < 26)
    {
       printf("%c ", 'A' + i); 
       ++i;
    }
    


    return 0;
}
