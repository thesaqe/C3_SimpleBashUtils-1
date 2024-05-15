#include "s21_grep.h"

int main(int argc, char *argv[]) {
  char patterns[SIZE][SIZE] = {0};
  int opt_ind = 0;
  flags option = {0};
  grep_values value = {0};

  int file_location = 0;
  opt_ind = parser(argc, argv, &option, &value, patterns);

  if (argc >= 3 && option.errorflag != 1 && opt_ind != argc) {
    file_location = find_pattern(opt_ind, argv, patterns);
    while (file_location < argc) {
      if (argv[file_location + 1] != NULL) {
        value.count_files = value.count_files + 1;
      }
      value.path = argv[file_location];
      grep_file(value, option, patterns);
      file_location++;
    }
  }
}
