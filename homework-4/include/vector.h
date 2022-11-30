#ifndef _VECTOR
#define _VECTOR
#include "matrix.h"

template <typename T>
class Vector{
public:
  Vector(const int length);
  Vector(const Vector<T> & x);
  ~Vector();
  
  int length(void) const{ return length_; }  
  void print();

  // for indexing (e.g., x[i] = 1.0);  
  T & operator[](const int i) const; 
  T * getptr() const {return ptr_;};
  Vector<T> operator=(const Vector<T> &x);
private:
  int length_;
  T * ptr_;
};

template <typename T> Vector<T> operator+(const Vector<T> &x, T c);
template <typename T> Vector<T> operator+(T c, const Vector<T> &x);
template <typename T> Vector<T> operator-(const Vector<T> &x, T c);
template <typename T> Vector<T> operator-(T c, const Vector<T> &x);
template <typename T> Vector<T> operator*(const Vector<T> &x, T c);
template <typename T> Vector<T> operator*(T c, const Vector<T> &x);
template <typename T> Vector<T> operator/(const Vector<T> &x, T c);
template <typename T> Vector<T> operator+(const Vector<T> &x, const Vector<T> &y);
template <typename T> Vector<T> operator-(const Vector<T> &x, const Vector<T> &y);
template <typename T> Matrix<T> operator*(const Vector<T> &x, const Matrix<T> &y);
template <typename T> Vector<T> operator*(const Matrix<T> &x, const Vector<T> &y);

#include "vector.tpp"
#endif
