#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "diagonal.h"
#include "tridiagonal.h"
#include "uppertriangular.h"
#include <time.h>

Vector* diff(Vector * x, Vector * y){
    Vector * d=allocate_Vector(x->length);
    for (int j=0; j<x->length; ++j){
        d->ptr[j]=(x->ptr[j])-(y->ptr[j]);
    }
    return d;
}

int main(void){
    int n = 100;
    Matrix * A = allocate_Matrix(n, n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
          A->ptr[i][j] = (double) (i+j);
        }
    }
    
  Vector * x = allocate_Vector(n);
  for (int j = 0; j < n; ++j){
    x->ptr[j] = j;
  }


  DiagonalMatrix* D=DiagonalMatrix_copy(A);
  printf("Running Diagonal Matrix...");
  print_DiagonalMatrix(D);
  free_DiagonalMatrix(D);

  UpperTriangularMatrix* U= UpperTriangularMatrix_copy(A);
  printf("Running Upper Triangular Matrix...");
  print_UpperTriangularMatrix(U);
  free_UpperTriangularMatrix(U);

  TridiagonalMatrix* T= TridiagonalMatrix_copy(A);
  printf("Running Tridiagonal Matrix...");
  print_TridiagonalMatrix(T);
  free_TridiagonalMatrix(T);

  Matrix * D1=allocate_Matrix(n,n);
  for (int i=0;i<D1->n;++i){
    for (int j=0; j<D1->n; ++j){
        if (i==j){
            D1->ptr[i][j]=A->ptr[i][j];
        }
        else{
            D1->ptr[i][j]=(double)0;
        }
    }
  }

  Matrix * U1=allocate_Matrix(n,n);
  for (int i = 0; i < A->n; ++i){
      for (int j = 0; j < A->n; ++j){
        if (i<=j){
         U1->ptr[i][j]=A->ptr[i][j];
        }
        else{
         U1->ptr[i][j]=(double)0;
        }
      }
  }

  Matrix * T1=allocate_Matrix(n,n);
  for (int i = 0; i < A->n; ++i){
        for (int j = 0; j < A->n; ++j){

          if (i==j || i==(j+1) || i==(j-1)){
            T1->ptr[i][j]=A->ptr[i][j];
          }
          else{
            T1->ptr[i][j]=(double)0;
          }
        }     
  }

//matrix-vector multiplication
  Vector * outD = allocate_Vector(n);
  Vector * outD1 = allocate_Vector(n);
  Vector * outU = allocate_Vector(n);
  Vector * outU1 = allocate_Vector(n);
  Vector * outT = allocate_Vector(n);
  Vector * outT1 = allocate_Vector(n);
  multiply_DiagonalMatrix_Vector(outD, D, x);
  multiply_Matrix_Vector(outD1, D1, x);

  printf("The norm of the difference between the two matrix-vector products for Diagonal Matrix is %f\n", norm(diff(outD,outD1)));

  multiply_UpperTriangularMatrix_Vector(outU, U, x);
  multiply_Matrix_Vector(outU1, U1, x);
  
  printf("The norm of the difference between the two matrix-vector products for Upper Triangular Matrix is %f\n", norm(diff(outU,outU1)));

  multiply_TridiagonalMatrix_Vector(outT, T, x);
  multiply_Matrix_Vector(outT1, T1, x);

 printf("The norm of the difference between the two matrix-vector products for Tridiagonal Matrix is %f\n", norm(diff(outT,outT1)));

 //Computing Runtimes
 clock_t start, end;
 double avg_time;


 start=clock();
 for (int i=1;i<100;++i){
   multiply_DiagonalMatrix_Vector(outD, D, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Diagonal matrix is %1.9f\n", avg_time);


 start=clock();
 for (i=1;i<100;++i){
     multiply_Matrix_Vector(outD1, D1, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Diagonal matrix using Matrix type is %1.9f\n", avg_time);

  start=clock();
 for (i=1;i<100;++i){
   multiply_UpperTriangularMatrix_Vector(outU, U, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Upper Triangular matrix is %1.9f\n", avg_time);

  start=clock();
 for (i=1;i<100;++i){
   multiply_Matrix_Vector(outU1, U1, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Upper Triangular matrix using Matrix type is %1.9f\n", avg_time);

  start=clock();
 for (i=1;i<100;++i){
  multiply_TridiagonalMatrix_Vector(outT, T, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Tridiagonal matrix is %1.9f\n", avg_time);

 
  start=clock();
 for (i=1;i<100;++i){
    multiply_Matrix_Vector(outT1, T1, x);
 }
 end=clock();
 avg_time = ((double) (end - start)) / (CLOCKS_PER_SEC*100.0);
 printf("The average run time for matrix_vector multiplication for Tridiagonal matrix using Matrix type is %1.9f\n", avg_time);


 //Freeing all allocated memory

  free_Matrix(A);
  free_DiagonalMatrix(D);
  free_Matrix(D1);
  free_UpperTriangularMatrix(U);
  free_Matrix(U1);
  free_TridiagonalMatrix(T);
  free_Matrix(T1);

  free_Vector(x);

  free_Vector(outD);
  free_Vector(outD1);
  free_Vector(outU);
  free_Vector(outU1);
  free_Vector(outT);
  free_Vector(outT1);

}
