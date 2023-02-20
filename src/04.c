#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const* argv[])
{
    float x = 0;
    float y = 0;
    for (size_t i = 0; i < 100000; i++) {
        x = sqrt(i + 100);
        y = sqrt(i + 168);

        if ((x * x == i + 100) && (y * y == i + 168)) {
            printf("%zu\n", i);
        }
    }

    return 0;
}
