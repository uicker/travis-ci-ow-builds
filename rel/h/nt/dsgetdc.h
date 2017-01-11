/*
 *  dsgetdc.h   Directory service domain controller functions
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

#ifndef _DSGETDC_
#define _DSGETDC_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Domain to specify domain controller functions */
#define DSGETDCAPI  DECLSPEC_IMPORT

/* DsGetDcName() flags */
#define DS_FORCE_REDISCOVERY            0x00000001L
#define DS_DIRECTORY_SERVICE_REQUIRED   0x00000010L
#define DS_DIRECTORY_SERVICE_PREFERRED  0x00000020L
#define DS_GC_SERVER_REQUIRED           0x00000040L
#define DS_PDC_REQUIRED                 0x00000080L
#define DS_BACKGROUND_ONLY              0x00000100L
#define DS_IP_REQUIRED                  0x00000200L
#define DS_KDC_REQUIRED                 0x00000400L
#define DS_TIMESERV_REQUIRED            0x00000800L
#define DS_WRITABLE_REQUIRED            0x00001000L
#define DS_GOOD_TIMESERV_PREFERRED      0x00002000L
#define DS_AVOID_SELF                   0x00004000L
#define DS_ONLY_LDAP_NEEDED             0x00008000L
#define DS_IS_FLAT_NAME                 0x00010000L
#define DS_IS_DNS_NAME                  0x00020000L
#define DS_TRY_NEXTCLOSEST_SITE         0x00040000L
#define DS_DIRECTORY_SERVICE_6_REQUIRED 0x00080000L
#define DS_WEB_SERVICE_REQUIRED         0x00100000L
#define DS_RETURN_DNS_NAME              0x40000000L
#define DS_RETURN_FLAT_NAME             0x80000000L
#define DSGETDC_VALID_FLAGS \
    (DS_FORCE_REDISCOVERY | DS_DIRECTORY_SERVICE_REQUIRED | \
    DS_DIRECTORY_SERVICE_PREFERRED | DS_GC_SERVER_REQUIRED | DS_PDC_REQUIRED | \
    DS_BACKGROUND_ONLY | DS_IP_REQUIRED | DS_KDC_REQUIRED | DS_TIMESERV_REQUIRED | \
    DS_WRITABLE_REQUIRED | DS_GOOD_TIMESERV_PREFERRED | DS_AVOID_SELF | \
    DS_ONLY_LDAP_NEEDED | DS_IS_FLAT_NAME | DS_IS_DNS_NAME | DS_TRY_NEXTCLOSEST_SITE | \
    DS_DIRECTORY_SERVICE_6_REQUIRED | DS_WEB_SERVICE_REQUIRED | DS_RETURN_FLAT_NAME | \
    DS_RETURN_DNS_NAME)

/* Domain controller address types */
#define DS_INET_ADDRESS     1
#define DS_NETBIOS_ADDRESS  2

/* DsGetDcName() return flags */
#define DS_PDC_FLAG                     0x00000001L
#define DS_GC_FLAG                      0x00000004L
#define DS_LDAP_FLAG                    0x00000008L
#define DS_DS_FLAG                      0x00000010L
#define DS_KDC_FLAG                     0x00000020L
#define DS_TIMESERV_FLAG                0x00000040L
#define DS_CLOSEST_FLAG                 0x00000080L
#define DS_WRITABLE_FLAG                0x00000100L
#define DS_GOOD_TIMESERV_FLAG           0x00000200L
#define DS_NDNC_FLAG                    0x00000400L
#define DS_SELECT_SECRET_DOMAIN_6_FLAG  0x00000800L
#define DS_FULL_SECRET_DOMAIN_6_FLAG    0x00001000L
#define DS_WS_FLAG                      0x00002000L
#define DS_PING_FLAGS                   0x000FFFFFL
#define DS_DNS_CONTROLLER_FLAG          0x20000000L
#define DS_DNS_DOMAIN_FLAG              0x40000000L
#define DS_DNS_FOREST_FLAG              0x80000000L

/* Domain trust flags */
#define DS_DOMAIN_IN_FOREST         0x00000001L
#define DS_DOMAIN_DIRECT_OUTBOUND   0x00000002L
#define DS_DOMAIN_TREE_ROOT         0x00000004L
#define DS_DOMAIN_PRIMARY           0x00000008L
#define DS_DOMAIN_NATIVE_MODE       0x00000010L
#define DS_DOMAIN_DIRECT_INBOUND    0x00000020L
#define DS_DOMAIN_VALID_FLAGS \
    (DS_DOMAIN_IN_FOREST | DS_DOMAIN_DIRECT_OUTBOUND | DS_DOMAIN_TREE_ROOT | \
    DS_DOMAIN_PRIMARY | DS_DOMAIN_NATIVE_MODE | DS_DOMAIN_DIRECT_INBOUND)

/* DsGetForestTrustInformation() flags */
#ifdef _NTSECAPI_
    #define DS_GFTI_UPDATE_TDO  0x00000001L
    #define DS_GFTI_VALID_FLAGS 0x00000001L
#endif

/* DsGetDcOpen() flags */
#ifdef _WINSOCK2API_
    #define DS_ONLY_DO_SITE_NAME            0x00000001L
    #define DS_NOTIFY_AFTER_SITE_RECORDS    0x00000002L
    #define DS_OPEN_VALID_OPTION_FLAGS \
        (DS_ONLY_DO_SITE_NAME | DS_NOTIFY_AFTER_SITE_RECORDS)
    #define DS_OPEN_VALID_FLAGS \
        (DS_FORCE_REDISCOVERY | DS_ONLY_LDAP_NEEDED | DS_KDC_REQUIRED | \
        DS_PDC_REQUIRED | DS_GC_SERVER_REQUIRED | DS_WRITABLE_REQUIRED)
#endif

/* Domain controller information */
typedef struct _DOMAIN_CONTROLLER_INFOA {
    LPSTR   DomainControllerName;
    LPSTR   DomainControllerAddress;
    ULONG   DomainControllerAddressType;
    GUID    DomainGuid;
    LPSTR   DomainName;
    LPSTR   DnsForestName;
    ULONG   Flags;
    LPSTR   DcSiteName;
    LPSTR   ClientSiteName;
} DOMAIN_CONTROLLER_INFOA;
typedef DOMAIN_CONTROLLER_INFOA     *PDOMAIN_CONTROLLER_INFOA;
typedef struct _DOMAIN_CONTROLLER_INFOW {
    LPWSTR  DomainControllerName;
    LPWSTR  DomainControllerAddress;
    ULONG   DomainControllerAddressType;
    GUID    DomainGuid;
    LPWSTR  DomainName;
    LPWSTR  DnsForestName;
    ULONG   Flags;
    LPWSTR  DcSiteName;
    LPWSTR  ClientSiteName;
} DOMAIN_CONTROLLER_INFOW;
typedef DOMAIN_CONTROLLER_INFOW     *PDOMAIN_CONTROLLER_INFOW;
#ifdef UNICODE
typedef DOMAIN_CONTROLLER_INFOW     DOMAIN_CONTROLLER_INFO;
typedef PDOMAIN_CONTROLLER_INFOW    PDOMAIN_CONTROLLER_INFO;
#else
typedef DOMAIN_CONTROLLER_INFOA     DOMAIN_CONTROLLER_INFO;
typedef PDOMAIN_CONTROLLER_INFOA    PDOMAIN_CONTROLLER_INFO;
#endif

/* Directory Service domain trusts */
typedef struct _DS_DOMAIN_TRUSTSA {
    LPSTR   NetbiosDomainName;
    LPSTR   DnsDomainName;
    ULONG   Flags;
    ULONG   ParentIndex;
    ULONG   TrustType;
    ULONG   TrustAttributes;
    PSID    DomainSid;
    GUID    DomainGuid;
} DS_DOMAIN_TRUSTSA;
typedef DS_DOMAIN_TRUSTSA   *PDS_DOMAIN_TRUSTSA;
typedef struct _DS_DOMAIN_TRUSTSW {
    LPWSTR  NetbiosDomainName;
    LPWSTR  DnsDomainName;
    ULONG   Flags;
    ULONG   ParentIndex;
    ULONG   TrustType;
    ULONG   TrustAttributes;
    PSID    DomainSid;
    GUID    DomainGuid;
} DS_DOMAIN_TRUSTSW;
typedef DS_DOMAIN_TRUSTSW   *PDS_DOMAIN_TRUSTSW;
#ifdef UNICODE
typedef DS_DOMAIN_TRUSTSW   DS_DOMAIN_TRUSTS;
typedef PDS_DOMAIN_TRUSTSW  PDS_DOMAIN_TRUSTS;
#else
typedef DS_DOMAIN_TRUSTSA   DS_DOMAIN_TRUSTS;
typedef PDS_DOMAIN_TRUSTSA  PDS_DOMAIN_TRUSTS;
#endif

/* Functions in NETAPI32.DLL */
DSGETDCAPI DWORD WINAPI DsDeregisterDnsHostRecordsA( LPSTR, LPSTR, GUID *, GUID *, LPSTR );
DSGETDCAPI DWORD WINAPI DsDeregisterDnsHostRecordsW( LPWSTR, LPWSTR, GUID *, GUID *, LPWSTR );
DSGETDCAPI DWORD WINAPI DsEnumerateDomainTrustsA( LPSTR, ULONG, PDS_DOMAIN_TRUSTSA *, PULONG );
DSGETDCAPI DWORD WINAPI DsEnumerateDomainTrustsW( LPWSTR, ULONG, PDS_DOMAIN_TRUSTSW *, PULONG );
DSGETDCAPI DWORD WINAPI DsGetDcNameA( LPCSTR, LPCSTR, GUID *, LPCSTR, ULONG, PDOMAIN_CONTROLLER_INFOA * );
DSGETDCAPI DWORD WINAPI DsGetDcNameW( LPCWSTR, LPCWSTR, GUID *, LPCWSTR, ULONG, PDOMAIN_CONTROLLER_INFOW * );
DSGETDCAPI DWORD WINAPI DsGetDcSiteCoverageA( LPCSTR, PULONG, LPSTR ** );
DSGETDCAPI DWORD WINAPI DsGetDcSiteCoverageW( LPCWSTR, PULONG, LPWSTR ** );
DSGETDCAPI DWORD WINAPI DsGetSiteNameA( LPCSTR, LPSTR * );
DSGETDCAPI DWORD WINAPI DsGetSiteNameW( LPCWSTR, LPWSTR * );
DSGETDCAPI DWORD WINAPI DsValidateSubnetNameA( LPCSTR );
DSGETDCAPI DWORD WINAPI DsValidateSubnetNameW( LPCWSTR );
#ifdef _NTSECAPI_
DSGETDCAPI DWORD WINAPI DsGetForestTrustInformationW( LPCWSTR, LPCWSTR, DWORD, PLSA_FOREST_TRUST_INFORMATION * );
DSGETDCAPI DWORD WINAPI DsMergeForestTrustInformationW( LPCWSTR, PLSA_FOREST_TRUST_INFORMATION, PLSA_FOREST_TRUST_INFORMATION, PLSA_FOREST_TRUST_INFORMATION * );
#endif
#ifdef _WINSOCK2API_
DSGETDCAPI DWORD WINAPI DsAddressToSiteNamesA( LPCSTR, DWORD, PSOCKET_ADDRESS, LPSTR ** );
DSGETDCAPI DWORD WINAPI DsAddressToSiteNamesExA( LPCSTR, DWORD, PSOCKET_ADDRESS, LPSTR **, LPSTR ** );
DSGETDCAPI DWORD WINAPI DsAddressToSiteNamesExW( LPCWSTR, DWORD, PSOCKET_ADDRESS, LPWSTR **, LPWSTR ** );
DSGETDCAPI DWORD WINAPI DsAddressToSiteNamesW( LPCWSTR, DWORD, PSOCKET_ADDRESS, LPWSTR ** );
DSGETDCAPI VOID WINAPI  DsGetDcCloseW( HANDLE );
DSGETDCAPI DWORD WINAPI DsGetDcNextA( HANDLE, PULONG, LPSOCKET_ADDRESS *, LPSTR * );
DSGETDCAPI DWORD WINAPI DsGetDcNextW( HANDLE, PULONG, LPSOCKET_ADDRESS *, LPWSTR * );
DSGETDCAPI DWORD WINAPI DsGetDcOpenA( LPCSTR, ULONG, LPCSTR, GUID *, LPCSTR, ULONG, PHANDLE );
DSGETDCAPI DWORD WINAPI DsGetDcOpenW( LPCWSTR, ULONG, LPCWSTR, GUID *, LPCWSTR, ULONG, PHANDLE );
#endif

/* Map generic function names to the appropriate ANSI or Unicode version. */
#ifdef UNICODE
    #define DsDeregisterDnsHostRecords  DsDeregisterDnsHostRecordsW
    #define DsEnumerateDomainTrusts     DsEnumerateDomainTrustsW
    #define DsGetDcName                 DsGetDcNameW
    #define DsGetDcNext                 DsGetDcNextW
    #define DsGetDcSiteCoverage         DsGetDcSiteCoverageW
    #define DsGetSiteName               DsGetSiteNameW
    #define DsValidateSubnetName        DsValidateSubnetNameW
    #ifdef _WINSOCK2API_
        #define DsAddressToSiteName     DsAddressToSiteNameW
        #define DsAddressToSiteNameEx   DsAddressToSiteNameExW
        #define DsGetDcClose            DsGetDcCloseW
        #define DsGetDcNext             DsGetDcNextW
        #define DsGetDcOpen             DsGetDcOpenW
    #endif
#else
    #define DsDeregisterDnsHostRecords  DsDeregisterDnsHostRecordsA
    #define DsEnumerateDomainTrusts     DsEnumerateDomainTrustsA
    #define DsGetDcName                 DsGetDcNameA
    #define DsGetDcNext                 DsGetDcNextA
    #define DsGetDcSiteCoverage         DsGetDcSiteCoverageA
    #define DsGetSiteName               DsGetSiteNameA
    #define DsValidateSubnetName        DsValidateSubnetNameA
    #ifdef _WINSOCK2API_
        #define DsAddressToSiteName     DsAddressToSiteNameA
        #define DsAddressToSiteNameEx   DsAddressToSiteNameExA
        #define DsGetDcClose            DsGetDcCloseW
        #define DsGetDcNext             DsGetDcNextA
        #define DsGetDcOpen             DsGetDcOpenA
    #endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _DSGETDC_ */
