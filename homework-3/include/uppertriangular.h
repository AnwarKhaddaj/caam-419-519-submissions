#include "vector.h"
#include "matrix.h"

#ifndef _UPPTRIAGMATRIX
#define _UPPTRIAGMATRIX

typedef struct{
  int n; //dimension of matrix
  double * ptr; //represents the n(n+1)/2 entries of the upper triangular matrix
} UpperTriangularMatrix;
 
#endif

void print_UpperTriangularMatrix(UpperTriangularMatrix* A);
UpperTriangularMatrix* UpperTriangularMatrix_copy(Matrix* A);
UpperTriangularMatrix* allocate_UpperTriangularMatrix(int n);
void free_UpperTriangularMatrix(UpperTriangularMatrix* A);
void multiply_UpperTriangularMatrix_Vector(Vector* out,UpperTriangularMatrix* A, Vector* x);
