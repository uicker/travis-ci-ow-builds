/*
 *  fcntl.h     File control options used by open
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
 */
#ifndef _FCNTL_H_INCLUDED
#define _FCNTL_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
 #ifndef _WCHAR_T_DEFINED
 #define _WCHAR_T_DEFINED
  #define _WCHAR_T_DEFINED_
  typedef unsigned short wchar_t;
 #endif
#endif

#ifdef _M_IX86
 #pragma pack( __push, 1 )
#else
 #pragma pack( __push, 8 )
#endif

#define O_RDONLY        0x0000  /* open for read only */
#define _O_RDONLY       0x0000  /* open for read only */
#define O_WRONLY        0x0001  /* open for write only */
#define _O_WRONLY       0x0001  /* open for write only */
#define O_RDWR          0x0002  /* open for read and write */
#define _O_RDWR         0x0002  /* open for read and write */
#define O_APPEND        0x0010  /* writes done at end of file */
#define _O_APPEND       0x0010  /* writes done at end of file */
#define O_CREAT         0x0020  /* create new file */
#define _O_CREAT        0x0020  /* create new file */
#define O_TRUNC         0x0040  /* truncate existing file */
#define _O_TRUNC        0x0040  /* truncate existing file */
#define O_NOINHERIT     0x0080  /* file is not inherited by child process */
#define _O_NOINHERIT    0x0080  /* file is not inherited by child process */
#define O_TEXT          0x0100  /* text file */
#define _O_TEXT         0x0100  /* text file */
#define O_BINARY        0x0200  /* binary file */
#define _O_BINARY       0x0200  /* binary file */
#define O_EXCL          0x0400  /* exclusive open */
#define _O_EXCL         0x0400  /* exclusive open */

/*
 *  POSIX 1003.1 Prototypes.
 */
_WCRTLINK extern int open( const char *__path, int __oflag, ... );
_WCRTLINK extern int sopen( const char *__path, int __oflag, int __share, ... );

_WCRTLINK extern int _wopen( const wchar_t *, int, ... );
_WCRTLINK extern int _wsopen( const wchar_t *, int, int, ... );
_WCRTLINK extern int _wcreat( const wchar_t *, int );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
