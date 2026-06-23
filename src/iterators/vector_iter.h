#pragma once
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

#define DEFINE_VECTOR_ITERATOR(T)                                                                                              \
    typedef struct vector_##T##_iter                                                                                           \
    {                                                                                                                          \
        T *ptr;                                                                                                                \
    } vector_##T##_iter;                                                                                                       \
                                                                                                                               \
    vector_##T##_iter vector_##T##_iter_init(T *ptr)                                                                           \
    {                                                                                                                          \
        vector_##T##_iter iter = {ptr};                                                                                        \
        return iter;                                                                                                           \
    }                                                                                                                          \
    T vector_##T##_iter_init(const vector_##T##_iter *iter) { return *iter->ptr; }                                             \
    void vector_##T##_iter_next(vector_##T##_iter *iter) { iter->ptr++; }                                                      \
    void vector_##T##_iter_prev(vector_##T##_iter *iter) { iter->ptr--; }                                                      \
    void vector_##T##_iter_advance(vector_##T##_iter *iter, size_t n) { iter->ptr += n; }                                      \
    size_t vector##T##_iter_dist(vector_##T##_iter *iter1, vector_##T##_iter *iter2) { (size_t)ABS(iter1->ptr - iter2->ptr); } \
    bool vector_##T##_iter_equal(vector_##T##_iter *iter1, vector_##T##_iter *iter2) { return iter1->ptr == iter2->ptr; }      \
    bool vector_##T##_iter_less(vector_##T##_iter *iter1, vector_##T##_iter *iter2) { return iter1->ptr < iter2->ptr; }\
