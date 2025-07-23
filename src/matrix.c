#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

int** allocate_matrix(int row, int col){
    int** mat;
    int i;
    mat = (int**) malloc(row*sizeof(int*));
    for(i=0; i<row; i++){
        mat[i] = (int*) malloc(col*sizeof(int));
    }
    return mat;
}

int** allocate_matrix_to_zero(int row, int col){
    int** mat;
    int i;
    mat = (int**) malloc(row*sizeof(int*));
    for(i=0; i<row; i++){
        mat[i] = (int*) calloc(col,sizeof(int));
    }
    return mat;
}

void populate_matrix(char file[],int** mat, int row, int col){
    int i,j;
    FILE* fp = fopen(file, "r");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            fscanf(fp, "%d", &mat[i][j]);
        }
    }
    fclose(fp);
    return;
}

int** matrix_multiplication(int** mat1, int r1, int c1, int**mat2, int r2, int c2){
    int i, j, k, **r;
    if(c1!=r2){
        printf("Matrix multiplication not possible");
        exit(0);
    }
    r = allocate_matrix_to_zero(r1,c2);
    for(i=0; i<r1; i++){
        for (j=0; j<c2; j++){
            for(k=0; k<r2; k++){
                r[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }        
    }
    return r;
}

void free_matrix(int** mat, int row, int col){
    int i;
    for(i=0; i<row; i++){
        free(mat[i]);
    }
    free(mat);
    return;
}

