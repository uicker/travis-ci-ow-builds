/*
 *  netdb.h      Net database functions.
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
#ifndef _NETDB_H_INCLUDED
#define _NETDB_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _SYS_SOCKET_H_INCLUDED
 #include <sys/socket.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 4 )

struct netent {
    char     *n_name;       /* official network name */
    char     **n_aliases;   /* alias list */
    int      n_addrtype;    /* address type */
    uint32_t n_net;         /* network number */
};

struct protoent {
    char    *p_name;        /* official protocol name */
    char    **p_aliases;    /* alias list */
    int     p_proto;        /* protocol number */
};

struct servent {
    char    *s_name;        /* official service name */
    char    **s_aliases;    /* alias list */
    int     s_port;         /* port number */
    char    *s_proto;       /* protocol to use */
};

struct hostent {
    char    *h_name;        /* official name of host */
    char    **h_aliases;    /* alias list */
    int     h_addrtype;     /* host address type */
    int     h_length;       /* length of address */
    char    **h_addr_list;  /* list of addresses */
};
#define h_addr  h_addr_list[0]  /* for backward compatibility */

_WCRTDATA extern int h_errno;

#define HOST_NOT_FOUND 1
#define TRY_AGAIN      2
#define NO_RECOVERY    3
#define NO_DATA        4

/* GNU libc compatibility */
#define NO_ADDRESS     NO_DATA

_WCRTLINK extern struct netent   *getnetent( void );
_WCRTLINK extern struct netent   *getnetbyaddr( uint32_t __naddr, int __type );
_WCRTLINK extern struct netent   *getnetbyname( const char *__name );
_WCRTLINK extern void            setnetent( int __stayopen );
_WCRTLINK extern void            endnetent( void );

_WCRTLINK extern struct protoent *getprotoent( void );
_WCRTLINK extern struct protoent *getprotobyname( const char *__name );
_WCRTLINK extern struct protoent *getprotobynumber( int __proto );
_WCRTLINK extern void            setprotoent( int __stayopen );
_WCRTLINK extern void            endprotoent( void );

_WCRTLINK extern struct servent  *getservent( void );
_WCRTLINK extern struct servent  *getservbyname( const char *__name, const char *__proto );
_WCRTLINK extern struct servent  *getservbyport( int __port, const char *__proto );
_WCRTLINK extern void            setservent( int __stayopen );
_WCRTLINK extern void            endservent( void );

_WCRTLINK extern struct hostent  *gethostbyname( const char *__name );
_WCRTLINK extern struct hostent  *gethostbyaddr( const void *__addr, socklen_t __len, int __type );
_WCRTLINK extern struct hostent  *gethostent(void);
_WCRTLINK extern void            sethostent( int __stayopen );
_WCRTLINK extern void            endhostent( void );

_WCRTLINK extern void            herror( const char *__s );
_WCRTLINK extern const char      *hstrerror( int __err );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !_NETDB_H_INCLUDED */
