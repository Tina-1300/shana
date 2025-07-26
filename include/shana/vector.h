/** @file vector.h */

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdbool.h>


/**
    @struct vector_t
    The vector_t structure is designed to represent a generic vector in C.
    This means that it can store elements of any type (integers, floats, other structures, etc.)
    without being specifically tied to a single type.
*/
typedef struct {
    void* data;           /**< @brief raw table */
    size_t size;          /**< @brief number of elements */ 
    size_t capacity;      /**< @brief allocated capacity */
    size_t element_size;  /**< @brief size of an element */
} vector_t;

/**
    @brief Initializes a new vector.

    @param[out] vec Pointeur vers la structure vector_t à initialiser.
    @param[in] element_size Size of the element type to store in the vector.
    @return This function does not return a value. 
*/
void vector_init(vector_t* vec, size_t element_size);

/**
    @brief Frees the memory allocated during vector initialization.

    @param[in] vec  Pointer to the initialized vector_t structure.
    @return This function does not return a value.
*/
void vector_free(vector_t* vec);

/**
    @brief Inserts an element at the end of the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @param[in] element Constant void pointer to the element to insert.
    @return Returns true if everything went smoothly.

*/
bool vector_push_back(vector_t* vec, const void* element);

/**
    @brief Retrieves an element from the vector at the specified index.

    @param[in] vec Pointer to the initialized vector_t structure.
    @param[in] index Index de l'élément à récupéré.
    @return Returns a void pointer to the element stored at the specified index.
*/
void* vector_at(vector_t* vec, size_t index);

/**
    @brief Retrieves the very first element of the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns a void pointer to the very first element of the vector.
*/
void* vector_front(vector_t* vec);

/**
    @brief Retrieves the last element of the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns a void pointer to the very last element of the vector.
*/
void * vector_back(vector_t* vec);

/**
    @brief Retrieves the number of elements stored in the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns the number of elements stored in the vector.
*/
size_t vector_size(const vector_t* vec);

/**
    @brief Retrieves the allocated capacity.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns the memory capacity allocated to the vector.
*/
size_t vector_capacity(const vector_t* vec);

/**
    @brief Checks if the vector is empty.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns true if the vector is empty.
*/
bool vector_is_empty(const vector_t* vec);

/**
    @brief Removes the last element from the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns true if everything went smoothly.
*/
bool vector_pop_back(vector_t* vec);


#endif


/*

methods (functions) to do:

vector_push_at() -> inserts an element at a given index

vector_pop_at() -> removes an element at a given index

vector_pop_front() -> removes the first element

vector_check() -> checks if an element already exists in the vector

vector_count() -> counts how many times an element appears in the vector

vector_clear_data() -> resets all vector values without freeing memory

vector_reverse() -> reverses the content of the array

vector_print() -> prints the vector values from index a to index b

vector_print_all() -> prints all values of a vector

vector_push_front() -> inserts an element at the front of the vector

vector_reverse_at() -> reverses elements of a vector from a given index

*/