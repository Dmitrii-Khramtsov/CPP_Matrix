// Copyright 2024 Dmitrii Khramtsov

/**
 * @file s21_matrix_oop.cc
 *
 * @author Dmitrii Khramtsov (lonmouth@student.21-school.ru)
 *
 * @brief The header file of the CPP1_s21_matrixplus project,
 * which implements a library for working with matrices.
 *
 * @date 2024-02-19
 *
 * @copyright School-21 (c) 2024
 */

#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_

#include <algorithm>  // std::copy
#include <cmath>      // std::abs
#include <iostream>
#include <limits>     // kMinEps
#include <stdexcept>  // out_of_range | invalid_argument
#include <utility>    // std::move | std::swap

namespace S21 {

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix(std::initializer_list<std::initializer_list<double>> initList);
  ~S21Matrix() noexcept;

  // Main methods
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const noexcept;
  double Determinant() const;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  int GetRows() const noexcept;
  int GetCols() const noexcept;
  void SetRows(int new_rows);
  void SetCols(int now_cols);

  // Overloaded methods
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator*(const double& num) const noexcept;
  S21Matrix& operator*=(const double& num) noexcept;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix& operator*=(const S21Matrix& other);
  double operator()(int i, int j) const;
  double& operator()(int i, int j);

 private:
  constexpr static const double kMinEps =
      std::numeric_limits<double>::epsilon();

  void AllocateMatrix();

  int rows_, cols_;
  double** matrix_;

  void SwapRows(int rows_1, int rows_2);
  double Minor(int i, int j) const;
};

}  // namespace S21

#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
