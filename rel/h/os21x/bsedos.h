/*
 *  bsedos.h    OS/2 Base DOS include file for 16-bit development.
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

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef INCL_DOS
  #define INCL_DOSDATETIME
  #define INCL_DOSDEVICES
  #define INCL_DOSFILEMGR
  #define INCL_DOSINFOSEG
  #define INCL_DOSMEMMGR
  #define INCL_DOSMISC
  #define INCL_DOSMODULEMGR
  #define INCL_DOSMONITORS
  #define INCL_DOSNLS
  #define INCL_DOSNMPIPES
  #define INCL_DOSPROCESS
  #define INCL_DOSQUEUES
  #define INCL_DOSRESOURCES
  #define INCL_DOSSEMAPHORES
  #define INCL_DOSSESMGR
  #define INCL_DOSSIGNALS
#endif

#define CCHMAXPATH          260
#define CCHMAXPATHCOMP      256

#if (defined(INCL_DOSPROCESS) || !defined(INCL_NOCOMMON))

#define EXIT_THREAD  0
#define EXIT_PROCESS 1

#define EXEC_SYNC        0
#define EXEC_ASYNC       1
#define EXEC_ASYNCRESULT 2
#define EXEC_TRACE       3
#define EXEC_BACKGROUND  4
#define EXEC_LOAD        5

#define EXLST_ADD    1
#define EXLST_REMOVE 2
#define EXLST_EXIT   3

#define PRTYS_PROCESS     0
#define PRTYS_PROCESSTREE 1
#define PRTYS_THREAD      2

#define PRTYC_NOCHANGE         0
#define PRTYC_IDLETIME         1
#define PRTYC_REGULAR          2
#define PRTYC_TIMECRITICAL     3
#define PRTYC_FOREGROUNDSERVER 4

#define PRTYD_MINIMUM (-31)
#define PRTYD_MAXIMUM   31

#define DCWA_PROCESS     0
#define DCWA_PROCESSTREE 1

#define DCWW_WAIT   0
#define DCWW_NOWAIT 1

typedef struct _RESULTCODES {
    USHORT codeTerminate;
    USHORT codeResult;
} RESULTCODES, FAR *PRESULTCODES;

typedef struct _PIDINFO {
    PID pid;
    TID tid;
    PID pidParent;
} PIDINFO, FAR *PPIDINFO;

typedef VOID (FAR *PFNTHREAD)(VOID);
typedef VOID (PASCAL FAR *PFNEXITLIST)(USHORT);

USHORT APIENTRY DosBeep(USHORT,USHORT);
USHORT APIENTRY DosCreateThread(PFNTHREAD,PTID,PBYTE);
USHORT APIENTRY DosCwait(USHORT,USHORT,PRESULTCODES,PPID,PID);
USHORT APIENTRY DosEnterCritSec(VOID);
USHORT APIENTRY DosExecPgm(PCHAR,SHORT,USHORT,PSZ,PSZ,PRESULTCODES,PSZ);
VOID   APIENTRY DosExit(USHORT,USHORT);
USHORT APIENTRY DosExitCritSec(VOID);
USHORT APIENTRY DosExitList(USHORT,PFNEXITLIST);
USHORT APIENTRY DosGetPID(PPIDINFO);
USHORT APIENTRY DosGetPPID(USHORT,PUSHORT);
USHORT APIENTRY DosGetPrty(USHORT,PUSHORT,USHORT);
USHORT APIENTRY DosKillProcess(USHORT,PID);
USHORT APIENTRY DosResumeThread(TID);
USHORT APIENTRY DosSetPrty(USHORT,USHORT,SHORT,USHORT);
USHORT APIENTRY DosSleep(ULONG);
USHORT APIENTRY DosSuspendThread(TID);

#endif

#if (defined(INCL_DOSFILEMGR) || !defined(INCL_NOCOMMON))

#define FILE_BEGIN    0
#define FILE_CURRENT  1
#define FILE_END      2

#define HDIR_SYSTEM   0x0001
#define HDIR_CREATE   0xFFFF

#define DCPY_EXISTING 1
#define DCPY_APPEND   2

#define FILE_NORMAL    0x0000
#define FILE_READONLY  0x0001
#define FILE_HIDDEN    0x0002
#define FILE_SYSTEM    0x0004
#define FILE_DIRECTORY 0x0010
#define FILE_ARCHIVED  0x0020

#define FILE_EXISTED   1
#define FILE_CREATED   2
#define FILE_TRUNCATED 3

#define FILE_OPEN      0x0001
#define FILE_TRUNCATE  0x0002
#define FILE_CREATE    0x0010

#define OPEN_ACTION_FAIL_IF_EXISTS     0
#define OPEN_ACTION_OPEN_IF_EXISTS     1
#define OPEN_ACTION_REPLACE_IF_EXISTS  2

#define OPEN_ACTION_FAIL_IF_NEW     0x0000
#define OPEN_ACTION_CREATE_IF_NEW   0x0010

#define OPEN_ACCESS_READONLY        0x0000
#define OPEN_ACCESS_WRITEONLY       0x0001
#define OPEN_ACCESS_READWRITE       0x0002
#define OPEN_SHARE_DENYREADWRITE    0x0010
#define OPEN_SHARE_DENYWRITE        0x0020
#define OPEN_SHARE_DENYREAD         0x0030
#define OPEN_SHARE_DENYNONE         0x0040
#define OPEN_FLAGS_NOINHERIT        0x0080
#define OPEN_FLAGS_NO_LOCALITY      0x0000
#define OPEN_FLAGS_SEQUENTIAL       0x0100
#define OPEN_FLAGS_RANDOM           0x0200
#define OPEN_FLAGS_RANDOMSEQUENTIAL 0x0300
#define OPEN_FLAGS_NO_CACHE         0x1000
#define OPEN_FLAGS_FAIL_ON_ERROR    0x2000
#define OPEN_FLAGS_WRITE_THROUGH    0x4000
#define OPEN_FLAGS_DASD             0x8000

#define SEARCH_PATH          0
#define SEARCH_CUR_DIRECTORY 1
#define SEARCH_ENVIRONMENT   2
#define SEARCH_IGNORENETERRS 4

#define FIO_LOCK      0
#define FIO_UNLOCK    1
#define FIO_SEEK      2
#define FIO_READ      3
#define FIO_WRITE     4

#define FIO_NOSHARE   0
#define FIO_SHAREREAD 1

#define FSIL_ALLOC    1
#define FSIL_VOLSER   2

#define FHT_DISKFILE  0
#define FHT_CHRDEV    1
#define FHT_PIPE      2

#define FHB_DSKREMOTE    0x8000
#define FHB_CHRDEVREMOTE 0x8000
#define FHB_PIPEREMOTE   0x8000

#define FEA_NEEDEA  0x80

#define EAT_BINARY       0xFFFE
#define EAT_ASCII        0xFFFD
#define EAT_BITMAP       0xFFFB
#define EAT_METAFILE     0xFFFA
#define EAT_ICON         0xFFF9
#define EAT_EA           0xFFEE

#define EAT_MVMT         0xFFDF
#define EAT_MVST         0xFFDE
#define EAT_ASN1         0xFFDD

#define HANDTYPE_FILE       0x0000
#define HANDTYPE_DEVICE     0x0001
#define HANDTYPE_PIPE       0x0002
#define HANDTYPE_NETWORK    0x8000

typedef SHANDLE     HDIR;
typedef HDIR FAR    *PHDIR;

typedef struct _DENA1 {
    UCHAR  reserved;
    UCHAR  cbName;
    USHORT cbValue;
    UCHAR  szName[1];
} DENA1;

typedef struct _FDATE {
    unsigned day   : 5;
    unsigned month : 4;
    unsigned year  : 7;
} FDATE;

typedef struct _FTIME {
    unsigned twosecs : 5;
    unsigned minutes : 6;
    unsigned hours   : 5;
} FTIME;

typedef struct _FILEFINDBUF {
    FDATE  fdateCreation;
    FTIME  ftimeCreation;
    FDATE  fdateLastAccess;
    FTIME  ftimeLastAccess;
    FDATE  fdateLastWrite;
    FTIME  ftimeLastWrite;
    ULONG  cbFile;
    ULONG  cbFileAlloc;
    USHORT attrFile;
    UCHAR  cchName;
    CHAR   achName[CCHMAXPATHCOMP];
} FILEFINDBUF, FAR *PFILEFINDBUF;

typedef struct _FILEFINDBUF2 {
    FDATE  fdateCreation;
    FTIME  ftimeCreation;
    FDATE  fdateLastAccess;
    FTIME  ftimeLastAccess;
    FDATE  fdateLastWrite;
    FTIME  ftimeLastWrite;
    ULONG  cbFile;
    ULONG  cbFileAlloc;
    USHORT attrFile;
    ULONG  cbList;
    UCHAR  cchName;
    CHAR   achName[CCHMAXPATHCOMP];
} FILEFINDBUF2, FAR *PFILEFINDBUF2;

typedef struct _FILESTATUS {
    FDATE  fdateCreation;
    FTIME  ftimeCreation;
    FDATE  fdateLastAccess;
    FTIME  ftimeLastAccess;
    FDATE  fdateLastWrite;
    FTIME  ftimeLastWrite;
    ULONG  cbFile;
    ULONG  cbFileAlloc;
    USHORT attrFile;
} FILESTATUS, FAR *PFILESTATUS;

typedef struct _FSALLOCATE {
    ULONG  idFileSystem;
    ULONG  cSectorUnit;
    ULONG  cUnit;
    ULONG  cUnitAvail;
    USHORT cbSector;
} FSALLOCATE, FAR *PFSALLOCATE;

typedef struct _GEA {
    BYTE cbName;
    CHAR szName[1];
} GEA, FAR *PGEA;

typedef struct _GEALIST {
    ULONG  cbList;
    GEA list[1];
} GEALIST, FAR *PGEALIST;

typedef struct _FEA {
    BYTE fEA;
    BYTE cbName;
    USHORT cbValue;
} FEA, FAR *PFEA;

typedef struct _FEALIST {
    ULONG  cbList;
    FEA list[1];
} FEALIST, FAR *PFEALIST;

typedef struct _EAOP {
    PGEALIST fpGEAList;
    PFEALIST fpFEAList;
    ULONG    oError;
} EAOP, FAR *PEAOP;

typedef struct _VOLUMELABEL {
    BYTE cch;
    CHAR szVolLabel[12];
} VOLUMELABEL, FAR *PVOLUMELABEL;

typedef struct _FSINFO {
    FDATE fdateCreation;
    FTIME ftimeCreation;
    VOLUMELABEL vol;
} FSINFO, FAR *PFSINFO;

USHORT APIENTRY DosBufReset(HFILE);
USHORT APIENTRY DosChDir(PSZ,ULONG);
USHORT APIENTRY DosChgFilePtr(HFILE,LONG,USHORT,PULONG);
USHORT APIENTRY DosClose(HFILE);
USHORT APIENTRY DosCopy(PSZ,PSZ,USHORT,ULONG);
USHORT APIENTRY DosDelete(PSZ,ULONG);
USHORT APIENTRY DosDupHandle(HFILE,PHFILE);
USHORT APIENTRY DosEditName(USHORT,PSZ,PSZ,PBYTE,USHORT);
USHORT APIENTRY DosEnumAttribute(USHORT,PVOID,ULONG,PVOID,ULONG,PULONG,ULONG,ULONG);
USHORT APIENTRY DosFileIO(HFILE,PBYTE,USHORT,PLONG);
USHORT APIENTRY DosFileLocks(HFILE,PLONG,PLONG);
USHORT APIENTRY DosFindClose(HDIR);
USHORT APIENTRY DosFindFirst(PSZ,PHDIR,USHORT,PFILEFINDBUF,USHORT,PUSHORT,ULONG);
USHORT APIENTRY DosFindFirst2(PSZ,PHDIR,USHORT,PVOID,USHORT,PUSHORT,USHORT,ULONG);
USHORT APIENTRY DosFindNext(HDIR,PFILEFINDBUF,USHORT,PUSHORT);
USHORT APIENTRY DosFSAttach(PSZ,PSZ,PBYTE,USHORT,USHORT,ULONG);
USHORT APIENTRY DosFSCtl(PBYTE,USHORT,PUSHORT,PBYTE,USHORT,PUSHORT,USHORT,PSZ,HFILE,USHORT,ULONG);
USHORT APIENTRY DosMkDir(PSZ,ULONG);
USHORT APIENTRY DosMkDir2(PSZ,PEAOP,ULONG);
USHORT APIENTRY DosMove(PSZ,PSZ,ULONG);
USHORT APIENTRY DosNewSize(HFILE,ULONG);
USHORT APIENTRY DosOpen(PSZ,PHFILE,PUSHORT,ULONG,USHORT,USHORT,USHORT,ULONG);
USHORT APIENTRY DosOpen2(PSZ,PHFILE,PUSHORT,ULONG,USHORT,USHORT,USHORT,PEAOP,ULONG);
USHORT APIENTRY DosQCurDir(USHORT,PBYTE,PUSHORT);
USHORT APIENTRY DosQCurDisk(PUSHORT,PULONG);
USHORT APIENTRY DosQFHandState(HFILE,PUSHORT);
USHORT APIENTRY DosQFileInfo(HFILE,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosQFileMode(PSZ,PUSHORT,ULONG);
USHORT APIENTRY DosQFSAttach(PSZ,USHORT,USHORT,PBYTE,PUSHORT,ULONG);
USHORT APIENTRY DosQFSInfo(USHORT,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosQHandType(HFILE,PUSHORT,PUSHORT);
USHORT APIENTRY DosQPathInfo(PSZ,USHORT,PBYTE,USHORT,ULONG);
USHORT APIENTRY DosQVerify(PUSHORT);
USHORT APIENTRY DosRead(HFILE,PVOID,USHORT,PUSHORT);
USHORT APIENTRY DosReadAsync(HFILE,PULONG,PUSHORT,PVOID,USHORT,PUSHORT);
USHORT APIENTRY DosRmDir(PSZ,ULONG);
USHORT APIENTRY DosSelectDisk(USHORT);
USHORT APIENTRY DosSetFHandState(HFILE,USHORT);
USHORT APIENTRY DosSetFileInfo(HFILE,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosSetFileMode(PSZ,USHORT,ULONG);
USHORT APIENTRY DosSetFSInfo(USHORT,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosSetMaxFH(USHORT);
USHORT APIENTRY DosSetPathInfo(PSZ,USHORT,PBYTE,USHORT,USHORT,ULONG);
USHORT APIENTRY DosSetVerify(USHORT);
USHORT APIENTRY DosShutdown(ULONG);
USHORT APIENTRY DosWrite(HFILE,PVOID,USHORT,PUSHORT);
USHORT APIENTRY DosWriteAsync(HFILE,PULONG,PUSHORT,PVOID,USHORT,PUSHORT);

#endif

#if (defined(INCL_DOSMEMMGR) || !defined(INCL_NOCOMMON))

#define SEG_NONSHARED    0
#define SEG_GIVEABLE     1
#define SEG_GETTABLE     2
#define SEG_DISCARDABLE  4

USHORT APIENTRY DosAllocHuge(USHORT,USHORT,PSEL,USHORT,USHORT);
USHORT APIENTRY DosAllocSeg(USHORT,PSEL,USHORT);
USHORT APIENTRY DosAllocShrSeg(USHORT,PSZ,PSEL);
USHORT APIENTRY DosCreateCSAlias(SEL,PSEL);
USHORT APIENTRY DosFreeSeg(SEL);
USHORT APIENTRY DosGetHugeShift(PUSHORT);
USHORT APIENTRY DosGetSeg(SEL);
USHORT APIENTRY DosGetShrSeg(PSZ,PSEL);
USHORT APIENTRY DosGiveSeg(SEL,PID,PSEL);
USHORT APIENTRY DosLockSeg(SEL);
USHORT APIENTRY DosMemAvail(PULONG);
USHORT APIENTRY DosReallocHuge(USHORT,USHORT,SEL);
USHORT APIENTRY DosReallocSeg(USHORT,SEL);
USHORT APIENTRY DosSizeSeg(SEL,PULONG);
USHORT APIENTRY DosSubAlloc(SEL,PUSHORT,USHORT);
USHORT APIENTRY DosSubFree(SEL,USHORT,USHORT);
USHORT APIENTRY DosSubSet(SEL,USHORT,USHORT);
USHORT APIENTRY DosUnlockSeg(SEL);

#endif

#ifdef INCL_DOSMODULEMGR

USHORT APIENTRY DosFreeModule(HMODULE);
USHORT APIENTRY DosGetModHandle(PSZ,PHMODULE);
USHORT APIENTRY DosGetModName(HMODULE,USHORT,PCHAR);
USHORT APIENTRY DosGetProcAddr(HMODULE,PSZ,PFN FAR *);
USHORT APIENTRY DosLoadModule(PSZ,USHORT,PSZ,PHMODULE);

#endif

#ifdef INCL_DOSNMPIPES

typedef SHANDLE     HPIPE;
typedef HPIPE FAR   *PHPIPE;

USHORT APIENTRY DosCallNmPipe(PSZ,PBYTE,USHORT,PBYTE,USHORT,PUSHORT,ULONG);
USHORT APIENTRY DosConnectNmPipe(HPIPE);
USHORT APIENTRY DosDisConnectNmPipe(HPIPE);
USHORT APIENTRY DosMakeNmPipe(PSZ,PHPIPE,USHORT,USHORT,USHORT,USHORT,ULONG);
USHORT APIENTRY DosPeekNmPipe(HPIPE,PBYTE,USHORT,PUSHORT,PUSHORT,PUSHORT);
USHORT APIENTRY DosQNmPHandState(HPIPE,PUSHORT);
USHORT APIENTRY DosQNmPipeInfo(HPIPE,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosQNmPipeSemState(HSEM,PBYTE,USHORT);
USHORT APIENTRY DosSetNmPHandState(HPIPE,USHORT);
USHORT APIENTRY DosSetNmPipeSem(HPIPE,HSEM,USHORT);
USHORT APIENTRY DosTransactNmPipe(HPIPE,PBYTE,USHORT,PBYTE,USHORT,PUSHORT);
USHORT APIENTRY DosWaitNmPipe(PSZ,ULONG);

#endif

#ifdef INCL_DOSQUEUES

typedef SHANDLE     HQUEUE;
typedef HQUEUE FAR  *PHQUEUE;

USHORT APIENTRY DosCloseQueue(HQUEUE);
USHORT APIENTRY DosCreateQueue(PHQUEUE,USHORT,PSZ);
USHORT APIENTRY DosMakePipe(PHFILE,PHFILE,USHORT);
USHORT APIENTRY DosOpenQueue(PUSHORT,PHQUEUE,PSZ);
USHORT APIENTRY DosPeekQueue(HQUEUE,PULONG,PUSHORT,PULONG,PUSHORT,UCHAR,PBYTE,ULONG);
USHORT APIENTRY DosPurgeQueue(HQUEUE);
USHORT APIENTRY DosQueryQueue(HQUEUE,PUSHORT);
USHORT APIENTRY DosReadQueue(HQUEUE,PULONG,PUSHORT,PULONG,USHORT,UCHAR,PBYTE,HSEM);
USHORT APIENTRY DosWriteQueue(HQUEUE,USHORT,USHORT,PBYTE,UCHAR);

#endif

#ifdef INCL_DOSSEMAPHORES

#define SEM_INDEFINITE_WAIT  (-1L)
#define SEM_IMMEDIATE_RETURN   0

typedef LHANDLE     HSYSSEM;
typedef HSYSSEM FAR *PHSYSSEM;

typedef struct _DOSFSRSEM {
    USHORT cb;
    PID    pid;
    TID    tid;
    USHORT cUsage;
    USHORT client;
    ULONG  sem;
} DOSFSRSEM, FAR *PDOSFSRSEM;

typedef struct _MUXSEM {
    USHORT zero;
    HSEM   hsem;
} MUXSEM, FAR *PMUXSEM;

typedef struct _MUXSEMLIST {
    USHORT  cmxs;
    MUXSEM  amxs[16];
} MUXSEMLIST, FAR *PMUXSEMLIST;

USHORT APIENTRY DosCloseSem(HSEM);
USHORT APIENTRY DosCreateSem(USHORT,PHSYSSEM,PSZ);
USHORT APIENTRY DosFSRamSemClear(PDOSFSRSEM);
USHORT APIENTRY DosFSRamSemRequest(PDOSFSRSEM,LONG);
USHORT APIENTRY DosMuxSemWait(PUSHORT,PVOID,LONG);
USHORT APIENTRY DosOpenSem(PHSEM,PSZ);
USHORT APIENTRY DosSemClear(HSEM);
USHORT APIENTRY DosSemRequest(HSEM,LONG);
USHORT APIENTRY DosSemSet(HSEM);
USHORT APIENTRY DosSemSetWait(HSEM,LONG);
USHORT APIENTRY DosSemWait(HSEM,LONG);

#endif

#ifdef INCL_DOSMONITORS

typedef SHANDLE       HMONITOR;
typedef HMONITOR FAR  *PHMONITOR;

USHORT APIENTRY DosMonClose(HMONITOR);
USHORT APIENTRY DosMonOpen(PSZ,PHMONITOR);
USHORT APIENTRY DosMonRead(PBYTE,USHORT,PBYTE,PUSHORT);
USHORT APIENTRY DosMonReg(HMONITOR,PBYTE,PBYTE,USHORT,USHORT);
USHORT APIENTRY DosMonWrite(PBYTE,PBYTE,USHORT);

#endif

#ifdef INCL_DOSINFOSEG

#define PT_FULLSCREEN    0
#define PT_REALMODE      1
#define PT_WINDOWABLEVIO 2
#define PT_PM            3
#define PT_DETACHED      4

#define PS_EXITLIST 1

#define MAKEPGINFOSEG(sel) ((PGINFOSEG)MAKEP(sel, 0))
#define MAKEPLINFOSEG(sel) ((PLINFOSEG)MAKEP(sel, 0))

typedef struct _GINFOSEG {
    ULONG   time;
    ULONG   msecs;
    UCHAR   hour;
    UCHAR   minutes;
    UCHAR   seconds;
    UCHAR   hundredths;    USHORT  timezone;
    USHORT  cusecTimerInterval;
    UCHAR   day;
    UCHAR   month;
    USHORT  year;
    UCHAR   weekday;
    UCHAR   uchMajorVersion;
    UCHAR   uchMinorVersion;
    UCHAR   chRevisionLetter;
    UCHAR   sgCurrent;
    UCHAR   sgMax;
    UCHAR   cHugeShift;
    UCHAR   fProtectModeOnly;
    USHORT  pidForeground;
    UCHAR   fDynamicSched;
    UCHAR   csecMaxWait;
    USHORT  cmsecMinSlice;
    USHORT  cmsecMaxSlice;
    USHORT  bootdrive;
    UCHAR   amecRAS[32];
    UCHAR   csgWindowableVioMax;
    UCHAR   csgPMMax;
} GINFOSEG, FAR *PGINFOSEG;

typedef struct _LINFOSEG {
    PID     pidCurrent;
    PID     pidParent;
    USHORT  prtyCurrent;
    TID     tidCurrent;
    USHORT  sgCurrent;
    UCHAR   rfProcStatus;
    UCHAR   dummy1;
    BOOL    fForeground;
    UCHAR   typeProcess;
    UCHAR   dummy2;
    SEL     selEnvironment;
    USHORT  offCmdLine;
    USHORT  cbDataSegment;
    USHORT  cbStack;
    USHORT  cbHeap;
    HMODULE hmod;
    SEL     selDS;
} LINFOSEG, FAR *PLINFOSEG;

USHORT APIENTRY DosGetInfoSeg(PSEL,PSEL);

#endif

#ifdef INCL_DOSNLS

typedef struct _COUNTRYCODE {
    USHORT country;
    USHORT codepage;
} COUNTRYCODE, FAR *PCOUNTRYCODE;

typedef struct _COUNTRYINFO {
    USHORT country;
    USHORT codepage;
    USHORT fsDateFmt;
    CHAR   szCurrency[5];
    CHAR   szThousandsSeparator[2];
    CHAR   szDecimal[2];
    CHAR   szDateSeparator[2];
    CHAR   szTimeSeparator[2];
    UCHAR  fsCurrencyFmt;
    UCHAR  cDecimalPlace;
    UCHAR  fsTimeFmt;
    USHORT abReserved1[2];
    CHAR   szDataSeparator[2];
    USHORT abReserved2[5];
} COUNTRYINFO, FAR *PCOUNTRYINFO;

USHORT APIENTRY DosCaseMap(USHORT,PCOUNTRYCODE,PCHAR);
USHORT APIENTRY DosGetCollate(USHORT,PCOUNTRYCODE,PCHAR,PUSHORT);
USHORT APIENTRY DosGetCp(USHORT,PUSHORT,PUSHORT);
USHORT APIENTRY DosGetCtryInfo(USHORT,PCOUNTRYCODE,PCOUNTRYINFO,PUSHORT);
USHORT APIENTRY DosGetDBCSEv(USHORT,PCOUNTRYCODE,PCHAR);
USHORT APIENTRY DosSetCp(USHORT,USHORT);
USHORT APIENTRY DosSetProcCp(USHORT,USHORT);

#endif

#ifdef INCL_DOSSIGNALS

#define SIG_CTRLC        1
#define SIG_BROKENPIPE   2
#define SIG_KILLPROCESS  3
#define SIG_CTRLBREAK    4
#define SIG_PFLG_A       5
#define SIG_PFLG_B       6
#define SIG_PFLG_C       7
#define SIG_CSIGNALS     8

#define PFLG_A           0
#define PFLG_B           1
#define PFLG_C           2

#define SIGA_KILL        0
#define SIGA_IGNORE      1
#define SIGA_ACCEPT      2
#define SIGA_ERROR       3
#define SIGA_ACKNOWLEDGE 4

#define HLDSIG_ENABLE    0
#define HLDSIG_DISABLE   1

#define FLGP_SUBTREE     0
#define FLGP_PID         1

typedef VOID (PASCAL FAR *PFNSIGHANDLER)(USHORT,USHORT);

USHORT APIENTRY DosFlagProcess(PID,USHORT,USHORT,USHORT);
USHORT APIENTRY DosHoldSignal(USHORT);
USHORT APIENTRY DosSendSignal(USHORT,USHORT);
USHORT APIENTRY DosSetSigHandler(PFNSIGHANDLER,PFNSIGHANDLER FAR *,PUSHORT,USHORT,USHORT);

#endif

#ifdef INCL_DOSRESOURCES

USHORT APIENTRY DosFreeResource(PBYTE);
USHORT APIENTRY DosGetResource(HMODULE,USHORT,USHORT,PSEL);
USHORT APIENTRY DosGetResource2(HMODULE,USHORT,USHORT,PULONG);

#endif

#if (defined(INCL_DOSDATETIME) || !defined(INCL_NOCOMMON))

typedef struct _DATETIME {
    UCHAR   hours;
    UCHAR   minutes;
    UCHAR   seconds;
    UCHAR   hundredths;
    UCHAR   day;
    UCHAR   month;
    USHORT  year;
    SHORT   timezone;
    UCHAR   weekday;
} DATETIME, FAR *PDATETIME;

USHORT APIENTRY DosGetDateTime(PDATETIME);
USHORT APIENTRY DosSetDateTime(PDATETIME);

#endif

#ifdef INCL_DOSDATETIME

typedef SHANDLE     HTIMER;
typedef HTIMER FAR  *PHTIMER;

USHORT APIENTRY DosTimerAsync(ULONG,HSEM,PHTIMER);
USHORT APIENTRY DosTimerStart(ULONG,HSEM,PHTIMER);
USHORT APIENTRY DosTimerStop(HTIMER);

#endif

#ifdef INCL_DOSMISC

USHORT APIENTRY DosErrClass(USHORT,PUSHORT,PUSHORT,PUSHORT);
USHORT APIENTRY DosError(USHORT);
USHORT APIENTRY DosGetEnv(PUSHORT,PUSHORT);
USHORT APIENTRY DosGetMachineMode(PBYTE);
USHORT APIENTRY DosGetMessage(PCHAR FAR *,USHORT,PCHAR,USHORT,USHORT,PSZ,PUSHORT);
USHORT APIENTRY DosGetVersion(PUSHORT);
USHORT APIENTRY DosInsMessage(PCHAR FAR *,USHORT,PSZ,USHORT,PCHAR,USHORT,PUSHORT);
USHORT APIENTRY DosPutMessage(USHORT,USHORT,PCHAR);
USHORT APIENTRY DosPtrace(PBYTE);
USHORT APIENTRY DosQSysInfo(USHORT,PBYTE,USHORT);
USHORT APIENTRY DosScanEnv(PSZ,PSZ FAR *);
USHORT APIENTRY DosSearchPath(USHORT,PSZ,PSZ,PBYTE,USHORT);
USHORT APIENTRY DosSetVec(USHORT,PFN,PFN FAR *);

#endif

#ifdef INCL_DOSSESMGR

typedef struct _STATUSDATA {
  USHORT Length;
  USHORT SelectInd;
  USHORT BondInd;
} STATUSDATA, FAR *PSTATUSDATA;

typedef struct _STARTDATA {
    USHORT Length;
    USHORT Related;
    USHORT FgBg;
    USHORT TraceOpt;
    PSZ    PgmTitle;
    PSZ    PgmName;
    PBYTE  PgmInputs;
    PBYTE  TermQ;
    PBYTE  Environment;
    USHORT InheritOpt;
    USHORT SessionType;
    PSZ    IconFile;
    ULONG  PgmHandle;
    USHORT PgmControl;
    USHORT InitXPos;
    USHORT InitYPos;
    USHORT InitXSize;
    USHORT InitYSize;
} STARTDATA, FAR *PSTARTDATA;

USHORT APIENTRY DosQAppType(PSZ,PUSHORT);
USHORT APIENTRY DosSelectSession(USHORT,ULONG);
USHORT APIENTRY DosSetSession(USHORT,PSTATUSDATA);
USHORT APIENTRY DosStartSession(PSTARTDATA,PUSHORT,PUSHORT);
USHORT APIENTRY DosStopSession(USHORT,USHORT,ULONG);

#endif

#ifdef INCL_DOSDEVICES

VOID   APIENTRY DosCallback(PFN);
USHORT APIENTRY DosCLIAccess(VOID);
USHORT APIENTRY DosDevConfig(PVOID,USHORT,USHORT);
USHORT APIENTRY DosDevIOCtl(PVOID,PVOID,USHORT,USHORT,HFILE);
USHORT APIENTRY DosDevIOCtl2(PVOID,USHORT,PVOID,USHORT,USHORT,USHORT,HFILE);
USHORT APIENTRY DosPhysicalDisk(USHORT,PBYTE,USHORT,PBYTE,USHORT);
USHORT APIENTRY DosPortAccess(USHORT,USHORT,USHORT,USHORT);
USHORT APIENTRY DosR2StackRealloc(USHORT);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
