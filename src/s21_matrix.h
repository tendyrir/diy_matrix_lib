#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdio.h>   //  printf, fprintf
#include <stdlib.h>  //  calloc, free
#include <math.h>

/* Resulting codes for matrix comparison */
#define SUCCESS 1
#define FAILURE 0

/* Resulting codes for matrix operations 

- 0 - OK
- 1 - Ошибка, некорректная матрица   
- 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)

*/
#define OK 0
#define ERR_1 1
#define ERR_2 2


/* Matrix structure */
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

/* Library functions */
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

double get_rand(double min, double max);

#endif  // SRC_S21_MATRIX_H_
