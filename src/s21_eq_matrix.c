#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int error = SUCCESS;

    if ((A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) ||
        (B == NULL || B->matrix == NULL || B->columns <= 0 || B->rows <= 0)) {
        error = ERR_1;
    } else {
        if (A->rows == B->rows && A->columns == B->columns) {
            for (int i = 0; i < A->rows; i++) {
                for (int j  = 0; j < A->columns; j++) {
                    if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
                        return error = FAILURE;
                    }
                }
            }
        }
    }
    return error;
}
