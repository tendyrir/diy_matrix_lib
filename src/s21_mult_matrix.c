#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = OK;
    if ((A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) ||
        (B == NULL || B->matrix == NULL || B->columns <= 0 || B->rows <= 0)) {
        error = ERR_1;
    } else if (!((A->columns == B->rows) || (B->columns == A->rows))) {
        error = ERR_2;
    } else {
        s21_create_matrix(A->rows, B->columns, result);
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j< result->columns; j++) {
                for (int k = 0; k < B->rows; k++) {
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    }
    return error;
}
