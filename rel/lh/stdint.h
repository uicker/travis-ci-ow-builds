/***************************************************************************
 * FILE: stdint.h/cstdint (Various integer type definitions)
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2002-2016 The Open Watcom Contributors. All Rights Reserved.
 * Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 *
 * Description: This header is part of the C99/C++ standard library. It
 *              describes a number of useful integer types.
 ***************************************************************************/
#ifndef _STDINT_H_INCLUDED
#define _STDINT_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus

#include <cstdint>

using std::int8_t;
using std::uint8_t;
using std::int16_t;
using std::uint16_t;
using std::int32_t;
using std::uint32_t;
using std::int64_t;
using std::uint64_t;
using std::int_least8_t;
using std::uint_least8_t;
using std::int_least16_t;
using std::uint_least16_t;
using std::int_least32_t;
using std::uint_least32_t;
using std::int_least64_t;
using std::uint_least64_t;
using std::int_fast8_t;
using std::uint_fast8_t;
using std::int_fast16_t;
using std::uint_fast16_t;
using std::int_fast32_t;
using std::uint_fast32_t;
using std::int_fast64_t;
using std::uint_fast64_t;
using std::intptr_t;
using std::uintptr_t;
using std::intmax_t;
using std::uintmax_t;

#else /* __cplusplus not defined */

/* Limit macros */

/* Exact-width types. */
#define INT8_MIN   (-128)
#define INT8_MAX   127
#define INT16_MIN  (-32767-1)
#define INT16_MAX  32767
#define INT32_MIN  (-2147483647L-1)
#define INT32_MAX  2147483647L
#define INT64_MIN  (-9223372036854775807LL-1)
#define INT64_MAX  9223372036854775807LL

#define UINT8_MAX   255
 #define UINT16_MAX  65535
#define UINT32_MAX  4294967295UL
#define UINT64_MAX  18446744073709551615ULL

/* Minimum-width types. */
#define INT_LEAST8_MIN   (-128)
#define INT_LEAST8_MAX   127
#define INT_LEAST16_MIN  (-32767-1)
#define INT_LEAST16_MAX  32767
#define INT_LEAST32_MIN  (-2147483647L-1)
#define INT_LEAST32_MAX  2147483647L
#define INT_LEAST64_MIN  (-9223372036854775807LL-1)
#define INT_LEAST64_MAX  9223372036854775807LL

#define UINT_LEAST8_MAX   255
 #define UINT_LEAST16_MAX  65535
#define UINT_LEAST32_MAX  4294967295UL
#define UINT_LEAST64_MAX  18446744073709551615ULL

/* Fast minimum-width types. */
 #define INT_FAST8_MIN   (-2147483647-1)
 #define INT_FAST8_MAX   2147483647
 #define INT_FAST16_MIN  (-2147483647-1)
 #define INT_FAST16_MAX  2147483647
#define INT_FAST32_MIN  (-2147483647L-1)
#define INT_FAST32_MAX  2147483647L
#define INT_FAST64_MIN  (-9223372036854775807LL-1)
#define INT_FAST64_MAX  9223372036854775807LL

 #define UINT_FAST8_MAX   4294967295U
 #define UINT_FAST16_MAX  4294967295U
#define UINT_FAST32_MAX  4294967295UL
#define UINT_FAST64_MAX  18446744073709551615ULL

/* Integer types able to hold object pointers. */
 #if defined(__COMPACT__) || defined(__LARGE__)
  #define INTPTR_MIN   (-9223372036854775807LL-1)
  #define INTPTR_MAX   9223372036854775807LL
  #define UINTPTR_MAX  18446744073709551615ULL
 #else
  #define INTPTR_MIN   (-2147483647L-1)
  #define INTPTR_MAX   2147483647L
  #define UINTPTR_MAX  4294967295UL
 #endif

/* Greatest-width types. */
#define INTMAX_MIN   (-9223372036854775807LL-1)
#define INTMAX_MAX   9223372036854775807LL
#define UINTMAX_MAX  18446744073709551615ULL

/* Limits of wide character types */
#define WCHAR_MIN       0
#define WCHAR_MAX       65535U
#define WINT_MIN        WCHAR_MIN
#define WINT_MAX        WCHAR_MAX

/* Limits of other integer types. */
 #define PTRDIFF_MIN     (-2147483647-1)
 #define PTRDIFF_MAX     2147483647
 #define SIG_ATOMIC_MIN  (-2147483647-1)
 #define SIG_ATOMIC_MAX  2147483647
 #define SIZE_MAX        4294967295U

/* Constant macros */

#define INT8_C(x)    (x)
#define INT16_C(x)   (x)
#define INT32_C(x)   (x + (INT32_MAX - INT32_MAX))
#define INT64_C(x)   (x + (INT64_MAX - INT64_MAX))

#define UINT8_C(x)   (x)
#define UINT16_C(x)  (x)
#define UINT32_C(x)  (x + (UINT32_MAX - UINT32_MAX))
#define UINT64_C(x)  (x + (UINT64_MAX - UINT64_MAX))

#define INTMAX_C(x)  (x + (INT64_MAX - INT64_MAX))
#define UINTMAX_C(x) (x + (UINT64_MAX - UINT64_MAX))

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ == 1

#if SIZE_MAX > 65535U
 #define RSIZE_MAX      (SIZE_MAX >> 1)
#else
 #define RSIZE_MAX      SIZE_MAX
#endif

#endif /* Safer C Library */

/*          char | short | int | long | long long                        */
/* 16 bit : 8      16      16    32     64     All 16 bit targets.       */
/* 32 bit : 8      16      32    32     64     386, AXP, PPC, MIPS       */
/* 64 bit : 8      16      32    64     64     No targets implemented.   */

/* Exact-width types. */
#ifndef _EXACT_WIDTH_INTS
#define _EXACT_WIDTH_INTS
typedef signed char         int8_t;
typedef unsigned char       uint8_t;
typedef short               int16_t;
typedef unsigned short      uint16_t;
 typedef int                int32_t;
 typedef unsigned int       uint32_t;
typedef long long           int64_t;
typedef unsigned long long  uint64_t;
#endif /* _EXACT_WIDTH_INTS */

/* Minimum-width types. */
typedef signed   char      int_least8_t;
typedef signed   short     int_least16_t;
typedef signed   long      int_least32_t;
typedef signed   long long int_least64_t;

typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned long      uint_least32_t;
typedef unsigned long long uint_least64_t;

/* Fastest minimum-width types. */
typedef signed   int       int_fast8_t;
typedef signed   int       int_fast16_t;
typedef signed   long      int_fast32_t;
typedef signed   long long int_fast64_t;

typedef unsigned int       uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned long      uint_fast32_t;
typedef unsigned long long uint_fast64_t;

/* Integer type able to hold pointers. */
#ifndef _INTPTR_T_DEFINED_
 #define _INTPTR_T_DEFINED_
  #if defined(__COMPACT__) || defined(__LARGE__)
   typedef long long intptr_t;
  #else
   typedef long intptr_t;
  #endif
#endif
/* Unsigned integer type able to hold pointers. */
#ifndef _UINTPTR_T_DEFINED_
 #define _UINTPTR_T_DEFINED_
  #if defined(__COMPACT__) || defined(__LARGE__)
   typedef unsigned long long uintptr_t;
  #else
   typedef unsigned long uintptr_t;
  #endif
#endif

/* Greatest-width types. */
typedef long long intmax_t;
typedef unsigned long long uintmax_t;

#endif /* __cplusplus not defined */

#endif
