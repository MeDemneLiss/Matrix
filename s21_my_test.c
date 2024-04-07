/*

#include "s21_matrix.h"
#include "stdio.h"

int main() {
  //  int check = 0;
  // matrix_t A, B, res;
  //  s21_create_matrix(14, 14, &A);
  //  s21_create_matrix(8, 14, &B);
  // int code = s21_mult_matrix(&A, &B, &res);
  //  s21_remove_matrix(&A);
  // s21_remove_matrix(&B);
  //  for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     printf("%f ", (res.matrix)[i][j]);
  //   }
  //   printf("\n");
  // }
  // s21_remove_matrix(&res);

  int check = 0;
  matrix_t A, res;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 3;
  int code = s21_inverse_matrix(&A, &res);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
 */
