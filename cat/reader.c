#include "s21_cat.h"

void read_file(char *path, flags flag) {
  if (access(path, F_OK) == 0) {
    FILE *filename = fopen(path, "r");
    if (filename == NULL) {
      fprintf(stderr, "Error opening file %s: %s\n", path, strerror(errno));
      return;
    }

    char ch, prev;

    int line_num = 1;
    int empty_line_count = 0;
    for (prev = '\n'; (ch = getc(filename)) != EOF; prev = ch) {
      if (flag.sflag == 1) {
        if (ch == '\n' && prev == '\n') {
          if (empty_line_count == 1) {
            continue;
          }
          empty_line_count++;
        } else
          empty_line_count = 0;
      }

      if (flag.bflag == 1) {
        if (prev == '\n' && ch != '\n') {
          printf("%*d\t", 6, line_num);
          line_num++;
        }
      }

      if (flag.nflag == 1 && flag.bflag == 0 && prev == '\n') {
        printf("%*d\t", 6, line_num);
        line_num++;
      }

      if (flag.eflag == 1 && flag.bflag == 0 && ch == '\n') {
        putchar('$');
      }

      if (flag.eflag == 1 && flag.bflag == 1 && ch == '\n') {
        if (prev == '\n' && ch == '\n') {
          printf("%6c\t", ' ');
        }
        putchar('$');
      }

      if (flag.tflag == 1 && ch == '\t') {
        printf("^");
        ch = 'I';
      }

      if (flag.vflag == 1) {
        if ((ch >= 0 && ch <= 31) && ch != '\t' && ch != '\n') {
          printf("^");
          ch = ch + 64;

        } else if (ch == 127) {
          printf("^");
          ch = ch - 64;
        }
      }
      putchar(ch);
    }
    fclose(filename);
  } else {
    fprintf(stderr, "s21_cat: %s: No such file or directory\n", path);
  }
}
