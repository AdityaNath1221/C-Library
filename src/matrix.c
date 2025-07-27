#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

void allocate_matrix(matrix* m){
    int i, **mat;
    mat = (int**) malloc( m->row * sizeof(int*));
    for(i=0; i<m->row; i++){
        mat[i] = (int*) calloc(m->col,sizeof(int));
    }
    m->data = mat;
    return;
}

matrix create_matrix(int row, int col, int isSparse){
    matrix m;
    m.row = row;
    m.col = col;
    m.isSparse = isSparse;
    allocate_matrix(&m);
    return m;
}

matrix copy_matrix(matrix a){
    matrix b;
    int i,j;
    b = create_matrix(a.row, a.col, a.isSparse);
    for(i=0; i<b.row; i++){
        for(j=0; j<b.col; j++){
            b.data[i][j] = a.data[i][j];
        }
    }
    return b;
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
    int i, j;
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

matrixResult to_upper_triangular(matrix a){
    int i, j, k, l, row_swap = 0, swap_found = 0;
    matrix result = copy_matrix(a);
    for(i=0, j=0; i<result.row && j<result.col; i++, j++){
        if(result.data[i][j]==0){
            for(k=i+1; k<result.row; k++){
                if(result.data[k][j]!=0){
                    for(l=0; l<result.col; l++){
                        double temp = result.data[i][l];
                        result.data[i][l] = result.data[k][l];
                        result.data[k][l] = temp;
                    }
                    row_swap++;
                    swap_found = 1; 
                    break;
                }
                if(!swap_found){
                    continue;
                }
            }
        }
        for(l=i+1; l<result.row; l++){
            double factor = result.data[l][j]/result.data[i][j];
            for(k=0; k<result.col; k++){
                result.data[l][k] -= factor*result.data[i][k];
            }
        }
    }
    matrixResult res;
    res.mat = result;
    res.row_swap = row_swap;
    return res;
}

double determinant_matrix(matrix a){
    matrixResult UT_mat = to_upper_triangular(a);
    int i, j, sign=1;
    double det = 1;
    for(i=0,j=0; i<UT_mat.mat.row && j<UT_mat.mat.col; i++,j++){
        det = det*UT_mat.mat.data[i][j];
    }
    if(UT_mat.row_swap%2!=0){
        det*=-1;
    }
    return det;
}

int trace_matrix(matrix a){
    int i, j;
    int trace = 0;
    for(i=0,j=0; i<a.row && j<a.col; i++,j++){
        trace += a.data[i][j];
    }
    return trace;
}

matrix multiply_scalar(matrix a, int k){
    matrix res = create_matrix(a.row, a.col, a.isSparse);
    int i,j;
    for(i=0; i<res.row; i++){
        for(j=0; j<res.col; j++){
            res.data[i][j] = k*a.data[i][j];
        }
    }
    return res;
}

int rank_matrix(matrix a){
    int i, j, zero_row=0, count;
    matrixResult res = to_upper_triangular(a);
    for(i=0; i<res.mat.row; i++){
        count = 0;
        for(j=0; j<res.mat.col; j++){
            if(res.mat.data[i][j]==0){
                count++;
            }
        }
        if(count==res.mat.col){
            zero_row++;
        }
    }
    return (res.mat.row-zero_row);
}

int check_identity(matrix a){
    int i, j;
    for(i=0; i<a.row; i++){
        for(j=0; j<a.col; j++){
            if(i==j){
                if(a.data[i][j]!=1){
                    return 0;
                }
            }
            else{
                if(a.data[i][j]!=0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int check_equality(matrix a, matrix b){
    int i, j;
    if(a.row!=b.row || a.col!=b.col){
        fprintf(stderr, "ERROR: Matrix sizes are different.\n");
        return 0;
    }
    for(i=0; i<a.row; i++){
        for(j=0; j<a.col; j++){
            if(a.data[i][j]!=b.data[i][j]){
                return 0;
            }
        }
    }
    return 1;
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