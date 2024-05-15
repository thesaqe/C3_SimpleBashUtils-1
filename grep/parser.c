#include "s21_grep.h"

int parser(int argc, char *argv[], flags *flag, grep_values *value,
           char patterns[SIZE][SIZE]) {
  int opt = 0;
  opterr = 0;

  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) != -1) {
    switch (opt) {
      case 'e':
        while (*patterns[value->count_pattern] != 0) {
          value->count_pattern = value->count_pattern + 1;
        }
        strcpy(patterns[value->count_pattern], optarg);
        value->count_pattern = value->count_pattern + 1;
        flag->eflag = 1;
        break;
      case 'i':
        flag->iflag = 1;
        break;
      case 'v':
        flag->vflag = 1;
        break;
      case 'c':
        flag->cflag = 1;
        break;
      case 'l':
        flag->lflag = 1;
        break;
      case 'n':
        flag->nflag = 1;
        break;
      case 'h':
        flag->hflag = 1;
        break;
      case 's':
        flag->sflag = 1;
        break;
      case 'f':
        while (*patterns[value->count_pattern] != 0) {
          value->count_pattern = value->count_pattern + 1;
        }
        f_flag(optarg, patterns, value);
        flag->fflag = 1;
        break;
      case 'o':
        flag->oflag = 1;
        break;
      case '?':
        flag->errorflag = 1;
        break;
    }
  }
  return optind;
}

void f_flag(char *path, char pattern[SIZE][SIZE], grep_values *value) {
  FILE *filename;
  int lenght = 0;
  if (access(path, F_OK) == 0) {
    filename = fopen(path, "r");
    while (!feof(filename)) {
      fgets(pattern[value->count_pattern], SIZE, filename);
      lenght = strlen(pattern[value->count_pattern]);

      if (pattern[value->count_pattern][0] != '\n' &&
          pattern[value->count_pattern][lenght - 1] == '\n') {
        pattern[value->count_pattern][lenght - 1] = '\0';
      }
      value->count_pattern = value->count_pattern + 1;
    }
    fclose(filename);
  }
}
