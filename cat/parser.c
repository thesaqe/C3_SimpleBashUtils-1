#include "s21_cat.h"

int parser(int argc, char *argv[], flags *flag) {
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  int current_option = 0;

  while ((current_option =
              getopt_long(argc, argv, "beEnstTv?", long_options, NULL)) != -1) {
    switch (current_option) {
      case 'b':
        flag->bflag = 1;
        break;
      case 'e':
        flag->eflag = flag->vflag = 1;
        break;
      case 'E':
        flag->eflag = 1;
        break;
      case 'n':
        flag->nflag = 1;
        break;
      case 's':
        flag->sflag = 1;
        break;
      case 't':
        flag->tflag = flag->vflag = 1;
        break;
      case 'T':
        flag->tflag = 1;
        break;
      case 'v':
        flag->vflag = 1;
        break;
      case '?':
        flag->errorflag = 1;
        break;
    }
  }
  return optind;
}
