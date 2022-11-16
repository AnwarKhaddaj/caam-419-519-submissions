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
UpperTriangular* UpperTriangular_copy(Matrix* A);
void free_UpperTriangularMatrix(UpperTriangularMatrix* A);
void multiply_UpperTriangular_Matrix_Vector(Vector* out,UpperTriangularMatrix* A, Vector* x);