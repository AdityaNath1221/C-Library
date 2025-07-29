#ifndef TUPLE_H
#define TUPLE_H

typedef struct tuple{
    int** data;
    int NNZ;
}tuple;

void init_tuple(tuple* t, int nnz);
void fill_tuple(tuple* t, matrix m);
void print_tuple(tuple t);
tuple transpose_tuple(tuple t);
void free_tuple(tuple* t);

#endif