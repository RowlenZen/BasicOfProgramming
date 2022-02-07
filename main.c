#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include "tests/vectorTests.c"

void test();

int main() {
    test();
    int capacity;
    printf("Enter wish capacity of vector: ");
    scanf("%d", &capacity);
    vector vector = createVector(capacity);
    printVector(&vector);
    return 0;
}

void test() {
    test_pushBack_emptyVectorWithNullData();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}
