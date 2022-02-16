
#include <assert.h>
#include "matrix.h"

void matrix_test();

/**Дана квадратная матрица, все элементы которой различны. Поменять местами
 * строки, в которых находятся максимальный и минимальный элементы*/
void swapRowsWithMaxAndMinValues_task(matrix m) {
    swapRowsWithMaxAndMinValues(m);
}

void swapRowsWithMaxAndMinValues_test() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    1, 56, 52,
                    32, 4, 2
            },
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 56, 52,
                    0, 7, 14,
                    32, 4, 2
            }, 3, 3
    );

    swapRowsWithMaxAndMinValues_task(testMatrix);
    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

/**Упорядочить строки матрицы по неубыванию наибольших элементов строк*/
void sortRowsByMaxElement_task(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void sortRowsByMaxElement_test(){
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    1, 56, 52,
                    32, 4, 2
            },
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    32, 4, 2,
                    1, 56, 52
            }, 3, 3
    );

    sortRowsByMaxElement_task(testMatrix);
    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void matrix_test() {
    swapRowsWithMaxAndMinValues_test();
    sortRowsByMaxElement_test();
//    sortColsByMinElement_test();
}