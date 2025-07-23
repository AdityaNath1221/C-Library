#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>

void write_data_to_file(FILE* fp, int data);
void write_random_nos_to_file(char file[], int n, int UL, int LL);
void write_matrix_to_file(char file[], int** mat, int row, int col);

#endif