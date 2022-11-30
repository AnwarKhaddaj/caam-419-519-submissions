#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;
//#include "matrix.tpp"
//#include "vector.tpp"
	      
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
  // z.print();
  // z = y;
  // z.print();
  A.print();
  B.print();
  C.print();
  x.print();
  y.print();
  std::cout << a << std::endl;
  z=((A*B + C) * x + a * y);
  //z.print();
  z = 3.0*z - (y - 1.0) / 2.0 + 0.5;
  z.print();
  E = C;
  E.print();
  // (3.0*((A*B + C) * x + a * y)-(y-1.0)/2.0+0.5).print();
  //z.print();
  //C.print();
  //x.print();
  // E = x*D;
  // E.print();

  //(C*x).print();

  // A.print();
  // B.print();
  // D = A*B;
  // D.print();

  //a+A;
  //B+b;
  // A-a;
  // A.print();
  // A*b;
  // A.print();
  // A/3.0;
  // A.print();
  // //D-3;
  // x-a;
  // x.print();
  // x*b;
  // x.print();
  // x/3.0;
  // x.print();

  //A+B;
  // A.print();
  // D = A-A;
  // D.print();
  // //A+B;

  // x=x+x;
  // x.print();
}
