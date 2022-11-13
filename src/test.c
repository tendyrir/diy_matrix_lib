#include "s21_matrix.h"
#include <check.h>


START_TEST(create_remove_matrix) {
    matrix_t a;
    ck_assert_uint_eq(s21_create_matrix(0, 15, &a), 1);

    ck_assert_uint_eq(s21_create_matrix(15, 15, &a), 0);
    s21_remove_matrix(&a);
    ck_assert_uint_eq(s21_create_matrix(15, -4, &a), 1);

    ck_assert_uint_eq(s21_create_matrix(-7, 0, &a), 1);

    ck_assert_uint_eq(s21_create_matrix(7, 3, &a), 0);
    s21_remove_matrix(&a);
}
END_TEST


START_TEST(add_test) {
  matrix_t a, b, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  d.matrix[0][0] = 4;
  d.matrix[0][1] = 4;
  d.matrix[0][2] = 4;
  d.matrix[1][0] = 4;
  d.matrix[1][1] = 4;
  d.matrix[1][2] = 4;
  d.matrix[2][0] = 4;
  d.matrix[2][1] = 4;
  d.matrix[2][2] = 4;
  int res = s21_sum_matrix(&a, &b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(sub_test) {
  matrix_t a, b, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &b);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  d.matrix[0][0] = -2;
  d.matrix[0][1] = 0;
  d.matrix[0][2] = 2;
  d.matrix[1][0] = -2;
  d.matrix[1][1] = 0;
  d.matrix[1][2] = 2;
  d.matrix[2][0] = -2;
  d.matrix[2][1] = 0;
  d.matrix[2][2] = 2;
  int res = s21_sub_matrix(&a, &b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(mul_num) {
  matrix_t a, c, d;
  double b = 2;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  d.matrix[0][0] = 2;
  d.matrix[0][1] = 4;
  d.matrix[0][2] = 6;
  d.matrix[1][0] = 2;
  d.matrix[1][1] = 4;
  d.matrix[1][2] = 6;
  d.matrix[2][0] = 2;
  d.matrix[2][1] = 4;
  d.matrix[2][2] = 6;
  int res = s21_mult_number(&a, b, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(mul_matrix) {
  matrix_t a, b, c, d;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 4, &b);
  s21_create_matrix(2, 4, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  b.matrix[0][0] = 3;
  b.matrix[0][1] = 2;
  b.matrix[0][2] = 1;
  b.matrix[0][3] = 1;
  b.matrix[1][0] = 3;
  b.matrix[1][1] = 2;
  b.matrix[1][2] = 1;
  b.matrix[1][3] = 1;
  b.matrix[2][0] = 3;
  b.matrix[2][1] = 2;
  b.matrix[2][2] = 1;
  b.matrix[2][3] = 1;
  d.matrix[0][0] = 18;
  d.matrix[0][1] = 12;
  d.matrix[0][2] = 6;
  d.matrix[0][3] = 6;
  d.matrix[1][0] = 18;
  d.matrix[1][1] = 12;
  d.matrix[1][2] = 6;
  d.matrix[1][3] = 6;

  int res = s21_mult_matrix(&a, &b, &c);

  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(trans_test) {
  matrix_t a, c, d;
  s21_create_matrix(2, 3, &a);
  s21_create_matrix(3, 2, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 2;
  a.matrix[1][2] = 3;
  d.matrix[0][0] = 1;
  d.matrix[0][1] = 1;
  d.matrix[1][0] = 2;
  d.matrix[1][1] = 2;
  d.matrix[2][0] = 3;
  d.matrix[2][1] = 3;
  int res = s21_transpose(&a, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(inv_test) {
  matrix_t a, c, d;
  s21_create_matrix(3, 3, &a);
  s21_create_matrix(3, 3, &d);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[1][0] = 1;
  a.matrix[1][1] = 5;
  a.matrix[1][2] = 3;
  a.matrix[2][0] = 7;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  d.matrix[0][0] = -1.0 / 6;
  d.matrix[0][1] = 0;
  d.matrix[0][2] = 1.0 / 6;
  d.matrix[1][0] = -1.0 / 3;
  d.matrix[1][1] = 1.0 / 3;
  d.matrix[1][2] = 0;
  d.matrix[2][0] = 11.0 / 18;
  d.matrix[2][1] = -2.0 / 9;
  d.matrix[2][2] = -1.0 / 18;
  int res = s21_inverse_matrix(&a, &c);
  if (!res)
    ck_assert_int_eq(s21_eq_matrix(&c, &d), 1);
  else
    ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
  s21_remove_matrix(&d);
}
END_TEST

START_TEST(eq_test) {
  matrix_t a, c;
  s21_create_matrix(2, 2, &a);
  s21_create_matrix(2, 2, &c);
  a.matrix[0][0] = NAN;
  a.matrix[0][1] = 0;
  a.matrix[1][0] = 0;
  a.matrix[1][1] = 0;
  c.matrix[0][0] = NAN;
  c.matrix[0][1] = 1;
  c.matrix[1][0] = 0;
  c.matrix[1][1] = 0;
  int res = s21_eq_matrix(&a, &c);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&c);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_test_0) {
  matrix_t a = {0};
  double b = 0.0;
  s21_create_matrix(5, 5, &a);
  a.matrix[0][0] = 1;
  a.matrix[0][1] = 2;
  a.matrix[0][2] = 3;
  a.matrix[0][3] = 4;
  a.matrix[0][4] = 5;
  a.matrix[1][0] = 6;
  a.matrix[1][1] = 7;
  a.matrix[1][2] = 8;
  a.matrix[1][3] = 9;
  a.matrix[1][4] = -10;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  a.matrix[2][3] = 4;
  a.matrix[2][4] = 5;
  a.matrix[3][0] = 6;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 8;
  a.matrix[3][3] = 9;
  a.matrix[3][4] = -10;
  a.matrix[4][0] = 1;
  a.matrix[4][1] = 2;
  a.matrix[4][2] = 3;
  a.matrix[4][3] = 4;
  a.matrix[4][4] = 5;
  s21_determinant(&a, &b);
  ck_assert_double_eq_tol(b, 0, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(det_test_1) {
  matrix_t a = {0};
  double b = 0.0;
  s21_create_matrix(5, 5, &a);
  a.matrix[0][0] = 55;
  a.matrix[0][1] = 54;
  a.matrix[0][2] = 53;
  a.matrix[0][3] = -52;
  a.matrix[0][4] = 51;
  a.matrix[1][0] = 50;
  a.matrix[1][1] = 49;
  a.matrix[1][2] = 48;
  a.matrix[1][3] = 47;
  a.matrix[1][4] = -10;
  a.matrix[2][0] = 1;
  a.matrix[2][1] = 2;
  a.matrix[2][2] = 3;
  a.matrix[2][3] = 4;
  a.matrix[2][4] = -7;
  a.matrix[3][0] = 6;
  a.matrix[3][1] = 7;
  a.matrix[3][2] = 8;
  a.matrix[3][3] = 9;
  a.matrix[3][4] = 11;
  a.matrix[4][0] = 13;
  a.matrix[4][1] = 17;
  a.matrix[4][2] = 19;
  a.matrix[4][3] = 11;
  a.matrix[4][4] = 7;
  s21_determinant(&a, &b);
  ck_assert_double_eq_tol(b, 208624, 1e-6);
  s21_remove_matrix(&a);
}
END_TEST

START_TEST(inverse_matrix_1) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_inverse_matrix(&A, &B);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -1;
  C.matrix[0][2] = 1;
  C.matrix[1][0] = -38;
  C.matrix[1][1] = 41;
  C.matrix[1][2] = -34;
  C.matrix[2][0] = 27;
  C.matrix[2][1] = -29;
  C.matrix[2][2] = 24;
  ck_assert_int_eq(s21_eq_matrix(&B, &C), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST


START_TEST(determinant) {
    matrix_t a = {0};
    double result = 0;
    s21_create_matrix(4, 4, &a);
    double A[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
    for (int k = 0; k < 4; k++) {
        for (int g = 0; g < 4; g++) {
            a.matrix[k][g] = A[k][g];
        }
    }
    int d = s21_determinant(&a, &result);
    ck_assert_int_eq(d, 0);
    ck_assert_double_eq_tol(result, 0, 1e-6);

    s21_remove_matrix(&a);
}
END_TEST

START_TEST(determinant_error) {
    matrix_t a = {0};
    double result;
    int k = s21_determinant(NULL, &result);
    ck_assert_int_eq(k, 1);
    s21_create_matrix(4, 3, &a);
    k = s21_determinant(&a, NULL);
    ck_assert_int_eq(k, 1);
    k = s21_determinant(&a, &result);
    ck_assert_int_eq(k, 2);
    s21_remove_matrix(&a);
}
END_TEST


START_TEST(determinant_3) {
    double determinant = 0;
    matrix_t matrix = {NULL, 0, 0};
    matrix_t matrix2 = {NULL, 0, 0};
    s21_create_matrix(4, 4, &matrix);
    s21_create_matrix(1, 1, &matrix2);
    matrix.matrix[0][0] = 9;
    matrix.matrix[0][1] = 2;
    matrix.matrix[0][2] = 2;
    matrix.matrix[0][3] = 4;
    matrix.matrix[1][0] = 3;
    matrix.matrix[1][1] = 4;
    matrix.matrix[1][2] = 4;
    matrix.matrix[1][3] = 4;
    matrix.matrix[2][0] = 4;
    matrix.matrix[2][1] = 4;
    matrix.matrix[2][2] = 9;
    matrix.matrix[2][3] = 9;
    matrix.matrix[3][0] = 1;
    matrix.matrix[3][1] = 1;
    matrix.matrix[3][2] = 5;
    matrix.matrix[3][3] = 1;
    int result = s21_determinant(&matrix, &determinant);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(determinant, -578);
    matrix2.matrix[0][0] = 10;
    result = s21_determinant(&matrix2, &determinant);
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(determinant, 10);
    s21_remove_matrix(&matrix);
    s21_remove_matrix(&matrix2);
}

END_TEST


START_TEST(determinant1) {
    const int size = 5;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            m.matrix[i][j] = j;
    double res = 0;
    int code = s21_determinant(&m, &res);
    ck_assert_double_eq_tol(res, 0, 1e-6);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant2) {
    const int size = 4;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            m.matrix[i][j] = j + i;

    double res = 0;
    int code = s21_determinant(&m, &res);
    ck_assert_double_eq_tol(res, 0, 1e-6);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant3) {
    const int size = 5;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);
    m.matrix[0][1] = 6;
    m.matrix[0][2] = -2;
    m.matrix[0][3] = -1;
    m.matrix[0][4] = 5;
    m.matrix[1][3] = -9;
    m.matrix[1][4] = -7;
    m.matrix[2][1] = 15;
    m.matrix[2][2] = 35;
    m.matrix[3][1] = -1;
    m.matrix[3][2] = -11;
    m.matrix[3][3] = -2;
    m.matrix[3][4] = 1;
    m.matrix[4][0] = -2;
    m.matrix[4][1] = -2;
    m.matrix[4][2] = 3;
    m.matrix[4][4] = -2;

    double res = 0;
    int code = s21_determinant(&m, &res);
    ck_assert_double_eq_tol(res, 2480, 1e-6);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant4) {
    const int size = 3;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 3;
    m.matrix[0][2] = 1;
    m.matrix[1][0] = 7;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 1;
    m.matrix[2][0] = 9;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = 1;

    double res = 0;
    int code = s21_determinant(&m, &res);
    ck_assert_double_eq_tol(res, -32, 1e-6);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant5) {
    const int size = 2;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);
    m.matrix[0][0] = -5;
    m.matrix[0][1] = -4;
    m.matrix[1][0] = -2;
    m.matrix[1][1] = -3;

    double res = 0;
    int code = s21_determinant(&m, &res);
    ck_assert_double_eq_tol(res, 7, 1e-6);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
}
END_TEST

START_TEST(s21_inverse_2) {
    matrix_t A, B, C;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &C);
    C.matrix[0][0] = 44300.0 / 367429.0;
    C.matrix[0][1] = -236300.0 / 367429.0;
    C.matrix[0][2] = 200360.0 / 367429.0;
    C.matrix[1][0] = 20600.0 / 367429.0;
    C.matrix[1][1] = 56000.0 / 367429.0;
    C.matrix[1][2] = -156483.0 / 367429.0;
    C.matrix[2][0] = 30900.0 / 367429.0;
    C.matrix[2][1] = 84000.0 / 367429.0;
    C.matrix[2][2] = -51010.0 / 367429.0;
    A.matrix[0][0] = 2.8;
    A.matrix[0][1] = 1.3;
    A.matrix[0][2] = 7.01;
    A.matrix[1][0] = -1.03;
    A.matrix[1][1] = -2.3;
    A.matrix[1][2] = 3.01;
    A.matrix[2][0] = 0;
    A.matrix[2][1] = -3;
    A.matrix[2][2] = 2;
    s21_inverse_matrix(&A, &B);
    int res = s21_eq_matrix(&B, &C);
    ck_assert_int_eq(res, 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}

END_TEST

START_TEST(s21_inverse_1) {
    matrix_t A, C;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &C);
    C.matrix[0][0] = 1.0;
    C.matrix[0][1] = -1.0;
    C.matrix[0][2] = 1.0;
    C.matrix[1][0] = -38.0;
    C.matrix[1][1] = 41.0;
    C.matrix[1][2] = -34.0;
    C.matrix[2][0] = 27.0;
    C.matrix[2][1] = -29.0;
    C.matrix[2][2] = 24.0;
    A.matrix[0][0] = 2.0;
    A.matrix[0][1] = 5.0;
    A.matrix[0][2] = 7.0;
    A.matrix[1][0] = 6.0;
    A.matrix[1][1] = 3.0;
    A.matrix[1][2] = 4.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = -2.0;
    A.matrix[2][2] = -3.0;
    matrix_t B;
    s21_inverse_matrix(&A, &B);
    int res = s21_eq_matrix(&B, &C);
    ck_assert_int_eq(res, 1);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
    matrix_t m = {0};
    matrix_t result = {0};
    int codec = s21_create_matrix(1, 1, &m);
    if (!codec) {
        m.matrix[0][0] = 1431.12312331;
        int code = s21_inverse_matrix(&m, &result);
        ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
        ck_assert_int_eq(code, OK);
        s21_remove_matrix(&m);
        s21_remove_matrix(&result);
    }
}
END_TEST

START_TEST(test_zero_det) {
    matrix_t m = {0};
    matrix_t result = {0};
    int codec = s21_create_matrix(1, 1, &m);
    if (!codec) {
        int code = s21_inverse_matrix(&m, &result);
        ck_assert_int_eq(code, ERR_2);
        s21_remove_matrix(&m);
        s21_remove_matrix(&result);
    }
}
END_TEST

START_TEST(test_incorrect) {
    matrix_t m = {0};
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, ERR_1);
    s21_remove_matrix(&m);
}
END_TEST

START_TEST(test_not_sqare) {
    matrix_t m = {0};
    matrix_t result = {0};
    int codec = s21_create_matrix(1, 4, &m);
    if (!codec) {
        int code = s21_inverse_matrix(&m, &result);
        ck_assert_int_eq(code, ERR_2);
        s21_remove_matrix(&m);
    }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, create_remove_matrix);
  tcase_add_test(tc1_1, add_test);
  tcase_add_test(tc1_1, sub_test);
  tcase_add_test(tc1_1, mul_num);
  tcase_add_test(tc1_1, mul_matrix);
  tcase_add_test(tc1_1, trans_test);
  tcase_add_test(tc1_1, inv_test);
  tcase_add_test(tc1_1, eq_test);
  tcase_add_test(tc1_1, det_test_0);
  tcase_add_test(tc1_1, det_test_1);
  tcase_add_test(tc1_1, inverse_matrix_1);
  tcase_add_test(tc1_1, determinant);
  tcase_add_test(tc1_1, determinant_3);
  tcase_add_test(tc1_1, determinant_error);
  tcase_add_test(tc1_1, determinant1);
  tcase_add_test(tc1_1, determinant2);
  tcase_add_test(tc1_1, determinant3);
  tcase_add_test(tc1_1, determinant4);
  tcase_add_test(tc1_1, determinant5);

  tcase_add_test(tc1_1, s21_inverse_1);
  tcase_add_test(tc1_1, s21_inverse_2);

  tcase_add_test(tc1_1, test_not_sqare);
  tcase_add_test(tc1_1, test_zero_det);
  tcase_add_test(tc1_1, test_incorrect);
  tcase_add_test(tc1_1, test_one_by_one);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
