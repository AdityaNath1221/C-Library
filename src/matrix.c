#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

matrix create_matrix(int row, int col, int isSparse){
    matrix m;
    m.row = row;
    m.col = col;
    m.isSparse = isSparse;
    allocate_matrix(&m);
    return m;
}

void allocate_matrix(matrix* m){
    int i, **mat;
    mat = (int**) malloc( m->row * sizeof(int*));
    for(i=0; i<m->row; i++){
        mat[i] = (int*) calloc(m->col,sizeof(int));
    }
    m->data = mat;
    return;
}

int populate_matrix(matrix a, int percent, int ul, int ll){
    int i,j, count=0;
    if(a.isSparse){
        for(i=0; i<a.row; i++){
            for(j=0; j<a.col; j++){
                if((rand()%100)<(100-percent)){
                    a.data[i][j] = rand()%(ul-ll+1)+ll;
                    count++;
                }
            }
    }
    }
    else{
        for(i=0; i<a.row; i++){
            for(j=0; j<a.col; j++){
                a.data[i][j] = rand()%(ul-ll+1)+ll;
            }
    }
    }
    return a.isSparse ? count:0 ;
}

matrix add_matrices(matrix a, matrix b){
    int i, j;
    matrix r;
    if((a.row!=b.row)||(a.col!=b.col)){
        printf("Matrix addition not possible");
        exit(0);
    }
    r.row = a.row;
    r.col = b.col;
    allocate_matrix(&r);
    for(i=0; i<r.row; i++){
        for (j=0; j<r.col; j++){
                r.data[i][j]=a.data[i][j]+b.data[i][j];
        }        
    }
    return r;
}

matrix subtract_matrices(matrix a, matrix b){
    int i, j;
    matrix r;
    if((a.row!=b.row)||(a.col!=b.col)){
        printf("Matrix subtraction not possible");
        exit(0);
    }
    r.row = a.row;
    r.col = b.col;
    allocate_matrix(&r);
    for(i=0; i<r.row; i++){
        for (j=0; j<r.col; j++){
                r.data[i][j]=a.data[i][j]-b.data[i][j];
        }        
    }
    return r;
}

matrix multiply_matrices(matrix a, matrix b){
    int i, j, k;
    matrix r;
    if(a.col!=b.row){
        printf("Matrix multiplication not possible");
        exit(0);
    }
    r.row = a.row;
    r.col = b.col;
    allocate_matrix(&r);
    for(i=0; i<r.row; i++){
        for (j=0; j<r.col; j++){
            for(k=0; k<a.col; k++){
                r.data[i][j]+=a.data[i][k]*b.data[k][j];
            }
        }        
    }
    return r;
}

matrix transpose_matrix(matrix a){
    int i, j, k;
    matrix r;
    r.row = a.col;
    r.col = a.row;
    allocate_matrix(&r);
    for(i=0; i<a.row; i++){
        for (j=0; j<a.col; j++){
            r.data[j][i]=a.data[i][j];
        }        
    }
    return r;
}

void print_matrix(matrix a){
    int i, j;
    for(i=0; i<a.row; i++){
        for(j=0; j<a.col; j++){
            printf("%d ", a.data[i][j]);
        }
        printf("\n");
    }
    return;
}

void free_matrix(matrix m){
    int i;
    for(i=0; i<m.row; i++){
        free(m.data[i]);
    }
    free(m.data);
    return;
}