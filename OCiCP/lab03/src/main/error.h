#pragma once

enum Error { JUST_QUIT, CHILD_FAILED };

void error(enum Error code, const char *format, ...)
    __attribute__((format(printf, 2, 3)));
