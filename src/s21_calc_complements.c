#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err = OK;
  if (A != NULL && result != NULL && A->rows > 0 && A->columns > 0) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
        matrix_t minor = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            int c1 = 0;
            int c2 = 0;
            for (int x = 0; x < A->rows; x++) {
              for (int y = 0; y < A->columns; y++) {
                if (x != i && y != j) {
                  minor.matrix[c1][c2] = A->matrix[x][y];
                  c2++;
                  if (c2 == A->rows - 1) {
                    c2 = 0;
                    c1++;
                  }
                }
              }
            }
            s21_determinant(&minor, &(result->matrix[i][j]));
            if (((i + j) % 2)) {
              result->matrix[i][j] *= -1;
            }
          }
        }
        s21_remove_matrix(&minor);
    } else {
      err = ERR_2;
    }
  } else {
    err = ERR_1;
  }
  return err;
}
