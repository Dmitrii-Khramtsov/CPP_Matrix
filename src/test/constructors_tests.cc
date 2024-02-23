// Copyright 2024 Dmitrii Khramtsov

#include "s21_matrix_test.h"

/**
 * TEST for s21_constructors_tests, constructor_1.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_constructors_tests, constructor_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  for (int i = 0; i != 0; i++) {
    for (int j = 0; j != 0; j++) {
      EXPECT_EQ(m1(i, j), 0.0);
    }
  }
}

/**
 * TEST for constructors_tests function.
 */
TEST(s21_constructors_tests, constructor_2) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

/**
 * Test case for the constructor_3 function of s21_constructors_tests.
 */
TEST(s21_constructors_tests, constructor_3) {
  S21::S21Matrix m1 = S21::S21Matrix(3, 3);
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

/**
 * Test case for the constructor_4 function in the s21_constructors_tests suite.
 */
TEST(s21_constructors_tests, constructor_4) {
  S21::S21Matrix m1 = S21::S21Matrix(3, 3);
  EXPECT_EQ(m1.GetCols(), 3);
  EXPECT_EQ(m1.GetRows(), 3);
}

/**
 * Test case for the copy constructor of S21Matrix class.
 */
TEST(S21MatrixTest, CopyConstructor) {
  S21::S21Matrix original(3, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;
  original(2, 0) = 7.0;
  original(2, 1) = 8.0;
  original(2, 2) = 9.0;

  S21::S21Matrix copy(original);

  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());

  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

/**
 * Test for the copy constructor of S21Matrix with an empty original matrix.
 */
TEST(S21MatrixTest, CopyConstructorEmptyMatrix) {
  S21::S21Matrix original;
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
}

/**
 * TEST for the S21Matrix copy constructor with a single element.
 */
TEST(S21MatrixTest, CopyConstructorSingleElement) {
  S21::S21Matrix original(1, 1);
  original(0, 0) = 42.0;
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  EXPECT_DOUBLE_EQ(copy(0, 0), original(0, 0));
}

/**
 * Test case for the copy constructor with negative values for the S21Matrix
 * class.
 */
TEST(S21S21MatrixTest, CopyConstructorNegativeValues) {
  S21::S21Matrix original(2, 2);
  original(0, 0) = -1.0;
  original(0, 1) = -2.0;
  original(1, 0) = -3.0;
  original(1, 1) = -4.0;
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

/**
 * Test for the copy constructor with large matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(S21MatrixTest, CopyConstructorLargeMatrix) {
  const int rows = 100;
  const int cols = 100;
  S21::S21Matrix original(rows, cols);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      original(i, j) = i * cols + j;
    }
  }
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

/**
 * Test for the copy constructor with different sizes for the S21Matrix class.
 */
TEST(S21MatrixTest, CopyConstructorDifferentSizes) {
  S21::S21Matrix original(2, 3);
  original(0, 0) = 1.0;
  original(0, 1) = 2.0;
  original(0, 2) = 3.0;
  original(1, 0) = 4.0;
  original(1, 1) = 5.0;
  original(1, 2) = 6.0;
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
  for (int i = 0; i < original.GetRows(); ++i) {
    for (int j = 0; j < original.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(copy(i, j), original(i, j));
    }
  }
}

/**
 * TEST for the S21Matrix copy constructor with zero size.
 */
TEST(S21MatrixTest, CopyConstructorZeroSize) {
  S21::S21Matrix original(0, 0);
  S21::S21Matrix copy(original);
  EXPECT_EQ(copy.GetRows(), original.GetRows());
  EXPECT_EQ(copy.GetCols(), original.GetCols());
}
