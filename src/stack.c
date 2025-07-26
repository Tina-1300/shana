#include "../include/shana/stack.h"

#include <stdlib.h>
#include <string.h>



void stack_init(stack_t* s, size_t element_size){
    s->element_size = element_size;
    s->size = 0;
    s->capacity = 4;
    s->data = malloc(s->capacity * s->element_size);
}


void stack_free(stack_t* s){
    free(s->data);
    s->data = NULL;
    s->size = 0;
    s->capacity = 0;
    s->element_size = 0;
}


bool stack_push(stack_t* s, const void* element){
    if (s->size >= s->capacity){
        s->capacity *= 2;
        void* new_data = realloc(s->data, s->capacity * s->element_size);
        if (!new_data){return false;}
        s->data = new_data;
    }
    void* dest = (char*)s->data + s->size * s->element_size;
    memcpy(dest, element, s->element_size);
    s->size++;
    return true;
}


bool stack_pop(stack_t* s){
    if (s->size == 0){return false;} 
    s->size--;
    return true;
}


void* stack_top(stack_t* s){
    if (s->size == 0){return NULL;}
    return (char*)s->data + (s->size - 1) * s->element_size;
}


bool stack_is_empty(const stack_t* s){
    return s->size == 0;
}


size_t stack_size(const stack_t* s){
    return s->size;
}
