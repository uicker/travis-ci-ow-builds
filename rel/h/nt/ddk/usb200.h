/*
 *  usb200.h    USB 2.0 definitions
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

#ifndef __USB200_H__
#define __USB200_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <usb100.h>

#ifdef __cplusplus
extern "C" {
#endif

/* USB port status flags */
#define USB_PORT_STATUS_CONNECT         0x0001
#define USB_PORT_STATUS_ENABLE          0x0002
#define USB_PORT_STATUS_SUSPEND         0x0004
#define USB_PORT_STATUS_OVER_CURRENT    0x0008
#define USB_PORT_STATUS_RESET           0x0010
#define USB_PORT_STATUS_POWER           0x0100
#define USB_PORT_STATUS_LOW_SPEED       0x0200
#define USB_PORT_STATUS_HIGH_SPEED      0x0400

/* USB descriptor types */
#define USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE            0x06
#define USB_OTHER_SPEED_CONFIGURATION_DESCRIPTOR_TYPE   0x07
#define USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE       0x0B

/* All structures in this file get one-byte packing. */
#include <pshpack1.h>

/* USB device speeds */
typedef enum _USB_DEVICE_SPEED {
    UsbLowSpeed     = 0,
    UsbFullSpeed    = 1,
    UsbHighSpeed    = 2
} USB_DEVICE_SPEED;

/* USB device types */
typedef enum _USB_DEVICE_TYPE {
    Usb11Device = 0,
    Usb20Device = 1
} USB_DEVICE_TYPE;

/* Request type */
typedef union _BM_REQUEST_TYPE {
    struct _BM {
        UCHAR   Recipient   : 2;
        UCHAR   Reserved    : 3;
        UCHAR   Type        : 2;
        UCHAR   Dir         : 1;
    };
    UCHAR   B;
} BM_REQUEST_TYPE;
typedef BM_REQUEST_TYPE *PBM_REQUEST_TYPE;

/* USB default pipe setup packet */
typedef struct _USB_DEFAULT_PIPE_SETUP_PACKET {
    BM_REQUEST_TYPE bmRequestType;
    UCHAR           bRequest;
    union _wValue {
        struct {
            UCHAR   LowByte;
            UCHAR   HiByte;
        };
        USHORT  W;
    } wValue;
    union _wIndex {
        struct {
            UCHAR   LowByte;
            UCHAR   HiByte;
        };
        USHORT  W;
    } wIndex;
    USHORT          wLength;
} USB_DEFAULT_PIPE_SETUP_PACKET;
typedef USB_DEFAULT_PIPE_SETUP_PACKET   *PUSB_DEFAULT_PIPE_SETUP_PACKET;

/* USB device qualifier descriptor */
typedef struct _USB_DEVICE_QUALIFIER_DESCRIPTOR {
    UCHAR   bLength;
    UCHAR   bDescriptorType;
    USHORT  bcdUSB;
    UCHAR   bDeviceClass;
    UCHAR   bDeviceSubClass;
    UCHAR   bDeviceProtocol;
    UCHAR   bMaxPacketSize0;
    UCHAR   bNumConfigurations;
    UCHAR   bReserved;
} USB_DEVICE_QUALIFIER_DESCRIPTOR;
typedef USB_DEVICE_QUALIFIER_DESCRIPTOR *PUSB_DEVICE_QUALIFIER_DESCRIPTOR;

/* USB high speed maximum packet */
typedef union _USB_HIGH_SPEED_MAXPACKET {
    struct _MP {
        USHORT  MaxPacket   : 11;
        USHORT  HSmux       : 2;
        USHORT  Reserved    : 3;
    };
    USHORT  us;
} USB_HIGH_SPEED_MAXPACKET;
typedef USB_HIGH_SPEED_MAXPACKET    *PUSB_HIGH_SPEED_MAXPACKET;

/* USB interface association descriptor */
typedef struct _USB_INTERFACE_ASSOCIATION_DESCRIPTOR {
    UCHAR   bLength;
    UCHAR   bDescriptorType;
    UCHAR   bFirstInterface;
    UCHAR   bInterfaceCount;
    UCHAR   bFunctionClass;
    UCHAR   bFunctionSubClass;
    UCHAR   bFunctionProtocol;
    UCHAR   iFunction;
} USB_INTERFACE_ASSOCIATION_DESCRIPTOR;
typedef USB_INTERFACE_ASSOCIATION_DESCRIPTOR    *PUSB_INTERFACE_ASSOCIATION_DESCRIPTOR;

/* Revert to default packing. */
#include <poppack.h>

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __USB200_H__ */
