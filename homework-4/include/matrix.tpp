#include "matrix.h"
#include <iostream>
using namespace std;

//constructor
template <typename T>
Matrix<T>::Matrix(int rows, int columns){
  _rows = rows;
  _columns = columns;
  
  _ptr = new T*[_rows]; 
  _ptr[0] = new T[_rows * _columns];
  for (int i = 1; i < _rows; ++i) {
    _ptr[i] = _ptr[0] + i * _columns;
  }
}
//copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T> & A) : Matrix(A.num_rows(), A.num_columns()) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _columns; ++j) {
      _ptr[i][j] = A[i][j];
    }
  }
}
//destructor
template <typename T>
Matrix<T>::~Matrix(){
  free(_ptr[0]);    
  free(_ptr);
}

template <typename T>
T * Matrix<T>::operator[](const int i) const {
  return _ptr[i];
}

template <typename T>
void Matrix<T>::print(){
  std::cout << "Matrix = [" << std::endl;
  for (int i = 0; i < _rows; ++i){      
    for (int j = 0; j < _columns; ++j){      
      std::cout << _ptr[i][j] << " "; 
    }
    std::cout << std::endl;      
  }
  std::cout << "]" << std::endl;    
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> &x) {
	delete (this->_ptr[0]);
	delete (this->_ptr);
	this->_rows=x.num_rows();
	this->_columns=x.num_columns();
	this->_ptr = new T*[x.num_rows()]; 
        this->_ptr[0] = new T[_rows * x.num_columns()];
	//this->_ptr=(T**) malloc(sizeof(T)*x.num_rows());
        //this->_ptr[0]=(T*) malloc(sizeof(T)*x.num_rows()*x.num_columns());
	for (int i = 1; i < x.num_rows(); ++i) {
    	this->_ptr[i] = this->_ptr[0] + i * x.num_columns();
  	}
        for (int i = 0; i < x.num_rows(); ++i) {
            for (int j = 0; j < x.num_columns(); ++j) {
                (this->_ptr)[i][j] = (x.getptr())[i][j];
            }
        }
    return *this;
}

//overloading + operator for scalar-matrix addition
template <typename T>
Matrix<T> operator+( Matrix<T> &x, T c) {
Matrix<T> sum(x.num_rows(),x.num_columns());
   for (int i = 0; i < x.num_rows(); ++i) {
           for (int j = 0; j < x.num_columns(); ++j) {
               (sum.getptr())[i][j] = (x.getptr())[i][j]+c;
           }
   }
   return sum;
}
template <typename T>
Matrix<T> operator+(T c,Matrix<T> &x) {
   return x+c;
}
//overloading - operator for scalar-matrix subtraction
template <typename T>
Matrix<T> operator-(Matrix<T> &x, T c) {
Matrix<T> diff(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (diff.getptr())[i][j] = (x.getptr())[i][j]-c;
          }
      }
return diff;
}
template <typename T>
Matrix<T> operator-(T c, Matrix<T> &x) {
   return x-c;
}
//overloading * operator for scalar-matrix multiplication
template <typename T>
Matrix<T> operator*(Matrix<T> &x, T c) {
Matrix<T> mult(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (mult.getptr())[i][j] = (x.getptr())[i][j]*c;
          }
      }
return mult;
}
template <typename T>
Matrix<T> operator*(T c, Matrix<T> &x) {
   return x*c;
}
//overloading / operator for scalar-matrix division
template <typename T>
Matrix<T>operator/(Matrix<T> &x, T c) {
Matrix<T> div(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (div.getptr())[i][j] = (x.getptr())[i][j]/c;
          }
      }
   return div;
}
//overloading + operator for matrix-matrix addition
template <typename T> 
Matrix<T> operator+(const Matrix<T> &x, const Matrix<T> &y){
    if (x.num_rows() == y.num_rows() && x.num_columns() == y.num_columns()) {
        Matrix<T> sum(x.num_rows(), x.num_columns()) ;  
        for (int i = 0; i < x.num_rows(); ++i) {
            for (int j = 0; j < x.num_columns(); ++j) {
                (sum.getptr())[i][j] = (x.getptr())[i][j]+(y.getptr())[i][j];
            }
        }
        return sum;
}
    else {
	throw std::domain_error("Error: incompatible matrix dimensions");
     }
}
//overloading - operator for matrix-matrix subtraction
template <typename T>
Matrix<T> operator-(const Matrix<T> &x, const Matrix<T> &y){
   if (x.num_rows() == y.num_rows() && x.num_columns() == y.num_columns()) {
       Matrix<T> diff(x.num_rows(), x.num_columns()) ; 
       for (int i = 0; i < x.num_rows(); ++i) {
           for (int j = 0; j < x.num_columns(); ++j) {
               (diff.getptr())[i][j] = (x.getptr())[i][j]-(y.getptr())[i][j];
           }
       }
       return diff;
}
    else {
	throw std::domain_error("Error: incompatible matrix dimensions");
    }
}
//overloading * operator for matrix-matrix multiplication
template <typename T>
Matrix<T> operator*(const Matrix<T> &x, const Matrix<T> &y){
   if (x.num_columns() == y.num_rows()) {
       Matrix<T> mult(x.num_rows(), y.num_columns()) ; 
         for (int i = 0; i < x.num_rows(); ++i) {
           	for (int j = 0; j < y.num_columns(); ++j) {
		   T Sum = (T) 0;
		   for(int k = 0; k< x.num_columns(); ++k){
			Sum += (x.getptr())[i][k]*(y.getptr())[k][j];
		   }
		   (mult.getptr())[i][j]=Sum;
             }
         }
         return mult;
    }
    else {
	    throw std::domain_error("Error: incompatible matrix dimensions");
    }
}
