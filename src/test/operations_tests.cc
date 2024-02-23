// Copyright 2024 Dmitrii Khramtsov

#include "s21_matrix_test.h"

/**
 * TEST for sum_matrix_1 function.
 */
TEST(s21_operation_tests, sum_matrix_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SumMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 2);
    }
  }
}

/**
 * TEST for sum_matrix_incorrect_size_2
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument
 */
TEST(s21_operation_tests, sum_matrix_incorrect_size_2) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = S21::S21Matrix(5, 5);
  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
}

/**
 * TEST for sum_matrix_3 function.
 */
TEST(s21_operation_tests, sum_matrix_3) {
  S21::S21Matrix m1 = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};
  S21::S21Matrix m2 = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};

  double matrix_res[3][3] = {{2, 4, 6}, {2, 4, 6}, {2, 4, 6}};
  m1.SumMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), matrix_res[i][j]);
    }
  }
}

/**
 * Test for subtracting two matrices.
 *
 * @param s21_operation_tests The name of the test suite
 *
 * @return void
 *
 * @throws None
 */
TEST(s21_operation_tests, sub_matrix_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.SubMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

/**
 * A test for the sub_matrix_2 function.
 */
TEST(s21_operation_tests, sub_matrix_2) {
  S21::S21Matrix m1 = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};
  S21::S21Matrix m2 = {{1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}};

  m1.SubMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

/**
 * TEST for sum_matrix_incorrect_size_3 in s21_operation_tests.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument if the submatrix operation fails
 */
TEST(s21_operation_tests, sum_matrix_incorrect_size_3) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = S21::S21Matrix(5, 5);
  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
}

/**
 * Test case for multiplying a matrix by a number.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, mul_number_1) {
  S21::S21Matrix m1 = {{5, 6}, {7, 8}};

  S21::S21Matrix m2 = {{50, 60}, {70, 80}};
  m1.MulNumber(10);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), m2(i, j));
    }
  }
}

/**
 * Test case for multiplying a number by 0.5.
 *
 * No parameters
 *
 * No return value
 *
 * Throws no errors
 */
TEST(s21_operation_tests, mul_number_2) {
  S21::S21Matrix m1 = S21::S21Matrix(1, 1);
  m1(0, 0) = 5;
  m1.MulNumber(0.5);
  EXPECT_EQ(m1(0, 0), 2.5);
}

/**
 * TEST for multiplying a matrix by 0.
 *
 * No parameters
 *
 * No return value
 *
 * No errors thrown
 */
TEST(s21_operation_tests, mul_number_3) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.MulNumber(0);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

/**
 * Test case for multiplying two matrices and checking the result.
 *
 * This test case creates two 3x3 matrices filled with 1.0 values, multiplies
 * them together using the MulMatrix method, and then checks that all elements
 * in the resulting matrix are equal to 3.
 */
TEST(s21_operation_tests, mul_matrix_1) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 3);
    }
  }
}

/**
 * A test for multiplying matrices that should throw an invalid_argument.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument When the matrices cannot be multiplied.
 */
TEST(s21_operation_tests, mul_matrix_throw) {
  S21::S21Matrix m1 = {{1.0, 1.0, 1.}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
  S21::S21Matrix m2 = S21::S21Matrix(5, 5);
  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
}

/**
 * Test for multiplying a 2x3 matrix by a 3x2 matrix and checking the result.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, mul_matrix_2) {
  S21::S21Matrix m1 = S21::S21Matrix(1, 3);
  S21::S21Matrix m2 = S21::S21Matrix(3, 2);
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), 0);
    }
  }
}

/**
 * A test case for the mul_matrix_3 function in the s21_operation_tests suite.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, mul_matrix_3) {
  S21::S21Matrix m1 = S21::S21Matrix(1, 3);
  S21::S21Matrix m2 = S21::S21Matrix(3, 2);
  m1.MulMatrix(m2);
  EXPECT_EQ(m1.GetRows(), 1);
  EXPECT_EQ(m1.GetCols(), 2);
}

/**
 * TEST for the mul_matrix_4 function in the s21_operation_tests suite.
 */
TEST(s21_operation_tests, mul_matrix_4) {
  S21::S21Matrix m1 = {{1, 2, 3}, {4, 5, 6}};
  S21::S21Matrix m2 = {{7, 8}, {9, 1}, {2, 3}};

  double proizv[2][2] = {{31, 19}, {85, 55}};
  m1.MulMatrix(m2);
  for (int i = 0; i != m1.GetRows(); ++i) {
    for (int j = 0; j != m1.GetCols(); ++j) {
      EXPECT_EQ(m1(i, j), proizv[i][j]);
    }
  }
}

/**
 * TEST for multiplying matrices in the s21_operation_tests C++ function.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, mul_matrix_5) {
  S21::S21Matrix m1 = {{1, 2, 3}, {4, 5, 6}};
  S21::S21Matrix m2 = {{7, 8}, {9, 1}, {2, 3}};

  m1.MulMatrix(m2);
  EXPECT_EQ(2, m1.GetCols());
  EXPECT_EQ(2, m1.GetRows());
}

/**
 * TEST for transposing a matrix.
 */
TEST(s21_operation_tests, transpose_1) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(2, 3);
  S21::S21Matrix transposed_matrix = origin_matrix.Transpose();
  EXPECT_EQ(3, transposed_matrix.GetRows());
  EXPECT_EQ(2, transposed_matrix.GetCols());
}

/**
 * Test case for the transpose_2 function.
 */
TEST(s21_operation_tests, transpose_2) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(2, 3);
  S21::S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(0, transposed_matrix(i, j));
    }
  }
}
/**
 * This is a test for transposing a 3x2 matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, transpose_3) {
  S21::S21Matrix origin_matrix = {{1, 2, 3}, {4, 5, 6}};

  double t_m[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  S21::S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(t_m[i][j], transposed_matrix(i, j));
    }
  }
}

/**
 * Test case for transposing a 4x3 matrix.
 */
TEST(s21_operation_tests, transpose_4) {
  S21::S21Matrix origin_matrix = {{5, 4}, {5, 4}, {5, 4}};

  double t_m[2][3] = {{5, 5, 5}, {4, 4, 4}};
  S21::S21Matrix transposed_matrix = origin_matrix.Transpose();
  for (int i = 0; i != transposed_matrix.GetRows(); ++i) {
    for (int j = 0; j != transposed_matrix.GetCols(); ++j) {
      EXPECT_EQ(t_m[i][j], transposed_matrix(i, j));
    }
  }
}

/**
 * Test case for the determinant_1 function.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, determinant_1) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(1, 1);
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

/**
 * TEST function for s21_operation_tests.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument if the determinant calculation throws an error
 */
TEST(s21_operation_tests, determinant_throw) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(1, 2);
  EXPECT_THROW(origin_matrix.Determinant(), std::invalid_argument);
}

/**
 * Test case for the determinant_2 function in s21_operation_tests.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, determinant_2) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(2, 2);
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

/**
 * Test for the determinant_3 function in the s21_operation_tests suite.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, determinant_3) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(3, 3);
  origin_matrix(0, 0) = 1;
  origin_matrix(0, 1) = 1;
  origin_matrix(0, 2) = 1;
  origin_matrix(1, 0) = 1;
  origin_matrix(1, 1) = 1;
  origin_matrix(1, 2) = 1;
  origin_matrix(2, 0) = 1;
  origin_matrix(2, 1) = 1;
  origin_matrix(2, 2) = 1;
  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

/**
 * Test for calculating the determinant of a 3x3 matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, determinant_4) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(3, 3);
  origin_matrix(0, 0) = 0;
  origin_matrix(0, 1) = -1;
  origin_matrix(0, 2) = 3;
  origin_matrix(1, 0) = 0;
  origin_matrix(1, 1) = 1;
  origin_matrix(1, 2) = -2;
  origin_matrix(2, 0) = 5;
  origin_matrix(2, 1) = 4;
  origin_matrix(2, 2) = 1;
  EXPECT_EQ(origin_matrix.Determinant(), -5);
}

/**
 * TEST for the s21_operation_tests function, with the determinant of a 5x5
 * matrix.
 */
TEST(s21_operation_tests, determinant_5) {
  S21::S21Matrix origin_matrix = {
      {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 0, 1}, {2, 3, 4, 5}};

  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

/**
 * Test case for calculating the determinant of a 3x3 matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, determinant_6) {
  S21::S21Matrix origin_matrix = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

  EXPECT_EQ(origin_matrix.Determinant(), 0);
}

/**
 * Test case for calccomplements_1 in s21_operation_tests.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, calccomplements_1) {
  S21::S21Matrix origin_matrix = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};

  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 3; ++j) {
      EXPECT_EQ(0, calcs(i, j));
    }
  }
}

/**
 * Test case for calculating complements that should throw an invalid argument
 * error.
 *
 */
TEST(s21_operation_tests, calccomplements_throw) {
  S21::S21Matrix origin_matrix = S21::S21Matrix(3, 4);
  EXPECT_THROW(origin_matrix.CalcComplements(), std::invalid_argument);
}

/**
 * Test case for calccomplements_2 in s21_operation_tests.
 */
TEST(s21_operation_tests, calccomplements_2) {
  S21::S21Matrix origin_matrix = {{1, 2}, {1, 1}};

  S21::S21Matrix calcs_d = {{1, -1}, {-2, 1}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i != 2; ++i) {
    for (int j = 0; j != 2; ++j) {
      EXPECT_EQ(calcs_d(i, j), calcs(i, j));
    }
  }
}

/**
 * Test case for calculating complements of a 2x2 matrix.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(s21_operation_tests, calccomplements_3) {
  S21::S21Matrix origin_matrix = {{1, 2}, {1, 1}};

  double calcs_d[2][2] = {{1, -1}, {-2, 1}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

/**
 * TEST for calccomplements_4 function.
 */
TEST(s21_operation_tests, calccomplements_4) {
  S21::S21Matrix origin_matrix = {{1, 2, 3}, {2, -1, 3}, {3, 4, -1}};

  double calcs_d[3][3] = {{-11, 11, 11}, {14, -10, 2}, {9, 3, -5}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

/**
 * TEST for calccomplements_5 function in s21_operation_tests
 */
TEST(s21_operation_tests, calccomplements_5) {
  S21::S21Matrix origin_matrix = {{1, 2}, {3, 4}};

  double calcs_d[2][2] = {{4, -3}, {-2, 1}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

/**
 * Test case for calccomplements_6 function.
 */
TEST(s21_operation_tests, calccomplements_6) {
  S21::S21Matrix origin_matrix = {{2, -1, 3}, {0, 1, -2}, {5, 4, 1}};

  double calcs_d[3][3] = {{9, -10, -5}, {13, -13, -13}, {-1, 4, 2}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

/**
 * Test case for calccomplements_7 function.
 */
TEST(s21_operation_tests, calccomplements_7) {
  S21::S21Matrix origin_matrix = {{3, 0}, {0, 2}};
  double calcs_d[2][2] = {{2, 0}, {0, 3}};
  S21::S21Matrix calcs = origin_matrix.CalcComplements();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(calcs_d[i][j], calcs(i, j));
    }
  }
}

/**
 * TEST for inverse_matrix_1
 */
TEST(inverse_matrix_tests, inverse_matrix_1) {
  S21::S21Matrix matrix = {{1, 2}, {1, 1}};

  double o[2][2] = {{-1, 2}, {1, -1}};
  S21::S21Matrix test = matrix.InverseMatrix();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(o[i][j], test(i, j));
    }
  }
}

/**
 * TEST for the inverse_matrix_2 function.
 *
 * @param None
 *
 * @return None
 *
 * @throws None
 */
TEST(inverse_matrix_tests, inverse_matrix_2) {
  S21::S21Matrix matrix = {{1, 2}, {3, 4}};

  double o[2][2] = {{-2, 1}, {1.5, -0.5}};
  S21::S21Matrix test = matrix.InverseMatrix();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      EXPECT_EQ(o[i][j], test(i, j));
    }
  }
}

/**
 * A test case for the inverse_matrix_throw_incorrect_size function.
 *
 * @param None
 *
 * @return None
 *
 * @throws std::invalid_argument if the matrix size is incorrect
 */
TEST(inverse_matrix_tests, inverse_matrix_throw_incorrect_size) {
  S21::S21Matrix matrix = S21::S21Matrix(3, 2);
  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}

/**
 * Test case for checking if the inverse matrix function throws an exception
 * when the determinant is zero.
 *
 * @throws std::invalid_argument if the determinant of the matrix is zero
 */
TEST(inverse_matrix_tests, inverse_matrix_throw_zero_determinant) {
  S21::S21Matrix matrix = S21::S21Matrix(2, 2);
  EXPECT_THROW(matrix.InverseMatrix(), std::invalid_argument);
}
