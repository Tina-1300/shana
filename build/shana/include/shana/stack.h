#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>



typedef struct {
    void* data;           /* Pointer to the raw memory block allocated for the stack elements.  */
    size_t size;          /* Current number of elements stored in the stack.                    */
    size_t capacity;      /* Maximum capacity of the stack.                                     */
    size_t element_size;  /* size of an element (e.g., int, struct, etc.).                      */
} stack_t;



void stack_init(stack_t* s, size_t element_size); // Initializes the stack



void stack_free(stack_t* s); // Frees the memory allocated for the stack



bool stack_push(stack_t* s, const void* element); // ajoute un élément à la pile



bool stack_pop(stack_t* s); // Removes the last element added to the stack



void* stack_top(stack_t* s); // Accesses the top element



bool stack_is_empty(const stack_t* s); // Checks if the stack is empty



size_t stack_size(const stack_t* s); // Checks the size of the stack


#endif