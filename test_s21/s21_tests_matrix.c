#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_secondary_functions.h"

//
//

//    create run
START_TEST(test_create_1) {
  int check = 0;
  matrix_t A;
  int code = s21_create_matrix(1, 1, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_create_2) {
  int check = 1;
  int code = s21_create_matrix(1, 1, NULL);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_create_3) {
  int check = 2;
  matrix_t A;
  int code = s21_create_matrix(-1, 21, &A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_create_4) {
  int check = 2;
  matrix_t A;
  int code = s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_create_5) {
  int check = 0;
  matrix_t A;
  int code = s21_create_matrix(1, 13, &A);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST
//    create end
//    eq run
START_TEST(test_eq_matrix_1) {
  int check = 0;
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_eq_matrix_2) {
  int check = 0;
  matrix_t A, B;
  s21_create_matrix(1, 14, &A);
  s21_create_matrix(1000, 2, &B);
  int code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_eq_matrix_3) {
  int check = 0;
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 199.99999657;
  B.matrix[1][0] = 31.0;
  B.matrix[1][1] = 1.8;
  int code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_eq_matrix_4) {
  int check = 1;
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 199.99999653;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 1.8;
  int code = s21_eq_matrix(&A, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_eq_matrix_error_1) {
  int check = 0;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_eq_matrix(&A, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_eq_matrix_error_2) {
  int check = 0;
  matrix_t A, B;
  s21_create_matrix(10, 15, &A);
  s21_create_matrix(10, 15, &B);
  int code = s21_eq_matrix(NULL, &B);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST
//    eq end
//    sum run
START_TEST(test_sum_1) {
  int check = 2;
  matrix_t A, B, res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sum_2) {
  int check = 2;
  matrix_t A, B, res;
  s21_create_matrix(1, 14, &A);
  s21_create_matrix(1000, 2, &B);
  int code = s21_sum_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sum_3) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 1.0;
  B.matrix[1][0] = 31.0;
  B.matrix[1][1] = 1.8;
  int code = s21_sum_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(2.0, res.matrix[0][0]);
  ck_assert_double_eq(200.99999651, res.matrix[0][1]);
  ck_assert_double_eq(34.0, res.matrix[1][0]);
  ck_assert_double_eq(3.6, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_4) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[1][0] = 31.0;
  B.matrix[1][1] = -1.8;
  int code = s21_sum_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(2.0, res.matrix[0][0]);
  ck_assert_double_eq(198.99999651, res.matrix[0][1]);
  ck_assert_double_eq(34.0, res.matrix[1][0]);
  ck_assert_double_eq(0, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sum_error_1) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_sum_matrix(&A, NULL, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sum_error_2) {
  int check = 1;
  matrix_t B, res;
  s21_create_matrix(10, 15, &B);
  int code = s21_sum_matrix(NULL, &B, &res);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST
//    sum end
//    sub run
START_TEST(test_sub_1) {
  int check = 2;
  matrix_t A, B, res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  int code = s21_sub_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sub_2) {
  int check = 2;
  matrix_t A, B, res;
  s21_create_matrix(1, 14, &A);
  s21_create_matrix(1000, 2, &B);
  int code = s21_sub_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sub_3) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 1.0;
  B.matrix[1][0] = 31.0;
  B.matrix[1][1] = 1.8;
  int code = s21_sub_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(0.0, res.matrix[0][0]);
  ck_assert_double_eq(198.99999651, res.matrix[0][1]);
  ck_assert_double_eq(-34.0, res.matrix[1][0]);
  ck_assert_double_eq(0.0, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_4) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.99999651;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 1.8;
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[1][0] = 31.0;
  B.matrix[1][1] = -1.8;
  int code = s21_sub_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(0.0, res.matrix[0][0]);
  ck_assert_double_eq(200.99999651, res.matrix[0][1]);
  ck_assert_double_eq(-28.0, res.matrix[1][0]);
  ck_assert_double_eq(3.6, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_sub_error_1) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_sub_matrix(&A, NULL, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_sub_error_2) {
  int check = 1;
  matrix_t B, res;
  s21_create_matrix(10, 15, &B);
  int code = s21_sub_matrix(NULL, &B, &res);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST
//    sub end
//    mul num run
START_TEST(test_mul_n_1) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(1, 1, &A);
  int code = s21_mult_number(&A, 10, &res);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_mul_n_2) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 199.10;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = 1.8;
  int code = s21_mult_number(&A, 2, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(2.0, res.matrix[0][0]);
  ck_assert_double_eq(398.20, res.matrix[0][1]);
  ck_assert_double_eq(-6.0, res.matrix[1][0]);
  ck_assert_double_eq(3.6, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mul_n_3) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 11.0;
  A.matrix[0][1] = 199.10;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = 1.8;
  int code = s21_mult_number(&A, -10, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(-110.0, res.matrix[0][0]);
  ck_assert_double_eq(-1991.0, res.matrix[0][1]);
  ck_assert_double_eq(30.0, res.matrix[1][0]);
  ck_assert_double_eq(-18.0, res.matrix[1][1]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mul_n_error_1) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_mult_number(&A, 1000, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_mul_n_error_2) {
  int check = 1;
  matrix_t res;
  int code = s21_mult_number(NULL, -2387478.23499032, &res);
  ck_assert_int_eq(code, check);
}
END_TEST
//    mul num end
//    mul m run
START_TEST(test_mul_m_1) {
  int check = 2;
  matrix_t A, B, res;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 1, &B);
  int code = s21_mult_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_mul_m_2) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(14, 16, &A);
  s21_create_matrix(16, 1, &B);
  int code = s21_mult_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_mul_m_3) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(2, 3, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 4;
  int code = s21_mult_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(9, res.matrix[0][0]);
  ck_assert_double_eq(11, res.matrix[0][1]);
  ck_assert_double_eq(17, res.matrix[0][2]);
  ck_assert_double_eq(12, res.matrix[1][0]);
  ck_assert_double_eq(13, res.matrix[1][1]);
  ck_assert_double_eq(22, res.matrix[1][2]);
  ck_assert_double_eq(15, res.matrix[2][0]);
  ck_assert_double_eq(15, res.matrix[2][1]);
  ck_assert_double_eq(27, res.matrix[2][2]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mul_m_4) {
  int check = 0;
  matrix_t A, B, res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_create_matrix(3, 3, &B);
  B.matrix[0][0] = 5;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 3;
  B.matrix[1][2] = 2;
  B.matrix[2][0] = 2;
  B.matrix[2][1] = 1;
  B.matrix[2][2] = 5;
  int code = s21_mult_matrix(&A, &B, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_double_eq(27, res.matrix[0][0]);
  ck_assert_double_eq(17, res.matrix[0][1]);
  ck_assert_double_eq(24, res.matrix[0][2]);
  ck_assert_double_eq(24, res.matrix[1][0]);
  ck_assert_double_eq(12, res.matrix[1][1]);
  ck_assert_double_eq(29, res.matrix[1][2]);
  ck_assert_double_eq(25, res.matrix[2][0]);
  ck_assert_double_eq(13, res.matrix[2][1]);
  ck_assert_double_eq(12, res.matrix[2][2]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_mul_m_error_1) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_mult_matrix(&A, NULL, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_mul_m_error_2) {
  int check = 1;
  matrix_t B, res;
  s21_create_matrix(10, 15, &B);
  int code = s21_mult_matrix(NULL, &B, &res);
  s21_remove_matrix(&B);
  ck_assert_int_eq(code, check);
}
END_TEST
//    mul m end
//    transpose run
START_TEST(test_trans_1) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(1, 100, &A);
  int code = s21_transpose(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_trans_2) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  int code = s21_transpose(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(1, res.matrix[0][0]);
  ck_assert_double_eq(2, res.matrix[0][1]);
  ck_assert_double_eq(3, res.matrix[0][2]);
  ck_assert_double_eq(4, res.matrix[1][0]);
  ck_assert_double_eq(5, res.matrix[1][1]);
  ck_assert_double_eq(6, res.matrix[1][2]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_trans_3) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_transpose(&A, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_trans_4) {
  int check = 1;
  matrix_t res;
  int code = s21_transpose(NULL, &res);
  ck_assert_int_eq(code, check);
}
END_TEST
//    transpose end
//    calc run

START_TEST(test_calc_1) {
  int check = 2;
  matrix_t A, res;
  s21_create_matrix(14, 10, &A);
  int code = s21_calc_complements(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_calc_2) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  int code = s21_calc_complements(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(0, res.matrix[0][0]);
  ck_assert_double_eq(10, res.matrix[0][1]);
  ck_assert_double_eq(-20, res.matrix[0][2]);
  ck_assert_double_eq(4, res.matrix[1][0]);
  ck_assert_double_eq(-14, res.matrix[1][1]);
  ck_assert_double_eq(8, res.matrix[1][2]);
  ck_assert_double_eq(-8, res.matrix[2][0]);
  ck_assert_double_eq(-2, res.matrix[2][1]);
  ck_assert_double_eq(4, res.matrix[2][2]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_calc_3) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1;
  int code = s21_calc_complements(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(1, res.matrix[0][0]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_calc_4) {
  int check = 1;
  matrix_t res;
  int code = s21_calc_complements(NULL, &res);
  ck_assert_int_eq(code, check);
}
END_TEST

//    calc end
//    determinant run
START_TEST(test_determ_1) {
  int check = 2;
  matrix_t A;
  double res;
  s21_create_matrix(14, 10, &A);
  int code = s21_determinant(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_determ_2) {
  int check = 0;
  matrix_t A;
  double res;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 3;
  A.matrix[0][1] = 8;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 6;
  int code = s21_determinant(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(-14, res);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_determ_3) {
  int check = 0;
  matrix_t A;
  double res;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 23;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 0.1;
  A.matrix[1][2] = 12;
  A.matrix[1][3] = 6;
  A.matrix[2][0] = 0.2;
  A.matrix[2][1] = 121;
  A.matrix[2][2] = 34;
  A.matrix[2][3] = 234;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 43.1;
  A.matrix[3][2] = 2;
  A.matrix[3][3] = 1;
  int code = s21_determinant(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(-546191.5, res);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_determ_4) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_determinant(&A, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_determ_5) {
  int check = 1;
  double res;
  int code = s21_determinant(NULL, &res);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_determ_6) {
  int check = 0;
  matrix_t A;
  double res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 3;
  int code = s21_determinant(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(3, res);
  ck_assert_int_eq(code, check);
}
END_TEST
//    determinant end
//    inverse run

START_TEST(test_inverse_1) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  int code = s21_inverse_matrix(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(1, res.matrix[0][0]);
  ck_assert_double_eq(-1, res.matrix[0][1]);
  ck_assert_double_eq(1, res.matrix[0][2]);
  ck_assert_double_eq(-38, res.matrix[1][0]);
  ck_assert_double_eq(41, res.matrix[1][1]);
  ck_assert_double_eq(-34, res.matrix[1][2]);
  ck_assert_double_eq(27, res.matrix[2][0]);
  ck_assert_double_eq(-29, res.matrix[2][1]);
  ck_assert_double_eq(24, res.matrix[2][2]);
  ck_assert_int_eq(code, check);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(test_inverse_2) {
  int check = 0;
  matrix_t A, res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 3;
  int code = s21_inverse_matrix(&A, &res);
  s21_remove_matrix(&A);
  ck_assert_double_eq(1, res.matrix[0][0]);
  s21_remove_matrix(&res);
  ck_assert_int_eq(code, check);
}
END_TEST

START_TEST(test_inverse_3) {
  int check = 1;
  matrix_t A;
  s21_create_matrix(10, 15, &A);
  int code = s21_inverse_matrix(&A, NULL);
  s21_remove_matrix(&A);
  ck_assert_int_eq(code, check);
}
END_TEST
//    inverse end

int main(void) {
  Suite *suite = suite_create("s21_matrix_utils");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_create_1);
  tcase_add_test(tc_core, test_create_2);
  tcase_add_test(tc_core, test_create_3);
  tcase_add_test(tc_core, test_create_4);
  tcase_add_test(tc_core, test_create_5);
  tcase_add_test(tc_core, test_eq_matrix_1);
  tcase_add_test(tc_core, test_eq_matrix_2);
  tcase_add_test(tc_core, test_eq_matrix_3);
  tcase_add_test(tc_core, test_eq_matrix_4);
  tcase_add_test(tc_core, test_eq_matrix_error_1);
  tcase_add_test(tc_core, test_eq_matrix_error_2);
  tcase_add_test(tc_core, test_sum_1);
  tcase_add_test(tc_core, test_sum_2);
  tcase_add_test(tc_core, test_sum_3);
  tcase_add_test(tc_core, test_sum_4);
  tcase_add_test(tc_core, test_sum_error_1);
  tcase_add_test(tc_core, test_sum_error_2);
  tcase_add_test(tc_core, test_sub_1);
  tcase_add_test(tc_core, test_sub_2);
  tcase_add_test(tc_core, test_sub_3);
  tcase_add_test(tc_core, test_sub_4);
  tcase_add_test(tc_core, test_sub_error_1);
  tcase_add_test(tc_core, test_sub_error_2);
  tcase_add_test(tc_core, test_mul_n_1);
  tcase_add_test(tc_core, test_mul_n_2);
  tcase_add_test(tc_core, test_mul_n_3);
  tcase_add_test(tc_core, test_mul_n_error_1);
  tcase_add_test(tc_core, test_mul_n_error_2);
  tcase_add_test(tc_core, test_mul_m_1);
  tcase_add_test(tc_core, test_mul_m_2);
  tcase_add_test(tc_core, test_mul_m_3);
  tcase_add_test(tc_core, test_mul_m_4);
  tcase_add_test(tc_core, test_mul_m_error_1);
  tcase_add_test(tc_core, test_mul_m_error_2);
  tcase_add_test(tc_core, test_trans_1);
  tcase_add_test(tc_core, test_trans_2);
  tcase_add_test(tc_core, test_trans_3);
  tcase_add_test(tc_core, test_trans_4);
  tcase_add_test(tc_core, test_determ_1);
  tcase_add_test(tc_core, test_determ_2);
  tcase_add_test(tc_core, test_determ_3);
  tcase_add_test(tc_core, test_determ_4);
  tcase_add_test(tc_core, test_determ_5);
  tcase_add_test(tc_core, test_determ_6);
  tcase_add_test(tc_core, test_calc_1);
  tcase_add_test(tc_core, test_calc_2);
  tcase_add_test(tc_core, test_calc_3);
  tcase_add_test(tc_core, test_calc_4);
  tcase_add_test(tc_core, test_inverse_1);
  tcase_add_test(tc_core, test_inverse_2);
  tcase_add_test(tc_core, test_inverse_3);

  //////

  suite_add_tcase(suite, tc_core);

  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_VERBOSE);

  int failures = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failures == 0) ? 0 : 1;
}
