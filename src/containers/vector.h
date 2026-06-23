#pragma once
#include <stdlib.h>
#include "common.h"
#include "result.h"
#include "typeDeduction.h"
#include "vector_iter.h"

#ifndef DEFAULT_VECTOR_SIZE
#define DEFAULT_VECTOR_SIZE 4
#endif

#define DEFINE_VECTOR(T)                                                \
    DEFINE_RESULT(T)                                                    \
    DEFINE_VECTOR_ITERATOR(T)                                           \
    typedef struct vector_##T                                           \
    {                                                                   \
        T *data;                                                        \
        size_t used;                                                    \
        size_t size;                                                    \
        size_t capacity;                                                \
    } vector_##T;                                                       \
                                                                        \
    static vector_##T vector_##T##_init(size_t size)                    \
    {                                                                   \
        void *memory = calloc(size, size * sizeof(T));                  \
        if (memory == NULL)                                             \
        {                                                               \
            perror("vector_##T##_init: invalid memory allocation\n");   \
            exit(EXIT_FAILURE);                                         \
        }                                                               \
                                                                        \
        vector_##T v = {                                                \
            .capacity = size,                                           \
            .size = size,                                               \
            .data = (T *)memory,                                        \
            .used = 0};                                                 \
    }                                                                   \
                                                                        \
    size_t vector_##T##_size(vector_##T##*self)                         \
    {                                                                   \
        return self->size;                                              \
    }                                                                   \
    size_t vector_##T##_capacity(vector_##T##*self)                     \
    {                                                                   \
        return self->capacity;                                          \
    }                                                                   \
    int *vector_##T##_data(vector_##T##*self)                           \
    {                                                                   \
        return self->data;                                              \
    }                                                                   \
    size_t vector_##T##_empty(vector_##T##*self)                        \
    {                                                                   \
        return self->used == 0;                                         \
    }                                                                   \
                                                                        \
    result_##T vector_##T##_at(vector_##T##*self, size_t index)         \
    {                                                                   \
        if (self->size < index)                                         \
        {                                                               \
            return Some_##T(self->data[index]);                         \
        }                                                               \
        else                                                            \
        {                                                               \
            return None_##T();                                          \
        }                                                               \
    }                                                                   \
    T vector_##T##_front(vector_##T *self)                              \
    {                                                                   \
        return self->data[0];                                           \
    }                                                                   \
    T vector_##T##_back(vector_##T *self)                               \
    {                                                                   \
        return self->data[self->used - 1];                              \
    }                                                                   \
                                                                        \
    void vector_##T##_reserve(vector_##T *self, size_t new_capacity)    \
    {                                                                   \
        void *memory = realloc(self->data, new_capacity);               \
        if (memory == NULL)                                             \
        {                                                               \
            perror("vector_##T_resize: invalid memory reallocation\n"); \
            return;                                                     \
        }                                                               \
                                                                        \
        self->data = memory;                                            \
        self->capacity = self->capacity * 2;                            \
    }                                                                   \
                                                                        \
    void vector_##T##_resize(vector_##T *self, size_t new_size)         \
    {                                                                   \
        if (new_size <= self->size)                                     \
        {                                                               \
            self->size = new_size;                                      \
            return;                                                     \
        }                                                               \
        self->size = new_size;                                          \
        if (new_size > self->capacity)                                  \
        {                                                               \
            vector_##T##_resize(self, 2 * self->capacity);              \
        }                                                               \
    }                                                                   \
                                                                        \
    void vector_##T##_push_back(vector_##T *self, T value)              \
    {                                                                   \
        if (self->capacity == self->size)                               \
        {                                                               \
            vector_##T##_resize(self, 2 * self->capacity);              \
        }                                                               \
        self->data[self->used++] = value;                               \
    }                                                                   \
                                                                        \
    vector_##T##_iter vector_##T##_begin(const vector_##T *self)              \
    {                                                                   \
        vector_##T##_iter it = vector_##T##_iter_init(self->data);                  \
        return it;                                                      \
    }                                                                   \
                                                                        \
    vector_##T##_iter vector_##T##_end(const vector_##T *self)                \
    {                                                                   \
        vector_##T##_iter it = vector_##T##_iter_init(self->data + self->capacity); \
        return it;                                                      \
    }\
