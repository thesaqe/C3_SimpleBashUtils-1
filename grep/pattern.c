#include "s21_grep.h"

int find_pattern(int opt_ind, char *argv[], char patterns[SIZE][SIZE]) {
  int file_location = 0;
  if (*patterns[0] == 0) {
    file_location = opt_ind + 1;
    strcpy(patterns[0], argv[optind]);
  } else {
    file_location = opt_ind;
  }
  return file_location;
}
