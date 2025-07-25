#ifndef MATRIX_H
#define MATRIX_H

int** allocate_matrix(int row, int col);
int** allocate_matrix_to_zero(int row, int col);
void populate_matrix(char file[],int** mat, int row, int col);
int** matrix_multiplication(int** mat1, int r1, int c1, int**mat2, int r2, int c2);
void free_matrix(int** mat, int row, int col);
void populate_matrix_sparsely(char file[],int** mat, int row, int col, int upper, int lower);
int populate_matrix_sparsely_return_nnz(char file[],int** mat, int row, int col, int upper, int lower);
void represent_matrix_in_triple_form(int** mat, int row, int col, int** mat_tuple);
int** transpose_matrix_in_triple_form(int** mat_tuple );

#endif