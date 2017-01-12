/*
 *  fltdefs.h   Filter definitions
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

#ifndef _FLTDEFS_H
#define _FLTDEFS_H

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to specify filter functions */
#ifdef __cplusplus
    #define EXTERNCDECL EXTERN_C
#else
    #define EXTERNCDECL
#endif
#define PFAPIENTRY      EXTERNCDECL DWORD WINAPI

/* Handle data types */
typedef PVOID   FILTER_HANDLE;
typedef PVOID   *PFILTER_HANDLE;
typedef PVOID   INTERFACE_HANDLE;
typedef PVOID   *PINTERFACE_HANDLE;

/* Macro to make filter protocol constants */
#define FILTER_PROTO( x )   MAKELONG( MAKEWORD( x, 0x00 ), 0x0000 )

/* Filter protocols */
#define FILTER_PROTO_ANY    FILTER_PROTO( 0x00 )
#define FILTER_PROTO_ICMP   FILTER_PROTO( 0x01 )
#define FILTER_PROTO_TCP    FILTER_PROTO( 0x06 )
#define FILTER_PROTO_UDP    FILTER_PROTO( 0x11 )

/* Filter TCP/UDP port special value */
#define FILTER_TCPUDP_PORT_ANY  0x0000

/* Filter ICMP special values */
#define FILTER_ICMP_TYPE_ANY    0xFF
#define FILTER_ICMP_CODE_ANY    0xFF

/* Filter descriptor flags */
#define FD_FLAGS_NOSYN      0x00000001L
#define FD_FLAGS_ALLFLAGS   FD_FLAGS_NOSYN

/* Filter descriptor late bound flags */
#define LB_SRC_ADDR_USE_SRCADDR_FLAG    0x00000001L
#define LB_SRC_ADDR_USE_DSTADDR_FLAG    0x00000002L
#define LB_DST_ADDR_USE_SRCADDR_FLAG    0x00000004L
#define LB_DST_ADDR_USE_DSTADDR_FLAG    0x00000008L
#define LB_SRC_MASK_LATE_FLAG           0x00000010L
#define LB_DST_MASK_LATE_FLAG           0x00000020L

/* Filter error codes */
#define ERROR_BASE                  2000
#define PFERROR_NO_PF_INTERFACE     (ERROR_BASE + 0)
#define PFERROR_NO_FILTERS_GIVEN    (ERROR_BASE + 1)
#define PFERROR_BUFFER_TOO_SMALL    (ERROR_BASE + 2)
#define ERROR_IPV6_NOT_IMPLEMENTED  (ERROR_BASE + 3)

/* Global filter constants */
typedef enum _GlobalFilter {
    GF_FRAGMENTS    = 2,
    GF_STRONGHOST   = 8,
    GF_FRAGCACHE    = 9,
} GLOBAL_FILTER;
typedef GLOBAL_FILTER   *PGLOBAL_FILTER;

/* Filter forward actions */
typedef enum _PfForwardAction {
    PF_ACTION_FORWARD   = 0,
    PF_ACTION_DROP      = 1
} PFFORWARD_ACTION;
typedef PFFORWARD_ACTION    *PPFFORWARD_ACTION;

/* Filter address types */
typedef enum _PfAddressType {
    PF_IPV4 = 0,
    PF_IPV6 = 1
} PFADDRESSTYPE;
typedef PFADDRESSTYPE   *PPFADDRESSTYPE;

/* Filter descriptor */
typedef struct _PF_FILTER_DESCRIPTOR {
    DWORD           dwFilterFlags;
    DWORD           dwRule;
    PFADDRESSTYPE   pfatType;
    PBYTE           SrcAddr;
    PBYTE           SrcMask;
    PBYTE           DstAddr;
    PBYTE           DstMask;
    DWORD           dwProtocol;
    DWORD           fLateBound;
    WORD            wSrcPort;
    WORD            wDstPort;
    WORD            wSrcPortHighRange;
    WORD            wDstPortHighRange;
} PF_FILTER_DESCRIPTOR;
typedef PF_FILTER_DESCRIPTOR    *PPF_FILTER_DESCRIPTOR;
#define FILTERSIZE \
    (sizeof( PF_FILTER_DESCRIPTOR ) - (DWORD)(&((PPF_FILTER_DESCRIPTOR)0)->SrcAddr))

/* Filter statistics */
typedef struct _PF_FILTER_STATS {
    DWORD                   dwNumPacketsFiltered;
    PF_FILTER_DESCRIPTOR    info;
} PF_FILTER_STATS;
typedef PF_FILTER_STATS *PPF_FILTER_STATS;

/* Filter interfaces */
typedef struct _PF_INTERFACE_STATS {
    PVOID               pvDriverContext;
    DWORD               dwFlags;
    DWORD               dwInDrops;
    DWORD               dwOutDrops;
    PFFORWARD_ACTION    eaInAction;
    PFFORWARD_ACTION    eaOutAction;
    DWORD               dwNumInFilters;
    DWORD               dwNumOutFilters;
    DWORD               dwFrag;
    DWORD               dwSpoof;
    DWORD               dwReserved1;
    DWORD               dwReserved2;
    LARGE_INTEGER       liSYN;
    LARGE_INTEGER       liTotalLogged;
    DWORD               dwLostLogEntries;
    PF_FILTER_STATS     FilterInfo[1];
} PF_INTERFACE_STATS;
typedef PF_INTERFACE_STATS  *PPF_INTERFACE_STATS;

/* Filter late binding information */
typedef struct _PF_LATEBIND_INFO {
    PBYTE   SrcAddr;
    PBYTE   DstAddr;
    PBYTE   Mask;
} PF_LATEBIND_INFO;
typedef PF_LATEBIND_INFO    *PPF_LATEBIND_INFO;

/* Filter frame types */
typedef enum _PfFrameType {
    PFFT_FILTER = 1,
    PFFT_FRAG   = 2,
    PFFT_SPOOF  = 3
} PFFRAMETYPE;
typedef PFFRAMETYPE *PPFFRAMETYPE;

/* Filter log frame */
typedef struct _pfLogFrame {
    LARGE_INTEGER   Timestamp;
    PFFRAMETYPE     pfeTypeOfFrame;
    DWORD           dwTotalSizeUsed;
    DWORD           dwFilterRule;
    WORD            wSizeOfAdditionalData;
    WORD            wSizeOfIpHeader;
    DWORD           dwInterfaceName;
    DWORD           dwIPIndex;
    BYTE            bPacketData[1];
} PFLOGFRAME;
typedef PFLOGFRAME  *PPFLOGFRAME;

/* Functions in IPHLPAPI.DLL */
PFAPIENTRY  PfAddFiltersToInterface( INTERFACE_HANDLE, DWORD, PPF_FILTER_DESCRIPTOR, DWORD, PPF_FILTER_DESCRIPTOR, PFILTER_HANDLE );
PFAPIENTRY  PfAddGlobalFilterToInterface( INTERFACE_HANDLE, GLOBAL_FILTER );
PFAPIENTRY  PfBindInterfaceToIPAddress( INTERFACE_HANDLE, PFADDRESSTYPE, PBYTE );
PFAPIENTRY  PfBindInterfaceToIndex( INTERFACE_HANDLE, DWORD, PFADDRESSTYPE, PBYTE );
PFAPIENTRY  PfCreateInterface( DWORD, PFFORWARD_ACTION, PFFORWARD_ACTION, BOOL, BOOL, INTERFACE_HANDLE * );
PFAPIENTRY  PfDeleteInterface( INTERFACE_HANDLE );
PFAPIENTRY  PfDeleteLog( VOID );
PFAPIENTRY  PfGetInterfaceStatistics( INTERFACE_HANDLE, PPF_INTERFACE_STATS, PDWORD, BOOL );
PFAPIENTRY  PfMakeLog( HANDLE );
PFAPIENTRY  PfRebindFilters( INTERFACE_HANDLE, PPF_LATEBIND_INFO );
PFAPIENTRY  PfRemoveFilterHandles( INTERFACE_HANDLE, DWORD, PFILTER_HANDLE );
PFAPIENTRY  PfRemoveFiltersFromInterface( INTERFACE_HANDLE, DWORD, PPF_FILTER_DESCRIPTOR, DWORD, PPF_FILTER_DESCRIPTOR );
PFAPIENTRY  PfRemoveGlobalFilterFromInterface( INTERFACE_HANDLE, GLOBAL_FILTER );
PFAPIENTRY  PfSetLogBuffer( PBYTE, DWORD, DWORD, DWORD, PDWORD, PDWORD, PDWORD );
PFAPIENTRY  PfTestPacket( INTERFACE_HANDLE, INTERFACE_HANDLE, DWORD, PBYTE, PFFORWARD_ACTION );
PFAPIENTRY  PfUnBindInterface( INTERFACE_HANDLE );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _FLTDEFS_H */