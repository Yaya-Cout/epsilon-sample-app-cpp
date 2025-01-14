#ifndef STDINT_H
#define STDINT_H


typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long long int64_t;

typedef unsigned int uintptr_t;
typedef signed int intptr_t;

typedef uint32_t uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef int32_t int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint8_t uint_least8_t;

typedef uint32_t size_t;

#define INT8_MAX 0x7f
#define INT8_MIN (-INT8_MAX-1)

#define UINT8_MAX 0xff
#define UINT16_MAX 0xffff

#define INT16_MAX 0x7fff
#define INT16_MIN (-INT16_MAX-1)

#define UINT64_C(c) c ## ULL
#define INT64_C(c) c ## LL

// Define intmax_t and uintmax_t types
#ifndef __intmax_t_defined
typedef long long intmax_t;
#define __intmax_t_defined
#endif

#ifndef __uintmax_t_defined
typedef unsigned long long uintmax_t;
#define __uintmax_t_defined
#endif

#endif
