#include <stdio.h>
#include "shana/stack.h"

// gcc -o test_stack.exe test_stack.c -lshana & color

int main(){

    stack_t stack;

    stack_init(&stack, sizeof(int));

    /*
    int values[] = {10, 20, 30};

    for (int i = 0; i < 3; ++i){
        stack_push(&stack, &values[i]);
    }
    */
   
    /*
    int tmp = 10;

    stack_push(&stack, &tmp);
    
    tmp = 20;
    stack_push(&stack, &tmp);

    tmp = 30;
    stack_push(&stack, &tmp);
    */

    stack_push(&stack, &(int){10});

    stack_push(&stack, &(int){20});

    stack_push(&stack, &(int){30});


    while (!stack_is_empty(&stack)){
        printf("Top = %d\n", *(int*)stack_top(&stack));
        stack_pop(&stack);
    }

    stack_free(&stack);


    return 0;
}
