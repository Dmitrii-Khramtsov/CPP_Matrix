# CPP_Matrix

Methods of the CPP_Matrix project,
which implements a library for working with matrices.



## Contents

1. [Introduction](#introduction)
2. [Build](#build)
3. [Tests](#tests)


## Introduction

Implementation of a library for working with matrices using an object-oriented approach. The object-oriented approach allows you to implement a library for working with matrices in the form of a separate class, on the objects of which operations are defined, represented by both methods and standard operators +, -, *, etc.


## Matrix operations

Below is a brief description of the matrix operations that need to be implemented in the development library.
They are similar to the operations you performed earlier in "Structured Programming", so you can see a more detailed description of them there.
Note that some operations have exceptional situations that require special handling using the exception mechanism.

| Operation | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Checks matrices for equality with each other. |  |
| `void SumMatrix(const S21Matrix& other)` | Adds the second matrix to the current one | different matrix dimensions. |
| `void SubMatrix(const S21Matrix& other)` | Subtracts another matrix from the current one | different matrix dimensions. |
| `void MulNumber(const double num) ` | Multiplies the current matrix by a number. |  |
| `void MulMatrix(const S21Matrix& other)` | Multiplies the current matrix by the second matrix. | The number of columns of the first matrix is not equal to the number of rows of the second matrix. |
| `S21Matrix Transpose()` | Creates a new transposed matrix from the current one and returns it. |  |
| `S21Matrix CalcComplements()` | Calculates the algebraic addition matrix of the current one and returns it. | The matrix is not square. |
| `double Determinant()` | Calculates and returns the determinant of the current matrix. | The matrix is not square. |
| `S21Matrix InverseMatrix()` | Calculates and returns the inverse matrix. | Matrix determinant is 0. |

Apart from those operations, you also need to implement constructors and destructors:

| Method | Description |
| ----------- | ----------- |
| `S21Matrix()` | A basic constructor that initialises a matrix of some predefined dimension. |  
| `S21Matrix(int rows, int cols) ` | Parametrized constructor with number of rows and columns. |
| `S21Matrix(const S21Matrix& other)` | Copy constructor. |
| `S21Matrix(S21Matrix&& other)` | Move constructor. |
| `~S21Matrix()` | Destructor. |

And you also need to overload the following operators, partly corresponding to the operations above:

| Operator | Description | Exceptional situations |
| ----------- | ----------- | ----------- |
| `+`      | Addition of two matrices. | Different matrix dimensions. |
| `-`   | Subtraction of one matrix from another. | Different matrix dimensions. |
| `*`  | Matrix multiplication and matrix multiplication by a number. | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `==`  | Checks for matrices equality (`EqMatrix`). | |
| `=`  | Assignment of values from one matrix to another one. | |
| `+=`  | Addition assignment (`SumMatrix`) | different matrix dimensions. |
| `-=`  | Difference assignment (`SubMatrix`) | different matrix dimensions. |
| `*=`  | Multiplication assignment (`MulMatrix`/`MulNumber`). | The number of columns of the first matrix does not equal the number of rows of the second matrix. |
| `(int i, int j)`  | Indexation by matrix elements (row, column). | Index is outside the matrix. |


## Build
```
$ git clone git@github.com:Dmitrii-Khramtsov/CPP_Matrix.git
$ cd CPP_Matrix/src
$ make
```


## Tests
Unit tests are implemented using [googletest](https://google.github.io/googletest /), coverage report using [LCOV](https://github.com/linux-test-project/lcov )
```
$ git clone git@github.com:Dmitrii-Khramtsov/CPP_Matrix.git
$ cd CPP_Matrix/src
$ make test
```
Coverage Report:
```
$ git clone git@github.com:Dmitrii-Khramtsov/CPP_Matrix.git
$ cd CPP_Matrix/src
$ make gcovr_report
```
