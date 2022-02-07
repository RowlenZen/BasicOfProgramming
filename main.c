#include <stdio.h>
#include "libs/data_structures/vector/vector.h"
#include "tests/vectorTests.c"
#include "libs/data_structures/vector/vectorVoid.h"

void test();

void manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeInt();

void manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeFloat();

int main() {
    test();
//    int capacity;
//    printf("Enter wish capacity of vector: ");
//    scanf("%d", &capacity);
//    vector vector = createVector(capacity);
//    printVector(&vector);

    manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeInt();
    manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeFloat();

    return 0;
}

void manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeFloat() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);

        printf("%f ", x);
    }
}

void manualTest_pushBackV_getVectorValueV_emptyVectorVoid_BaseTypeInt() {
    size_t n;
    scanf("%zd", &n);

    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        pushBackV(&v, &x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);

        printf("%d ", x);
    }
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
