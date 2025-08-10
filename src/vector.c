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

    void * temp_buffer = malloc(vec->element_size);
        
    if (temp_buffer == NULL){
        return false;
    }

    while (left_idx < right_idx){
        
        void* left_ptr = (char*)vec->data + left_idx * vec->element_size;
        void* right_ptr = (char*)vec->data + right_idx * vec->element_size;

        memcpy(temp_buffer, left_ptr, vec->element_size);
        memcpy(left_ptr, right_ptr, vec->element_size);
        memcpy(right_ptr, temp_buffer, vec->element_size);

        left_idx++;

        right_idx--;

    }

    free(temp_buffer);

    return true;
}

bool vector_swap(vector_t* vec, size_t index_element_a, size_t index_element_b){

    if (vec == NULL || vec->data == NULL){
        return false;
    }
    
    if (vec->size <= 1){
        return false;
    }

    if (index_element_a > vec->size || index_element_b > vec->size){
        return false;
    }

    void * a = vector_at(vec, index_element_a);
    void * b = vector_at(vec, index_element_b);

    if (a == NULL || b == NULL){
        return false;
    }

    void * tmp = malloc(vec->element_size);

    memcpy(tmp, a, vec->element_size);
    memcpy(a, b, vec->element_size);
    memcpy(b, tmp, vec->element_size);

    free(tmp);

    return true;
}


bool vector_check(vector_t* vec, const void* element){
    
    bool status = false;

    if (vec == NULL || vec->data == NULL){
        return false;
    }

    for (size_t i = 0; i < vec->size; i++){
        
        void * element_search = vector_at(vec, i);

        if (memcmp(element_search, element, vec->element_size) == 0){
            status = true;
            break;
        }

    }
        
    return status;
}


void vector_resize(vector_t* vec, size_t new_size){
    
    if (!vec){
        return;
    }

    void * new_data = realloc(vec->data, new_size * vec->element_size);

    if (!new_data && new_size > 0 ){
        return;
    }

    if (new_size > vec->size){
        size_t extra_bytes = (new_size - vec->size) * vec->element_size;
        memset((char*)new_data + vec->size * vec->element_size, 0, extra_bytes);
    }

    vec->data = new_data;
    vec->size = new_size;
}


vector_t vector_slice(const vector_t* src, size_t start, size_t end){

    if (start > src->size){
        start = src->size;
    }

    if (end > src->size) {
        end = src->size;
    }

    if (start > end){
        start = end;
    }

    size_t new_size = end - start;


    vector_t slice;
    vector_init(&slice, src->element_size);
    vector_resize(&slice, new_size);


    for (size_t i = 0; i < new_size; i++){
        memcpy((char*)slice.data + i * src->element_size, (char*)src->data + (start + i) * src->element_size, src->element_size);
    }
    
    return slice;
}


unsigned int vector_count(vector_t* vec, const void* element){

    int increment = 0;

    if (vec == NULL || vec->data == NULL){
        return false;
    }

    for (size_t i = 0; i < vec->size; i++){
        
        void * element_search = vector_at(vec, i);

        if (memcmp(element_search, element, vec->element_size) == 0){
            increment += 1;
            
        }

    }
        
    return increment;
}