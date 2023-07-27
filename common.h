#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define FAIL    (-1)
#define OK      (0)

inline void panic(const char *err_type, const char *fmt, ...);

#endif