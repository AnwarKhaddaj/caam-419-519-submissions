#include "vector.h"
#include "matrix.h"

#ifndef _TRIDIAGMATRIX
#define _TRIDIAGMATRIX

typedef struct{
  int n; //dimension of matrix
  double * ptr_u;
  double * ptr_c;
  double * ptr_l;
} TridiagonalMatrix;
 
#endif

void print_TridiagonalMatrix(TridiagonalMatrix* A);
TridiagonalMatrix* allocate_TridiagonalMatrix(int n);
TridiagonalMatrix* TridiagonalMatrix_copy(Matrix* A);
void free_TridiagonalMatrix(TridiagonalMatrix* A);
void multiply_TridiagonalMatrix_Vector(Vector* out,TridiagonalMatrix* A, Vector* x);
