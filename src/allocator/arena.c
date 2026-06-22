#define _GNU_SOURCE
#include "arena.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define DEFAULT_ARENA_ALIGNMENT 8

struct arena_impl {
    void *start;
    size_t size;
    size_t offset;
    bool is_created;
};

void arena_init1(Arena *arena, const size_t size, u64 alignment)
{
    if (!arena) return;

    size_t aligned = ALIGN_UP(size,alignment);
    size_t total_size = aligned + sizeof(struct arena_impl);

    void* memory_block = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (memory_block == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    struct arena_impl *metadata = (struct arena_impl *)memory_block;
    
    metadata->start = (u8*)memory_block + sizeof(struct arena_impl);
    metadata->size = aligned;
    metadata->offset = 0;

    arena->impl = metadata;
}

void arena_init(Arena* arena, const size_t size){
    arena_init1(arena, size, DEFAULT_ARENA_ALIGNMENT);
}

static void arena_resize(Arena *arena, const size_t size)
{
    size_t old_total_size = arena->impl->size + sizeof(struct arena_impl);
    size_t new_total_size = old_total_size + size;

    void* memory_block = mremap(arena->impl, old_total_size, new_total_size, MREMAP_MAYMOVE);
    if (memory_block == MAP_FAILED) {
        perror("mremap failed");
        exit(EXIT_FAILURE);
    }

    arena->impl = (struct arena_impl *)memory_block;
    arena->impl->start = (char*)memory_block + sizeof(struct arena_impl);
    arena->impl->size += size;
}

void *alloc_arena1(Arena *arena, const size_t size, const uint64_t alignment)
{
    if (!arena) return NULL;
    size_t aligned = ALIGN_UP(size, alignment);

    if (arena->impl->offset + aligned > arena->impl->size) {
        arena_resize(arena, aligned);
    }

    void *ptr = (char *)arena->impl->start + arena->impl->offset;
    arena->impl->offset += aligned;
    return ptr;
}

void* alloc_arena(Arena* arena, const size_t size) {
    return alloc_arena1(arena, size, DEFAULT_ARENA_ALIGNMENT);
}

void free_arena(Arena* arena) {
    if (arena && arena->impl) arena->impl->offset = 0;
}

void arena_destroy(Arena *arena)
{
    if (!arena || !arena->impl) return;

    size_t total_size = arena->impl->size + sizeof(struct arena_impl);
    munmap(arena->impl, total_size);
    
    arena->impl = NULL;
}
