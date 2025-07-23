#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fileio.h"

void write_data_to_file(FILE* fp, int data){
    fprintf(fp, "%d ", data);
    return;
}

void write_random_nos_to_file(char file[], int n, int UL, int LL){
    int i;
    srand(time(0));
    FILE* fp = fopen(file, "w");
    for(i=0; i<n; i++){
        fprintf(fp, "%d ", (rand()%(UL-LL+1)+LL));
    }
    fclose(fp);
    return;
}

void write_matrix_to_file(char file[], int** mat, int row, int col){
    int i, j;
    FILE* fp = fopen(file, "w");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            fprintf(fp, "%d ", mat[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return;
}