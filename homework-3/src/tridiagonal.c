#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "tridiagonal.h"

void free_TridiagonalMatrix(TridiagonalMatrix *A){
  free(A->ptr_u);
  free(A->ptr_c);
  free(A->ptr_l);
}

TridiagonalMatrix* allocate_TridiagonalMatrix(int n){
  double * ptr_u = malloc(sizeof(double)*(n-1));
  double * ptr_c = malloc(sizeof(double)*n);
  double * ptr_l = malloc(sizeof(double)*(n-1));
  // return a pointer to a new matrix object
  TridiagonalMatrix * A = malloc(sizeof(TridiagonalMatrix));
  A->n = n;
  A->ptr_u = ptr_u;
  A->ptr_l = ptr_l;
  A->ptr_c = ptr_c;
  return A;
}

TridiagonalMatrix* TridiagonalMatrix_copy(Matrix* A){
    TridiagonalMatrix* copy=allocate_TridiagonalMatrix(A->n);
    copy->n=A->n;
    for (int i = 0; i < A->n; ++i){
        for (int j = 0; j < A->n; ++j){
          if (i==j){
            copy->ptr_c[i]=A->ptr[i][j];
          }
          else if (i==(j+1)){
            copy->ptr_l[j]=A->ptr[i][j];
          }
          else if(i==(j-1)){
            copy->ptr_u[i]=A->ptr[i][j];
          }
    }
  return copy;  
}

void print_TridiagonalMatrix(TridiagonalMatrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
      if (i==j){
        printf("%7.2f  ", A->ptr_c[i]);}
      else if (i==(j+1)){
        printf("%7.2f  ", A->ptr_l[j]);
      }
      else if(i==(j-1)){
        printf("%7.2f  ", A->ptr_u[i]);
      }
      else{
      printf("         ");}
    }
    printf("\n");    
  }
  printf("]\n");
}

void multiply_TridiagonalMatrix_Vector(Vector* out, TridiagonalMatrix* A, Vector* x){
    int n=A->n;
    out->ptr[0]=(x->ptr[0])*(A->ptr_c[0])+(x->ptr[1])*(A->ptr_u[0]);
    out->ptr[n-1]=(x->ptr[n-2])*(A->ptr_l[n-2])+(x->ptr[n-1])*(A->ptr_c[n-1]);
    for(int i=1;i<n-1;++i){
        out->ptr[i]=(x->ptr[i-1])*(A->ptr_l[i-1])+(x->ptr[i])*(A->ptr_c[i])+(x->ptr[i+1])*(A->ptr_u[i]);
    }
}
