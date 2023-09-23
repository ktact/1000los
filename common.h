#pragma once

#include "type.h"

#define va_list  __builtin_va_list
#define va_start __builtin_va_start
#define va_end   __builtin_va_end
#define va_arg   __builtin_va_arg

void printf(const char *fmt, ...);
void *memset(void *buf, char c, size_t n);
