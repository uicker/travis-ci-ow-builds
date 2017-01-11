/*
 *  routprot.h  Routing protocol definitions
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

#ifndef _ROUTPROT_H_
#define _ROUTPROT_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <stm.h>
#include <nldef.h>
#include <in6addr.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Supported functionality flags */
#define RF_ROUTING              0x00000001L
#define RF_DEMAND_UPDATE_ROUTES 0x00000004L
#define RF_ADD_ALL_INTERFACES   0x00000010L
#define RF_MULTICAST            0x00000020L
#define RF_POWER                0x00000040L

/* Router version number */
#ifdef MPR50
    #define MS_ROUTER_VERSION   0x00000500L
#else
    #error Define MPR50 before including routprot.h.
#endif

/* Interface receive types */
#define IR_PROMISCUOUS              0
#define IR_PROMISCUOUS_MULTICAST    1

/* IP protocols */
#define PROTO_IP_MSDP               9
#define PROTO_IP_IGMP               10
#define PROTO_IP_BGMP               11
#define PROTO_IP_VRRP               112
#define PROTO_IP_BOOTP              9999
#define PROTO_IP_NT_AUTOSTATIC      10002
#define PROTO_IP_DNS_PROXY          10003
#define PROTO_IP_DHCP_ALLOCATOR     10004
#define PROTO_IP_NAT                10005
#define PROTO_IP_NT_STATIC          10006
#define PROTO_IP_NT_STATIC_NON_DOD  10007
#define PROTO_IP_DIFFSERV           10008
#define PROTO_IP_MGM                10009
#define PROTO_IP_ALG                10010
#define PROTO_IP_H323               10011
#define PROTO_IP_FTP                10012
#define PROTO_IP_DTP                10013

/* IPv6 protocols */
#define PROTO_IPV6_DHCP 999

/* Macro to manipulate protocol identifiers */
#define PROTOCOL_ID( p1, p2, p3 ) \
    ((((p1) & 0x03) << 30) | (((p2) & 0x3FFF) << 16) | ((p3) & 0xFFFF))
#define TYPE_FROM_PROTO_ID( x )     (((x) >> 30) & 0x03)
#define VENDOR_FROM_PROTO_ID( x )   (((x) >> 16) & 0x3FFF)
#define PROTO_FROM_PROTO_ID( x )    ((x) & 0xFFFF)

/* Protocol types */
#define PROTO_TYPE_UCAST    0
#define PROTO_TYPE_MCAST    1
#define PROTO_TYPE_MS0      2
#define PROTO_TYPE_MS1      3

/* Protocol vendors */
#define PROTO_VENDOR_MS0    0x0000
#define PROTO_VENDOR_MS1    0x0137
#define PROTO_VENDOR_MS2    0x3FFF

/* Microsoft protocol identifiers */
#define MS_IPV6_DHCP \
    PROTOCOL_ID( PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IPV6_DHCP )
#define MS_IP_BOOTP \
    PROTOCOL_ID( PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_BOOTP )
#define MS_IP_RIP \
    PROTOCOL_ID( PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_RIP )
#define MS_IP_OSPF \
    PROTOCOL_ID( PROTO_TYPE_UCAST, PROTO_VENDOR_MS0, PROTO_IP_OSPF )
#define MS_IP_BGP \
    PROTOCOL_ID( PROTO_TYPE_UCAST, PROTO_VENDOR_MS1, PROTO_IP_BGP )
#define MS_IP_IGMP \
    PROTOCOL_ID( PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_IGMP )
#define MS_IP_BGMP \
    PROTOCOL_ID( PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_BGMP )
#define MS_IP_MSDP \
    PROTOCOL_ID( PROTO_TYPE_MCAST, PROTO_VENDOR_MS1, PROTO_IP_MSDP )
#define MS_IP_DNS_PROXY \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DNS_PROXY )
#define MS_IP_DHCP_ALLOCATOR \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DHCP_ALLOCATOR )
#define MS_IP_NAT \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_NAT )
#define MS_IP_DIFFSERV \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DIFFSERV )
#define MS_IP_MGM \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_MGM )
#define MS_IP_VRRP \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_VRRP )
#define MS_IP_DTP \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_DTP )
#define MS_IP_H323 \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_H323 )
#define MS_IP_FTP \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_FTP )
#define MS_IP_ALG \
    PROTOCOL_ID( PROTO_TYPE_MS0, PROTO_VENDOR_MS1, PROTO_IP_ALG )

/* IPX protocols */
#define IPX_PROTOCOL_BASE   0x0001FFFFL
#define IPX_PROTOCOL_RIP    (IPX_PROTOCOL_BASE + 1)

/* Routing interface status types */
#define RIS_INTERFACE_ADDRESS_CHANGE    0
#define RIS_INTERFACE_ENABLED           1
#define RIS_INTERFACE_DISABLED          2
#define RIS_INTERFACE_MEDIA_PRESENT     3
#define RIS_INTERFACE_MEDIA_ABSENT      4

/* Interface flags */
#define MRINFO_TUNNEL_FLAG      0x01
#define MRINFO_PIM_FLAG         0x04
#define MRINFO_DOWN_FLAG        0x10
#define MRINFO_DISABLED_FLAG    0x20
#define MRINFO_QUERIER_FLAG     0x40
#define MRINFO_LEAF_FLAG        0x80

/* MFE status codes */
#define MFE_NO_ERROR            0
#define MFE_REACHED_CORE        1
#define MFE_NOT_FORWARDING      2
#define MFE_WRONG_IF            3
#define MFE_PRUNED_UPSTREAM     4
#define MFE_OIF_PRUNED          5
#define MFE_BOUNDARY_REACHED    6
#define MFE_NO_MULTICAST        7
#define MFE_IIF                 8
#define MFE_NO_ROUTE            9
#define MFE_NOT_LAST_HOP        10
#define MFE_OLD_ROUTER          11
#define MFE_PROHIBITED          12
#define MFE_NO_SPACE            13

/* Routing protocl entry point name */
#define REGISTER_PROTOCOL_ENTRY_POINT           RegisterProtocol
#define REGISTER_PROTOCOL_ENTRY_POINT_STRING    "RegisterProtocol"

/* Routing protocol events */
typedef enum _ROUTING_PROTOCOL_EVENTS {
    ROUTER_STOPPED              = 0,
    SAVE_GLOBAL_CONFIG_INFO     = 1,
    SAVE_INTERFACE_CONFIG_INFO  = 2,
    UPDATE_COMPLETE             = 3
} ROUTING_PROTOCOL_EVENTS;

/* Network interface types */
typedef enum _NET_INTERFACE_TYPE {
    PERMANENT               = 0,
    DEMAND_DIAL             = 1,
    LOCAL_WORKSTATION_DIAL  = 2,
    REMOTE_WORKSTATION_DIAL = 3
} NET_INTERFACE_TYPE;

/* Support functions */
typedef struct _SUPPORT_FUNCTIONS {
    union {
        ULONGLONG   _Align8;
        struct {
            DWORD   dwVersion;
            DWORD   dwReserved;
        };
    };
    DWORD   (WINAPI *DemandDialRequest)( DWORD, DWORD );
    DWORD   (WINAPI *SetInterfaceReceiveType)( DWORD, DWORD, DWORD, BOOL );
    DWORD   (WINAPI *ValidateRoute)( DWORD, PVOID, PVOID );
    DWORD   (WINAPI *MIBEntryCreate)( DWORD, DWORD, LPVOID );
    DWORD   (WINAPI *MIBEntryDelete)( DWORD, DWORD, LPVOID );
    DWORD   (WINAPI *MIBEntrySet)( DWORD, DWORD, LPVOID );
    DWORD   (WINAPI *MIBEntryGet)( DWORD, DWORD, LPVOID, LPDWORD, LPVOID );
    DWORD   (WINAPI *MIBEntryGetFirst)( DWORD, DWORD, LPVOID, LPDWORD, LPVOID );
    DWORD   (WINAPI *MIBEntryGetNext)( DWORD, DWORD, LPVOID, LPDWORD, LPVOID );
    DWORD   (WINAPI *GetRouterId)( VOID );
    BOOL    (WINAPI *HasMulticastBoundary)( DWORD, DWORD );
} SUPPORT_FUNCTIONS;
typedef SUPPORT_FUNCTIONS   *PSUPPORT_FUNCTIONS;

/* Update complete message */
typedef struct _UPDATE_COMPLETE_MESSAGE {
    ULONG   InterfaceIndex;
    ULONG   UpdateType;
    ULONG   UpdateStatus;
} UPDATE_COMPLETE_MESSAGE;
typedef UPDATE_COMPLETE_MESSAGE *PUPDATE_COMPLETE_MESSAGE;

/* Message */
typedef union _MESSAGE {
    UPDATE_COMPLETE_MESSAGE UpdateCompleteMessage;
    DWORD                   InterfaceIndex;
} MESSAGE;
typedef MESSAGE *PMESSAGE;

/* IP local binding */
typedef struct IP_LOCAL_BINDING {
    DWORD   Address;
    DWORD   Mask;
} IP_LOCAL_BINDING;
typedef IP_LOCAL_BINDING    *PIP_LOCAL_BINDING;

/* IPv6 local binding */
typedef struct IPV6_LOCAL_BINDING {
    IN6_ADDR    Address;
    DWORD       PrefixLength;
} IPV6_LOCAL_BINDING;
typedef IPV6_LOCAL_BINDING  *PIPV6_LOCAL_BINDING;

/* IP adapter binding information */
typedef struct IP_ADAPTER_BINDING_INFO {
    ULONG               AddressCount;
    DWORD               RemoteAddress;
    ULONG               Mtu;
    ULONGLONG           Speed;
    IP_LOCAL_BINDING    Address[1];
} IP_ADAPTER_BINDING_INFO;
typedef IP_ADAPTER_BINDING_INFO *PIP_ADAPTER_BINDING_INFO;

/* IPv6 adapter binding information */
typedef struct IPV6_ADAPTER_BINDING_INFO {
    ULONG               AddressCount;
    IN6_ADDR            RemoteAddress;
    ULONG               Mtu;
    ULONGLONG           Speed;
    IPV6_LOCAL_BINDING  Address[1];
} IPV6_ADAPTER_BINDING_INFO;
typedef IPV6_ADAPTER_BINDING_INFO   *PIPV6_ADAPTER_BINDING_INFO;

/* Callbacks */
typedef DWORD (WINAPI *PSTART_PROTOCOL)( HANDLE, PSUPPORT_FUNCTIONS, LPVOID, ULONG, ULONG, ULONG );
typedef DWORD (WINAPI *PSTART_COMPLETE)( VOID );
typedef DWORD (WINAPI *PSTOP_PROTOCOL)( VOID );
typedef DWORD (WINAPI *PADD_INTERFACE)( LPWSTR, ULONG, NET_INTERFACE_TYPE, DWORD, WORD, WORD, PVOID, ULONG, ULONG, ULONG );
typedef DWORD (WINAPI *PDELETE_INTERFACE)( ULONG );
typedef DWORD (WINAPI *PGET_EVENT_MESSAGE)( ROUTING_PROTOCOL_EVENTS *, MESSAGE * );
typedef DWORD (WINAPI *PGET_INTERFACE_INFO)( ULONG, PVOID, PULONG, PULONG, PULONG, PULONG );
typedef DWORD (WINAPI *PSET_INTERFACE_INFO)( ULONG, PVOID, ULONG, ULONG, ULONG );
typedef DWORD (WINAPI *PINTERFACE_STATUS)( ULONG, BOOL, DWORD, PVOID );
typedef DWORD (WINAPI *PQUERY_POWER)( DWORD );
typedef DWORD (WINAPI *PSET_POWER)( DWORD );
typedef DWORD (WINAPI *PGET_GLOBAL_INFO)( PVOID, PULONG, PULONG, PULONG, PULONG );
typedef DWORD (WINAPI *PSET_GLOBAL_INFO)( PVOID, ULONG, ULONG, ULONG );
typedef DWORD (WINAPI *PDO_UPDATE_ROUTES)( ULONG );
typedef DWORD (WINAPI *PMIB_CREATE)( ULONG, PVOID );
typedef DWORD (WINAPI *PMIB_DELETE)( ULONG, PVOID );
typedef DWORD (WINAPI *PMIB_GET)( ULONG, PVOID, PULONG, PVOID );
typedef DWORD (WINAPI *PMIB_SET)( ULONG, PVOID );
typedef DWORD (WINAPI *PMIB_GET_FIRST)( ULONG, PVOID, PULONG, PVOID );
typedef DWORD (WINAPI *PMIB_GET_NEXT)( ULONG, PVOID, PULONG, PVOID );
typedef DWORD (WINAPI *PMIB_SET_TRAP_INFO)( HANDLE, ULONG, PVOID, PULONG, PVOID );
typedef DWORD (WINAPI *PMIB_GET_TRAP_INFO)( ULONG, PVOID, PULONG, PVOID );
typedef DWORD (WINAPI *PCONNECT_CLIENT)( ULONG, PVOID );
typedef DWORD (WINAPI *PDISCONNECT_CLIENT)( ULONG, PVOID );
typedef DWORD (WINAPI *PGET_NEIGHBORS)( DWORD, PDWORD, PDWORD, PBYTE );
typedef DWORD (WINAPI *PGET_MFE_STATUS)( DWORD, DWORD, DWORD, PBYTE );

/* MPR 5.0 routing characteristics */
typedef struct _MPR50_ROUTING_CHARACTERISTICS {
    DWORD               dwVersion;
    DWORD               dwProtocolId;
    DWORD               fSupportedFunctionality;
    PSTART_PROTOCOL     pfnStartProtocol;
    PSTART_COMPLETE     pfnStartComplete;
    PSTOP_PROTOCOL      pfnStopProtocol;
    PGET_GLOBAL_INFO    pfnGetGlobalInfo;
    PSET_GLOBAL_INFO    pfnSetGlobalInfo;
    PQUERY_POWER        pfnQueryPower;
    PSET_POWER          pfnSetPower;
    PADD_INTERFACE      pfnAddInterface;
    PDELETE_INTERFACE   pfnDeleteInterface;
    PINTERFACE_STATUS   pfnInterfaceStatus;
    PGET_INTERFACE_INFO pfnGetInterfaceInfo;
    PSET_INTERFACE_INFO pfnSetInterfaceInfo;
    PGET_EVENT_MESSAGE  pfnGetEventMessage;
    PDO_UPDATE_ROUTES   pfnUpdateRoutes;
    PCONNECT_CLIENT     pfnConnectClient;
    PDISCONNECT_CLIENT  pfnDisconnectClient;
    PGET_NEIGHBORS      pfnGetNeighbors;
    PGET_MFE_STATUS     pfnGetMfeStatus;
    PMIB_CREATE         pfnMibCreateEntry;
    PMIB_DELETE         pfnMibDeleteEntry;
    PMIB_GET            pfnMibGetEntry;
    PMIB_SET            pfnMibSetEntry;
    PMIB_GET_FIRST      pfnMibGetFirstEntry;
    PMIB_GET_NEXT       pfnMibGetNextEntry;
    PMIB_SET_TRAP_INFO  pfnMibSetTrapInfo;
    PMIB_GET_TRAP_INFO  pfnMibGetTrapInfo;
} MPR50_ROUTING_CHARACTERISTICS;

/* MPR routing characteristics */
#ifdef MPR50
typedef MPR50_ROUTING_CHARACTERISTICS   MPR_ROUTING_CHARACTERISTICS;
#endif
typedef MPR_ROUTING_CHARACTERISTICS     *PMPR_ROUTING_CHARACTERISTICS;

/* Protocol entry point */
typedef DWORD (WINAPI *PREGISTER_PROTOCOL)( PMPR_ROUTING_CHARACTERISTICS, PMPR_SERVICE_CHARACTERISTICS );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _ROUTPROT_H_ */
