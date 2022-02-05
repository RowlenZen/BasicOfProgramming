#include <stddef.h>

#ifndef DATA_STRUCTURE_VECTOR_VECTOR_H
#define DATA_STRUCTURE_VECTOR_VECTOR_H

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} vector;

/** выводит в консоль структуру-дескриптор вектор и его значения*/
void printVector(vector *vector);

/**возвращает структуру-дескриптор вектор из capacity значений*/
vector createVector(size_t capacity);

/**изменяет количество памяти, выделенное под хранение элементов вектора*/
void reserve(vector *v, size_t newCapacity);

/**удаляет элементы из контейнера, но не освобождает выделенную память*/
void clear(vector *v);

/**освобождает память, выделенную под неиспользуемые элементы*/
void shrinkToFit(vector *v);

/**освобождает память, выделенную вектору*/
void deleteVector(vector *v);

#endif