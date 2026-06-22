#include "randomAcessIter.h"

void jump(randomAcessIter* self,int n){
    self->ptr = self->ptr + n;
}

void* get(const randomAcessIter* self){
    return self->ptr;
}

bool equals(const randomAcessIter* self,const randomAcessIter* other){
    if(!self || !other) return false;
    bool areSame = self->ptr == other->ptr;
    return areSame;
}

randomAcessIter randomAcessIter_init(void *ptr)
{
    randomAcessIter itr = {0};
    itr.ptr = ptr;
    itr.get = get;
    itr.jump = jump;
    itr.equals = equals;
    return itr;
}

