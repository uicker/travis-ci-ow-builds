/*
 *  termios.h
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
#ifndef _TERMIOS_H_INCLUDED
#define _TERMIOS_H_INCLUDED

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifndef __COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif

#ifndef _TIME_H_INCLUDED
 #include <time.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( __push, 4 )

#ifndef _PID_T_DEFINED_
 #define _PID_T_DEFINED_
 typedef int            pid_t;  /* Used for process IDs & group IDs */
#endif

typedef unsigned char   cc_t;
typedef unsigned int    speed_t;
typedef unsigned int    tcflag_t;

#define NCCS 32
struct termios {
    tcflag_t        c_iflag;        /* Input mode flags     */
    tcflag_t        c_oflag;        /* Output mode flags    */
    tcflag_t        c_cflag;        /* Control mode flags   */
    tcflag_t        c_lflag;        /* Local mode flags     */
    cc_t            c_cc[NCCS];     /* Control characters   */
    speed_t         c_ispeed;       /* Input speed          */
    speed_t         c_ospeed;       /* Output speed         */
    cc_t            c_line;         /* Line discipline      */
};

/*
 * Special Control Character indices into c_cc[]
 */
#define VINTR       0
#define VQUIT       1
#define VERASE      2
#define VKILL       3
#define VEOF        4
#define VTIME       5
#define VMIN        6
#define VSWTC       7
#define VSTART      8
#define VSTOP       9
#define VSUSP       10
#define VEOL        11
#define VREPRINT    12
#define VDISCARD    13
#define VWERASE     14
#define VLNEXT      15
#define VEOL2       16

/*
 * Input modes (c_iflag)
 */
#define IGNBRK      0000001
#define BRKINT      0000002
#define IGNPAR      0000004
#define PARMRK      0000010
#define INPCK       0000020
#define ISTRIP      0000040
#define INLCR       0000100
#define IGNCR       0000200
#define ICRNL       0000400
#define IUCLC       0001000
#define IXON        0002000
#define IXANY       0004000
#define IXOFF       0010000
#define IMAXBEL     0020000

/*
 * Ouput Modes (c_oflag)
 */
#define OPOST       0000001
#define OLCUC       0000002
#define ONLCR       0000004
#define OCRNL       0000010
#define ONOCR       0000020
#define ONLRET      0000040
#define OFILL       0000100
#define OFDEL       0000200
#define VTDLY       0040000
#define   VT0       0000000
#define   VT1       0040000

/*
 * Pre-Defined Baud rates used by cfgetospeed(), c_cflag etc.
 */
#define  B0         0000000         /* hang up */
#define  B50        0000001
#define  B75        0000002
#define  B110       0000003
#define  B134       0000004
#define  B150       0000005
#define  B200       0000006
#define  B300       0000007
#define  B600       0000010
#define  B1200      0000011
#define  B1800      0000012
#define  B2400      0000013
#define  B4800      0000014
#define  B9600      0000015
#define  B19200     0000016
#define  B38400     0000017
#define CSIZE       0000060
#define   CS5       0000000
#define   CS6       0000020
#define   CS7       0000040
#define   CS8       0000060
#define CSTOPB      0000100
#define CREAD       0000200
#define PARENB      0000400
#define PARODD      0001000
#define HUPCL       0002000
#define CLOCAL      0004000
#define  B57600     0010001
#define  B115200    0010002
#define  B230400    0010003
#define  B460800    0010004
#define  B500000    0010005
#define  B576000    0010006
#define  B921600    0010007
#define  B1000000   0010010
#define  B1152000   0010011
#define  B1500000   0010012
#define  B2000000   0010013
#define  B2500000   0010014
#define  B3000000   0010015
#define  B3500000   0010016
#define  B4000000   0010017
#define CBAUD       0010017

/*
 * Local Modes (c_lflag)
 */
#define ISIG        0000001
#define ICANON      0000002
#define ECHO        0000010
#define ECHOE       0000020
#define ECHOK       0000040
#define ECHONL      0000100
#define NOFLSH      0000200
#define TOSTOP      0000400
#define IEXTEN      0100000

/*
 * Actions for tcflow()
 */
#define TCOOFF          0
#define TCOON           1
#define TCIOFF          2
#define TCION           3

/*
 * queue_selectors for tcflush()
 */
#define TCIFLUSH        0
#define TCOFLUSH        1
#define TCIOFLUSH       2

/*
 * Optional Actions for tcsetattr()
 */
#define TCSANOW         0
#define TCSADRAIN       1
#define TCSAFLUSH       2

_WCRTLINK extern speed_t cfgetospeed( const struct termios *__termios_p );
_WCRTLINK extern speed_t cfgetispeed( const struct termios *__termios_p );
_WCRTLINK extern int     cfsetospeed( struct termios *__termios_p, speed_t __speed );
_WCRTLINK extern int     cfsetispeed( struct termios *__termios_p, speed_t __speed );
_WCRTLINK extern int     tcgetattr( int __fd, struct termios *__termios_p );
_WCRTLINK extern int     tcsetattr( int __fd, int __optional_actions, const struct termios *__termios_p );
_WCRTLINK extern void    cfmakeraw( struct termios *__termios_p );
_WCRTLINK extern int     tcsendbreak( int __fd, int __duration );
_WCRTLINK extern int     tcdrain( int __fd );
_WCRTLINK extern int     tcflush( int __fd, int __queue_selector );
_WCRTLINK extern int     tcflow( int __fd, int __action );
_WCRTLINK extern pid_t   tcgetsid( int __fildes );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !_TERMIOS_H_INCLUDED */
