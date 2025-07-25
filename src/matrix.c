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

void populate_matrix_sparsely(char file[],int** mat, int row, int col, int upper, int lower){
    int i,j;
    FILE* fp = fopen(file, "r");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(((rand()%upper-lower+1)+lower)==1){
                fscanf(fp, "%d", &mat[i][j]);
            }
        }
    }
    fclose(fp);
    return;
}

int populate_matrix_sparsely_return_nnz(char file[],int** mat, int row, int col, int upper, int lower){
    int i,j, count=0;
    FILE* fp = fopen(file, "r");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
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

void represent_matrix_in_triple_form(int** mat, int row, int col, int** mat_tuple){
    int i,j, k=1;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(mat[i][j]!=0){
                mat_tuple[k][0] = i;
                mat_tuple[k][1] = j;
                mat_tuple[k][2] = mat[i][j];
                k++;
            }
        }
    }
    mat_tuple[0][0] = row;
    mat_tuple[0][1] = col;
    mat_tuple[0][2] = k-1;
    return;
}

int** transpose_matrix_in_triple_form(int** mat_tuple ){
    int i, j, k, row=mat_tuple[0][2], prev = 0, temp;
    int** mat_tuple_t = allocate_matrix(row+1, 3);
    mat_tuple_t[0][0]=mat_tuple[0][0];
    mat_tuple_t[0][1]=mat_tuple[0][1];
    mat_tuple_t[0][2]=mat_tuple[0][2];
    for(i=1; i<(row+1); i++){
        mat_tuple_t[i][0] = mat_tuple[i][1];
        mat_tuple_t[i][1] = mat_tuple[i][0];
        mat_tuple_t[i][2] = mat_tuple[i][2];
    }
    for(i=1; i<=row-1; i++){
        for(j=i+1;j<=row; j++){
            if((mat_tuple_t[i][0]>mat_tuple_t[j][0])||((mat_tuple_t[i][0]==mat_tuple_t[j][0]))&&(mat_tuple_t[i][1]>mat_tuple_t[j][1])){
                for(k=0; k<3; k++){
                    temp = mat_tuple_t[i][k];
                    mat_tuple_t[i][k] = mat_tuple_t[j][k];
                    mat_tuple_t[j][k] = temp;
                }
            }
        }
    }

    return mat_tuple_t; 
}