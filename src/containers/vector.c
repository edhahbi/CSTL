#include "vector.h"
#include "randomAcessIter.h"

randomAcessIter vector_begin(const vector* self){
    randomAcessIter it = randomAcessIter_init(self->data);
    return it;
}

randomAcessIter vector_end(const vector* self){
    randomAcessIter it = randomAcessIter_init(self->data + self->capacity);
    return it;
}

vector vector_init(const size_t size){
    void* memory = calloc(size,sizeof(size));
    if(memory == NULL){
        perror("vector_init: invalid memory allocation\n");
        exit(EXIT_FAILURE);
    }

    vector v = {
        .capacity = size,
        .size = 0,
        .data = memory
    };
    return v;
}

void vector_resize(vector* self){
    if(self->capacity == self->size){
        void* memory = realloc(self->data,self->capacity * 2);
        if(memory == NULL){
            perror("vector_resize: invalid memory reallocation\n");
            return;
        }

        self->data = memory;
        self->capacity = self->capacity * 2;
    }
}

void vector_push_back(vector* self ,int x){
    vector_resize(self);
    self->data[self->size] = x;
    self->size++;
}


