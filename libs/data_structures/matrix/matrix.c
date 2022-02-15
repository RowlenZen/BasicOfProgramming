#include <malloc.h>
#include <stdlib.h>
#include "matrix.h"
#include "../../algorithms/array/array.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        free(m.values[i]);
    }
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i) {
        freeMemMatrix(ms[i]);
    };
    free(ms);
}

void inputMatrix(matrix m) {
    printf("Input matrix %d rows to %d cols.", m.nRows, m.nCols);
    for (int i = 0; i < m.nRows; ++i) {
        inputArray_(m.values[i], m.nCols);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    printf("Input array of matrices size  %d.", nMatrices);
    for (int i = 0; i < nMatrices; ++i) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    printf("Matrix:");
    for (int i = 0; i < m.nRows; ++i) {
        printf("       ");
        outputArray_(m.values[i], m.nCols);
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    printf("All matrices in array size %d:", nMatrices);
    for (int i = 0; i < nMatrices; ++i) {
        printf("  ");
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaRowValues = malloc(m.nRows * sizeof(int));
    for (int i = 0; i < m.nRows; ++i) {
        criteriaRowValues[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 1; i < m.nRows; i++) {
        int currentValue = criteriaRowValues[i];
        while (i > 0 && criteriaRowValues[i - 1] > currentValue) {
            swapRows(m, i, i - 1);
            int temp = criteriaRowValues[i];
            criteriaRowValues[i] = criteriaRowValues[i - 1];
            criteriaRowValues[i - 1] = temp;
            i--;
        }
    }

    free(criteriaRowValues);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {

    int *criteriaColumnValues = malloc(m.nCols * sizeof(int));
    int *currentColumn = malloc(m.nRows * sizeof(int));

    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j) {
            currentColumn[j] = m.values[j][i];
        }
        criteriaColumnValues[i] = criteria(currentColumn, m.nRows);
    }

    free(currentColumn);

    for (int i = 1; i < m.nRows; i++) {
        while (i > 0 && criteriaColumnValues[i - 1] > criteriaColumnValues[i]) {
            swapColumns(m, i, i - 1);
            int temp = criteriaColumnValues[i];
            criteriaColumnValues[i] = criteriaColumnValues[i - 1];
            criteriaColumnValues[i - 1] = temp;
            i--;
        }
    }

    free(criteriaColumnValues);
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int row = 0; row < m1.nRows; ++row) {
        for (int column = 0; column < m1.nCols; ++column) {
            if (m1.values[row][column] != m2.values[row][column])
                return false;
        }
    }

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int row = 0; row < m.nRows; ++row) {
        for (int column = 0; column < m.nCols; ++column) {
            if (row == column && m.values[row][column] != 1 ||
                row != column && m.values[row][column] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            if (m.values[i][j] != m.values[j][i])
                return false;
        }
    }

    return true;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m)) {
        fprintf(stderr, "%s", "Matrix isn't square");
        exit(1);
    }

    for (int i = 0; i < m.nRows; ++i)
        for (int j = i; j < m.nCols; ++j)
            if (i != j) {
                int temp = m.values[i][j];
                m.values[i][j] = m.values[j][i];
                m.values[j][i] = temp;
            }
}

position getMinValuePos(matrix m) {
    position minValuePos = {0, 0};
    int min = m.values[0][0];

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int currentEl = m.values[i][j];
            if (currentEl < min) {
                min = currentEl;
                minValuePos = (position) {i, j};
            }
        }
    }

    return minValuePos;
}

position getMaxValuePos(matrix m) {
    position maxValuePos = {0, 0};
    int max = m.values[0][0];

    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            int currentEl = m.values[i][j];
            if (currentEl > max) {
                max = currentEl;
                maxValuePos = (position) {i, j};
            }
        }
    }

    return maxValuePos;
}

matrix createMatrixFromArray(const int *srcArray, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            m.values[i][j] = srcArray[k];
            k++;
        }
    }

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *ms, int nMatrices, int nRows, int nCols) {
    matrix *matrices = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int i = 0; i < nMatrices; ++i)
        for (int j = 0; j < nRows; ++j)
            for (int k = 0; k < nCols; ++k) {
                matrices[i].values[j][k] = ms[l];
                l++;
            }

    return matrices;
}
