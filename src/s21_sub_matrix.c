#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int error = OK;
    if ((A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0)
        || (B == NULL || B->matrix == NULL || B->columns <= 0 || B->rows <= 0)) {
        error = ERR_1;
    } else if (!(A->rows == B->rows && A->columns == B->columns)) {
        error = ERR_2;
    } else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; i++) {
            for (int j  = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
            }
        }
    }
    return error;
}
