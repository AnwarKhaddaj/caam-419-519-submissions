#ifndef _MATRIX
#define _MATRIX

template <typename T> class Matrix{
 public:
  Matrix(int rows, int columns);
  Matrix(const Matrix<T> & A);  
  ~Matrix();
  
  int num_rows() const { return _rows; };
  int num_columns() const { return _columns; };
  T * operator[](const int i) const;
  T ** getptr() const {return _ptr;};
  Matrix<T> operator=(const Matrix<T> &x);
  
  void print();
 private:
  int _rows;
  int _columns;
  T ** _ptr;
};

template <typename T> Matrix<T> operator+(const Matrix<T> &x, T c);
template <typename T> Matrix<T> operator+(T c, const Matrix<T> &x);
template <typename T> Matrix<T> operator-(const Matrix<T> &x, T c);
template <typename T> Matrix<T> operator-(T c, const Matrix<T> &x);
template <typename T> Matrix<T> operator*(const Matrix<T> &x, T c);
template <typename T> Matrix<T> operator*(T c, const Matrix<T> &x);
template <typename T> Matrix<T> operator/(const Matrix<T> &x, T c);
template <typename T> Matrix<T> operator+(const Matrix<T> &x, const Matrix<T> &y);
template <typename T> Matrix<T> operator-(const Matrix<T> &x, const Matrix<T> &y);
template <typename T> Matrix<T> operator*(const Matrix<T> &x, const Matrix<T> &y);

#include "matrix.tpp"
#endif


