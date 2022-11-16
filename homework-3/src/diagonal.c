#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "diagonal.h"

void free_DiagonalMatrix(DiagonalMatrix *A){
  free(A->ptr);  
}

DiagonalMatrix* allocate_DiagonalMatrix(n){
  double * ptr = malloc(sizeof(double)*n);

  // return a pointer to a new matrix object
  DiagonalMatrix * A = malloc(sizeof(DiagonalMatrix));
  A->n = n;
  A->ptr = ptr;
  return A;
}

DiagonalMatrix* DiagonalMatrix_copy(Matrix* A){
  if (A->n < A->m){
    DiagonalMatrix* copy=allocate_DiagonalMatrix(A->n);
    copy->n=A->n;
    for (int i=0;i<A->n;++i){
       copy->ptr[i]=A->ptr[i][i];
    }
  }
  else{
    DiagonalMatrix* copy=allocate_DiagonalMatrix(A->m);
    copy->n=A->m;
    for (int i=0;i<A->m;++i){
       copy->ptr[i]=A->ptr[i][i];
    }
  }
  return copy;  
}

void print_DiagonalMatrix(DiagonalMatrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
      if (i==j){
      printf("%7.2f  ", A->ptr[i]);}
      else{
      printf("         ");}
    }
    printf("\n");    
  }
  printf("]\n");
}

void multiply_DiagonalMatrix_Vector(Vector* out, DiagonalMatrix* A, Vector* x){
  for (int j = 0; j < A->n; ++j){
    double A_jj = A->ptr[j];
    double x_j = x->ptr[j];
    out->ptr[j] = A_jj* x_j;
  }
}
