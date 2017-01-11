/*
 *  compobj.h   Component Object Model (COM) base functions
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

#ifndef _COMPOBJ_H_
#define _COMPOBJ_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

/* Macro used to specify extern "C" */
#ifdef __cplusplus
    #define EXTERN_C    extern "C"
#else
    #define EXTERN_C    extern
#endif

/* Standard method and API calling conventions */
#define STDMETHODCALLTYPE   FAR CDECL
#define STDAPICALLTYPE      FAR PASCAL

/* Standard method implementation and API declaration macros */
#define STDAPI              EXTERN_C HRESULT STDAPICALLTYPE
#define STDAPI_( x )        EXTERN_C x STDAPICALLTYPE
#define STDMETHODIMP        HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_( x )  x STDMETHODCALLTYPE

/* Macros to declare interfaces - these macros can be used for both C and C++. Define
 * CINTERFACE to have these macros expand in C++ code as if they were in C code.
 * Define CONST_VTABLE to have constant vtables in C.
 */
#if defined( __cplusplus ) && !defined( CINTERFACE )
    #define interface                   struct FAR
    #define STDMETHOD( f )              virtual HRESULT STDMETHODCALLTYPE f
    #define STDMETHOD_( x, f )          virtual x STDMETHODCALLTYPE f
    #define PURE                        = 0
    #define THIS_
    #define THIS                        void
    #define DECLARE_INTERFACE( x )      interface x
    #define DECLARE_INTERFACE_( x, p )  interface x : public p
#else
    #define interface                   struct
    #define STDMETHOD( f )              HRESULT (STDMETHODCALLTYPE *f)
    #define STDMETHOD_( x, f )          x (STDMETHODCALLTYPE *f)
    #define PURE
    #define THIS_                       INTERFACE FAR *,
    #define THIS                        INTERFACE FAR *
    #ifdef CONST_VTABLE
        #define DECLARE_INTERFACE( x ) \
            typedef interface x { \
                const struct x##Vtbl FAR *lpVtbl; \
            } x; \
            typedef const struct x##Vtbl x##Vtbl; \
            const struct x##Vtbl
    #else
        #define DECLARE_INTERFACE( x ) \
            typedef interface x { \
                struct x##Vtbl FAR *lpVtbl; \
            } x; \
            typedef struct x##Vtbl x##Vtbl; \
            struct x##Vtbl
    #endif
    #define DECLARE_INTERFACE_( x, p )  DECLARE_INTERFACE( x )
#endif

/* Attributes */
#ifndef FARSTRUCT
    #ifdef __cplusplus
        #define FARSTRUCT   FAR
    #else
        #define FARSTRUCT
    #endif
#endif
#ifndef HUGEP
    #define HUGEP           __huge
#endif

/* This inclusion must occur after the declaration of STDAPI but before any functions or
 * structures that use HRESULT or SCODE.
 */
#include <scode.h>

/* Forward declarations */
typedef interface IStream   IStream;
typedef IStream FAR         *LPSTREAM;

/* Primitive data types */
typedef short           SHORT;
typedef unsigned short  USHORT;
typedef DWORD           ULONG;
typedef WORD            WCHAR;

/* COM error codes */
#define CO_E_NOTINITIALIZED     (CO_E_FIRST + 0)
#define CO_E_ALREADYINITIALIZED (CO_E_FIRST + 1)
#define CO_E_CANTDETERMINECLASS (CO_E_FIRST + 2)
#define CO_E_CLASSSTRING        (CO_E_FIRST + 3)
#define CO_E_IIDSTRING          (CO_E_FIRST + 4)
#define CO_E_APPNOTFOUND        (CO_E_FIRST + 5)
#define CO_E_APPSINGLEUSE       (CO_E_FIRST + 6)
#define CO_E_ERRORINAPP         (CO_E_FIRST + 7)
#define CO_E_DLLNOTFOUND        (CO_E_FIRST + 8)
#define CO_E_ERRORINDLL         (CO_E_FIRST + 9)
#define CO_E_WRONGOSFORAPP      (CO_E_FIRST + 10)
#define CO_E_OBJNOTREG          (CO_E_FIRST + 11)
#define CO_E_OBJISREG           (CO_E_FIRST + 12)
#define CO_E_OBJNOTCONNECTED    (CO_E_FIRST + 13)
#define CO_E_APPDIDNTREG        (CO_E_FIRST + 14)

/* Class factory error codes */
#define CLASS_E_NOAGGREGATION       (CLASSFACTORY_E_FIRST + 0)
#define CLASS_E_CLASSNOTAVAILABLE   (CLASSFACTORY_E_FIRST + 1)

/* Registration database error codes */
#define REGDB_E_READREGDB       (REGDB_E_FIRST + 0)
#define REGDB_E_WRITEREGDB      (REGDB_E_FIRST + 1)
#define REGDB_E_KEYMISSING      (REGDB_E_FIRST + 2)
#define REGDB_E_INVALIDVALUE    (REGDB_E_FIRST + 3)
#define REGDB_E_CLASSNOTREG     (REGDB_E_FIRST + 4)
#define REGDB_E_IIDNOTREG       (REGDB_E_FIRST + 5)

/* RPC error codes */
#define RPC_E_FIRST MAKE_SCODE( SEVERITY_ERROR, FACILITY_RPC, 0x0000 )
#define RPC_E_CALL_REJECTED                 (RPC_E_FIRST + 1)
#define RPC_E_CALL_CANCELED                 (RPC_E_FIRST + 2)
#define RPC_E_CANTPOST_INSENDCALL           (RPC_E_FIRST + 3)
#define RPC_E_CANTCALLOUT_INASYNCCALL       (RPC_E_FIRST + 4)
#define RPC_E_CANTCALLOUT_INEXTERNALCALL    (RPC_E_FIRST + 5)
#define RPC_E_CONNECTION_TERMINATED         (RPC_E_FIRST + 6)
#define RPC_E_SERVER_DIED                   (RPC_E_FIRST + 7)
#define RPC_E_CLIENT_DIED                   (RPC_E_FIRST + 8)
#define RPC_E_INVALID_DATAPACKET            (RPC_E_FIRST + 9)
#define RPC_E_CANTTRANSMIT_CALL             (RPC_E_FIRST + 10)
#define RPC_E_CLIENT_CANTMARSHAL_DATA       (RPC_E_FIRST + 11)
#define RPC_E_CLIENT_CANTUNMARSHAL_DATA     (RPC_E_FIRST + 12)
#define RPC_E_SERVER_CANTMARSHAL_DATA       (RPC_E_FIRST + 13)
#define RPC_E_SERVER_CANTUNMARSHAL_DATA     (RPC_E_FIRST + 14)
#define RPC_E_INVALID_DATA                  (RPC_E_FIRST + 15)
#define RPC_E_INVALID_PARAMETER             (RPC_E_FIRST + 16)
#define RPC_E_CANTCALLOUT_AGAIN             (RPC_E_FIRST + 17)
#define RPC_E_UNEXPECTED                    (RPC_E_FIRST + 0xFFFF)

/* Minimum number of bytes for interface marshalling */
#define MARSHALINTERFACE_MIN    40

/* Large integer */
typedef struct FARSTRUCT _LARGE_INTEGER {
    DWORD   LowPart;
    LONG    HighPart;
} LARGE_INTEGER;
typedef LARGE_INTEGER   *PLARGE_INTEGER;

/* Unsigned large integer */
typedef struct FARSTRUCT _ULARGE_INTEGER {
    DWORD   LowPart;
    DWORD   HighPart;
} ULARGE_INTEGER;
typedef ULARGE_INTEGER  *PULARGE_INTEGER;

/* File time */
#ifndef _FILETIME_
#define _FILETIME_
typedef struct FARSTRUCT tagFILETIME {
    DWORD   dwLowDateTime;
    DWORD   dwHighDateTime;
} FILETIME;
#endif

/* Globally unique identifier */
typedef struct FARSTRUCT GUID {
    DWORD   Data1;
    WORD    Data2;
    WORD    Data3;
    BYTE    Data4[8];
} GUID;

/* Interface identifier */
typedef GUID    IID;
typedef IID FAR *LPIID;

/* Class identifier */
typedef GUID        CLSID;
typedef CLSID FAR   *LPCLSID;

/* Reference data types */
#ifdef __cplusplus
    #define REFGUID     const GUID FAR &
    #define REFIID      const IID FAR &
    #define REFCLSID    const CLSID FAR &
#else
    #define REFGUID     const GUID FAR * const
    #define REFIID      const IID FAR * const
    #define REFCLSID    const CLSID FAR * const
#endif

/* Macro to define a GUID */
#define DEFINE_GUID( x, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11 ) \
    EXTERN_C const GUID CDECL FAR x

/* Macro used to define a standard GUID */
#define DEFINE_OLEGUID( x, p1, p2, p3 ) \
    DEFINE_GUID( x, p1, p2, p3, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 )

/* Memory contexts */
typedef enum tagMEMCTX {
    MEMCTX_TASK     = 1,
    MEMCTX_SHARED   = 2,
    MEMCTX_UNKNOWN  = -1,
    MEMCTX_SAME     = -2
} MEMCTX;

/* Class contexts */
typedef enum tagCLSCTX {
    CLSCTX_INPROC_SERVER    = 1,
    CLSCTX_INPROC_HANDLER   = 2,
    CLSCTX_LOCAL_SERVER     = 4
} CLSCTX;
#define CLSCTX_ALL \
    (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER)
#define CLSCTX_INPROC   (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER)
#define CLSCTX_SERVER   (CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER)

/* Registration classes */
typedef enum tagREGCLS {
    REGCLS_SINGLEUSE        = 0,
    REGCLS_MULTIPLEUSE      = 1,
    REGCLS_MULTI_SEPARATE   = 2
} REGCLS;

/* Marshal flags */
typedef enum tagMSHLFLAGS {
    MSHLFLAGS_NORMAL        = 0,
    MSHLFLAGS_TABLESTRONG   = 1,
    MSHLFLAGS_TABLEWEAK     = 2
} MSHLFLAGS;

/* Marshal contexts */
typedef enum tagMSHCTX {
    MSHCTX_LOCAL        = 0,
    MSHCTX_NOSHAREDMEM  = 1
} MSHCTX;

/* IMessageFilter::HandleInComingCall() call types */
typedef enum tagCALLTYPE {
    CALLTYPE_TOPLEVEL               = 1,
    CALLTYPE_NESTED                 = 2,
    CALLTYPE_ASYNC                  = 3,
    CALLTYPE_TOPLEVEL_CALLPENDING   = 4,
    CALLTYPE_ASYNC_CALLPENDING      = 5
} CALLTYPE;

/* Interface information */
typedef struct tagINTERFACEINFO {
    interface IUnknown FAR  *pUnk;
    IID                     iid;
    WORD                    wMethod;
} INTERFACEINFO;
typedef INTERFACEINFO FAR   *LPINTERFACEINFO;

/* Server call status values */
typedef enum tagSERVERCALL {
    SERVERCALL_ISHANDLED    = 0,
    SERVERCALL_REJECTED     = 1,
    SERVERCALL_RETRYLATER   = 2
} SERVERCALL;

/* Pending types */
typedef enum tagPENDINGTYPE {
    PENDINGTYPE_TOPLEVEL    = 1,
    PENDINGTYPE_NESTED      = 2
} PENDINGTYPE;

/* IMessageFilter::MessagePending() return values */
typedef enum tagPENDINGMSG {
    PENDINGMSG_CANCELCALL       = 0,
    PENDINGMSG_WAITNOPROCESS    = 1,
    PENDINGMSG_WAITDEFPROCESS   = 2
} PENDINGMSG;

/* External connection flags */
typedef enum tagEXTCONN {
    EXTCONN_STRONG  = 0x00000001
} EXTCONN;

/* Pointers to functions exported by COM servers */
typedef HRESULT (STDAPICALLTYPE *LPFNCANUNLOADNOW)( void );
typedef HRESULT (STDAPICALLTYPE *LPFNGETCLASSOBJECT)( REFCLSID, REFIID, LPVOID FAR * );

/* IUnknown interface */
#undef INTERFACE
#define INTERFACE   IUnknown
DECLARE_INTERFACE( IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
};
typedef IUnknown FAR    *LPUNKNOWN;

/* IClassFactory interface */
#undef INTERFACE
#define INTERFACE   IClassFactory
DECLARE_INTERFACE_( IClassFactory, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IClassFactory methods */
    STDMETHOD( CreateInstance )( THIS_ LPUNKNOWN, REFIID, LPVOID FAR * ) PURE;
    STDMETHOD( LockServer )( THIS_ BOOL ) PURE;
};
typedef IClassFactory FAR   *LPCLASSFACTORY;

/* IMalloc interface */
#undef INTERFACE
#define INTERFACE   IMalloc
DECLARE_INTERFACE_( IMalloc, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMalloc methods */
    STDMETHOD_( void FAR *, Alloc )( THIS_ ULONG ) PURE;
    STDMETHOD_( void FAR *, Realloc )( THIS_ void FAR *, ULONG ) PURE;
    STDMETHOD_( void, Free )( THIS_ void FAR * ) PURE;
    STDMETHOD_( ULONG, GetSize )( THIS_ void FAR * ) PURE;
    STDMETHOD_( int, DidAlloc )( THIS_ void FAR * ) PURE;
    STDMETHOD_( void, HeapMinimize )( THIS ) PURE;
};
typedef IMalloc FAR *LPMALLOC;

/* IMarshal interface */
#undef INTERFACE
#define INTERFACE   IMarshal
DECLARE_INTERFACE_( IMarshal, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMarshal methods */
    STDMETHOD( GetUnmarshalClass )( THIS_ REFIID, LPVOID, DWORD, LPVOID, DWORD, LPCLSID ) PURE;
    STDMETHOD( GetMarshalSizeMax )( THIS_ REFIID, LPVOID, DWORD, LPVOID, DWORD, LPDWORD ) PURE;
    STDMETHOD( MarshalInterface )( THIS_ LPSTREAM, REFIID, LPVOID, DWORD, LPVOID, DWORD ) PURE;
    STDMETHOD( UnmarshalInterface )( THIS_ LPSTREAM, REFIID, LPVOID FAR * ) PURE;
    STDMETHOD( ReleaseMarshalData )( THIS_ LPSTREAM ) PURE;
    STDMETHOD( DisconnectObject )( THIS_ DWORD ) PURE;
};
typedef IMarshal FAR    *LPMARSHAL;

/* IStdMarshalInfo interface */
#undef INTERFACE
#define INTERFACE   IStdMarshalInfo
DECLARE_INTERFACE_( IStdMarshalInfo, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IStdMarshalInfo methods */
    STDMETHOD( GetClassForHandler )( THIS_ DWORD, LPVOID, LPCLSID ) PURE;
};
typedef IStdMarshalInfo FAR *LPSTDMARSHALINFO;

/* IMessageFilter interface */
#undef INTERFACE
#define INTERFACE   IMessageFilter
DECLARE_INTERFACE_( IMessageFilter, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IMessageFilter methods */
    STDMETHOD_( DWORD, HandleInComingCall )( THIS_ DWORD, HTASK, DWORD, DWORD ) PURE;
    STDMETHOD_( DWORD, RetryRejectedCall )( THIS_ HTASK, DWORD, DWORD ) PURE;
    STDMETHOD_( DWORD, MessagePending )( THIS_ HTASK, DWORD, DWORD ) PURE;
};
typedef IMessageFilter FAR  *LPMESSAGEFILTER;

/* IExternalConnection interface */
#undef INTERFACE
#define INTERFACE   IExternalConnection
DECLARE_INTERFACE_( IExternalConnection, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IExternalConnection methods */
    STDMETHOD_( DWORD, AddConnection )( THIS_ DWORD, DWORD ) PURE;
    STDMETHOD_( DWORD, ReleaseConnection )( THIS_ DWORD, DWORD, BOOL ) PURE;
};
typedef IExternalConnection FAR *LPEXTERNALCONNECTION;

/* IEnumString interface */
#undef INTERFACE
#define INTERFACE   IEnumString
DECLARE_INTERFACE_( IEnumString, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IEnumString methods */
    STDMETHOD( Next )( THIS_ ULONG, LPSTR FAR *, ULONG FAR * ) PURE;
    STDMETHOD( Skip )( THIS_ ULONG ) PURE;
    STDMETHOD( Reset )( THIS ) PURE;
    STDMETHOD( Clone )( THIS_ IEnumString FAR * FAR * ) PURE;
};
typedef IEnumString FAR *LPENUMSTRING;

/* IEnumUnknown interface */
#undef INTERFACE
#define INTERFACE   IEnumUnknown
DECLARE_INTERFACE_( IEnumUnknown, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IEnumUnknown methods */
    STDMETHOD( Next )( THIS_ ULONG, LPUNKNOWN FAR *, ULONG FAR * ) PURE;
    STDMETHOD( Skip )( THIS_ ULONG ) PURE;
    STDMETHOD( Reset )( THIS ) PURE;
    STDMETHOD( Clone )( THIS_ IEnumUnknown FAR * FAR * ) PURE;
};
typedef IEnumUnknown FAR    *LPENUMUNKNOWN;

/* Functions exported by COM servers */
STDAPI  DllCanUnloadNow( void );
STDAPI  DllGetClassObject( REFCLSID, REFIID, LPVOID FAR * );

/* Functions in COMPOBJ.DLL */
STDAPI              CLSIDFromProgID( LPCSTR, LPCLSID );
STDAPI              CLSIDFromString( LPSTR, LPCLSID );
STDAPI_( DWORD )    CoBuildVersion( VOID );
STDAPI              CoCreateGuid( GUID FAR * );
STDAPI              CoCreateInstance( REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID FAR * );
STDAPI              CoCreateStandardMalloc( DWORD, IMalloc FAR * FAR * );
STDAPI              CoDisconnectObject( LPUNKNOWN, DWORD );
STDAPI_( BOOL )     CoDosDateTimeToFileTime( WORD, WORD, FILETIME FAR * );
STDAPI              CoFileTimeNow( FILETIME FAR * );
STDAPI_( BOOL )     CoFileTimeToDosDateTime( FILETIME FAR *, LPWORD, LPWORD );
STDAPI_( void )     CoFreeAllLibraries( void );
STDAPI_( void )     CoFreeLibrary( HINSTANCE );
STDAPI_( void )     CoFreeUnusedLibraries( void );
STDAPI              CoGetClassObject( REFCLSID, DWORD, LPVOID, REFIID, LPVOID FAR * );
STDAPI_( DWORD )    CoGetCurrentProcess( void );
STDAPI              CoGetMalloc( DWORD, LPMALLOC FAR * );
STDAPI              CoGetStandardMarshal( REFIID, LPUNKNOWN, DWORD, LPVOID, DWORD, LPMARSHAL FAR * );
STDAPI              CoGetTreatAsClass( REFCLSID, LPCLSID );
STDAPI              CoInitialize( LPMALLOC );
STDAPI_( BOOL )     CoIsHandlerConnected( LPUNKNOWN );
STDAPI_( BOOL )     CoIsOle1Class( REFCLSID );
STDAPI_( HINSTANCE )    CoLoadLibrary( LPSTR, BOOL );
STDAPI              CoLockObjectExternal( LPUNKNOWN, BOOL, BOOL );
STDAPI              CoMarshalHresult( LPSTREAM, HRESULT );
STDAPI              CoMarshalInterface( LPSTREAM, REFIID, LPUNKNOWN, DWORD, LPVOID, DWORD );
STDAPI              CoRegisterClassObject( REFCLSID, LPUNKNOWN, DWORD, DWORD, LPDWORD );
STDAPI              CoRegisterMessageFilter( LPMESSAGEFILTER, LPMESSAGEFILTER FAR * );
STDAPI              CoReleaseMarshalData( LPSTREAM );
STDAPI              CoRevokeClassObject( DWORD );
STDAPI              CoTreatAsClass( REFCLSID, REFCLSID );
STDAPI_( void )     CoUninitialize( void );
STDAPI              CoUnmarshalHresult( LPSTREAM, HRESULT FAR * );
STDAPI              CoUnmarshalInterface( LPSTREAM, REFIID, LPVOID FAR * );
STDAPI              IIDFromString( LPSTR, LPIID );
STDAPI_( BOOL )     IsEqualGUID( REFGUID, REFGUID );
STDAPI              ProgIDFromCLSID( REFCLSID, LPSTR FAR * );
STDAPI              StringFromCLSID( REFCLSID, LPSTR FAR * );
STDAPI_( int )      StringFromGUID2( REFGUID, LPSTR, int );
STDAPI              StringFromIID( REFIID, LPSTR FAR * );

#ifdef INITGUID
    #include <initguid.h>
#else
    #include <coguid.h>
#endif

#endif /* _COMPOBJ_H_ */
