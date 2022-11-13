#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
    if (A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0) {
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
            A->matrix[i] = NULL;
        }
        free(A->matrix);
        A->matrix = NULL;
        A->columns = 0;
        A->rows = 0;
    }
}
