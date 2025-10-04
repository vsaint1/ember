#pragma once
#include "definitions.h"


typedef struct Array {
    void** data;
    size_t size;
    size_t capacity;
} Array;


Array* array_create(size_t initial_capacity);

void array_push_back(Array* arr, void* element);

void array_pop_back(Array* arr);

void array_destroy(Array* arr);