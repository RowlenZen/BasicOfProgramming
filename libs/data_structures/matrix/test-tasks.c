
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

void matrix_test() {
    swapRowsWithMaxAndMinValues_test();
}