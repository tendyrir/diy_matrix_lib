CC = gcc -g
FLAG_C = -c
FLAG_O = -o
#ASAN = -g -O0 -fsanitize=address #-fsanitize=undefined -fanalyzer 
FLAG_COV = --coverage 
FLAG_ER = -Wall -Werror -Wextra -std=c11 -pedantic
s21_MATRIX_C = s21_*.c 
s21_MATRIX_O = s21_*.o

all: clean s21_matrix.a test #gcov_report

s21_matrix.a:
	$(CC)  $(ASAN) $(FLAG_C) $(FLAG_ER) $(s21_MATRIX_C) 
	ar rc s21_matrix.a $(s21_MATRIX_O)
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(ASAN) $(FLAG_ER) $(FLAG_COV) $(FLAG_O) tests s21_matrix.a $(s21_MATRIX_C) test.c -lcheck 
	./tests

clean:
	-rm -rf *.o *.html *.gcda *.gcno *.css *.a *.gcov *.info *.out *.cfg *.txt
	-rm -f tests
	-rm -f report
	find . -type d -name 'tests.dSYM' -exec rm -r {} +

gcov_report: test
	gcov s21_*.gcda	
	gcovr
	gcovr --html-details -o report.html
	open report.html

leaks:
	CK_FORK=no leaks --atExit -- ./tests

lint:
	cppcheck --enable=all --force --suppress=missingIncludeSystem *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	
check:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./tests
