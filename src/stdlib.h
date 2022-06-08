#include <stdint.h>
#ifndef STDLIB_H
#define STDLIB_H

// Abs
inline int abs(int n) { return n < 0 ? -n : n; }
// Malloc
inline void* malloc(size_t size) { return malloc(size); }
// Free
inline void free(void* ptr) { free(ptr); }

#endif

