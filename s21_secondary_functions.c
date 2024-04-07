#include "s21_secondary_functions.h"

int s21_sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result, int x) {
  int error = ERROR_RESULT_OK;
  if (!(A) || !(B) || !(result) ||
      ((A->columns < 1) || (A->rows < 1) || (B->rows < 1) ||
       (B->columns < 1))) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if ((A->columns != B->columns) || (A->rows != B->rows)) {
    error = ERROR_RESULT_FALSE_ARIFMETIC;
  } else if (!s21_create_matrix(A->rows, A->columns, result)) {
    for (int i = 0; (i < (A->rows)); i++) {
      for (int j = 0; j < (A->columns); j++) {
        (result->matrix)[i][j] =
            ((A->matrix)[i][j]) + (((B->matrix)[i][j]) * x);
      }
    }
  }
  return error;
}

void s21_minor(int row, matrix_t *old_mas, matrix_t *new_mas, int no_rows,
               int no_colomns) {
  for (int i = 0, i2 = 0; i < row; i++) {
    for (int j = 0, j2 = 0; j < row; j++) {
      if ((j != no_colomns) && (i != no_rows)) {
        new_mas->matrix[i2][j2] = old_mas->matrix[i][j];
        j2++;
      }
    }
    if (i != no_rows) {
      i2++;
    }
  }
}

double s21_determ_M(int rows, matrix_t *M) {
  double result = 0;
  if (rows > 2) {
    for (int i = 0; i < rows; i++) {
      matrix_t new_M;
      s21_create_matrix((rows - 1), (rows - 1), &new_M);
      s21_minor(rows, M, &new_M, 0, i);
      result += pow(-1.0, (double)i) * M->matrix[0][i] *
                s21_determ_M(rows - 1, &new_M);
      s21_remove_matrix(&new_M);
    }

  } else if (rows == 2) {
    result = (M->matrix[0][0] * M->matrix[1][1]) -
             (M->matrix[0][1] * M->matrix[1][0]);
  } else {
    result = M->matrix[0][0];
  }
  return result;
}

int s21_is_normal_for_square(matrix_t const *M, matrix_t const *result) {
  int error = ERROR_RESULT_OK;
  if (!(M) || !(result)) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if ((M->columns != M->rows) || (M->columns < 0)) {
    error = ERROR_RESULT_FALSE_ARIFMETIC;
  }
  return error;
}
