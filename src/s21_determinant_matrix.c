#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int err = OK;
  if (A != NULL && result != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      *result = 0;
      if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        if (A->rows == 2) {
          *result = A->matrix[0][0] * A->matrix[1][1] -
                    A->matrix[0][1] * A->matrix[1][0];
        } else {
          matrix_t B = {0};
          s21_calc_complements(A, &B);
          for (int i = 0; i < A->columns; i++) {
            *result += A->matrix[0][i] * B.matrix[0][i];
          }
          s21_remove_matrix(&B);
        }
      }
    } else {
      err = ERR_2;
    }
  } else {
    err = ERR_1;
  }
  return err;
}
