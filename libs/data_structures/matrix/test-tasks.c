#include <assert.h>
#include <malloc.h>
#include "matrix.h"

void matrix_test();

/**Дана квадратная матрица, все элементы которой различны. Поменять местами
 * строки, в которых находятся максимальный и минимальный элементы*/
void task_swapRowsWithMaxAndMinValues(matrix m) {
    swapRowsWithMaxAndMinValues(m);
}

void test_swapRowsWithMaxAndMinValues() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    1, 56, 52,
                    32, 4, 2
            }, 3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 56, 52,
                    0, 7, 14,
                    32, 4, 2
            }, 3, 3
    );

    task_swapRowsWithMaxAndMinValues(testMatrix);
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
void task_sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMaxElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    1, 56, 52,
                    32, 4, 2
            }, 3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    32, 4, 2,
                    1, 56, 52
            }, 3, 3
    );

    task_sortRowsByMaxElement(testMatrix);
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
void task_sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMinElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14, 5,
                    1, 56, 52, 6,
                    32, 4, 2, 10
            }, 3, 4);

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 14, 7, 5,
                    1, 52, 56, 6,
                    32, 2, 4, 10
            }, 3, 4
    );

    task_sortColsByMinElement(testMatrix);
    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

/**Если данная квадратная матрица 𝐴 симметрична, то заменить 𝐴 ее квадратом*/
void task_getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    *m = multiplyMatrices(*m, *m);
}

void test_getSquareOfMatrixIfSymmetric() {
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

    task_getSquareOfMatrixIfSymmetric(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

long long getSum(int *row, int nCols) {
    long long sum = 0;
    for (int i = 0; i < nCols; ++i) {
        sum += row[i];
    }
    return sum;
}

bool isUniqueArray(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

void task_transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long *sum = malloc(sizeof(long long) * m.nRows);

    for (int i = 0; i < m.nRows; ++i) {
        sum[i] = getSum(m.values[i], m.nCols);
    }

    if (!isUniqueArray(sum, m.nRows))
        return;

    transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    0, 7, 14,
                    1, 56, 52,
                    32, 4, 2
            }, 3, 3
    );

    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    0, 1, 32,
                    7, 56, 4,
                    14, 52, 2

            }, 3, 3
    );

    task_transposeIfMatrixHasNotEqualSumOfRows(testMatrix);
    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void matrix_test() {
    test_swapRowsWithMaxAndMinValues();
    test_sortRowsByMaxElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
}