/***************************************************************************
 * FILE: wctype.h/cwctype (Wide character classification functions)
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
 * Description: This header is part of the C/C++ standard library. It
 *              declares functions and types used to classify wide
 *              characters.
 ***************************************************************************/
#ifndef _WCTYPE_H_INCLUDED
#define _WCTYPE_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus

#include <cwctype>

// C99 types in wctype.h
#ifndef _WINT_T_DEFINED
#define _WINT_T_DEFINED
#define _WINT_T_DEFINED_
using std::wint_t;
#endif
#ifndef _WCTYPE_T_DEFINED
#define _WCTYPE_T_DEFINED
#define _WCTYPE_T_DEFINED_
using std::wctype_t;
#endif

// C99 functions in wctype.h
using std::iswalnum;
using std::iswalpha;
using std::iswcntrl;
using std::iswdigit;
using std::iswgraph;
using std::iswlower;
using std::iswprint;
using std::iswpunct;
using std::iswspace;
using std::iswupper;
using std::iswxdigit;
using std::iswctype;
using std::wctype;
using std::towlower;
using std::towupper;

#if !defined(NO_EXT_KEYS) || __STDC_VERSION__ >= 199901L /* extensions enabled or C99 */
using std::iswblank;
#endif /* extensions enabled */

#else /* __cplusplus not defined */

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

 #ifndef _WINT_T_DEFINED
 #define _WINT_T_DEFINED
  #define _WINT_T_DEFINED_
  typedef unsigned short wint_t;
 #endif

 #ifndef _WCTYPE_T_DEFINED
 #define _WCTYPE_T_DEFINED
  #define _WCTYPE_T_DEFINED_
  typedef unsigned short wctype_t;
 #endif

 #ifndef _WCTRANS_T_DEFINED
 #define _WCTRANS_T_DEFINED
  #define _WCTRANS_T_DEFINED_
  typedef unsigned short wctrans_t;
 #endif

#define WEOF ((wint_t)(-1))

_WCRTLINK extern int      iswalnum( wint_t __wc );
_WCRTLINK extern int      iswalpha( wint_t __wc );
_WCRTLINK extern int      iswascii( wint_t __wc );
_WCRTLINK extern int      iswcntrl( wint_t __wc );
_WCRTLINK extern int      iswdigit( wint_t __wc );
_WCRTLINK extern int      iswgraph( wint_t __wc );
_WCRTLINK extern int      iswlower( wint_t __wc );
_WCRTLINK extern int      iswprint( wint_t __wc );
_WCRTLINK extern int      iswpunct( wint_t __wc );
_WCRTLINK extern int      iswspace( wint_t __wc );
_WCRTLINK extern int      iswupper( wint_t __wc );
_WCRTLINK extern int      iswxdigit( wint_t __wc );
_WCRTLINK extern int      iswctype( wint_t __wc, wctype_t __desc );
_WCRTLINK extern wctype_t wctype( const char *__property );
_WCRTLINK extern wint_t   towctrans( wint_t __wc, wctrans_t __desc );
_WCRTLINK extern wint_t   towlower( wint_t __wc );
_WCRTLINK extern wint_t   towupper( wint_t __wc );
_WCRTLINK extern wctrans_t wctrans( const char *__property );

#if !defined(NO_EXT_KEYS) || __STDC_VERSION__ >= 199901L /* extensions enabled or C99 */
_WCRTLINK extern int      iswblank( wint_t __wc );
#endif /* extensions enabled */

_WCRTLINK extern int      __iswcsymf( wint_t __wc );
_WCRTLINK extern int      __iswcsym( wint_t __wc );

#endif /* __cplusplus not defined */

#endif
