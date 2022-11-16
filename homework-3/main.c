#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "diagonal.h"
#include "tridiagonal.h"
#include "uppertriangular.h"

int main(void){
  int n = 5;
  Matrix * A = allocate_Matrix(n, n);

  printf("Running Matrix...")
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
	A->ptr[i][j] = (double) (i+j);
      }
    }
  print_Matrix(A);

  D=DiagonalMatrix* DiagonalMatrix_copy(A);
  printf("Running Diagonal Matrix...")
    print_DiagonalMatrix(D);
  free_DiagonalMatrix(D);

  U=UpperTriangularMatrix* UpperTriangularMatrix_copy(A);
  printf("Running Upper Triangular Matrix...")
    print_UpperTriangularMatrix(U);
  free_UpperTriangularMatrix(U);

  T=UpperTridiagonalMatrix* UpperTridiagonalMatrix_copy(A);
  printf("Running Tridiagonal Matrix...")
    print_UpperTridiagonalMatrix(T);
  free_UpperTridiagonalMatrix(T);

}

int main(void){

  int m = 5;
  int n = 5;
  Matrix * A = allocate_Matrix(m, n);
  Vector * x = allocate_Vector(n);

  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      A->ptr[i][j] = (double) (i+j);
    }
  }
  for (int j = 0; j < n; ++j){
    x->ptr[j] = j+1;
  }

  print_Matrix(A);
  print_Vector(x);

  // test matrix-vector multiplication
  Vector * out = allocate_Vector(m);
  multiply_Matrix_Vector(out, A, x);
  print_Vector(out);
  printf("The norm of A*x is %f\n", norm(out));

  free_Matrix(A);
  free_Vector(x);
  free_Vector(out);

}

