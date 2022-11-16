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

  printf("Running Matrix...\n");
    for (int i = 0; i < n; ++i){
      for (int j = 0; j < n; ++j){
	A->ptr[i][j] = (double) (i+j);
      }
    }
  print_Matrix(A);

  DiagonalMatrix * D=DiagonalMatrix_copy(A);
  printf("Running Diagonal Matrix...\n");
    print_DiagonalMatrix(D);
  free_DiagonalMatrix(D);

  UpperTriangularMatrix* U=UpperTriangularMatrix_copy(A);
  printf("Running Upper Triangular Matrix...\n");
    print_UpperTriangularMatrix(U);
  free_UpperTriangularMatrix(U);

  TridiagonalMatrix* T= TridiagonalMatrix_copy(A);
  printf("Running Tridiagonal Matrix...\n");
    print_TridiagonalMatrix(T);
  free_TridiagonalMatrix(T);

}


