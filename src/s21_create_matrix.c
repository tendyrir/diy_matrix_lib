#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int error = OK;

    if (result == NULL || rows <= 0 || columns <= 0) {
        error = ERR_1;

    } else {
        result->rows = rows;
        result->columns = columns;
        result->matrix = calloc(result->rows, sizeof(double*));
        if (result->matrix == NULL) {
            error = ERR_1;
        } else  {
            for (int i = 0; i < result->rows; i++) {
                result->matrix[i] = calloc(result->columns, sizeof(double));
                if (result->matrix[i] == NULL) {
                    error = ERR_1;
                }
            }
        }
    }
    return error;
}

