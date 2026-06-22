#pragma once
#include <stddef.h>
#include <stdint.h>
#include "common.h"


typedef struct arena_impl arena_impl;

typedef struct Arena
{
    arena_impl *impl; 
} Arena;

void arena_init(Arena* arena, const size_t size);
void arena_init1(Arena* arena, const size_t size, u64 alignment);
void  arena_destroy(Arena *arena);
void* alloc_arena(Arena *arena, const size_t size);
void* alloc_arena1(Arena *arena, const size_t size, uint64_t alignment);
void  free_arena(Arena *arena);
