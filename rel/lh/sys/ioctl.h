/*
 *  ioctl.h
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
#ifndef _SYS_IOCTL_H_INCLUDED
#define _SYS_IOCTL_H_INCLUDED

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

#ifndef _ARCH_DIR
 #if defined(__386__)
  #define _ARCH_DIR i386
 #elif defined(__MIPS__)
  #define _ARCH_DIR mips
 #else
  #error unknown platform
  #define _ARCH_DIR
 #endif
 #define _ARCH_INCLUDE(hdr) <arch/ ## _ARCH_DIR ## / ## hdr ## >
#endif /* !_ARCH_DIR */

#include _ARCH_INCLUDE(sys/ioctl.h)

/**** From <bits/ioctls.h> ****/

/* Routing table calls.  */
#define SIOCADDRT       0x890B          /* add routing table entry      */
#define SIOCDELRT       0x890C          /* delete routing table entry   */
#define SIOCRTMSG       0x890D          /* call to routing system       */

/* Socket configuration controls. */
#define SIOCGIFNAME     0x8910          /* get iface name               */
#define SIOCSIFLINK     0x8911          /* set iface channel            */
#define SIOCGIFCONF     0x8912          /* get iface list               */
#define SIOCGIFFLAGS    0x8913          /* get flags                    */
#define SIOCSIFFLAGS    0x8914          /* set flags                    */
#define SIOCGIFADDR     0x8915          /* get PA address               */
#define SIOCSIFADDR     0x8916          /* set PA address               */
#define SIOCGIFDSTADDR  0x8917          /* get remote PA address        */
#define SIOCSIFDSTADDR  0x8918          /* set remote PA address        */
#define SIOCGIFBRDADDR  0x8919          /* get broadcast PA address     */
#define SIOCSIFBRDADDR  0x891a          /* set broadcast PA address     */
#define SIOCGIFNETMASK  0x891b          /* get network PA mask          */
#define SIOCSIFNETMASK  0x891c          /* set network PA mask          */
#define SIOCGIFMETRIC   0x891d          /* get metric                   */
#define SIOCSIFMETRIC   0x891e          /* set metric                   */
#define SIOCGIFMEM      0x891f          /* get memory address (BSD)     */
#define SIOCSIFMEM      0x8920          /* set memory address (BSD)     */
#define SIOCGIFMTU      0x8921          /* get MTU size                 */
#define SIOCSIFMTU      0x8922          /* set MTU size                 */
#define SIOCSIFHWADDR   0x8924          /* set hardware address         */
#define SIOCGIFENCAP    0x8925          /* get/set encapsulations       */
#define SIOCSIFENCAP    0x8926
#define SIOCGIFHWADDR   0x8927          /* Get hardware address         */
#define SIOCGIFSLAVE    0x8929          /* Driver slaving support       */
#define SIOCSIFSLAVE    0x8930
#define SIOCADDMULTI    0x8931          /* Multicast address lists      */
#define SIOCDELMULTI    0x8932
#define SIOCGIFINDEX    0x8933          /* name -> if_index mapping     */
#define SIOGIFINDEX     SIOCGIFINDEX    /* misprint compatibility :-)   */
#define SIOCSIFPFLAGS   0x8934          /* set/get extended flags set   */
#define SIOCGIFPFLAGS   0x8935
#define SIOCDIFADDR     0x8936          /* delete PA address            */
#define SIOCSIFHWBROADCAST      0x8937  /* set hardware broadcast addr  */
#define SIOCGIFCOUNT    0x8938          /* get number of devices */

#define SIOCGIFBR       0x8940          /* Bridging support             */
#define SIOCSIFBR       0x8941          /* Set bridging options         */

#define SIOCGIFTXQLEN   0x8942          /* Get the tx queue length      */
#define SIOCSIFTXQLEN   0x8943          /* Set the tx queue length      */


/* ARP cache control calls. */
                    /*  0x8950 - 0x8952  * obsolete calls, don't re-use */
#define SIOCDARP        0x8953          /* delete ARP table entry       */
#define SIOCGARP        0x8954          /* get ARP table entry          */
#define SIOCSARP        0x8955          /* set ARP table entry          */

/* RARP cache control calls. */
#define SIOCDRARP       0x8960          /* delete RARP table entry      */
#define SIOCGRARP       0x8961          /* get RARP table entry         */
#define SIOCSRARP       0x8962          /* set RARP table entry         */

/* Driver configuration calls */

#define SIOCGIFMAP      0x8970          /* Get device parameters        */
#define SIOCSIFMAP      0x8971          /* Set device parameters        */

/* DLCI configuration calls */

#define SIOCADDDLCI     0x8980          /* Create new DLCI device       */
#define SIOCDELDLCI     0x8981          /* Delete DLCI device           */

/* Device private ioctl calls.  */

/* These 16 ioctls are available to devices via the do_ioctl() device
   vector.  Each device should include this file and redefine these
   names as their own. Because these are device dependent it is a good
   idea _NOT_ to issue them to random objects and hope.  */

#define SIOCDEVPRIVATE          0x89F0  /* to 89FF */

/*
 *      These 16 ioctl calls are protocol private
 */

#define SIOCPROTOPRIVATE 0x89E0 /* to 89EF */

/**** From <bits/ioctl-types.h> ****/

struct winsize {
    unsigned short int ws_row;
    unsigned short int ws_col;
    unsigned short int ws_xpixel;
    unsigned short int ws_ypixel;
};

#define NCC 8
struct termio {
    unsigned short int c_iflag;         /* input mode flags */
    unsigned short int c_oflag;         /* output mode flags */
    unsigned short int c_cflag;         /* control mode flags */
    unsigned short int c_lflag;         /* local mode flags */
    unsigned char c_line;               /* line discipline */
    unsigned char c_cc[NCC];            /* control characters */
};

/* modem lines */
#define TIOCM_LE        0x001
#define TIOCM_DTR       0x002
#define TIOCM_RTS       0x004
#define TIOCM_ST        0x008
#define TIOCM_SR        0x010
#define TIOCM_CTS       0x020
#define TIOCM_CAR       0x040
#define TIOCM_RNG       0x080
#define TIOCM_DSR       0x100
#define TIOCM_CD        TIOCM_CAR
#define TIOCM_RI        TIOCM_RNG

/* ioctl (fd, TIOCSERGETLSR, &result) where result may be as below */

/* line disciplines */
#define N_TTY           0
#define N_SLIP          1
#define N_MOUSE         2
#define N_PPP           3
#define N_STRIP         4
#define N_AX25          5
#define N_X25           6       /* X.25 async  */
#define N_6PACK         7
#define N_MASC          8       /* Mobitex module  */
#define N_R3964         9       /* Simatic R3964 module  */
#define N_PROFIBUS_FDL  10      /* Profibus  */
#define N_IRDA          11      /* Linux IR  */
#define N_SMSBLOCK      12      /* SMS block mode  */
#define N_HDLC          13      /* synchronous HDLC  */
#define N_SYNC_PPP      14      /* synchronous PPP  */
#define N_HCI           15      /* Bluetooth HCI UART  */

/**** From <sys/ttydefaults.h> ****/

/*
 * Defaults on "first" open.
 */
#define TTYDEF_IFLAG    (BRKINT | ISTRIP | ICRNL | IMAXBEL | IXON | IXANY)
#define TTYDEF_OFLAG    (OPOST | ONLCR | XTABS)
#define TTYDEF_LFLAG    (ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
#define TTYDEF_CFLAG    (CREAD | CS7 | PARENB | HUPCL)
#define TTYDEF_SPEED    (B9600)

/*
 * Control Character Defaults
 */
#define CTRL(x) (x&037)
#define CEOF            CTRL('d')
#ifdef _POSIX_VDISABLE
# define CEOL           _POSIX_VDISABLE
#else
# define CEOL           '\0'            /* XXX avoid _POSIX_VDISABLE */
#endif
#define CERASE          0177
#define CINTR           CTRL('c')
#ifdef _POSIX_VDISABLE
# define CSTATUS        _POSIX_VDISABLE
#else
# define CSTATUS        '\0'            /* XXX avoid _POSIX_VDISABLE */
#endif
#define CKILL           CTRL('u')
#define CMIN            1
#define CQUIT           034             /* FS, ^\ */
#define CSUSP           CTRL('z')
#define CTIME           0
#define CDSUSP          CTRL('y')
#define CSTART          CTRL('q')
#define CSTOP           CTRL('s')
#define CLNEXT          CTRL('v')
#define CDISCARD        CTRL('o')
#define CWERASE         CTRL('w')
#define CREPRINT        CTRL('r')
#define CEOT            CEOF
/* compat */
#define CBRK            CEOL
#define CRPRNT          CREPRINT
#define CFLUSH          CDISCARD

/* Perform the I/O control operation specified by REQUEST on FD.
 * One argument may follow; its presence and type depend on REQUEST.
 * Return value depends on REQUEST.  Usually -1 indicates error.
 */
_WCRTLINK extern int ioctl( int __fd, unsigned long int __request, ... );

#pragma pack( __pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* !_SYS_IOCTL_H_INCLUDED */