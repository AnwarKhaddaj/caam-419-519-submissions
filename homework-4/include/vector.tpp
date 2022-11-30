#include <iostream>
#include "vector.h"

// constructor
template <typename T>
Vector<T>::Vector(const int length) {
  length_ = length;
  ptr_ = (T*) malloc(sizeof(T) * length_);
  for (int i = 0; i < length_; ++i){
    ptr_[i] = 0.0;
  }
}

// copy constructor
template <typename T>
Vector<T>::Vector(const Vector<T> & x){
  length_ = x.length();
  ptr_ = new T[length_];
  for (int i = 0; i < length_; ++i){
    ptr_[i] = x[i];
  }
}

// destructor
template <typename T>
Vector<T>::~Vector(){    
  free(ptr_);
  ptr_ = nullptr; // C++ can use nullptr instead of NULL
}

template <typename T>
void Vector<T>::print(){
  std::cout << "Vector = [" << std::endl;
  for (int i = 0; i < length_; ++i){
    std::cout << ptr_[i] << std::endl;
  }
  std::cout << "]" << std::endl;
}

template <typename T>
T & Vector<T>::operator[](const int i) const {
  return ptr_[i];
}

// template <typename T>
// void Vector<T>::operator=(const Vector<T> &x) {
//     if (this->length_ == x.length()) {
        
//             for (int j = 0; j < this->length_; ++j) {
//                 (this->getptr())[j] = (x.getptr())[j];
//             }
        
//     }
//     else {throw std::domain_error("Error: incompatible vector dimensions");}
// }

template <typename T>
Vector<T> Vector<T>::operator=(const Vector<T> &x) {
    if (this->length_ == x.length()) {
        //Vector<T> sum(x.length()) ;  
            for (int j = 0; j < x.length(); ++j) {
                (this->getptr())[j] = (x.getptr())[j];
                //(sum.getptr())[j] = 3.0;
                //(sum.getptr())[j] = (x.getptr())[j];
            }
            //this = sum;
        return *this;
     }
    else {throw std::domain_error("Error: incompatible vector dimensions");}
}

template <typename T>
Vector<T> operator+(const Vector<T> &x, T c) {
    Vector<T> sum(x.length());
            for (int j = 0; j < x.length(); ++j) {
                (sum.getptr())[j] = (x.getptr())[j]+c;
            }
            return sum;
        
}

template <typename T>
Vector<T> operator+(T c, const Vector<T> &x) {
    return x+c;
        
}

template <typename T>
Vector<T> operator-(const Vector<T> &x, T c) {
    Vector<T> sum(x.length());
            for (int j = 0; j < x.length(); ++j) {
                (sum.getptr())[j] = (x.getptr())[j]-c;
            }
        return sum;
}

template <typename T>
Vector<T> operator-(T c, const Vector<T> &x) {
    return x-c;
        
}

template <typename T>
Vector<T> operator*(const Vector<T> &x, T c) {
    Vector<T> sum(x.length());
            for (int j = 0; j < x.length(); ++j) {
                (sum.getptr())[j] = (x.getptr())[j]*c;
            }
        return sum;
}

template <typename T>
Vector<T> operator*(T c, const Vector<T> &x) {
    return x*c;
        
}

template <typename T>
Vector<T> operator/(const Vector<T> &x, T c) {
    Vector<T> sum(x.length());
            for (int j = 0; j < x.length(); ++j) {
                (sum.getptr())[j] = (x.getptr())[j]/c;
            }
        return sum;
}

template <typename T> 
Vector<T> operator+(const Vector<T> &x, const Vector<T> &y){
    if (x.length() == y.length()) {
        Vector<T> sum(x.length()) ;  
        for (int i = 0; i < x.length(); ++i) {
            
                (sum.getptr())[i] = (x.getptr())[i]+(y.getptr())[i];
            
        }
        return sum;
}
else {throw std::domain_error("Error: incompatible vector dimensions");}

}

template <typename T> 
Vector<T> operator-(const Vector<T> &x, const Vector<T> &y){
    if (x.length() == y.length()) {
        Vector<T> sum(x.length()) ;  
        for (int i = 0; i < x.length(); ++i) {
            
                (sum.getptr())[i] = (x.getptr())[i]-(y.getptr())[i];
            
        }
        return sum;
}
else {throw std::domain_error("Error: incompatible vector dimensions");}

}

template <typename T>
Matrix<T> operator*(const Vector<T> &x, const Matrix<T> &y){
   if (y.num_rows() == 1) {
       Matrix<T> sum(x.length(), y.num_columns()) ; 	
	
	  T t=(T)0;
         for (int i = 0; i < x.length(); ++i) {
           	for (int j = 0; j < y.num_columns(); ++j) {
		   //T Sum = (T) 0;
		   
		   (sum.getptr())[i][j]=(x.getptr())[i]*(y.getptr())[0][j];
             }
         }
         return sum;
	}
       

else {throw std::domain_error("Error: incompatible vector and matrix dimensions");}
}

template <typename T>
Vector<T> operator*(const Matrix<T> &x, const Vector<T> &y){
   if (x.num_columns() == y.length()) {
       Vector<T> sum(x.num_rows()) ; 	
	
	  T t=(T)0;
         for (int i = 0; i < x.num_rows(); ++i) {
            T Sum = (T) 0;
           	for (int j = 0; j < x.num_columns(); ++j) {
		   Sum += (x.getptr())[i][j]*(y.getptr())[j];
             }
             (sum.getptr())[i] = Sum;
         }
         return sum;
	}
       

else {throw std::domain_error("Error: incompatible vector and matrix dimensions");}
}