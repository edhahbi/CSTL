#pragma once
#include "common.h"
#include <stdbool.h>
#include <stdio.h>

struct randomAcessIter{
    void* ptr;
    void* (*get)(const struct randomAcessIter* self);
    void (*jump)(struct randomAcessIter* self, int n);
    bool (*equals)(const struct randomAcessIter* self,const struct randomAcessIter* other);
};

typedef struct randomAcessIter randomAcessIter;

randomAcessIter randomAcessIter_init(void* ptr);
static void* get(const randomAcessIter* self);
void jump(randomAcessIter* self,int n);
bool equals(const randomAcessIter* self,const randomAcessIter* other);
