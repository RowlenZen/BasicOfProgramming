#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "vectorVoid.h"

void exitWithErrorV(char message[]) {
    fprintf(stderr, "%s", message);
    exit(1);
}

vectorVoid createVectorV(size_t capacity, size_t baseTypeSize) {
    int *data = malloc(baseTypeSize * capacity);
    vectorVoid *vectorVptr = malloc(sizeof(vectorVoid));

    if (vectorVptr == NULL || data == NULL) {
        exitWithErrorV("Bad alloc");
    }

    vectorVptr->data = data;
    vectorVptr->size = 0;
    vectorVptr->capacity = capacity;
    vectorVptr->baseTypeSize = baseTypeSize;

    return *vectorVptr;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
    } else {
        int *newData = realloc(v->data, v->baseTypeSize * newCapacity);
        if (newData == NULL) {
            exitWithErrorV("Bad alloc");
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

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (v->size == 0) {
        exitWithErrorV("Error removing element cause vector is empty");
    }
    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    size_t *vectorVSize = &(v->size);
    size_t vectorVCapacity = v->capacity;
    if (*vectorVSize >= vectorVCapacity) {
        //vectorVCapacity could be 0
        size_t newCapacity = vectorVCapacity ? vectorVCapacity * 2 : 1;
        reserveV(v, newCapacity);
    }
    setVectorValueV(v, *vectorVSize, source);
    (*vectorVSize)++;
}