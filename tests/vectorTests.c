#include <assert.h>
#include "../libs/data_structures/vector/vector.h"

void test_pushBack_emptyVectorWithNullData() {
    vector v = createVector(5);
    reserve(&v, 0); //here set v.data = NULL
    pushBack(&v, 20);
    assert(v.data[0] == 20);
    assert(v.size == 1);
    assert(v.capacity == 1);
}

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

void test_atVector_notEmptyVector() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 20);
    pushBack(&v, 40);
    assert(*atVector(&v, 1) == 20);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 30);
    assert(*atVector(&v, 1) == 30);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 100);
    pushBack(&v, 200);
    pushBack(&v, 300);
    assert(*back(&v) == 300);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 100);
    pushBack(&v, 200);
    assert(*front(&v) == 100);
}