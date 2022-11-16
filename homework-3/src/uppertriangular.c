#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "upperdiagonal.h"

void free_UpperTriangularatrix(UpperTriangularMatrix *A){
  free(A->ptr);  
}

UpperTriangularMatrix* allocate_UpperTriangularMatrix(n){
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
    count=0;
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
  count=0;
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
    for (int i=0; i<A->n; ++i){
        sum=0;
        count=0;
        for (int p=0; p<=i; ++p){
            count+=p;
        }
        for(int j=0;j<A->n; ++j){
            if(i<=j){
                double A_el=A->ptr[i*n+j-count];
                double x_j=x->ptr[j];
                sum+=A_el*x_j;
            }
        }
        out->ptr[i]=sum;
    }
}