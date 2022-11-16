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

  printf("Running Matrix...");
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
	A->ptr[i][j] = (double) (i+j);
      }
    }
  print_Matrix(A);

  DiagonalMatrix * D=DiagonalMatrix_copy(A);
  printf("Running Diagonal Matrix...");
    print_DiagonalMatrix(D);
  free_DiagonalMatrix(D);

  UpperTriangularMatrix* U=UpperTriangularMatrix_copy(A);
  printf("Running Upper Triangular Matrix...");
    print_UpperTriangularMatrix(U);
  free_UpperTriangularMatrix(U);

  UpperTridiagonalMatrix* T= UpperTridiagonalMatrix_copy(A);
  printf("Running Tridiagonal Matrix...");
    print_UpperTridiagonalMatrix(T);
  free_UpperTridiagonalMatrix(T);

}


