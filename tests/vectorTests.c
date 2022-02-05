#include <assert.h>
#include "../libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0); //создали пустой вектор
    pushBack(&v, 25);
    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 25);
}

void test_pushBack_fullVector() {
    vector v = createVector(2);
    pushBack(&v, 25);
    pushBack(&v, 26); //заполнили вектор полностью
    assert(v.size == 2);
    assert(v.capacity == 2);
    pushBack(&v, 27);
    assert(v.size == 3);
    assert(v.capacity == 4);
    assert(v.data[2] == 27);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}