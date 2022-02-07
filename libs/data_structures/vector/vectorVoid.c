#include <malloc.h>
#include "vectorVoid.h"
#include "vector.c"

vectorVoid createVectorV(size_t capacity, size_t baseTypeSize) {
    int *data = malloc(baseTypeSize * capacity);
    vectorVoid *vectorVptr = malloc(sizeof(vectorVoid));

    if (vectorVptr == NULL || data == NULL) {
        exitWithError("Bad alloc");
    }

    vectorVptr->data = data;
    vectorVptr->size = 0;
    vectorVptr->capacity = capacity;

    return *vectorVptr;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        int *newData = realloc(v->data, v->baseTypeSize * newCapacity);
        if (newData == NULL) {
            exitWithError("Bad alloc");
        }

        v->data = newData;
    }

    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v) {
    v->capacity = v->size;
}

void deleteVectorV(vectorVoid *v) {
    free(v);
}