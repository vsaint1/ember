#include "ds.h"


Array* array_create(size_t initial_capacity){

    Array* arr = (Array*)malloc(sizeof(Array));
    if (!arr) {
        LOG_ERROR("Failed to allocate memory for Array");
        return NULL;
    }

    arr->data = (void**)malloc(initial_capacity * sizeof(void*));

    if (!arr->data) {
        LOG_ERROR("Failed to allocate memory for Array data");
        free(arr);
        return NULL;
    }
    
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

void array_push_back(Array* arr, void* element){
    if(arr->size >= arr->capacity){
        size_t new_capacity = arr->capacity * 2;
        void** new_data = (void**)realloc(arr->data, new_capacity * sizeof(void*));
      
        if(!new_data){
            LOG_ERROR("Failed to reallocate memory for Array data");
            return;
        }

        arr->data = new_data;
        arr->capacity = new_capacity;
    }

    arr->data[arr->size++] = element;
}

void array_pop_back(Array* arr){

   if (arr->size > 0) {
       free(arr->data[arr->size - 1]);
       arr->size--;
   } else {
       LOG_ERROR("Array is already empty, cannot pop back");
   }
}

void array_destroy(Array* arr){
    if(arr){
        free(arr->data);
        free(arr);
    }
}