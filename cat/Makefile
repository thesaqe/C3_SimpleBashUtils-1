FLAGS= -std=c11 -Wall -Werror -Wextra -pedantic

all: s21_cat

rebuild: clean all

s21_cat: s21_cat.c
	gcc $(FLAGS) s21_cat.c parser.c reader.c -o s21_cat
clean:
	rm -rf s21_cat
clang:
	clang-format -n *.c *.h