# Shana Library

Welcome to the documentation for *Shana*, a library developed in **C language** aimed at providing a vast set of generic data collections.

Inspired by C++'s Standard Template Library (STL), the *Shana* project was created with the goal of offering a similar solution for C, enabling flexible and efficient management of elements of any type. Currently, *Shana* includes robust implementations for **stacks** and **vectors** (dynamic arrays).

In the near future, we plan to integrate other collection types to further enrich this library and address a wider range of needs in C development.


## Key Current Features


The current collections (stack, vector) offer the following characteristics :

- **Genericity :** Ability to store elements of any type (integers, floats, custom structures, etc.).
- **Dynamic Memory Allocation :** Flexibility in size, allowing collections to grow or shrink as needed.
- **Clear and Intuitive API :** Well-defined functions for initialization, memory deallocation, adding, removing, and accessing elements.


## Quick Start Guide

To start using the Shana library, simply include the header file for the desired collection (e.g., stack.h for stacks) : 

```c
#include <stdio.h>
#include <shana/stack.h>

// gcc -o test_stack.exe test_stack.c -lshana & color

int main(){

    stack_t stack;

    stack_init(&stack, sizeof(int));

    /*
    // works
    int values[] = {10, 20, 30};

    for (int i = 0; i < 3; ++i){
        stack_push(&stack, &values[i]);
    }
    */

    /*
    // works
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
```

## Module

- [Stack](stack.md)
- [Vector](vector.md)

## Example

- [example stack](./example/example_stack.md)
- [example vector](./example/example_vector.md)



## Project Information

- Library Creation Date: July 26, 2025
- Main Author: [https://github.com/Tina-1300](https://github.com/Tina-1300)
- Contributors: [https://tina-1300.github.io/contributor-shana.html](https://tina-1300.github.io/contributor-shana.html)
- GitHub Repository: [https://github.com/Tina-1300/shana](https://github.com/Tina-1300/shana)

!!! warning
    This project is constantly evolving. Your support is invaluable! Feel free to give a star ⭐ to the GitHub repository if you find Shana useful or promising.