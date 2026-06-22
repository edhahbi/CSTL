#pragma once
#include <stdlib.h>
#include "common.h"
#include "randomAcessIter.h"

#ifndef DEFAULT_VECTOR_SIZE
#define DEFAULT_VECTOR_SIZE 4
#endif

typedef struct vector{
    //normal properties
    int* data;
    size_t size;
    size_t capacity;


}vector;

vector vector_init(size_t size);
randomAcessIter vector_begin(const vector* self);
randomAcessIter vector_end(const vector* self);
