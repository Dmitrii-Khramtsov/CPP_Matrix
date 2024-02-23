// Copyright 2024 Dmitrii Khramtsov

#include "s21_matrix_test.h"

/**
 * TEST for setting rows in S21Matrix.
 *
 * No parameters.
 *
 * No return value.
 *
 * No error thrown.
 */
TEST(s21_mutator_tests, set_rows_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetRows(5);
  EXPECT_EQ(m1.GetRows(), 5);
}

/**
 * TEST for setting rows to 5 in the S21Matrix class and checking the resulting
 * matrix.
 *
 * No parameters
 *
 * No return value
 *
 * No exceptions thrown
 */
TEST(s21_mutator_tests, set_rows_2) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetRows(5);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      if (i > 2) {
        EXPECT_EQ(m1(i, j), 0.0);
      }
    }
  }
}

/**
 * Test case for setting the number of rows in a S21Matrix object.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_mutator_tests, set_rows_3) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetRows(2);
  EXPECT_EQ(m1.GetRows(), 2);
}

/**
 * Test for setting the number of rows in the S21Matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_mutator_tests, set_rows_4) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetRows(2);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 1.0);
    }
  }
}

/**
 * Test case for setting rows with invalid input, expecting an out_of_range
 * error.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::out_of_range
 */
TEST(s21_mutator_tests, SetRows_InvalidInput_ThrowsOutOfRange) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  EXPECT_THROW(m1.SetRows(-1), std::out_of_range);
}

/**
 * Test for setting the number of columns in the S21Matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_mutator_tests, set_cols_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetCols(5);
  EXPECT_EQ(m1.GetCols(), 5);
}

/**
 * Test case for setting the number of columns in a matrix.
 *
 * @param s21_mutator_tests The test suite for mutator functions in the
 * S21Matrix class.
 *
 * @return void
 *
 * @throws N/A
 */
TEST(s21_mutator_tests, set_cols_2) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetCols(5);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      if (j > 2) {
        EXPECT_EQ(m1(i, j), 0.0);
      }
    }
  }
}

/**
 * TEST for setting columns to 3 in s21_mutator_tests.
 */
TEST(s21_mutator_tests, set_cols_3) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetCols(2);
  EXPECT_EQ(m1.GetCols(), 2);
}

/**
 * Test case for setting the number of columns in a matrix and verifying the
 * values.
 *
 * No parameters
 *
 * No return value
 *
 * No exceptions thrown
 */
TEST(s21_mutator_tests, set_cols_4) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SetCols(2);
  for (int i = 0; i != m1.GetRows(); i++) {
    for (int j = 0; j != m1.GetCols(); j++) {
      EXPECT_EQ(m1(i, j), 1.0);
    }
  }
}

/**
 * TEST for setting columns with invalid input, expecting std::out_of_range
 * exception to be thrown.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::out_of_range if the input is negative
 */
TEST(s21_mutator_tests, SetCols_InvalidInput_ThrowsOutOfRange) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  EXPECT_THROW(m1.SetCols(-1), std::out_of_range);
}
