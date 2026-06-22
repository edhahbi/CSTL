#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define Bb 1
#define Kb(x) (x) << 10
#define Mb(x) (x) << 20
#define Gb(x) (x) << 30

#define MIN(x, y) (x) > (y) ? (y) : (x)
#define MAX(x, y) (x) == MIN((x), (y)) ? (y) : (x)
#define ALIGN_UP(x, a) (((x) + (a) - 1) & ~((a) - 1))
