#include "s21_secondary_functions.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = ERROR_RESULT_OK;
  if (!(result)) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if ((rows < 1) || (columns < 1)) {
    error = ERROR_RESULT_FALSE_ARIFMETIC;
  } else {
    // result = (matrix_t*)malloc(sizeof(matrix_t));
    result->columns = columns;
    result->rows = rows;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      (result->matrix)[i] = (double *)malloc(columns * sizeof(double));
      for (int j = 0; j < columns; j++) {
        (result->matrix)[i][j] = 0;
      }
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    for (int i = 0; i < A->rows; i++) {
      free((A->matrix)[i]);
    }
    free(A->matrix);
    A->columns = 0;
    A->rows = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if (A && B && (B->columns == A->columns) && (B->rows == A->rows)) {
    result = SUCCESS;
    for (int i = 0; (i < (A->rows)) && (result == SUCCESS); i++) {
      for (int j = 0; (j < (A->columns)) && (result == SUCCESS); j++) {
        if (fabs((fabs((A->matrix)[i][j])) - fabs(((B->matrix)[i][j]))) >=
            0.0000001) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_and_sub(A, B, result, SUM);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_and_sub(A, B, result, SUB);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = ERROR_RESULT_FALSE_MATRIX;
  if (A && result) {
    error = ERROR_RESULT_OK;
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < (A->rows); i++) {
        for (int j = 0; j < (A->columns); j++) {
          (result->matrix)[i][j] = (A->matrix)[i][j] * number;
        }
      }
    }
  }
  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = ERROR_RESULT_FALSE_ARIFMETIC;
  if (!(A) || !(B) || !(result) ||
      ((A->columns < 1) || (A->rows < 1) || (B->rows < 1) ||
       (B->columns < 1))) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if (A->columns != B->rows) {
    error = ERROR_RESULT_FALSE_ARIFMETIC;
  } else if (!s21_create_matrix(A->rows, B->columns, result)) {
    error = ERROR_RESULT_OK;
    for (int i = 0; (i < (result->rows)); i++) {
      for (int j = 0; j < (result->columns); j++) {
        double sum = 0;
        for (int g = 0; g < A->columns; g++) {
          sum += (A->matrix)[i][g] * (B->matrix)[g][j];
        }
        (result->matrix)[i][j] = sum;
      }
    }
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = ERROR_RESULT_FALSE_MATRIX;
  if (A && result) {
    error = ERROR_RESULT_FALSE_MATRIX;
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      error = ERROR_RESULT_OK;
      for (int i = 0; i < (A->rows); i++) {
        for (int j = 0; j < (A->columns); j++) {
          (result->matrix)[j][i] = (A->matrix)[i][j];
        }
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = s21_is_normal_for_square(A, result);
  if (!(error)) {
    s21_create_matrix(A->rows, A->rows, result);
    if (A->rows > 1) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->rows; j++) {
          matrix_t new_M;
          s21_create_matrix((A->rows - 1), (A->rows - 1), &new_M);
          s21_minor(A->rows, A, &new_M, i, j);
          (result->matrix)[i][j] =
              (s21_determ_M(new_M.rows, &new_M) * pow(-1.0, (i + j)));
          s21_remove_matrix(&new_M);
        }
      }
    } else {
      s21_create_matrix(1, 1, result);
      (result->matrix)[0][0] = (A->matrix)[0][0];
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = ERROR_RESULT_OK;
  if (!(A) || !(result)) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if ((A->columns != A->rows) || (A->columns < 0)) {
    error = ERROR_RESULT_FALSE_ARIFMETIC;
  } else {
    *result = s21_determ_M((A->rows), A);
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = s21_is_normal_for_square(A, result);
  double determ = 0;
  s21_determinant(A, &determ);
  if (!result) {
    error = ERROR_RESULT_FALSE_MATRIX;
  } else if (!(error)) {
    if (A->rows == 1) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1;
    } else {
      matrix_t buff, buff_transp;
      s21_calc_complements(A, &buff);
      s21_transpose(&buff, &buff_transp);
      s21_remove_matrix(&buff);
      s21_mult_number(&buff_transp, (1 / determ), result);
      s21_remove_matrix(&buff_transp);
    }
  }
  return error;
}
