#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (A != NULL && result != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      double determinant = 0;
      int res = s21_determinant(A, &determinant);
      s21_create_matrix(A->rows, A->columns, result);
      if (fabs(determinant) > 1e-7 || res) {
        if (A->rows == 1) {
          result->matrix[0][0] = 1.0 / A->matrix[0][0];
        } else {
          matrix_t temp_matrix = {0};
          s21_calc_complements(A, &temp_matrix);
          matrix_t temp_matrix_transpose = {0};
          s21_transpose(&temp_matrix, &temp_matrix_transpose);
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              result->matrix[i][j] =
                  temp_matrix_transpose.matrix[i][j] / determinant;
            }
          }
          s21_remove_matrix(&temp_matrix);
          s21_remove_matrix(&temp_matrix_transpose);
        }
      } else {
        err = ERR_2;
      }
    } else {
      err = ERR_2;
    }
  } else {
    err = ERR_1;
  }
  return err;
}
