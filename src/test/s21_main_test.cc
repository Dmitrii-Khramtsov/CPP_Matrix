// Copyright 2024 Dmitrii Khramtsov

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "s21_matrix_test.h"

/**
 * Main function for running the C++ program.
 *
 * @param argc the count of command line arguments
 * @param argv an array of C-style strings representing the command line
 * arguments
 *
 * @return the result of running all tests
 *
 * @throws None
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
