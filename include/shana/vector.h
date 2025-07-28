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


/**
    @brief Removes the first element from the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @return Returns true if everything went smoothly.
*/
bool vector_pop_front(vector_t* vec);


/**
    @brief Removes an element from the vector at a specified index.

    This function removes the element located at the given index within the vector.
    All elements following the removed index are shifted one position towards the beginning of the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @param[in] index Index of the element to be removed.

    @return Returns \c true if the operation was successful,
    \c false if the vector is NULL, uninitialized, empty, or if the index is out of bounds.
*/
bool vector_pop_at(vector_t* vec, size_t index);



/**
    @brief Adds an element to the very first index of the vector.

    @param[in] vec Pointer to the initialized vector_t structure.
    @param[in] element Constant void pointer to the element to be added.

    @return Returns \c true if the operation was successful,
    \c false if the vector is NULL or uninitialized.
*/
bool vector_push_front(vector_t* vec, const void* element);

/**
    @brief Adds an element to the vector at the specified index.

    @param[in] vec Pointer to the initialized vector_t structure.
    @param[in] index Index where the new element should be inserted.
    @param[in] element Constant void pointer to the element to be added.

    @return Returns \c true if the operation was successful,
    \c false if the vector is NULL, uninitialized, or if the index is out of bounds.
*/
bool vector_push_at(vector_t* vec, size_t index, const void* element);


/**
    @brief Reverse the elements of the vector

    @param[in] vec Pointer to the initialized vector_t structure.
    
    @return Returns \c true if the operation was successful,
    \c false is the vector is NULL or uninitialized.
*/
bool vector_reverse(vector_t* vec);



#endif

/*

methods (functions) to do:


vector_reverse_at() -> reverses elements of a vector from a given index

vector_check() -> checks if an element already exists in the vector

vector_clear_data() -> resets all vector values without freeing memory

vector_count() -> counts how many times an element appears in the vector


*/