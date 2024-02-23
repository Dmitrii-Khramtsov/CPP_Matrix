// Copyright 2024 Dmitrii Khramtsov

#include "s21_matrix_test.h"

/**
 * TEST for overloading the addition operator.
 */
TEST(s21_overloadings, Addition) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = 5;
  m2(0, 1) = 6;
  m2(1, 0) = 7;
  m2(1, 1) = 8;

  S21::S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 6);
  EXPECT_EQ(result(0, 1), 8);
  EXPECT_EQ(result(1, 0), 10);
  EXPECT_EQ(result(1, 1), 12);
}

/**
 * Test case for overloading the addition operator with matrices of different
 * sizes.
 *
 * @throws std::invalid_argument if the matrices have different dimensions
 */
TEST(s21_overloadings, AdditionDifferentSizes) {
  S21::S21Matrix m1(2, 2);
  S21::S21Matrix m2(3, 3);

  ASSERT_THROW({ S21::S21Matrix result = m1 + m2; }, std::invalid_argument);
}

/**
 * TEST for addition operation on a 2x2 matrix.
 *
 */
TEST(s21_overloadings, AdditionOnesMatrix) {
  S21::S21Matrix m1(2, 2);
  S21::S21Matrix m2(2, 2);

  S21::S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 0);
}

/**
 * TEST case for addition of negative numbers in S21Matrix.
 */
TEST(s21_overloadings, AdditionNegativeNumbers) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = -1;
  m1(0, 1) = -2;
  m1(1, 0) = -3;
  m1(1, 1) = -4;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = -1;
  m2(0, 1) = -1;
  m2(1, 0) = -1;
  m2(1, 1) = -1;

  S21::S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), -2);
  EXPECT_EQ(result(0, 1), -3);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -5);
}

/**
 * TEST for addition of large numbers in the S21Matrix class.
 */
TEST(s21_overloadings, AdditionLargeNumbers) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = 1000000000;
  m1(0, 1) = 2000000000;
  m1(1, 0) = 3000000000;
  m1(1, 1) = 4000000000;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = 5000000000;
  m2(0, 1) = 6000000000;
  m2(1, 0) = 7000000000;
  m2(1, 1) = 8000000000;

  S21::S21Matrix result = m1 + m2;

  EXPECT_EQ(result(0, 0), 6000000000);
  EXPECT_EQ(result(0, 1), 8000000000);
  EXPECT_EQ(result(1, 0), 10000000000);
  EXPECT_EQ(result(1, 1), 12000000000);
}

/**
 * Test for the Subtraction function in the s21_overloadings class.
 */
TEST(s21_overloadings, Subtraction) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(1, 0) = 3;
  m1(1, 1) = 4;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = 5;
  m2(0, 1) = 6;
  m2(1, 0) = 7;
  m2(1, 1) = 8;

  S21::S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), -4);
  EXPECT_EQ(result(0, 1), -4);
  EXPECT_EQ(result(1, 0), -4);
  EXPECT_EQ(result(1, 1), -4);
}

/**
 * Test case for subtraction with matrices of different sizes.
 *
 * @throws std::invalid_argument if subtraction of matrices with different sizes
 * is attempted
 */
TEST(s21_overloadings, SubtractionDifferentSizes) {
  S21::S21Matrix m1(2, 2);
  S21::S21Matrix m2(3, 3);

  ASSERT_THROW({ S21::S21Matrix result = m1 - m2; }, std::invalid_argument);
}

/**
 * Test case for subtracting a zero matrix from another matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_overloadings, SubtractionZeroMatrix) {
  S21::S21Matrix m1(2, 2);
  S21::S21Matrix m2(2, 2);

  S21::S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), 0);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 0);
}

/**
 * Test case for subtracting negative numbers from S21Matrix.
 *
 * This test case initializes two S21Matrix objects with negative numbers,
 * subtracts them, and checks the result.
 *
 */
TEST(s21_overloadings, SubtractionNegativeNumbers) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = -1;
  m1(0, 1) = -2;
  m1(1, 0) = -3;
  m1(1, 1) = -4;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = -1;
  m2(0, 1) = -1;
  m2(1, 0) = -1;
  m2(1, 1) = -1;

  S21::S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(0, 1), -1);
  EXPECT_EQ(result(1, 0), -2);
  EXPECT_EQ(result(1, 1), -3);
}

/**
 * TEST for SubtractionLargeNumbers function.
 */
TEST(s21_overloadings, SubtractionLargeNumbers) {
  S21::S21Matrix m1(2, 2);
  m1(0, 0) = 1000000000;
  m1(0, 1) = 2000000000;
  m1(1, 0) = 3000000000;
  m1(1, 1) = 4000000000;

  S21::S21Matrix m2(2, 2);
  m2(0, 0) = 5000000000;
  m2(0, 1) = 4000000000;
  m2(1, 0) = 3000000000;
  m2(1, 1) = 2000000000;

  S21::S21Matrix result = m1 - m2;

  EXPECT_EQ(result(0, 0), -4000000000);
  EXPECT_EQ(result(0, 1), -2000000000);
  EXPECT_EQ(result(1, 0), 0);
  EXPECT_EQ(result(1, 1), 2000000000);
}

/**
 * TEST function for s21_overloadings, MulNumber_Test1
 */
TEST(s21_overloadings, MulNumber_Test1) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 0), 2.0);
}

/**
 * TEST for the s21_overloadings function.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_overloadings, MulNumber_Test2) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 1), 4.0);
}

/**
 * TEST for s21_overloadings, MulNumber_Test3
 */
TEST(s21_overloadings, MulNumber_Test3) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(1, 0), 6.0);
}

/**
 * TEST(s21_overloadings, MulNumber_Test4)
 */
TEST(s21_overloadings, MulNumber_Test4) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1.0;
  mat(0, 1) = 2.0;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(1, 1), 8.0);
}

/**
 * TEST for s21_overloadings, MulNumber_Test5
 */
TEST(s21_overloadings, MulNumber_Test5) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 0.5;
  mat(0, 1) = 2.5;
  mat(1, 0) = 3.0;
  mat(1, 1) = 4.0;

  mat = mat * 2.0;

  ASSERT_EQ(mat(0, 0), 1.0);
}

/**
 * Test case for overloading the multiplication operator for matrices.
 *
 * @param s21_overloadings Test suite name
 *
 * @return void
 *
 * @throws Assertion error if the result is not as expected
 */
TEST(s21_overloadings, MulMatrix_Test1) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21::S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 0), 4.0);
}

/**
 * Test case for overloading the multiplication operator for matrices.
 */
TEST(s21_overloadings, MulMatrix_Test2) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21::S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 1), 4.0);
}

/**
 * TEST for multiplying matrices.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_overloadings, MulMatrix_Test3) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21::S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(1, 0), 10.0);
}

/**
 * TEST function for testing Matrix multiplication.
 */
TEST(s21_overloadings, MulMatrix_Test4) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 2.0;
  mat1(1, 0) = 3.0;
  mat1(1, 1) = 4.0;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 2.0;
  mat2(0, 1) = 0.0;
  mat2(1, 0) = 1.0;
  mat2(1, 1) = 2.0;

  S21::S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(1, 1), 8.0);
}

/**
 * TEST for the s21_overloadings with the MulMatrix_Test5 case.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_overloadings, MulMatrix_Test5) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1.0;
  mat1(0, 1) = 0.0;
  mat1(1, 0) = 0.0;
  mat1(1, 1) = 1.0;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 1.0;
  mat2(0, 1) = 2.0;
  mat2(1, 0) = 3.0;
  mat2(1, 1) = 4.0;

  S21::S21Matrix result = mat1 * mat2;

  ASSERT_EQ(result(0, 0), 1.0);
}

/**
 * Test case for overloading the multiplication operator of S21Matrix class to
 * throw an invalid_argument error.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument if the multiplication of matrices is not
 * possible
 */
TEST(s21_overloadings, MulMatrix_Test_throw) {
  S21::S21Matrix mat1(2, 3);
  S21::S21Matrix mat2(2, 2);
  ASSERT_THROW({ S21::S21Matrix result = mat1 * mat2; }, std::invalid_argument);
}

/**
 * Test case for assignment operator with same size matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(AssignmentOperatorTest, SameSizeMatrix) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(2, 2);
  mat2 = mat1;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat2(i, j), mat1(i, j));
    }
  }
}

/**
 * Test for assignment operator with different size matrices.
 *
 * @param AssignmentOperatorTest Test case name
 *
 * @return void
 *
 * @throws N/A
 */
TEST(AssignmentOperatorTest, DifferentSizeMatrix) {
  S21::S21Matrix mat1(2, 3);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(3, 2);
  mat2 = mat1;

  EXPECT_EQ(mat2.GetRows(), mat1.GetRows());
  EXPECT_EQ(mat2.GetCols(), mat1.GetCols());
  for (int i = 0; i < mat1.GetRows(); ++i) {
    for (int j = 0; j < mat1.GetCols(); ++j) {
      EXPECT_EQ(mat2(i, j), mat1(i, j));
    }
  }
}

/**
 * TEST function for EqualOperatorTest.
 */
TEST(EqualOperatorTest, CompareToItself) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  EXPECT_TRUE(mat == mat);
}

/**
 * Test for comparing equal matrices.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareEqualMatrices) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;

  EXPECT_TRUE(mat1 == mat2);
}

/**
 * Test case for comparing different matrices.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareDifferentMatrices) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 5;
  mat2(0, 1) = 6;
  mat2(1, 0) = 7;
  mat2(1, 1) = 8;

  EXPECT_FALSE(mat1 == mat2);
}

/**
 * Test case for comparing matrices of different sizes.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareMatricesOfDifferentSizes) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(3, 3);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(0, 2) = 0;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;
  mat2(1, 2) = 0;
  mat2(2, 0) = 0;
  mat2(2, 1) = 0;
  mat2(2, 2) = 0;

  EXPECT_FALSE(mat1 == mat2);
}

/**
 * Test case for comparing empty matrices.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareEmptyMatrices) {
  S21::S21Matrix mat1(0, 0);
  S21::S21Matrix mat2(0, 0);

  EXPECT_TRUE(mat1 == mat2);
}

/**
 * A test for comparing an empty matrix to a non-empty one.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareEmptyMatrixToNonEmpty) {
  S21::S21Matrix mat1(0, 0);
  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 2;
  mat2(1, 0) = 3;
  mat2(1, 1) = 4;

  EXPECT_FALSE(mat1 == mat2);
}

/**
 * Test case for comparing matrices with different values.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareMatricesWithDifferentValues) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 1;
  mat2(0, 1) = 3;
  mat2(1, 0) = 5;
  mat2(1, 1) = 7;

  EXPECT_FALSE(mat1 == mat2);
}

/**
 * Test case for comparing matrices with the same values but in different order.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareMatricesWithSameValuesDifferentOrder) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = 1;
  mat1(0, 1) = 2;
  mat1(1, 0) = 3;
  mat1(1, 1) = 4;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = 4;
  mat2(0, 1) = 3;
  mat2(1, 0) = 2;
  mat2(1, 1) = 1;
  EXPECT_FALSE(mat1 == mat2);
}

/**
 * Test case for comparing matrices with negative values using the
 * EqualOperatorTest.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(EqualOperatorTest, CompareMatricesWithNegativeValues) {
  S21::S21Matrix mat1(2, 2);
  mat1(0, 0) = -1;
  mat1(0, 1) = -2;
  mat1(1, 0) = -3;
  mat1(1, 1) = -4;

  S21::S21Matrix mat2(2, 2);
  mat2(0, 0) = -1;
  mat2(0, 1) = -2;
  mat2(1, 0) = -3;
  mat2(1, 1) = -4;

  EXPECT_TRUE(mat1 == mat2);
}

/**
 * Test case for adding a matrix to itself using the += operator.
 *
 */
TEST(PlusEqualOperatorTest, AddToItself) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  mat += mat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), (i * 2 + j + 1) * 2);
    }
  }
}

/**
 * TEST function for PlusEqualOperatorTest with AddZeroMatrix scenario.
 */
TEST(PlusEqualOperatorTest, AddZeroMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix zeroMat(2, 2);

  mat += zeroMat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

/**
 * Test case for adding a non-zero matrix to a zero matrix and verifying the
 * result.
 *
 * @param PlusEqualOperatorTest parameter for the test case
 *
 * @return void since it's a test case
 *
 * @throws N/A since it's a test case
 */
TEST(PlusEqualOperatorTest, AddToZeroMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix zeroMat(2, 2);

  zeroMat += mat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(zeroMat(i, j), i * 2 + j + 1);
    }
  }
}

/**
 * Test case for subtracting a zero matrix from another matrix and checking that
 * the values remain unchanged.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(MinusEqualOperatorTest, SubtractZeroMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix zeroMat(2, 2);

  mat -= zeroMat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), i * 2 + j + 1);
    }
  }
}

/**
 * Test case for subtracting a matrix from a zero matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(MinusEqualOperatorTest, SubtractFromZeroMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix zeroMat(2, 2);

  zeroMat -= mat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(zeroMat(i, j), -(i * 2 + j + 1));
    }
  }
}

/**
 * Test for multiplying a matrix by itself using the *= operator.
 *
 * @param MultiplyEqualOperatorTest test case name
 *
 * @return void
 *
 * @throws N/A
 */
TEST(MultiplyEqualOperatorTest, MultiplyByItselfMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix expectedResult(2, 2);
  expectedResult(0, 0) = 7;
  expectedResult(0, 1) = 10;
  expectedResult(1, 0) = 15;
  expectedResult(1, 1) = 22;

  mat *= mat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), expectedResult(i, j));
    }
  }
}

/**
 * Test case for multiplying a matrix by a zero matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(MultiplyEqualOperatorTest, MultiplyByZeroMatrix) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;

  S21::S21Matrix zeroMat(2, 2);

  mat *= zeroMat;

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(mat(i, j), 0);
    }
  }
}

/**
 * TEST for overloading brackets.
 *
 */
TEST(OverloadingBrackets, OverloadingBrackets_1) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(0, 0), 1);
}

/**
 * Test for overloading brackets with throw.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::out_of_range
 */
TEST(OverloadingBrackets, OverloadingBrackets_throw) {
  S21::S21Matrix mat(2, 2);
  EXPECT_THROW(mat(0, 3), std::out_of_range);
}

/**
 * Test case for overloading the bracket operator.
 *
 * @param OverloadingBrackets_2 the test case name
 *
 * @return void
 *
 * @throws N/A
 */
TEST(OverloadingBrackets, OverloadingBrackets_2) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(0, 1), 2);
}

/**
 * Test case for overloading the brackets operator.
 *
 * @param OverloadingBrackets_3 No parameters
 *
 * @return void No return value
 *
 * @throws Assertion error if the test case fails
 */
TEST(OverloadingBrackets, OverloadingBrackets_3) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(1, 0), 3);
}

/**
 * Test case for overloading the brackets operator in C++.
 *
 * No parameters
 *
 * No return value
 *
 * No exceptions thrown
 */
TEST(OverloadingBrackets, OverloadingBrackets_4) {
  S21::S21Matrix mat(2, 2);
  mat(0, 0) = 1;
  mat(0, 1) = 2;
  mat(1, 0) = 3;
  mat(1, 1) = 4;
  EXPECT_EQ(mat(1, 1), 4);
}

/**
 * Test for the OperatorMulEqualsScalar function in the S21MatrixTest class.
 */
TEST(S21MatrixTest, OperatorMulEqualsScalar) {
  S21::S21Matrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;

  matrix *= 2.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 8.0);
}
