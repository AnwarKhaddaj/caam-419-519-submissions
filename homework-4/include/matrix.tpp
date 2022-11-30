#include "matrix.h"
#include <iostream>
using namespace std;

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

template <typename T>
Matrix<T>::Matrix(const Matrix<T> & A) : Matrix(A.num_rows(), A.num_columns()) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _columns; ++j) {
      _ptr[i][j] = A[i][j];
    }
  }
}

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

// template <typename T>
// void Matrix<T>::operator=(const Matrix<T> &x) {
//     if (this->num_rows() == x.num_rows() && this->num_columns() == x.num_columns()) {
//         for (int i = 0; i < this->num_rows(); ++i) {
//             for (int j = 0; j < this->num_columns(); ++j) {
//                 (this->getptr())[i][j] = (x.getptr())[i][j];
//             }
//         }
//     }
//     else {printf("Error: exiting with code -1");}
// }

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> &x) {
    if (this->num_rows() == x.num_rows() && this->num_columns() == x.num_columns()) {
        Matrix<T> sum(x.num_rows(), x.num_columns()) ; 
        for (int i = 0; i < x.num_rows(); ++i) {
            for (int j = 0; j < x.num_columns(); ++j) {
                (this->getptr())[i][j] = (x.getptr())[i][j];
            }
        }
    return *this;
    }
    else {throw std::domain_error("Error: incompatible matrix dimensions");}
}

// template <typename T>
// void operator+( Matrix<T> &x, T c) {

//     for (int i = 0; i < x.num_rows(); ++i) {
//             for (int j = 0; j < x.num_columns(); ++j) {
//                 (x.getptr())[i][j] = (x.getptr())[i][j]+c;
//             }
//         }
// }

// template <typename T>
// void operator+(T c,Matrix<T> &x) {
// 	x+c;
// }

// template <typename T>
// void operator-(Matrix<T> &x, T c) {
 
//    for (int i = 0; i < x.num_rows(); ++i) {
//            for (int j = 0; j < x.num_columns(); ++j) {
//                (x.getptr())[i][j] = (x.getptr())[i][j]-c;
//            }
//        }
// }

 
// template <typename T>
// void operator-(T c, Matrix<T> &x) {
// 	x-c;
// }
 

// template <typename T>
// void operator*(Matrix<T> &x, T c) {
 
//    for (int i = 0; i < x.num_rows(); ++i) {
//            for (int j = 0; j < x.num_columns(); ++j) {
//                (x.getptr())[i][j] = (x.getptr())[i][j]*c;
//            }
//        }
// }
 

// template <typename T>
// void operator*(T c, Matrix<T> &x) {
// 	x*c;
// }
 
 
// template <typename T>
// void operator/(Matrix<T> &x, T c) {
 
//    for (int i = 0; i < x.num_rows(); ++i) {
//            for (int j = 0; j < x.num_columns(); ++j) {
//                (x.getptr())[i][j] = (x.getptr())[i][j]/c;
//            }
//        }
// }

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
 
template <typename T>
Matrix<T> operator-(Matrix<T> &x, T c) {
Matrix<T> sum(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (sum.getptr())[i][j] = (x.getptr())[i][j]-c;
          }
      }
return sum;
}
 
template <typename T>
Matrix<T> operator-(T c, Matrix<T> &x) {
   return x-c;
}
 
 
template <typename T>
Matrix<T> operator*(Matrix<T> &x, T c) {
Matrix<T> sum(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (sum.getptr())[i][j] = (x.getptr())[i][j]*c;
          }
      }
return sum;
}
 
template <typename T>
Matrix<T> operator*(T c, Matrix<T> &x) {
   return x*c;
}
template <typename T>
Matrix<T>operator/(Matrix<T> &x, T c) {
Matrix<T> sum(x.num_rows(),x.num_columns());
  for (int i = 0; i < x.num_rows(); ++i) {
          for (int j = 0; j < x.num_columns(); ++j) {
              (sum.getptr())[i][j] = (x.getptr())[i][j]/c;
          }
      }
   return sum;
}


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
else {throw std::domain_error("Error: incompatible matrix dimensions");}

}

template <typename T>
Matrix<T> operator-(const Matrix<T> &x, const Matrix<T> &y){
   if (x.num_rows() == y.num_rows() && x.num_columns() == y.num_columns()) {
       Matrix<T> sum(x.num_rows(), x.num_columns()) ; 
       for (int i = 0; i < x.num_rows(); ++i) {
           for (int j = 0; j < x.num_columns(); ++j) {
               (sum.getptr())[i][j] = (x.getptr())[i][j]-(y.getptr())[i][j];
           }
       }
       return sum;
}
else {throw std::domain_error("Error: incompatible matrix dimensions");}
}

template <typename T>
Matrix<T> operator*(const Matrix<T> &x, const Matrix<T> &y){
   if (x.num_columns() == y.num_rows()) {
       Matrix<T> sum(x.num_rows(), y.num_columns()) ; 	
	
	  T t=(T)0;
         for (int i = 0; i < x.num_rows(); ++i) {
           	for (int j = 0; j < y.num_columns(); ++j) {
		   T Sum = (T) 0;
		   for(int k=0; k<x.num_columns();++k){
			Sum += (x.getptr())[i][k]*(y.getptr())[k][j];
		   }
		   (sum.getptr())[i][j]=Sum;
             }
         }
         return sum;
	}
       

else {throw std::domain_error("Error: incompatible matrix dimensions");}
}

