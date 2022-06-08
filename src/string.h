#ifndef STRING_H
#define STRING_H

#include "stddef.h"

extern "C" {

void * memcpy(void * dst, const void * src, size_t n);
void * memset(void * b, int c, size_t len);
size_t strlen(const char * s);
char * strncpy(char * dst, const char * src, size_t n);
char * strrchr(const char * s, int c);
int strcmp(const char * s1, const char * s2);

}

#endif
