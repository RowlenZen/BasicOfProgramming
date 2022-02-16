
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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

/**Дана прямоугольная матрица. Упорядочить столбцы матрицы по неубыванию
минимальных элементов столбцов*/
void sortColsByMinElement_task(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void sortColsByMinElement_test(){
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14, 5,
                    1, 56, 52,6,
                    32, 4, 2,10
            },
            3, 4);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 14, 7,5,
                    1, 52, 56,6,
                    32, 2, 4,10
            }, 3, 4
    );

    sortColsByMinElement_task(testMatrix);
    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

/**Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом*/
void getSquareOfMatrixIfSymmetric_task(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    *m = multiplyMatrices(*m, *m);
}

void getSquareOfMatrixIfSymmetric_test() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 1, 2,
                    1, 4, 3,
                    2, 3, 4
            }, 3, 3
    );

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    5, 10, 11,
                    10, 26, 26,
                    11, 26, 29
            }, 3, 3
    );

    getSquareOfMatrixIfSymmetric_task(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void matrix_test() {
    swapRowsWithMaxAndMinValues_test();
    sortRowsByMaxElement_test();
    sortColsByMinElement_test();
    getSquareOfMatrixIfSymmetric_test();
}