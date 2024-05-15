FLAGS= -std=c11 -Wall -Werror -Wextra -pedantic

all: s21_grep

rebuild: clean all

s21_grep: s21_grep.c
	gcc $(FLAGS) s21_grep.c grep.c parser.c pattern.c -o s21_grep
clean:
	rm -rf s21_grep
clang:
	clang-format -n *.c *.h