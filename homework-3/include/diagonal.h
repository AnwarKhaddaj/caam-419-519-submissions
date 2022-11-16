#include "vector.h"
#include "matrix.h"

#ifndef _DIAGMATRIX
#define _DIAGMATRIX

typedef struct{
  int n; //dimension of matrix
  double * ptr; //represents the diagonal
} DiagonalMatrix;
 
#endif

void print_DiagonalMatrix(DiagonalMatrix* A);
DiagonalMatrix* DiagonalMatrix_copy(Matrix* A);
void free_DiagonalMatrix(DiagonalMatrix* A);
void multiply_DiagonalMatrix_Vector(Vector* out,DiagonalMatrix* A, Vector* x);
