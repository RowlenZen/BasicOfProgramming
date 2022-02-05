#include <malloc.h>
#include <stdlib.h>
#include "vector.h"
#include "../../algorithms/array/array.h"

void printVector(vector *vector) {
    outputArray_(vector->data, vector->capacity);
    printf("Size: %zu\n", vector->size);
    printf("Capacity: %zu", vector->capacity);
}

vector createVector(size_t capacity) {
    int *data = malloc(sizeof(int) * capacity);
    vector *vectorPtr = malloc(sizeof(vector));

    if (vectorPtr == NULL || data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    vectorPtr->data = data;
    vectorPtr->size = 0;
    vectorPtr->capacity = capacity;

    return *vectorPtr;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }

    int *newData = realloc(v->data, sizeof(int) * newCapacity);
    if (newData == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    free(v->data);
    v->data = newData;

    if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v);
}