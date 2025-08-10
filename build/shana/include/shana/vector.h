#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>


typedef struct {
    void* data;           /* raw table          */
    size_t size;          /* number of elements */ 
    size_t capacity;      /* allocated capacity */
    size_t element_size;  /* size of an element */
} vector_t;



void vector_init(vector_t* vec, size_t element_size);


void vector_free(vector_t* vec);


bool vector_push_back(vector_t* vec, const void* element);


bool vector_push_front(vector_t* vec, const void* element);


bool vector_push_at(vector_t* vec, size_t index, const void* element);


void * vector_back(vector_t* vec);


void* vector_front(vector_t* vec);


void* vector_at(vector_t* vec, size_t index);


size_t vector_size(const vector_t* vec);


size_t vector_capacity(const vector_t* vec);


bool vector_is_empty(const vector_t* vec);


bool vector_pop_back(vector_t* vec);


bool vector_pop_front(vector_t* vec);


bool vector_pop_at(vector_t* vec, size_t index);


bool vector_reverse(vector_t* vec);


bool vector_swap(vector_t* vec, size_t index_element_a, size_t index_element_b);


bool vector_check(vector_t* vec, const void* element);

// new fonction v0.3.0

void vector_resize(vector_t* vec, size_t new_size); // done
 
vector_t vector_slice(const vector_t* src, size_t start, size_t end); // done

unsigned int vector_count(vector_t* vec, const void* element); 


bool vector_merged(vector_t* dest, size_t count, ...); // todo  (variadique)

bool vector_reverse_at(vector_t* vec, size_t start, size_t end); // todo 

void vector_shuffle(vector_t* vec); // todo



#endif

/*

vector_merged() -> merges multiple vectors to the chosen vector


methods (functions) to do:

vector_unique() -> removes all duplicates from the vector so that the unique value remains

vector_clone() -> Creates a deep copy of the vector.

vector_shuffle() -> Shuffles the elements of the vector randomly (Fisher-Yates algorithm)

vector_rotate_left() -> makes a circular rotation of the elements to the left

vector_rotate_right() -> makes a circular rotation of the elements to the right

vector_reverse_at() -> reverses elements of a vector from a given index

vector_clear_data() -> resets all vector values without freeing memory

vector_count() -> counts how many times an element appears in the vector


*/