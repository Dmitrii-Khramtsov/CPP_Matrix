// Copyright 2024 Dmitrii Khramtsov

/**
 * @file s21_matrix_oop.cc
 *
 * @author Dmitrii Khramtsov (lonmouth@student.21-school.ru)
 *
 * @brief Methods of the CPP1_s21_matrixplus project,
 * which implements a library for working with matrices.
 *
 * @date 2024-02-19
 *
 * @copyright School-21 (c) 2024
 */

#include "s21_matrix_oop.h"

namespace S21 {

/******************************************************************************
 * CONSTRUCTOR & DESTRUCTOR
 ******************************************************************************/

/**
 * The default constructor for the S21Matrix class.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

/**
 * Constructor for S21Matrix class.
 *
 * @param rows the number of rows in the matrix
 * @param cols the number of columns in the matrix
 *
 * @throws std::invalid_argument if rows or cols are less than zero
 */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 0 || cols_ < 0) {
    throw std::invalid_argument(
        "Matrix size must be great then or equal to zero");
  }
  AllocateMatrix();
}

/**
 * Constructor for creating a copy of the S21Matrix object.
 *
 * @param other The S21Matrix object to be copied
 *
 * @return None
 *
 * @throws None
 */
S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

/**
 * Constructor for moving S21Matrix object.
 *
 * @param other S21Matrix object to be moved
 *
 * @return N/A
 *
 * @throws N/A
 */
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    S21Matrix copy(other);
    *this = std::move(copy);
  }
  return *this;
}

/**
 * Constructor for S21Matrix class.
 *
 * @brief A constructor for filling in the values of the matrix elements.
 *
 * @param initList List of lists of doubles for initializing the matrix
 *
 * @details The constructor for tests
 * is used to fill in the values of the matrix elements.
 *
 * @throws std::invalid_argument if rows or cols are not greater than zero
 */
S21Matrix::S21Matrix(
    std::initializer_list<std::initializer_list<double>> initList)
    : rows_(initList.size()), cols_(initList.begin()->size()) {
  if (!rows_ || !cols_) {
    throw std::invalid_argument("Rows and Cols must be greater than zero");
  }

  AllocateMatrix();

  int rowIndex = 0;
  for (const auto& row : initList) {
    int colIndex = 0;
    for (const auto& value : row) {
      matrix_[rowIndex][colIndex++] = value;
    }
    ++rowIndex;
  }
}

/**
 * Destructor for S21Matrix class.
 */
S21Matrix::~S21Matrix() noexcept {
  for (int j = 0; j < rows_; ++j) {
    delete[] matrix_[j];
  }
  delete[] matrix_;
}

/******************************************************************************
 * MAIN METHODS
 ******************************************************************************/

/**
 * Checks if the current S21Matrix is equal to the provided S21Matrix.
 *
 * @param other The S21Matrix to compare against.
 *
 * @return Returns true if the matrices are equal, false otherwise.
 *
 * @throws None
 */
bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }

  return true;
}

/**
 * Adds the elements of the input matrix to the current matrix.
 *
 * @param other The matrix to be added to the current matrix.
 *
 * @throws std::invalid_argument Incorrect matrix dimensions for Sum
 */
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect matrix dimensions for Sum");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

/**
 * Subtracts the elements of the given S21Matrix from this S21Matrix.
 *
 * @param other the S21Matrix to subtract from this matrix
 *
 * @throws std::invalid_argument if the dimensions of the given S21Matrix do not
 * match this matrix
 */
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Incorrect matrix dimensions for Sub");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

/**
 * Multiply all elements of the matrix by the given number.
 *
 * @param num the number to multiply all matrix elements by
 *
 * @return void
 *
 * @throws none
 */
void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}

/**
 * Multiply this matrix by another matrix.
 *
 * @param other The other matrix to multiply with
 *
 * @throws std::invalid_argument if the matrix dimensions are incorrect for
 * multiplication
 */
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument(
        "Incorrect matrix dimensions for Multiplication");
  }
  S21Matrix result{rows_, other.cols_};

  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      for (int k = 0; k < cols_; ++k) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  // It is more optimal to use moving instead of copying
  *this = std::move(result);
}

/**
 * Transposes the S21Matrix.
 *
 * @return the transposed S21Matrix
 *
 * @throws None
 */
S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix result{cols_, rows_};
  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

/**
 * Calculate the determinant of the S21Matrix.
 *
 * @details I use the Gauss method. O(n^3).
 *
 * @return the determinant of the S21Matrix
 *
 * @throws std::invalid_argument if the matrix dimensions are incorrect
 */
double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Incorrect matrix dimensions for Determinant");
  }

  S21Matrix tmp{*this};
  int sign = 1;
  double res = 1.0;

  for (int i = 0; i < tmp.rows_ - 1; ++i) {
    if (!tmp.matrix_[i][i]) {
      for (int k = 1; k < tmp.rows_; ++k) {
        if (tmp.matrix_[k][i]) {
          tmp.SwapRows(i, k);
          sign *= -1;
          break;
        }
      }
    }

    for (int j = i + 1; j < tmp.rows_; ++j) {
      if (std::abs(tmp.matrix_[i][i]) > kMinEps) {
        double ratio = tmp.matrix_[j][i] / tmp.matrix_[i][i];
        for (int l = i; l < tmp.cols_; ++l) {
          tmp.matrix_[j][l] -= tmp.matrix_[i][l] * ratio;
        }
      }
    }
  }

  for (int i = 0; i < tmp.rows_; i++) {
    res *= tmp.matrix_[i][i];
  }
  return res * sign;
}

/**
 * Calculate the complements of the S21Matrix.
 *
 * @return The S21Matrix containing the complements.
 *
 * @throws std::invalid_argument if the matrix dimensions are incorrect for
 * CalcComplements
 */
S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Incorrect matrix dimensions for CalcComplements");
  }

  S21Matrix result{rows_, cols_};

  for (int i = 0; i < result.rows_; ++i) {
    for (int j = 0; j < result.cols_; ++j) {
      result(i, j) = Minor(i, j);
    }
  }

  return result;
}

/**
 * Calculate the inverse matrix of the current S21Matrix.
 *
 * @return S21Matrix - the inverse matrix
 *
 * @throws std::invalid_argument - if the matrix dimensions are incorrect or the
 * determinant is zero
 */
S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Incorrect matrix dimensions for InverseMatrix");
  }

  double det = Determinant();

  if (std::abs(det) < kMinEps) {
    throw std::invalid_argument(
        "Determinant must be non-zero to calculate Inverse");
  }

  return S21Matrix(CalcComplements().Transpose() * (1 / det));
}

/******************************************************************************
 * GETTERS & SETTERS
 ******************************************************************************/

int S21Matrix::GetRows() const noexcept { return rows_; }
int S21Matrix::GetCols() const noexcept { return cols_; }

/**
 * Set the number of rows in the S21Matrix.
 *
 * @param new_rows the new number of rows
 *
 * @throws std::out_of_range if new_rows is negative
 */
void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 0) {
    throw std::out_of_range("Matrix row size can't be negative");
  }

  S21Matrix tmp{new_rows, cols_};
  for (int i = 0; i < (new_rows < rows_ ? new_rows : rows_); ++i) {
    for (int j = 0; j < cols_; ++j) {
      tmp(i, j) = (*this)(i, j);
    }
  }

  *this = std::move(tmp);
}

/**
 * Set the number of columns in the matrix.
 *
 * @param new_cols the new number of columns
 *
 * @throws std::out_of_range if the new_cols is negative
 */
void S21Matrix::SetCols(int new_cols) {
  if (new_cols < 0) {
    throw std::out_of_range("Matrix col size can't be negative");
  }

  S21Matrix tmp{rows_, new_cols};
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < (new_cols < cols_ ? new_cols : cols_); ++j) {
      tmp(i, j) = (*this)(i, j);
    }
  }

  *this = std::move(tmp);
}

/******************************************************************************
 * OVERLOADED METHODS
 ******************************************************************************/

/**
 * Check if the current S21Matrix is equal to the other S21Matrix.
 *
 * @param other The other S21Matrix to compare with.
 *
 * @return true if the current S21Matrix is equal to the other S21Matrix, false
 * otherwise.
 *
 * @throws None
 */
bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return EqMatrix(other);
}

/**
 * Overloads the '+' operator to perform matrix addition.
 *
 * @param other The matrix to be added.
 *
 * @return A new matrix resulting from the addition.
 *
 * @throws None
 */
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix tmp = *this;
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

/**
 * Overloads the subtraction operator to subtract another S21Matrix.
 *
 * @param other The S21Matrix to subtract from the current matrix.
 *
 * @return A new S21Matrix resulting from the subtraction.
 *
 * @throws None
 */
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix tmp = *this;
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

/**
 * Overloads the multiplication operator to multiply the matrix by a scalar.
 *
 * @param num the scalar to multiply the matrix by
 *
 * @return a new matrix resulting from the multiplication
 *
 * @throws None
 */
S21Matrix S21Matrix::operator*(const double& num) const noexcept {
  S21Matrix tmp = *this;
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(const double& num) noexcept {
  MulNumber(num);
  return *this;
}

/**
 * Overloads the * operator to perform matrix multiplication.
 *
 * @param other The matrix to be multiplied with
 *
 * @return The result of the matrix multiplication
 *
 * @throws None
 */
S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix tmp = *this;
  tmp.MulMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

/**
 * A function to retrieve the element at the specified indices from the
 * S21Matrix.
 *
 * @param i the row index
 * @param j the column index
 *
 * @return the value at the specified indices
 *
 * @throws std::out_of_range if the indices are outside the matrix
 */
double S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Index outside the matrix");
  }
  return matrix_[i][j];
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Index outside the matrix");
  }
  return matrix_[i][j];
}

/******************************************************************************
 * PRIVATE METHODS
 ******************************************************************************/

/**
 * Allocates memory for a matrix of double values.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
void S21Matrix::AllocateMatrix() {
  int i = 0;
  try {
    matrix_ = new double* [rows_] {};
    for (; i < rows_; ++i) {
      matrix_[i] = new double[cols_]{};
    }
  } catch (...) {
    for (int j = 0; j < i; ++j) {
      delete[] matrix_[j];
    }
    delete[] matrix_;
  }
}

/**
 * Swaps the rows of the S21Matrix.
 *
 * @param rows_1 the index of the first row to be swapped
 * @param rows_2 the index of the second row to be swapped
 *
 * @throws std::out_of_range if the row index is invalid
 */
void S21Matrix::SwapRows(int rows_1, int rows_2) {
  if (rows_1 == rows_2) return;
  if (rows_1 < 0 || rows_1 >= rows_ || rows_2 < 0 || rows_2 >= rows_) {
    throw std::out_of_range("Invalid row index");
  }

  for (int j = 0; j < cols_; ++j) {
    std::swap((*this)(rows_1, j), (*this)(rows_2, j));
  }
}

/**
 * Calculate the minor of the S21Matrix at the specified row and column.
 *
 * @param i the row index
 * @param j the column index
 *
 * @return the minor of the S21Matrix at the specified row and column
 *
 * @throws None
 */
double S21Matrix::Minor(int i, int j) const {
  S21Matrix result{rows_ - 1, rows_ - 1};
  double res = 0;

  for (int k = 0; k < rows_ - 1; ++k) {
    for (int l = 0; l < rows_ - 1; ++l) {
      result(k, l) = matrix_[k < i ? k : k + 1][l < j ? l : l + 1];
    }
  }

  res = result.Determinant() * ((i + j) % 2 ? -1 : 1);

  return res;
}

}  // namespace S21
