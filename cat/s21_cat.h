#ifndef S21_CAT_H
#define S21_CAT_H
#define BUFFER_SIZE 4096
#define _GNU_SOURCE

#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  int bflag;
  int eflag;
  int nflag;
  int sflag;
  int tflag;
  int vflag;
  int errorflag;
} flags;

int parser(int argc, char *argv[], flags *flag);
void read_file(char *path, flags option);
#endif  // S21_CAT_H
