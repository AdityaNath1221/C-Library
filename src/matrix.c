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

void populate_matrix_sparsely(char file[],int** mat, int r, int c, int upper, int lower){
    int i,j;
    FILE* fp = fopen(file, "r");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(((rand()%upper-lower+1)+lower)==1){
                fscanf(fp, "%d", &mat[i][j]);
            }
        }
    }
    fclose(fp);
    return;
}

int populate_matrix_sparsely_return_nnz(char file[],int** mat, int r, int c, int upper, int lower){
    int i,j, count=0;
    FILE* fp = fopen(file, "r");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(((rand()%(upper-lower+1))+lower)==1){
                fscanf(fp, "%d", &mat[i][j]);
                count++;
            }
        }
    }
    fclose(fp);
    return count;
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

void represent_matrix_in_triple_form(int** mat, int r, int c, int** triple){
    int i,j, k=1;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(mat[i][j]!=0){
                triple[k][0] = i;
                triple[k][1] = j;
                triple[k][2] = mat[i][j];
                k++;
            }
        }
    }
    triple[0][0] = r;
    triple[0][1] = c;
    triple[0][2] = k-1;
    return;
}

int** transpose_matrix_in_triple_form(int** mat_TR ){
    int k=1, i, j, r=mat_TR[0][2], prev = 0, curr, min, temp, imin;
    int** tmat_TR = allocate_matrix(r+1, 3);
    tmat_TR[0][0]=mat_TR[0][0];
    tmat_TR[0][1]=mat_TR[0][1];
    tmat_TR[0][2]=mat_TR[0][2];
    for(i=1; i<(r+1); i++){
        tmat_TR[i][0] = mat_TR[i][1];
        tmat_TR[i][1] = mat_TR[i][0];
        tmat_TR[i][2] = mat_TR[i][2];
    }
    min = tmat_TR[1][0];
    imin = 1;
    for(i=1; i<=r-1; i++){
        for(j=i+1;j<=r; j++){
            if((tmat_TR[i][0]>tmat_TR[j][0])||((tmat_TR[i][0]==tmat_TR[j][0]))&&(tmat_TR[i][1]>tmat_TR[j][1])){
                for(k=0; k<3; k++){
                    temp = tmat_TR[i][k];
                    tmat_TR[i][k] = tmat_TR[j][k];
                    tmat_TR[j][k] = temp;
                }
            }
        }
    }

    return tmat_TR; 
}