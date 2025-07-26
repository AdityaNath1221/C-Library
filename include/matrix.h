#ifndef MATRIX_H
#define MATRIX_H

typedef struct{
    int row;
    int col;
    int **data;
    int isSparse;
}matrix;

matrix create_matrix(int row, int col, int isSparse);
void allocate_matrix(matrix* m);
int populate_matrix(matrix a, int percent, int ul, int ll);
matrix add_matrices(matrix a, matrix b);
matrix subtract_matrices(matrix a, matrix b);
matrix multiply_matrices(matrix a, matrix b);
matrix transpose_matrix(matrix a);
void print_matrix(matrix a);
void free_matrix(matrix m);

#endif