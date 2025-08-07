# API - Vector

---


## Struct

<br>

`typedef struct vector_t`

**Description** : Struct representing a generic vector capable of storing elements of any type.

**Definition** : 

```c
typedef struct {
    void* data;           /* raw table          */
    size_t size;          /* number of elements */ 
    size_t capacity;      /* allocated capacity */
    size_t element_size;  /* size of an element */
} vector_t;
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

`void vector_init(vector_t* vec, size_t element_size)`

**Description** : Initializes a new instance of `vector_t`.

**Prototype** : 

```c
void vector_init(vector_t* vec, size_t element_size);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct to initialize.|
|element_size|size_t| Size (in bytes) of the element types stored in the vector. |

**Return value** : 

This function does not return any value.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));
```

!!! note
    - After calling this function, the vector `my_vector` is ready to be used.
    - The function allocates the memory needed to manage the vector.
    - The memory of the vector `my_vector` will need to be freed at the end of its use via the function `vector_free(vector_t* vec)`.

<br>

---

<br>

`void vector_free(vector_t* vec)`

**Description** : frees the memory allocated to the vector.

**Prototype** : 

```c
void vector_free(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct to be freed.|

**Return value** : 

This function does not return any value.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_free(&my_vector);
```

!!! note
    After calling this function, the memory allocated to the vector `my_vector` is freed.


<br>

---

<br>


`bool vector_push_back(vector_t* vec, const void* element)`

**Description** : This function adds a value to the end of the vector.

**Prototype** : 

```c
bool vector_push_back(vector_t* vec, const void* element);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*|Pointer to the vector_t struct.|
| element | const void* | Constant void pointer to the element to be inserted. |

**Return value** : 

This function only returns `true` if everything went well.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});

vector_free(&my_vector);
```


<br>

---

<br>


`void* vector_at(vector_t* vec, size_t index)`

**Description** : This function retrieves the value stored at the specified index.

**Prototype** : 

```c
void* vector_at(vector_t* vec, size_t index);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t* |Pointer to the vector_t struct.|
| index | size_t | Index of the item to be retrieved. |

**Return value** : 

This function returns a void pointer to the element stored at the specified index.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});

int* val = (int*)vector_at(&my_vector, 0);
printf("vec[0] = %d\n", *val);

vector_free(&my_vector);
```



<br>

---

<br>


`void* vector_front(vector_t* vec)`

**Description** : This function allows you to retrieve the value stored at the first location of the vector.

**Prototype** : 

```c
void* vector_front(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

This function returns a void pointer to the element stored at the first location of the vector.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

printf("%d", *(int*)vector_front(&my_vector));

vector_free(&my_vector);
```




<br>

---

<br>


`void * vector_back(vector_t* vec)`

**Description** : This function allows you to retrieve the value stored at the last location of the vector.

**Prototype** : 

```c
void * vector_back(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct. |

**Return value** : 

This function returns a void pointer to the element stored at the last location of the vector.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

printf("%d", *(int*)vector_back(&my_vector));

vector_free(&my_vector);
```


<br>

---

<br>


`size_t vector_size(const vector_t* vec)`

**Description** : This function retrieves the number of elements stored in the vector.

**Prototype** : 

```c
size_t vector_size(const vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns the number of elements stored in the vector.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

for (size_t i = 0; i < vector_size(&my_vector); ++i){
    int* val = (int*)vector_at(&my_vector, i);
    printf("vec[%zu] = %d\n", i, *val);
}


vector_free(&my_vector);
```



<br>

---

<br>


`size_t vector_capacity(const vector_t* vec)`

**Description** : This function retrieves the allocated capacity.

**Prototype** : 

```c
size_t vector_capacity(const vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns the memory capacity allocated to the vector.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

printf("vector capacity : %d", vector_capacity(&my_vector));


vector_free(&my_vector);
```




<br>

---

<br>



`bool vector_is_empty(const vector_t* vec)`

**Description** : This function checks if the vector is empty.

**Prototype** : 

```c
bool vector_is_empty(const vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | const vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns `true` if the vector is empty and `false` if the vector is not empty.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));

if (vector_is_empty(&my_vector) == true){
    printf("the vector is empty");
}

vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

if (vector_is_empty(&my_vector) == false){
    printf("the vector is not empty");
}



vector_free(&my_vector);
```


<br>

---

<br>



`bool vector_pop_back(vector_t* vec)`

**Description** : This function removes the last element of the vector.

**Prototype** : 

```c
bool vector_pop_back(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

if (vector_is_empty(&my_vector) == false){
    printf("the vector is not empty");
    if(vector_pop_back(&my_vector) ==true){
        printf("everything went well")
    }
}


vector_free(&my_vector);
```







<br>

---

<br>



`bool vector_pop_front(vector_t* vec)`

**Description** : This function removes the first element from the vector.

**Prototype** : 

```c
bool vector_pop_front(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

if (vector_is_empty(&my_vector) == false){
    printf("the vector is not empty");
    if(vector_pop_front(&my_vector) == true){
        printf("everything went well")
    }
}


vector_free(&my_vector);
```






<br>

---

<br>



`bool vector_pop_at(vector_t* vec, size_t index)`

**Description** : This function removes an element at the specified index.

**Prototype** : 

```c
bool vector_pop_at(vector_t* vec, size_t index);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|
| index | size_t | Index of the item to be deleted.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

if (vector_is_empty(&my_vector) == false){
    printf("the vector is not empty");
    if (vector_pop_at(&my_vector, 1) == true){
        printf("operation successfully completed");
    }
}


vector_free(&my_vector);
```



<br>

---

<br>




`bool vector_push_front(vector_t* vec, const void* element)`

**Description** : This function adds an element to the front of the vector.

**Prototype** : 

```c
bool vector_push_front(vector_t* vec, const void* element);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|
| element | const void * | Empty constant pointer to the element to be added.|

**Return value** : 

Returns `true` if everything went well.

**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});

vector_push_front(&my_vector, &(int){5});


vector_free(&my_vector);
```




<br>

---


<br>


`bool vector_push_at(vector_t* vec, size_t index, const void* element)`

**Description** : This function adds an element at a specified index of the vector.

**Prototype** : 

```c
bool vector_push_at(vector_t* vec, size_t index, const void* element);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|
| index | size_t | Index to specify to add the element to the vector. |
| element | const void * | Empty constant pointer to the element to be added.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});
vector_push_back(&my_vector, &(int){6});


vector_push_at(&my_vector, 1 , &(int){5});


vector_free(&my_vector);
```





<br>

---

<br>




`bool vector_reverse(vector_t* vec)`

**Description** : This function reverses all elements of the vector, the first element becomes the last and so on.

**Prototype** : 

```c
bool vector_reverse(vector_t* vec);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9});
vector_push_back(&my_vector, &(int){3});
vector_push_back(&my_vector, &(int){6});

// display : 9, 3, 6

vector_reverse(&my_vector);

// display : 6, 3, 9


vector_free(&my_vector);
```




<br>

---

<br>



`bool vector_swap(vector_t* vec, size_t index_element_a, size_t index_element_b)`

**Description** : This function swaps two elements in the vector.

**Prototype** : 

```c
bool vector_swap(vector_t* vec, size_t index_element_a, size_t index_element_b);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|
| index_element_a | size_t | Index of the element to be exchanged with the second.|
| index_element_b | size_t | Index of the element to be exchanged with the first.|

**Return value** : 

Returns `true` if everything went well.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9}); // index : 0

vector_push_back(&my_vector, &(int){3}); // index : 1

vector_push_back(&my_vector, &(int){6}); // index : 2

vector_push_back(&my_vector, &(int){2}); // index : 3

vector_swap(&my_vector, 2, 0);

// display : 6, 3, 9, 2


vector_free(&my_vector);
```



<br>

---

<br>



`bool vector_check(vector_t* vec, const void* element)`

**Description** : This function allows you to check if an element is already present in the vector.

**Prototype** : 

```c
bool vector_check(vector_t* vec, const void* element);
```

**Settings** : 

| Name | Type | Description|
|-----|------|------------|
| vec | vector_t*| Pointer to the vector_t struct.|
| element | const void* | Empty constant pointer to the element to check.|

**Return value** : 

This function returns true if the element is present and false if it is not present or if there was an error.


**Example of use** :

```c
vector_t my_vector;

vector_init(&my_vector, sizeof(int));


vector_push_back(&my_vector, &(int){9}); // index : 0

vector_push_back(&my_vector, &(int){3}); // index : 1

vector_push_back(&my_vector, &(int){6}); // index : 2

vector_push_back(&my_vector, &(int){2}); // index : 3

vector_swap(&my_vector, 2, 0); // display : 6, 3, 9, 2


if (vector_check(&my_vector, &(int){3})){
    printf("the element is present in the vector");
}


vector_free(&my_vector);
```

