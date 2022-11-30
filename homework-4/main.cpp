#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;
	      
int main(void){
  Matrix<double> A(6,4);
  Matrix<double> B(4,5);
  Matrix<double> C(6,5);
  Matrix<double> D(1,5);
  Matrix<double> E(6,5);

  
  Vector<double> z(6);

  for (int i = 0; i < A.num_rows(); ++i){
    for (int j = 0; j < A.num_columns(); ++j){
      A[i][j] = (double) (i+j);
    }
  }
  for (int i = 0; i < B.num_rows(); ++i){
    for (int j = 0; j < B.num_columns(); ++j){
      B[i][j] = (double) 1 / (i + j + 1);
    }
  }
  for (int i = 0; i < C.num_rows(); ++i){
    for (int j = 0; j < C.num_columns(); ++j){
      C[i][j] = (double) i * j;
    }
  }
    
  Vector<double> x(5);
  for (int i = 0; i < x.length(); ++i){
    x[i] = i;
  }
  Vector<double> y(6);
  for (int i = 0; i < y.length(); ++i){
    y[i] = 1 - i;
  }

  double a = 1.5;
  double b = 3.5;
  std::cout << "Matrix A is:" << std::endl;
  A.print();
  std::cout << "Matrix B is:" << std::endl;
  B.print();
  std::cout << "Matrix C is:" << std::endl;
  C.print();
  std::cout << "Vector x is:" << std::endl;
  x.print();
  std::cout << "Vector y is:" << std::endl;
  y.print();
  std::cout << a << std::endl;
  z=((A*B + C) * x + a * y);
  std::cout << "First computation of vector z is:" << std::endl;
  z.print();
  z = 3.0*z - (y - 1.0) / 2.0 + 0.5;
  std::cout << "Second computation of vector z is:" << std::endl;
  z.print();
}
