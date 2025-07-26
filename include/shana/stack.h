/** @file stack.h */

#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>


/**
    @struct stack_t
    The stack_t structure is designed to represent a generic stack in C.
    This means it can store elements of any type (integers, floats, other structures, etc.)
    without being specifically tied to a single type.
*/
typedef struct {
    void* data;           /**< @brief Pointer to the raw memory block allocated for the stack elements. */
    size_t size;          /**< @brief Current number of elements stored in the stack. */
    size_t capacity;      /**< @brief Maximum capacity of the stack. */
    size_t element_size;  /**< @brief size of an element (e.g., int, struct, etc.). */
} stack_t;


/**
    @brief Initializes a new generic stack.

    Allocates initial memory for the stack and initializes its members.
    
    @param[out]  s  Pointer to the stack_t structure to be initialized.
    @param[in]  element_size  The size in bytes of a single element the stack will contain, e.g., sizeof(int).
    @return This function does not return a value.
*/
void stack_init(stack_t* s, size_t element_size); // Initializes the stack


/**
    @brief Frees the memory allocated for the stack during initialization.

    @param[in] s  Pointer to the initialized stack_t structure.
    @return This function does not return a value.
*/
void stack_free(stack_t* s); // Frees the memory allocated for the stack


/**
    @brief Adds an element to the top of the stack. 

    @param[in] s Pointer to the initialized stack_t structure.
    @param[in] element Constant void pointer to a value to be added to the stack.
    @return Returns true if the operation was successful, false otherwise.
*/
bool stack_push(stack_t* s, const void* element); // ajoute un élément à la pile


/**
    @brief Removes the top element from the stack.

    @param[in] s Pointer to the initialized stack_t structure.
    @return Returns true if an element was successfully removed, false if the stack was empty.
*/
bool stack_pop(stack_t* s); // Removes the last element added to the stack


/**
    @brief Accesses the top element of the stack.

    @param[in] s Pointer to the initialized stack_t structure.
    @return Returns a void pointer to the top element of the stack, or NULL if the stack is empty.
*/
void* stack_top(stack_t* s); // Accesses the top element


/**
    @brief Checks if the stack is empty.

    @param[in] s Pointer to the initialized stack_t structure.
    @return Returns true if the stack is empty, false otherwise.
*/
bool stack_is_empty(const stack_t* s); // Checks if the stack is empty


/**
    @brief Checks the current number of elements in the stack.

    @param[in] s Pointer to the initialized stack_t structure.
    @return Returns the current number of elements in the stack.
*/
size_t stack_size(const stack_t* s); // Checks the size of the stack


#endif