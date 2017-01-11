/*
 *  lmalert.h   LAN Manager alert functions
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

#ifndef _ALERT_
#define _ALERT_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Alerter mailslot name */
#define ALERTER_MAILSLOT    L"\\\\.\\MAILSLOT\\Alerter"

/* Standard alert event names */
#define ALERT_PRINT_EVENT       L"PRINTING"
#define ALERT_MESSAGE_EVENT     L"MESSAGE"
#define ALERT_ERRORLOG_EVENT    L"ERRORLOG"
#define ALERT_ADMIN_EVENT       L"ADMIN"
#define ALERT_USER_EVENT        L"USER"

/* Job status masks */
#define PRJOB_QSTATUS       0x00000003L
#define PRJOB_DEVSTATUS     0x000001FCL
#define PRJOB_COMPLETE      0x00000004L
#define PRJOB_INTERV        0x00000008L
#define PRJOB_ERROR         0x00000010L
#define PRJOB_DESTOFFLINE   0x00000020L
#define PRJOB_DESTPAUSED    0x00000040L
#define PRJOB_NOTIFY        0x00000080L
#define PRJOB_DESTNOPAPER   0x00000100L
#define PRJOB_DELETED       0x00008000L

/* Queue status bits */
#define PRJOB_QS_QUEUED     0L
#define PRJOB_QS_PAUSED     1L
#define PRJOB_QS_SPOOLING   2L
#define PRJOB_QS_PRINTING   3L

/* Standard alert */
typedef struct _STD_ALERT {
    DWORD   alert_timestamp;
    WCHAR   alert_eventname[EVLEN + 1];
    WCHAR   alert_servicename[SNLEN + 1];
} STD_ALERT;
typedef STD_ALERT   *PSTD_ALERT;
typedef STD_ALERT   *LPSTD_ALERT;

/* Macros to get additional information */
#define ALERT_OTHER_INFO( x )   ((LPBYTE)(x) + sizeof( STD_ALERT ))
#define ALERT_VAR_DATA( x )     ((LPBYTE)(x) + sizeof( *x ))

/* Administrator other information */
typedef struct _ADMIN_OTHER_INFO {
    DWORD   alrtad_errcode;
    DWORD   alrtad_numstrings;
} ADMIN_OTHER_INFO;
typedef ADMIN_OTHER_INFO    *PADMIN_OTHER_INFO;
typedef ADMIN_OTHER_INFO    *LPADMIN_OTHER_INFO;

/* Error log other information */
typedef struct _ERRLOG_OTHER_INFO {
    DWORD   alrter_errcode;
    DWORD   alrter_offset;
} ERRLOG_OTHER_INFO;
typedef ERRLOG_OTHER_INFO   *PERRLOG_OTHER_INFO;
typedef ERRLOG_OTHER_INFO   *LPERRLOG_OTHER_INFO;

/* Print other information */
typedef struct _PRINT_OTHER_INFO {
    DWORD   alrtpr_jobid;
    DWORD   alrtpr_status;
    DWORD   alrtpr_submitted;
    DWORD   alrtpr_size;
} PRINT_OTHER_INFO;
typedef PRINT_OTHER_INFO    *PPRINT_OTHER_INFO;
typedef PRINT_OTHER_INFO    *LPPRINT_OTHER_INFO;

/* User other information */
typedef struct _USER_OTHER_INFO {
    DWORD   alrtus_errcode;
    DWORD   alrtus_numstrings;
} USER_OTHER_INFO;
typedef USER_OTHER_INFO *PUSER_OTHER_INFO;
typedef USER_OTHER_INFO *LPUSER_OTHER_INFO;

/* Functions in NETAPI32.DLL */
NET_API_STATUS NET_API_FUNCTION NetAlertRaise( LPCWSTR, LPVOID, DWORD );
NET_API_STATUS NET_API_FUNCTION NetAlertRaiseEx( LPCWSTR, LPVOID, DWORD, LPCWSTR );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _ALERT_ */
