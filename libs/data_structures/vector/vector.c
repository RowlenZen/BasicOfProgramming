#include <malloc.h>
#include <stdlib.h>
#include "vector.h"
#include "../../algorithms/array/array.h"

void exitWithError(char message[]);

void printVector(vector *vector) {
    outputArray_(vector->data, vector->capacity);
    printf("Size: %zu\n", vector->size);
    printf("Capacity: %zu\n", vector->capacity);
}

vector createVector(size_t capacity) {
    int *data = malloc(sizeof(int) * capacity);
    vector *vectorPtr = malloc(sizeof(vector));

    if (vectorPtr == NULL || data == NULL) {
        exitWithError("Bad alloc");
    }

    vectorPtr->data = data;
    vectorPtr->size = 0;
    vectorPtr->capacity = capacity;

    return *vectorPtr;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        int *newData = realloc(v->data, sizeof(int) * newCapacity);
        if (newData == NULL) {
            exitWithError("Bad alloc");
        }

        v->data = newData;
    }

    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
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

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    size_t *vectorSize = &(v->size);
    size_t vectorCapacity = v->capacity;
    if (*vectorSize >= vectorCapacity) {
        size_t newCapacity = vectorCapacity ? vectorCapacity * 2 : 1;
        reserve(v, newCapacity);
    }
    v->data[*vectorSize] = x;
    (*vectorSize)++;
}

void popBack(vector *v) {
    if (v->size == 0) {
        exitWithError("Error removing element cause vector is empty");
    }
    v->size--;
}

void exitWithError(char message[]) {
    fprintf(stderr, "%s", message);
    exit(1);
}
