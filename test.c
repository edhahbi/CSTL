#include "vector.h"
#include <stdio.h>

void main(){
    vector v = vector_init(50*sizeof(int));
    randomAcessIter itr = vector_begin(&v);
    randomAcessIter itr3 = vector_end(&v);

    while (!itr.equals(&itr,&itr3)){
        printf("%d\n",*(int*)itr.ptr);
        itr.jump(&itr,1);
    }
    
}
