#ifndef BASICOFPROGRAMMING_VECTORVOID_H
#define BASICOFPROGRAMMING_VECTORVOID_H

#include <limits.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;            // указатель на нулевой элемент вектора
    size_t size;           // размер вектора
    size_t capacity;       // вместимость вектора
    size_t baseTypeSize;   /* размер базового типа:
                             например, если вектор хранит int -
                             то поле baseTypeSize = sizeof(int)
                             если вектор хранит float -
                             то поле baseTypeSize = sizeof(float) */
} vectorVoid;

/**возвращает структуру-дескриптор вектор из capacity значений*/
vectorVoid createVectorV(size_t capacity, size_t baseTypeSize);

/**изменяет количество памяти, выделенное под хранение элементов вектора*/
void reserveV(vectorVoid *v, size_t newCapacity);

/**удаляет элементы из контейнера, но не освобождает выделенную память*/
void clearV(vectorVoid *v);

/**освобождает память, выделенную под неиспользуемые элементы*/
void shrinkToFitV(vectorVoid *v);

/**освобождает память, выделенную вектору*/
void deleteVectorV(vectorVoid *v);

/**является ли вектор пустым (отсутствуют "полезные" элементы)*/
bool isEmptyV(vectorVoid *v);

/**является ли вектор полным (используется вся доступная вместимость)*/
bool isFullV(vectorVoid *v);

/**возвращает i-ый элемент вектора v*/
void getVectorValueV(vectorVoid *v, size_t i, void *destination);

/**записывает на index-ый элемент вектора v значение, расположенное по адресу source*/
void setVectorValueV(vectorVoid *v, size_t index, void *source);

/**удаляет последний элемент из вектора*/
void popBackV(vectorVoid *v);

/**добавляет элемент x в конец вектора v*/
void pushBackV(vectorVoid *v, void *source);

#endif //BASICOFPROGRAMMING_VECTORVOID_H
