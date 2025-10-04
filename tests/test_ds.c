#include "ds.h"
#include <assert.h>

struct Person {
    char name[50];
    int age;
};

int main(){

    Array* arr = array_create(2);
    assert(arr != NULL);
    assert(arr->size == 0);
    assert(arr->capacity == 2);

    Person* p1 = (Person*) malloc(sizeof(Person));
    snprintf(p1->name, sizeof(p1->name), "Alice");
    p1->age = 30;
    array_push_back(arr, p1);

    assert(arr->size == 1);
    assert(arr->capacity == 2);
    assert(arr->data[0] == p1);

    Person* p2 = (Person*) malloc(sizeof(Person));
    snprintf(p2->name, sizeof(p2->name), "Bob");
    p2->age = 25;
    array_push_back(arr, p2);

    assert(arr->size == 2);
    assert(arr->capacity == 2);
    assert(arr->data[1] == p2);


    Person* test_p1 = (Person*) arr->data[0];
    Person* test_p2 = (Person*) arr->data[1];

    assert(test_p1->age == 30);
    assert(test_p2->age == 25);

    array_pop_back(arr);
    assert(arr->size == 1);

    array_pop_back(arr);
    assert(arr->size == 0);
    
    array_destroy(arr);

    return 0;
}