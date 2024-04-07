#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

/* OK
 */
#define ERROR_RESULT_OK 0
/* Ошибка, некорректная матрица
 */
#define ERROR_RESULT_FALSE_MATRIX 1
/* Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя
 * провести вычисления и т.д.)
 */
#define ERROR_RESULT_FALSE_ARIFMETIC 2
#define SUM 1
#define SUB -1
#define SUCCESS 1
#define FAILURE 0

int s21_sum_and_sub(matrix_t *A, matrix_t *B, matrix_t *result, int x);
void s21_minor(int row, matrix_t *old_mas, matrix_t *new_mas, int no_rows,
               int no_colomns);
double s21_determ_M(int rows, matrix_t *M);
void s21_write_mas(int row, double **M, double *res);
int s21_is_normal_for_square(matrix_t const *M, matrix_t const *result);