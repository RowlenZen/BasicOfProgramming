#include <stddef.h>
#include <stdbool.h>

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

/**является ли вектор пустым (отсутствуют "полезные" элементы)*/
bool isEmpty(vector *v);

/**является ли вектор полным (используется вся доступная вместимость)*/
bool isFull(vector *v);

/**возвращает i-ый элемент вектора v*/
int getVectorValue(vector *v, size_t i);

/**добавляет элемент x в конец вектора v*/
void pushBack(vector *v, int x);

/**удаляет последний элемент из вектора*/
void popBack(vector *v);

#endif