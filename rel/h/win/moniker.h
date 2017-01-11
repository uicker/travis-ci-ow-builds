/*
 *  moniker.h   Moniker interfaces and functions
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

#ifndef _MONIKER_H_
#define _MONIKER_H_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

/* Forward declarations */
typedef interface IRunningObjectTable   IRunningObjectTable;
typedef interface IEnumMoniker          IEnumMoniker;
typedef interface IMoniker              IMoniker;
typedef IRunningObjectTable FAR         *LPRUNNINGOBJECTTABLE;
typedef IEnumMoniker FAR                *LPENUMMONIKER;
typedef IMoniker FAR                    *LPMONIKER;

/* Moniker error codes */
#define MK_E_CONNECTMANUALLY            (MK_E_FIRST + 0)
#define MK_E_EXCEEDEDDEADLINE           (MK_E_FIRST + 1)
#define MK_E_NEEDGENERIC                (MK_E_FIRST + 2)
#define MK_E_UNAVAILABLE                (MK_E_FIRST + 3)
#define MK_E_SYNTAX                     (MK_E_FIRST + 4)
#define MK_E_NOOBJECT                   (MK_E_FIRST + 5)
#define MK_E_INVALIDEXTENSION           (MK_E_FIRST + 6)
#define MK_E_INTERMEDIATEINTERFACENOTSUPPORTED  (MK_E_FIRST + 7)
#define MK_E_NOTBINDABLE                (MK_E_FIRST + 8)
#define MK_E_NOTBOUND                   (MK_E_FIRST + 9)
#define MK_E_CANTOPENFILE               (MK_E_FIRST + 10)
#define MK_E_MUSTBOTHERUSER             (MK_E_FIRST + 11)
#define MK_E_NOINVERSE                  (MK_E_FIRST + 12)
#define MK_E_NOSTORAGE                  (MK_E_FIRST + 13)
#define MK_E_NOPREFIX                   (MK_E_FIRST + 14)
#define MK_S_REDUCED_TO_SELF            (MK_S_FIRST + 2)
#define MK_S_ME                         (MK_S_FIRST + 4)
#define MK_S_HIM                        (MK_S_FIRST + 5)
#define MK_S_US                         (MK_S_FIRST + 6)
#define MK_S_MONIKERALREADYREGISTERED   (MK_S_FIRST + 7)

/* IRunningObjectTable::Register() flags */
#define ROTFLAGS_REGISTRATIONKEEPSALIVE 0x00000001L

/* Bind options */
typedef struct FARSTRUCT tagBIND_OPTS {
    DWORD   cbStruct;
    DWORD   grfFlags;
    DWORD   grfMode;
    DWORD   dwTickCountDeadline;
} BIND_OPTS;
typedef BIND_OPTS FAR   *LPBIND_OPTS;

/* Bind flags */
typedef enum {
    BIND_MAYBOTHERUSER      = 1,
    BIND_JUSTTESTEXISTENCE  = 2
} BIND_FLAGS;

/* System moniker types */
typedef enum tagMKSYS {
    MKSYS_NONE              = 0,
    MKSYS_GENERICCOMPOSITE  = 1,
    MKSYS_FILEMONIKER       = 2,
    MKSYS_ANTIMONIKER       = 3,
    MKSYS_ITEMMONIKER       = 4,
    MKSYS_POINTERMONIKER    = 5
} MKSYS;

/* Moniker reductions */
typedef enum tagMKREDUCE {
    MKRREDUCE_ONE           = 0x00030000,
    MKRREDUCE_TOUSER        = 0x00020000,
    MKRREDUCE_THROUGHUSER   = 0x00010000,
    MKRREDUCE_ALL           = 0x00000000
} MKREDUCE;

/* IBindCtx interface */
#undef INTERFACE
#define INTERFACE   IBindCtx
DECLARE_INTERFACE_( IBindCtx, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IBindCtx methods */
    STDMETHOD( RegisterObjectBound )( THIS_ LPUNKNOWN ) PURE;
    STDMETHOD( RevokeObjectBound )( THIS_ LPUNKNOWN ) PURE;
    STDMETHOD( ReleaseBoundObjects )( THIS ) PURE;
    STDMETHOD( SetBindOptions )( THIS_ LPBIND_OPTS ) PURE;
    STDMETHOD( GetBindOptions )( THIS_ LPBIND_OPTS ) PURE;
    STDMETHOD( GetRunningObjectTable )( THIS_ LPRUNNINGOBJECTTABLE FAR * ) PURE;
    STDMETHOD( RegisterObjectParam )( THIS_ LPSTR, LPUNKNOWN ) PURE;
    STDMETHOD( GetObjectParam )( THIS_ LPSTR, LPUNKNOWN FAR * ) PURE;
    STDMETHOD( EnumObjectParam )( THIS_ LPENUMSTRING FAR * ) PURE;
    STDMETHOD( RevokeObjectParam )( THIS_ LPSTR ) PURE;
};
typedef IBindCtx FAR    *LPBC;
typedef IBindCtx FAR    *LPBINDCTX;

/* IMoniker interface */
#undef INTERFACE
#define INTERFACE   IMoniker
DECLARE_INTERFACE_( IMoniker, IPersistStream ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IPersist methods */
    STDMETHOD( GetClassID )( THIS_ LPCLSID ) PURE;
    
    /* IPersistStream methods */
    STDMETHOD( IsDirty )( THIS ) PURE;
    STDMETHOD( Load )( THIS_ LPSTREAM ) PURE;
    STDMETHOD( Save )( THIS_ LPSTREAM, BOOL ) PURE;
    STDMETHOD( GetSizeMax )( THIS_ ULARGE_INTEGER FAR * ) PURE;
    
    /* IMoniker methods */
    STDMETHOD( BindToObject )( THIS_ LPBC, LPMONIKER, REFIID, LPVOID FAR * ) PURE;
    STDMETHOD( BindToStorage )( THIS_ LPBC, LPMONIKER, REFIID, LPVOID FAR * ) PURE;
    STDMETHOD( Reduce )( THIS_ LPBC, DWORD, LPMONIKER FAR *, LPMONIKER FAR * ) PURE;
    STDMETHOD( ComposeWith )( THIS_ LPMONIKER, BOOL, LPMONIKER FAR * ) PURE;
    STDMETHOD( Enum )( THIS_ BOOL, LPENUMMONIKER FAR * ) PURE;
    STDMETHOD( IsEqual )( THIS_ LPMONIKER ) PURE;
    STDMETHOD( Hash )( THIS_ LPDWORD ) PURE;
    STDMETHOD( IsRunning )( THIS_ LPBC, LPMONIKER, LPMONIKER ) PURE;
    STDMETHOD( GetTimeOfLastChange )( THIS_ LPBC, LPMONIKER, FILETIME FAR * ) PURE;
    STDMETHOD( Inverse )( THIS_ LPMONIKER FAR * ) PURE;
    STDMETHOD( CommonPrefixWith )( THIS_ LPMONIKER, LPMONIKER FAR * ) PURE;
    STDMETHOD( RelativePathTo )( THIS_ LPMONIKER, LPMONIKER FAR * ) PURE;
    STDMETHOD( GetDisplayName )( THIS_ LPBC, LPMONIKER, LPSTR FAR * ) PURE;
    STDMETHOD( ParseDisplayName )( THIS_ LPBC, LPMONIKER, LPSTR, ULONG FAR *, LPMONIKER FAR * ) PURE;
    STDMETHOD( IsSystemMoniker )( THIS_ LPDWORD ) PURE;
};
typedef IMoniker FAR    *LPMONIKER;

/* IRunningObjectTable interface */
#undef INTERFACE
#define INTERFACE   IRunningObjectTable
DECLARE_INTERFACE_( IRunningObjectTable, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IRunningObjectTable methods */
    STDMETHOD( Register )( THIS_ DWORD, LPUNKNOWN, LPMONIKER, DWORD FAR * ) PURE;
    STDMETHOD( Revoke )( THIS_ DWORD ) PURE;
    STDMETHOD( IsRunning )( THIS_ LPMONIKER ) PURE;
    STDMETHOD( GetObject )( THIS_ LPMONIKER, LPUNKNOWN FAR * ) PURE;
    STDMETHOD( NoteChangeTime )( THIS_ DWORD, FILETIME FAR * ) PURE;
    STDMETHOD( GetTimeOfLastChange )( THIS_ LPMONIKER, FILETIME FAR * ) PURE;
    STDMETHOD( EnumRunning )( THIS_ LPENUMMONIKER FAR * ) PURE;
};
typedef IRunningObjectTable FAR *LPRUNNINGOBJECTTABLE;

/* IEnumMoniker interface */
#undef INTERFACE
#define INTERFACE   IEnumMoniker
DECLARE_INTERFACE_( IEnumMoniker, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, LPVOID FAR * ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IEnumMoniker methods */
    STDMETHOD( Next )( THIS_ ULONG, LPMONIKER FAR *, ULONG FAR * ) PURE;
    STDMETHOD( Skip )( THIS_ ULONG ) PURE;
    STDMETHOD( Reset )( THIS ) PURE;
    STDMETHOD( Clone )( THIS_ IEnumMoniker FAR * FAR * ) PURE;
};
typedef IEnumMoniker FAR    *LPENUMMONIKER;

/* Functions in OLE2.DLL */
STDAPI  BindMoniker( LPMONIKER, DWORD, REFIID, LPVOID FAR * );
STDAPI  CreateAntiMoniker( LPMONIKER FAR * );
STDAPI  CreateBindCtx( DWORD, LPBC FAR * );
STDAPI  CreateFileMoniker( LPSTR, LPMONIKER FAR * );
STDAPI  CreateGenericComposite( LPMONIKER, LPMONIKER, LPMONIKER FAR * );
STDAPI  CreateItemMoniker( LPSTR, LPSTR, LPMONIKER FAR * );
STDAPI  CreatePointerMoniker( LPUNKNOWN, LPMONIKER FAR * );
STDAPI  GetClassFile( LPCSTR, CLSID FAR * );
STDAPI  GetRunningObjectTable( DWORD, LPRUNNINGOBJECTTABLE FAR * );
STDAPI  MkParseDisplayName( LPBC, LPSTR, ULONG FAR *, LPMONIKER FAR * );
STDAPI  MonikerCommonPrefixWith( LPMONIKER, LPMONIKER, LPMONIKER FAR * );
STDAPI  MonikerRelativePathTo( LPMONIKER, LPMONIKER, LPMONIKER FAR *, BOOL );

#endif
