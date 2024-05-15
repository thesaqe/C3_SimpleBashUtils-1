#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int number_of_files;
  flags program_flags = {0};
  number_of_files = parser(argc, argv, &program_flags);

  if (program_flags.errorflag == 1) {
    fprintf(stderr, "usage: [-benstv] [file ...]");
  } else {
    while (number_of_files < argc) {
      char *path = argv[number_of_files];
      read_file(path, program_flags);
      number_of_files++;
    }
  }
  return 0;
}
