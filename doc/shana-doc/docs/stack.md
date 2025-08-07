# API - Stack

---


## Struct

<br>

`typedef struct stack_t`

**Description** : The `stack_t` struct is designed to represent a generic stack in C.

**Definition** : 

```c
typedef struct {
    void* data;           /* Pointer to the raw memory block allocated for the stack elements.  */
    size_t size;          /* Current number of elements stored in the stack.                    */
    size_t capacity;      /* Maximum capacity of the stack.                                     */
    size_t element_size;  /* size of an element (e.g., int, struct, etc.).                      */
} stack_t;
```

**Champs** : 

| Name | Type | Description |
|-------|------|-------------|
| data  | void*| Pointer to the data table |
| size  | size_t | Number of items currently stored |
| capacity | size_t | Maximum allocated capacity |
| element_size | size_t | Size of an element |


<br>


## Function 

<br>


`void stack_init(stack_t* s, size_t element_size)`

**Description** : Initializes a new instance of `stack_t`.

**Prototype** : 

```c
void stack_init(stack_t* s, size_t element_size);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | stack_t*| Pointer to the stack_t struct to initialize.|
|element_size|size_t| Size (in bytes) of the element types stored in the stack. |

**Return value** : 

This function does not return any value.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));
```

!!! note
    - Allocate memory for the stack, don't forget to free the stack memory via `stack_free()`

<br>

---

<br>

`void stack_free(stack_t* s)`

**Description** : frees the memory allocated to the stack.

**Prototype** : 

```c
void stack_free(stack_t* s);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | stack_t*| Pointer to the stack_t struct to be freed.|

**Return value** : 

This function does not return any value.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

stack_free(&my_stack);
```

!!! note
    After calling this function, the memory allocated to the stack `my_stack` is freed.



<br>

---

<br>



`bool stack_push(stack_t* s, const void* element)`

**Description** : Adds an element to the top of the stack. 

**Prototype** : 

```c
bool stack_push(stack_t* s, const void* element);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | stack_t*| Pointer to the stack_t struct to be freed.|
| element | const void* | Constant void pointer to a value to be added to the stack. |

**Return value** : 

Returns true if the operation was successful, false otherwise.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

stack_push(&my_stack, &(int){10});

stack_push(&my_stack, &(int){9});

stack_push(&my_stack, &(int){8});

stack_push(&my_stack, &(int){7});

stack_push(&my_stack, &(int){6});

stack_free(&my_stack);
```




<br>

---

<br>



`bool stack_pop(stack_t* s)`

**Description** : Removes the top element from the stack.

**Prototype** : 

```c
bool stack_pop(stack_t* s);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | stack_t*| Pointer to the stack_t struct to be freed.|


**Return value** : 

Returns true if an element was successfully removed, false if the stack was empty.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

stack_push(&my_stack, &(int){10});

stack_push(&my_stack, &(int){9});

stack_push(&my_stack, &(int){8});

stack_push(&my_stack, &(int){7});

stack_push(&my_stack, &(int){6});

stack_pop(&my_stack)

stack_free(&my_stack);
```




<br>


---

<br>



`void* stack_top(stack_t* s)`

**Description** : Accesses the top element of the stack.

**Prototype** : 

```c
void* stack_top(stack_t* s);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | stack_t*| Pointer to the stack_t struct to be freed.|


**Return value** : 

Returns a void pointer to the top element of the stack, or NULL if the stack is empty.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

stack_push(&my_stack, &(int){10});

stack_push(&my_stack, &(int){9});

stack_push(&my_stack, &(int){8});

stack_push(&my_stack, &(int){7});

stack_push(&my_stack, &(int){6});

while (!stack_is_empty(&my_stack)){
        
    printf("Top = %d\n", *(int*)stack_top(&my_stack));

    stack_pop(&my_stack);
}


stack_free(&my_stack);
```



<br>

---

<br>




`bool stack_is_empty(const stack_t* s)`

**Description** : Checks if the stack is empty.

**Prototype** : 

```c
bool stack_is_empty(const stack_t* s);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | const stack_t*| Pointer to the stack_t struct to be freed.|


**Return value** : 

Returns true if the stack is empty, false otherwise.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

if (stack_is_empty(&my_stack) != false){
    printf("the stack is empty");
}

stack_push(&my_stack, &(int){10});

stack_push(&my_stack, &(int){9});

stack_push(&my_stack, &(int){8});

stack_push(&my_stack, &(int){7});

stack_push(&my_stack, &(int){6});

if (stack_is_empty(&my_stack) != true){
    printf("the stack is not empty");
}


stack_free(&my_stack);
```



<br>

---

<br>



`size_t stack_size(const stack_t* s)`

**Description** : Checks the current number of elements in the stack.

**Prototype** : 

```c
size_t stack_size(const stack_t* s);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| s | const stack_t*| Pointer to the stack_t struct to be freed.|


**Return value** : 

Returns the current number of elements in the stack.

**Example of use** :

```c
stack_t my_stack;

stack_init(&my_stack, sizeof(int));

if (stack_is_empty(&my_stack) != false){
    printf("the stack is empty");
}

stack_push(&my_stack, &(int){10});

stack_push(&my_stack, &(int){9});

stack_push(&my_stack, &(int){8});

stack_push(&my_stack, &(int){7});

stack_push(&my_stack, &(int){6});

if (stack_is_empty(&my_stack) != true){
    printf("the stack is not empty");

    printf("there are %d elements currently stored in the stack", stack_size(&my_stack));
}


stack_free(&my_stack);
```


<br>

---

<br>



