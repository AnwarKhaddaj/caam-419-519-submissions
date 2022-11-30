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

template <typename T>
Vector<T> Vector<T>::operator=(const Vector<T> &x) {
delete this->ptr_;
this->length_=x.length();
this->ptr_=(T*) malloc(sizeof(T)*x.length());
  for (int j = 0; j < x.length(); ++j) {
         (this->ptr_)[j] = (x.getptr())[j];
  }
  return *this;
}

//overloading + operator for vector-scalar addition
template <typename T>
Vector<T> operator+(const Vector<T> &x, T c) {
    Vector<T> add(x.length());
    for (int j = 0; j < x.length(); ++j) {
        (add.getptr())[j] = (x.getptr())[j]+c;
    }
    return add;   
}
template <typename T>
Vector<T> operator+(T c, const Vector<T> &x) {
    return x+c;
        
}
//overloading - operator for vector-scalar subtraction
template <typename T>
Vector<T> operator-(const Vector<T> &x, T c) {
    Vector<T> diff(x.length());
    for (int j = 0; j < x.length(); ++j) {
        (diff.getptr())[j] = (x.getptr())[j]-c;
    }
    return diff;
}
template <typename T>
Vector<T> operator-(T c, const Vector<T> &x) {
    return x-c;
        
}
//overloading * operator for vector-scalar multiplication
template <typename T>
Vector<T> operator*(const Vector<T> &x, T c) {
    Vector<T> mult(x.length());
    for (int j = 0; j < x.length(); ++j) {
        (mult.getptr())[j] = (x.getptr())[j]*c;
    }
    return mult;
}
template <typename T>
Vector<T> operator*(T c, const Vector<T> &x) {
    return x*c;     
}
//overloading / operator for vector-scalar division
template <typename T>
Vector<T> operator/(const Vector<T> &x, T c) {
    Vector<T> div(x.length());
    for (int j = 0; j < x.length(); ++j) {
        (div.getptr())[j] = (x.getptr())[j]/c;
    }
    return div;
}
//overloading + operator for vector-vector addition
template <typename T> 
Vector<T> operator+(const Vector<T> &x, const Vector<T> &y){
    if (x.length() == y.length()) {
        Vector<T> add(x.length()) ;  
        for (int i = 0; i < x.length(); ++i) {  
            (add.getptr())[i] = (x.getptr())[i]+(y.getptr())[i];   
        }
        return add;
    }
    else {
         throw std::domain_error("Error: incompatible vector dimensions");
    }
}
//overloading - operator for vector-vector addition
template <typename T> 
Vector<T> operator-(const Vector<T> &x, const Vector<T> &y){
    if (x.length() == y.length()) {
        Vector<T> subt(x.length()) ;  
        for (int i = 0; i < x.length(); ++i) {
                (subt.getptr())[i] = (x.getptr())[i]-(y.getptr())[i];
        }
        return subt;
}
else {
	throw std::domain_error("Error: incompatible vector dimensions");
}
}
//overloading * operator for vector-matrix multiplication
template <typename T>
Matrix<T> operator*(const Vector<T> &x, const Matrix<T> &y){
   if (y.num_rows() == 1) {
       Matrix<T> mult(x.length(), y.num_columns()) ; 	
         for (int i = 0; i < x.length(); ++i) {
           	for (int j = 0; j < y.num_columns(); ++j) {
		   (mult.getptr())[i][j]=(x.getptr())[i]*(y.getptr())[0][j];
             }
         }
         return mult;
   }
  else {
	throw std::domain_error("Error: incompatible vector and matrix dimensions");}
   }

template <typename T>
Vector<T> operator*(const Matrix<T> &x, const Vector<T> &y){
   if (x.num_columns() == y.length()) {
       Vector<T> mult(x.num_rows()) ; 	
         for (int i = 0; i < x.num_rows(); ++i) {
            T Sum = (T) 0;
           	for (int j = 0; j < x.num_columns(); ++j) {
		   Sum += (x.getptr())[i][j]*(y.getptr())[j];
             }
             (mult.getptr())[i] = Sum;
         }
         return mult;
	}
       

else {throw std::domain_error("Error: incompatible vector and matrix dimensions");}
}
