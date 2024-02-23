NAME = s21_matrix
CC = g++
CC_FLAGS = -std=c++17 -Wall -Wextra -Werror #-g #-pedantic
GCOV_FLAGS = --coverage -lgtest -g -I/opt/homebrew/Cellar/googletest/1.14.0/include  -L/opt/homebrew/Cellar/googletest/1.14.0/lib #-lgtest_main
OS = $(shell uname)

# Цели для gcovr
GCOVR = gcovr
GCOVRFLAGS = --html --html-details -o coverage.html

ifeq ($(OS), Linux)
	CHECK_FLAGS = -lgtest -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = $(shell pkg-config --libs --cflags) -lm
endif

TEST_COMPILE = $(CC) $(CC_FLAGS) $(GCOV_FLAGS) test/*.cc libs21_matrix.a $(CHECK_FLAGS)

all: clean s21_matrix.a

clean:
	rm -rf *.o, *.g* *.info *.out report *.a *.dSYM *.html *.css

re: clean all

s21_matrix.o:
	$(CC) $(CC_FLAGS) -c *.cc

s21_matrix.a: s21_matrix.o
	ar rcs libs21_matrix.a *.o
	rm -rf *.o
	ranlib libs21_matrix.a
	cp libs21_matrix.a s21_matrix.a

test: s21_matrix.a
	$(TEST_COMPILE)
	./a.out

clang: 
	clang-format -i *.cc *.h test/*.cc test/*.h

gcovr_report: s21_matrix.a test
	rm -f *.g*
	$(CC) $(CC_FLAGS) test/*.cc *.cc libs21_matrix.a $(CHECK_FLAGS) $(GCOV_FLAGS)
	./a.out
	$(GCOVR) $(GCOVRFLAGS)
	open coverage.html
	rm -rf *.gcda *.gcno

dvi:
	doxygen doxyconfig
	open ./html/index.html

check:
	clang-format -style=google -n s21_*.cc *.h
	make test
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./a.out
else
	valgrind ./a.out --leak-check=full
endif
	make clean

.PHONY: all clean re s21_matrix.a test gcovr_report dvi check
