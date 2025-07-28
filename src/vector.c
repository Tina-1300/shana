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

    if(vec == NULL || vec->data == NULL) {return false;}

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
    if (vec == NULL || vec->data == NULL){return NULL;}
    if (vec->size == 0){ return NULL;}
    return vec->data;
}


void * vector_back(vector_t* vec){
    if (vec == NULL || vec->data == NULL){return NULL;}
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
    
    if (vec == NULL || vec->data == NULL){return false;} // vector not initialized or data pointer is NULL
    
    if (vec->size == 0){return false;} // vector is empty, nothing to remove

    vec->size--;
    
    memset((char*)vec->data + vec->element_size * vec->size, 0, vec->element_size);
    
    return true;
}


bool vector_pop_front(vector_t* vec){
    if (vec == NULL || vec->data == NULL){return false;} // vector not initialized or data pointer is NULL
    if (vec->size == 0){return false;} // vector is empty, nothing to remove
    memcpy(vec->data, (char*)vec->data + vec->element_size, (vec->size - 1) * vec->element_size);
    vec->size--;
    return true;
}


bool vector_pop_at(vector_t* vec, size_t index){

    if (vec == NULL || vec->data == NULL){return false;} // vector not initialized or data pointer is NULL
    
    if (vec->size == 0){return false;} // vector is empty, nothing to remove
    
    if (index > vec->size){return false;} // index is out of bounds
    
    if (index < vec->size - 1){
        char* destination = (char*)vec->data + index * vec->element_size;
        char* source = (char*)vec->data + (index + 1) * vec->element_size;
        size_t bytes_to_move = (vec->size - 1 - index) * vec->element_size;

        memmove(destination, source, bytes_to_move);
    }

    vec->size--;

    memset((char*)vec->data + vec->size * vec->element_size, 0, vec->element_size);

    return true; 
}


bool vector_push_front(vector_t* vec, const void* element){

    if (vec == NULL || vec->data == NULL){return false;} // vector not initialized or data pointer is NULL

    // if the vector is full, double its capacity
    if (vec->size >= vec->capacity){

        vec->capacity *= 2;
        
        void* new_data = realloc(vec->data, vec->capacity * vec->element_size);
        
        if (!new_data){ return false;}
        
        vec->data = new_data;
    }

    // Shift all existing elements one position to the right
    for (size_t i = vec->size; i > 0; --i){

        void* dst = (char*)vec->data + i * vec->element_size;

        void* src = (char*)vec->data + (i - 1) * vec->element_size;

        memcpy(dst, src, vec->element_size);
    }
    
    void* dst = (char*)vec->data;

    memcpy(dst, element, vec->element_size);

    vec->size++;

    return true;
}


bool vector_push_at(vector_t* vec, size_t index, const void* element){
    
    if (vec == NULL || vec->data == NULL){return false;} // vector not initialized or data pointer is NULL

    if (index > vec->size){return false;} // index is out of bounds

    // if the vector is full, double its capacity
    if (vec->size >= vec->capacity){

        vec->capacity *= 2;
        
        void* new_data = realloc(vec->data, vec->capacity * vec->element_size);
        
        if (!new_data){ return false;}
        
        vec->data = new_data;
    }

    for (size_t i = vec->size; i > index; --i){

        void* dst = (char*)vec->data + i * vec->element_size;

        void* src = (char*)vec->data + (i - 1) * vec->element_size;

        memcpy(dst, src, vec->element_size);

    }
    
    void* dst = (char*)vec->data + index * vec->element_size;

    memcpy(dst, element, vec->element_size);

    vec->size++;

    return true;
}


bool vector_reverse(vector_t* vec){

    if (vec == NULL || vec->data == NULL){
        return false;
    } // vector not initialized or data pointer is NULL

    if (vec->size <= 1){
        return true;
    }

    size_t left_idx = 0;

    size_t right_idx = vec->size - 1;

    while (left_idx < right_idx){
        
        void* left_ptr = (char*)vec->data + left_idx * vec->element_size;
        void* right_ptr = (char*)vec->data + right_idx * vec->element_size;

        char temp_buffer[vec->element_size];

        memcpy(temp_buffer, left_ptr, vec->element_size);
        memcpy(left_ptr, right_ptr, vec->element_size);
        memcpy(right_ptr, temp_buffer, vec->element_size);

        left_idx++;

        right_idx--;

    }

    return true;
}

