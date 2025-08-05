#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix{
    int row;
    int col;
    int **data;
    int isSparse;
}matrix;

typedef struct matrixResult{
    matrix mat;
    int row_swap;
}matrixResult;

void allocate_matrix(matrix* m);
matrix create_matrix(int row, int col, int isSparse);
matrix copy_matrix(matrix a);
int populate_matrix(matrix a, int percent, int ul, int ll);
matrix add_matrices(matrix a, matrix b);
matrix subtract_matrices(matrix a, matrix b);
matrix multiply_matrices(matrix a, matrix b);
matrix transpose_matrix(matrix a);
matrixResult to_upper_triangular(matrix a);
double determinant_matrix(matrix a);
int trace_matrix(matrix a);
matrix multiply_scalar(matrix a, int k);
int rank_matrix(matrix a);
int check_identity(matrix a);
int check_equality(matrix a, matrix b);
void print_matrix(matrix a);
void free_matrix(matrix m);

#endif