#include <stdio.h>
#include "shana/vector.h"

// gcc -o test_vector.exe test_vector.c -lshana & color

void space(unsigned int count_space){
    for (unsigned int i = 0; i != count_space; i++){
        printf("\n");
    }
}

int main(){

    vector_t vec;

    vector_init(&vec, sizeof(int));

    for (int i = 0; i < 10; ++i){
        vector_push_back(&vec, &i);
    }

    vector_pop_back(&vec); // there will be 8 left

    vector_pop_front(&vec); // there will be 7 left

    vector_pop_at(&vec, 2); // there will be 6 left 

    //vector_pop_at(&vec, 7);

    //vector_push_front(&vec, &(int){5});

    vector_push_at(&vec, 5, &(int){0});

    vector_reverse(&vec);


    for (size_t i = 0; i < vector_size(&vec); ++i){
        int* val = (int*)vector_at(&vec, i);
        printf("vec[%zu] = %d\n", i, *val);
    }

    printf("%d", *(int*)vector_front(&vec));

    space(1);

    printf("%d", *(int*)vector_back(&vec));


    space(1);

    vector_free(&vec);


    return 0;
};