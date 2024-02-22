#include <iostream>
#include "func.h"
#include "lib1/lib1.h"


uint8_t buf[1024 / 8 * 1024] = {0};


int main(void)
{
    const uint32_t HEIGHT = 8*4;
    const uint32_t WIDTH = 3;

    buf[0] = 0b10011101;
    buf[2*1024/8 + 3] = 0b11001100;
    PrintImage(buf, WIDTH, HEIGHT);
    printf("\n");
    if (!Rotate180Deg(buf, WIDTH, HEIGHT)) return 1;
    PrintImage(buf, WIDTH, HEIGHT);

    return 0;
}
