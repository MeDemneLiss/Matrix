

/* Массив указателей **matrix(указывают на начало строки) - нулевой элемент
 * каждой строки colomns - столбцы, rows - строки
 */
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;
/* Сохраняем в структуру колличество столбов и строчек.
 * Ввыделяем rows памяти на массив указателей **matrix - нулевой элемент
 * Для каждого указателя выделяем colomns памяти таким образом храним матрицу
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/* Очищаем память, выделенную для каждой строки и для массива указателей на
 * начало столбца(строки)
 */
void s21_remove_matrix(matrix_t *A);

/* Если матрица корректна, сравниваем сначала размеры матриц, затем каждый
 * элемент матрицы 0 - матрицы равны; 1 - матрицы не равны
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/*
 *
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*
 *
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*
 *
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/*
 *
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/*
 *
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/*
 *
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/*
 *
 */
int s21_determinant(matrix_t *A, double *result);

/*
 *
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);