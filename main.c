#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include "tests/vectorTests.c"

void test();

int main() {
    vector vector = createVector(5);
    printVector(&vector);
    test();
    return 0;
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}
