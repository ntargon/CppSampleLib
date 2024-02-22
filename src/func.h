#pragma once
#include <stdint.h>

int add(int x, int y);
uint32_t ReverseBits(uint32_t x);
bool Rotate180Deg(uint8_t *data, uint32_t width, uint32_t height);
void PrintImage(const uint8_t *data, uint32_t width, uint32_t height);