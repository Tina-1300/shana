#include "../include/shana/vector.h"

#include <stdlib.h>
#include <string.h>



void vector_init(vector_t* vec, size_t element_size){
    vec->element_size = element_size;
    vec->size = 0;
    vec->capacity = 4;
    vec->data = malloc(vec->capacity * element_size);
}



void vector_free(vector_t* vec){
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
    vec->element_size = 0;
}



bool vector_push_back(vector_t* vec, const void* element){
    if (vec->size >= vec->capacity){
        vec->capacity *= 2;
        void* new_data = realloc(vec->data, vec->capacity * vec->element_size);
        if (!new_data){ return false;}
        vec->data = new_data;
    }
    void* dest = (char*)vec->data + vec->size * vec->element_size;
    memcpy(dest, element, vec->element_size);
    vec->size++;
    return true;
}



void* vector_at(vector_t* vec, size_t index){
    if (index >= vec->size) {return NULL;}
    return (char*)vec->data + index * vec->element_size;
}



void* vector_front(vector_t* vec){
    if (vec->size == 0){ return NULL;}
    return vec->data;
}


void * vector_back(vector_t* vec){
    if (vec->size == 0){return NULL;}
    return (char*)vec->data + vec->element_size * (vec->size - 1);
}


size_t vector_size(const vector_t* vec){
    return vec->size;
}


size_t vector_capacity(const vector_t* vec){
    return vec->capacity;
}


bool vector_is_empty(const vector_t* vec){
    return vec->size == 0;
}


bool vector_pop_back(vector_t* vec){
    if (vec->size == 0){return false;}
    vec->size--;
    memset((char*)vec->data + vec->element_size * vec->size, 0, vec->element_size);
    return true;
}

