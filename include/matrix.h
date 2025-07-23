#ifndef MATRIX_H
#define MATRIX_H

int** allocate_matrix(int row, int col);
int** allocate_matrix_to_zero(int row, int col);
void populate_matrix(char file[],int** mat, int row, int col);
int** matrix_multiplication(int** mat1, int r1, int c1, int**mat2, int r2, int c2);
void free_matrix(int** mat, int row, int col);

#endif