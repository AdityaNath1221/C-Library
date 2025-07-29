#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "tuple.h"

void initialize_tuple(tuple* t, int nnz){
    t->NNZ = nnz;
    int i, j;
    t->data = (int**) malloc((nnz+1)*sizeof(int*));
    for(i=0; i<(nnz+1); i++){
        t->data[i] = (int*) malloc(3*sizeof(int));
    }
    return;
}

void populate_tuple(tuple* t, matrix m){
    int i, j, k=1;
    t->data[0][0] = m.row;
    t->data[0][1] = m.col;
    t->data[0][2] = t->NNZ;
    for(i=0; i<m.row; i++){
        for(j=0;j<m.col; j++){
            if(m.data[i][j] != 0){
                t->data[k][0] = i;
                t->data[k][1] = j;
                t->data[k][2] = m.data[i][j];
                k++;
            }
        }
    }
    return;
}

void print_tuple(tuple t){
    int i, j;
    for(i=0; i<t.NNZ+1; i++){
        for(j=0; j<3; j++){
            printf("%d ", t.data[i][j]);
        }
        printf("\n");
    }
    return;
}

tuple transpose_tuple(tuple t){
    tuple n;
    int i, j, k, row = t.NNZ, temp;
    initialize_tuple(&n, t.NNZ);
    n.data[0][0] = t.data[0][0];
    n.data[0][1] = t.data[0][1];
    n.data[0][2] = t.data[0][2];
    for(i=1; i<row+1; i++){
        n.data[i][0] = t.data[i][1];
        n.data[i][1] = t.data[i][0];
        n.data[i][2] = t.data[i][2];
    }
    for(i=1; i<=row-1; i++){
        for(j=i+1; j<=row; j++){
            if((n.data[i][0]>n.data[j][0])||((n.data[i][0]==n.data[j][0])&&(n.data[i][1]>n.data[j][1]))){
                for(k=0; k<3; k++){
                    temp = n.data[j][k];
                    n.data[j][k] = n.data[i][k];
                    n.data[i][k] = temp;
                }
            }
        }
    }
    return n;
}

void free_tuple(tuple* t){
    int i, j;
    for(i=0; i<t->NNZ+1; i++){
        free(t->data[i]);
    }
    return;
}