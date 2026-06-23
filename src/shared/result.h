#pragma once
#include "common.h"
#define DEFINE_RESULT(T)                       \
    typedef struct result_##T                  \
    {                                          \
        bool isSome;                           \
        T value;                               \
    } result_##T;                              \
                                               \
    result_##T None_##T()                      \
    {                                          \
        result_##T result = {.isSome = false}; \
        return result;                         \
    }                                          \
                                               \
    result_##T Some_##T(T value)               \
    {                                          \
        result_##T result = {                  \
            .isSome = true,                    \
            .value = value};                   \
        return result;                         \
    }\

