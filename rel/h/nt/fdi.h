/*
 *  fdi.h       File Decompression Interface
 *
 * =========================================================================
 *
 *                          Open Watcom Project
 *
 * Copyright (c) 2004-2016 The Open Watcom Contributors. All Rights Reserved.
 *
 *    This file is automatically generated. Do not edit directly.
 *
 * =========================================================================
 */

#ifndef __FDI_INCLUDED__
#define __FDI_INCLUDED__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

/* The Microsoft defintions all contain FAR and DIAMONDAPI
 * declarations to maintain 16-bit compatibility.  Since
 * we're building only for 32- and 64-bit (maybe), we can
 * just leave the FAR define blank.  However, it's good to
 * maintain the same terminology as Microsoft, I suppose...
 */
#ifndef FAR
#define FAR
#endif
#ifndef DIAMONDAPI
#define DIAMONDAPI __cdecl
#endif

typedef enum {
    FDIERROR_NONE,
    FDIERROR_CABINET_NOT_FOUND,
    FDIERROR_NOT_A_CABINET,
    FDIERROR_UNKNOWN_CABINET_VERSION,
    FDIERROR_CORRUPT_CABINET,
    FDIERROR_ALLOC_FAIL,
    FDIERROR_BAD_COMPR_TYPE,
    FDIERROR_MDI_FAIL,
    FDIERROR_TARGET_FILE,
    FDIERROR_RESERVE_MISMATCH,
    FDIERROR_WRONG_CABINET,
    FDIERROR_USER_ABORT
} FDIERROR;

typedef void *HFDI;

typedef struct {
    long cbCabinet;
    USHORT cFolders;
    USHORT cFiles;
    USHORT setID;
    USHORT iCabinet;
    BOOL fReserve;
    BOOL hasprev;
    BOOL hasnext;
} FDICABINETINFO, FAR *PFDICABINETINFO;

typedef struct {
    LONG cb;
    char FAR *psz1;
    char FAR *psz2;
    char FAR *psz3;
    void FAR *pv;
    INT_PTR hf;
    USHORT date;
    USHORT time;
    USHORT attribs;
    USHORT setID;
    USHORT iCabinet;
    USHORT iFolder;
    FDIERROR fdie;
} FDINOTIFICATION, *PFDINOTIFICATION;

typedef struct {
    int  erfOper;
    int  erfType;
    BOOL fError;
} ERF, FAR *PERF;

typedef void *(DIAMONDAPI *PFNALLOC)( ULONG );
#define FNALLOC(fn) void *DIAMONDAPI fn( ULONG cb )

typedef void (DIAMONDAPI *PFNFREE)( void * );
#define FNFREE(fn) void DIAMONDAPI fn( void *memory )

typedef INT_PTR (DIAMONDAPI *PFNOPEN) ( LPSTR, int, int );
typedef UINT    (DIAMONDAPI *PFNREAD) ( INT_PTR , void *, UINT );
typedef UINT    (DIAMONDAPI *PFNWRITE)( INT_PTR, void *, UINT );
typedef int     (DIAMONDAPI *PFNCLOSE)( INT_PTR );
typedef long    (DIAMONDAPI *PFNSEEK) ( INT_PTR, long, int );

#define FNOPEN(fn)  INT_PTR DIAMONDAPI fn( LPSTR pszFile, int oflag, int pmode )
#define FNREAD(fn)  UINT    DIAMONDAPI fn( INT_PTR hf, void FAR *pv, UINT cb )
#define FNWRITE(fn) UINT    DIAMONDAPI fn( INT_PTR hf, void FAR *pv, UINT cb )
#define FNCLOSE(fn) int     DIAMONDAPI fn( INT_PTR hf )
#define FNSEEK(fn)  long    DIAMONDAPI fn( INT_PTR hf, long dist, int seektype )

typedef enum {
    fdintCABINET_INFO,
    fdintPARTIAL_FILE,
    fdintCOPY_FILE,
    fdintCLOSE_FILE_INFO,
    fdintNEXT_CABINET,
    fdintENUMERATE
} FDINOTIFICATIONTYPE;

typedef INT_PTR (DIAMONDAPI *PFNFDINOTIFY)( FDINOTIFICATIONTYPE, PFDINOTIFICATION );
#define FNFDINOTIFY(fn) INT_PTR DIAMONDAPI fn( FDINOTIFICATIONTYPE fdint, PFDINOTIFICATION pfdin )

typedef int (DIAMONDAPI *PFNFDIDECRYPT)( PFDIDECRYPT );
#define FNFDIDECRYPT(fn) int DIAMONDAPI fn( PFDIDECRYPT pfdid)
  
#define cpuUNKNOWN (-1)
#define cpu80286 (0)
#define cpu80386 (1)

BOOL DIAMONDAPI FDICopy( HFDI, char *, char *, int, PFNFDINOTIFY, PFNFDIDECRYPT, void * );
HFDI DIAMONDAPI FDICreate( PFNALLOC, PFNFREE, PFNOPEN, PFNREAD, PFNWRITE, PFNCLOSE, PFNSEEK, int, PERF );
BOOL DIAMONDAPI FDIDestroy( HFDI );
BOOL DIAMONDAPI FDIIsCabinet( HFDI, INT_PTR, PFDICABINETINFO );
BOOL DIAMONDAPI FDITruncateCabinet( HFDI, char *, USHORT );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __FDI_INCLUDED__ */
