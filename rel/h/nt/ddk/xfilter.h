/*
 *  xfilter.h   NDIS filter definitions
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

#ifndef _X_FILTER_DEFS_
#define _X_FILTER_DEFS_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Primitive data types */
typedef ULONG   TR_FUNCTIONAL_ADDRESS;
typedef ULONG   TR_GROUP_ADDRESS;

/* Lengths */
#define ETH_LENGTH_OF_ADDRESS   6
#define TR_LENGTH_OF_FUNCTIONAL 4
#define TR_LENGTH_OF_ADDRESS    6

/* Address macros */
#define ETH_IS_MULTICAST( x )   (BOOLEAN)(((PUCHAR)(x))[0] & 0x01)
#define ETH_IS_BROADCAST( x ) \
    ((((PUCHAR)(x))[0] == 0xFF) && (((PUCHAR)(x))[1] == 0xFF) && \
    (((PUCHAR)(x))[2] == 0xFF) && (((PUCHAR)(x))[3] == 0xFF) && \
    (((PUCHAR)(x))[4] == 0xFF) && (((PUCHAR)(x))[5] == 0xFF))
#define ETH_COMPARE_NETWORK_ADDRESSES( p1, p2, p3 ) \
    { \
        if( *(ULONG UNALIGNED *)&(p1)[2] > *(ULONG UNALIGNED *)&(p2)[2] ) { \
            *(p3) = 1; \
        } else if( *(ULONG UNALIGNED *)&(p1)[2] < *(ULONG UNALIGNED *)&(p2)[2] ) { \
            *(p3) = (UINT)-1; \
        } else if( *(USHORT UNALIGNED *)(p1) > *(USHORT UNALIGNED *)(p2) ) { \
            *(p3) = 1; \
        } else if( *(USHORT UNALIGNED *)(p1) < *(USHORT UNALIGNED *)(p2) ) { \
            *(p3) = (UINT)-1; \
        } else { \
            *(p3) = 0; \
        } \
    }
#define ETH_COMPARE_NETWORK_ADDRESSES_EQ( p1, p2, p3 ) \
    { \
        if( (*(ULONG UNALIGNED *)&(p1)[2] == *(ULONG UNALIGNED *)&(p2)[2]) && \
            (*(USHORT UNALIGNED *)(p1) == *(USHORT UNALIGNED *)(p2)) ) { \
            *(p3) = 0; \
        } else { \
            *(p3) = 1; \
        } \
    }
#define ETH_COPY_NETWORK_ADDRESS( p1, p2 ) \
    { \
        *((ULONG UNALIGNED *)(p1)) = *((ULONG UNALIGNED *)(p2)); \
        *((USHORT UNALIGNED *)((UCHAR *)(p1) + 4)) = \
            *((USHORT UNALIGNED *)((UCHAR *)(p2) + 4)); \
    }
#define TR_IS_NOT_DIRECTED( p1, p2 ) \
    { \
        *(p2) = (BOOLEAN)((p1)[0] & 0x80); \
    }
#define TR_IS_FUNCTIONAL( p1, p2 ) \
    { \
        *(p2) = (BOOLEAN)(((p1)[0] & 0x80) && !((p1)[2] & 0x80)); \
    }
#define TR_IS_GROUP( p1, p2 ) \
    { \
        *(p2) = (BOOLEAN)((p1)[0] & (p1)[2] & 0x80); \
    }
#define TR_IS_SOURCE_ROUTING( p1, p2 ) \
    { \
        *(p2) = (BOOLEAN)((p1)[0] & 0x80); \
    }
#define TR_IS_MAC_FRAME( x )    ((((PUCHAR)(x))[1] & 0xFC) == 0)
#define TR_IS_BROADCAST( p1, p2 ) \
    { \
        *(p2) = (BOOLEAN)(((*(UNALIGNED USHORT *)&(p1)[0] == 0xFFFF) || \
            (*(UNALIGNED USHORT *)&(p1)[0] == 0x00C0)) && \
            (*(UNALIGNED ULONG *)&(p2)[2] == 0xFFFFFFFF)); \
    }
#define TR_COMPARE_NETWORK_ADDRESSES( p1, p2, p3 ) \
    { \
        if( *(ULONG UNALIGNED *)&(p1)[2] > *(ULONG UNALIGNED *)&(p2)[2] ) { \
            *(p3) = 1; \
        } else if( *(ULONG UNALIGNED *)&(p1)[2] < *(ULONG UNALIGNED *)&(p2)[2] ) { \
            *(p3) = (UINT)-1; \
        } else if( *(USHORT UNALIGNED *)(p1) > *(USHORT UNALIGNED *)(p2) ) { \
            *(p3) = 1; \
        } else if( *(USHORT UNALIGNED *)(p1) < *(USHORT UNALIGNED *)(p2) ) { \
            *(p3) = (UINT)-1; \
        } else { \
            *(p3) = 0; \
        } \
    }
#define TR_COMPARE_NETWORK_ADDRESSES_EQ( p1, p2, p3 ) \
    { \
        if( (*(ULONG UNALIGNED *)&(p1)[2] == *(ULONG UNALIGNED *)&(p2)[2]) && \
            (*(USHORT UNALIGNED *)&(p1)[0] == *(USHORT UNALIGNED *)&(p2)[0]) ) { \
            *(p3) = 0; \
        } else { \
            *(p3) = 1; \
        } \
    }
#define TR_COPY_NETWORK_ADDRESS( p1, p2 ) \
    { \
        *((ULONG UNALIGNED *)(p1)) = *((ULONG UNALIGNED *)(p2)); \
        *((USHORT UNALIGNED *)((UCHAR *)(p1) + 4)) = \
            *((USHORT UNALIGNED *)((UCHAR *)(p2) + 4)); \
    }

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _X_FILTER_DEFS_ */
