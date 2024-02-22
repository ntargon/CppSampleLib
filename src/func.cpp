#include "func.h"
#include <stdio.h>

int add(int x, int y)
{
    return x + y;
}

uint32_t ReverseBits(uint32_t x) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
        ret <<= 1;
        if (x & (1 << i))
            ret |= 1;
    }
    return ret;
}

#define FIXED_HEIGHT (1024)
#define BITS_PER_BYTE (8)

bool Rotate180Deg(uint8_t *data, uint32_t width, uint32_t height)
{
    // 入力チェック
    if (((uintptr_t)data % 4) != 0) return false;
    if (height % 32 != 0) return false;

    // 32bit単位で扱う
    uint32_t *p = (uint32_t *)data;

    // 行
    for (int i = 0; i < (width+1) / 2; i++)
    {
        // 列
        for (int j = 0; j < height / BITS_PER_BYTE / sizeof(uint32_t); j++)
        {
            uint32_t *p1 = &p[i * (FIXED_HEIGHT / BITS_PER_BYTE / sizeof(uint32_t)) + j];
            uint32_t *p2 = &p[(width - i - 1) * (FIXED_HEIGHT / BITS_PER_BYTE / sizeof(uint32_t)) + (height / BITS_PER_BYTE / sizeof(uint32_t) - j - 1)];
            uint32_t tmp = ReverseBits(*p1);
            *p1 = ReverseBits(*p2);
            *p2 = tmp;
        }
    }

    return true;
}

// Tを入力として受取、0埋めsizeof(T)桁の2進数を出力
template <typename T>
void PrintBinary(T x)
{
    for (int i = sizeof(T)*8-1; i >= 0; i--)
    {
        printf("%d", (x >> i) & 1);
    }
    printf(" ");
}


void PrintImage(const uint8_t *data, uint32_t width, uint32_t height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height / BITS_PER_BYTE; j++)
        {
            const uint8_t *p = &data[i * (FIXED_HEIGHT / BITS_PER_BYTE) + j];
            PrintBinary(*p);
        }
        printf("\n");
    }
}

