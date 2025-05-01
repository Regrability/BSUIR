#include "error.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void error(enum Error code, const char *format, ...) {
  va_list formatArgs;
  va_start(formatArgs, format);
  vfprintf(stderr, format, formatArgs);
  va_end(formatArgs);
  putc('\n', stderr);
  exit(code);
}
