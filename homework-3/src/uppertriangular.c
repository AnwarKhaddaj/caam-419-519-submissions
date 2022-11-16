#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "uppertriangular.h"

void free_UpperTriangularMatrix(UpperTriangularMatrix *A){
  free(A->ptr);  
}

UpperTriangularMatrix* allocate_UpperTriangularMatrix(int n){
  double * ptr = malloc(sizeof(double)*(n*(n+1)/2));

  // return a pointer to a new matrix object
  UpperTriangularMatrix * A = malloc(sizeof(UpperTriangularMatrix));
  A->n = n;
  A->ptr = ptr;
  return A;
}

UpperTriangularMatrix* UpperTriangularMatrix_copy(Matrix* A){
    UpperTriangularMatrix* copy=allocate_UpperTriangularMatrix(A->n);
    copy->n=A->n;
    int count=0;
    for (int i = 0; i < A->n; ++i){
      for (int j = 0; j < A->n; ++j){
        if (i<=j){
         copy->ptr[count]=A->ptr[i][j];
         count++;
        }
      }
    }
  return copy;  
}

void print_UpperTriangularMatrix(UpperTriangularMatrix * A){
  printf("A = [\n");
  int count=0;
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
      if (i<=j){
      printf("%7.2f  ", A->ptr[count]);
      count=count+1;
      }
      else{
      printf("         ");}
    }
    printf("\n");    
  }
  printf("]\n");
}

void multiply_UpperTriangularMatrix_Vector(Vector* out, UpperTriangularMatrix* A, Vector* x){
  int count = 0;
  for (int i = 0; i < A->n; ++i){
    for (int j = i; j < A->n; ++j){
      double A_ij = A->ptr[count];
      double x_j = x->ptr[j];
      out->ptr[i] += A_ij * x_j;
      count++;
    }
  }
}
