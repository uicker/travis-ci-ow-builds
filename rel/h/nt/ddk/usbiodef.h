/*
 *  usbiodef.h  USB I/O definitions
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

#ifndef __USBIODEF_H__
#define __USBIODEF_H__

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* USB I/O control indices */
#define USB_SUBMIT_URB                          0
#define USB_RESET_PORT                          1
#define USB_GET_ROOTHUB_PDO                     3
#define USB_GET_PORT_STATUS                     4
#define USB_ENABLE_PORT                         5
#define USB_GET_HUB_COUNT                       6
#define USB_CYCLE_PORT                          7
#define USB_GET_HUB_NAME                        8
#define USB_IDLE_NOTIFICATION                   9
#define USB_RECORD_FAILURE                      10
#define USB_GET_BUS_INFO                        264
#define USB_GET_CONTROLLER_NAME                 265
#define USB_GET_BUSGUID_INFO                    266
#define USB_GET_PARENT_HUB_INFO                 267
#define USB_GET_DEVICE_HANDLE                   268
#define USB_GET_DEVICE_HANDLE_EX                269
#define USB_GET_TT_DEVICE_HANDLE                270
#define USB_GET_TOPOLOGY_ADDRESS                271
#define USB_IDLE_NOTIFICATION_EX                272
#define USB_REQ_GLOBAL_SUSPEND                  273
#define USB_REQ_GLOBAL_RESUME                   274
#define USB_GET_HUB_CONFIG_INFO                 275
#define HCD_GET_STATS_1                         255
#define HCD_DIAGNOSTIC_MODE_ON                  256
#define HCD_DIAGNOSTIC_MODE_OFF                 257
#define HCD_GET_ROOT_HUB_NAME                   258
#define HCD_GET_DRIVERKEY_NAME                  265
#define HCD_GET_STATS_2                         266
#define HCD_DISABLE_PORT                        268
#define HCD_ENABLE_PORT                         269
#define HCD_USER_REQUEST                        270
#define HCD_TRACE_READ_REQUEST                  275
#define USB_GET_NODE_INFORMATION                258
#define USB_GET_NODE_CONNECTION_INFORMATION     259
#define USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION 260
#define USB_GET_NODE_CONNECTION_NAME            261
#define USB_DIAG_IGNORE_HUBS_ON                 262
#define USB_DIAG_IGNORE_HUBS_OFF                263
#define USB_GET_NODE_CONNECTION_DRIVERKEY_NAME  264
#define USB_GET_HUB_CAPABILITIES                271
#define USB_GET_NODE_CONNECTION_ATTRIBUTES      272
#define USB_HUB_CYCLE_PORT                      273
#define USB_GET_NODE_CONNECTION_INFORMATION_EX  274
#define USB_RESET_HUB                           275
#define USB_GET_HUB_CAPABILITIES_EX             276

/* USB device type */
#define FILE_DEVICE_USB FILE_DEVICE_UNKNOWN

/* Macro to make USB I/O control codes */
#define USB_CTL( x ) \
    CTL_CODE( FILE_DEVICE_USB, x, METHOD_BUFFERED, FILE_ANY_ACCESS )
#define USB_KERNEL_CTL( x ) \
    CTL_CODE( FILE_DEVICE_USB, x, METHOD_NEITHER, FILE_ANY_ACCESS )
#define USB_KERNEL_CTL_BUFFERED( x ) \
    CTL_CODE( FILE_DEVICE_USB, x, METHOD_BUFFERED, FILE_ANY_ACCESS )

/* USB idle callback */
#if (_WIN32_WINNT >= 0x0501)
typedef VOID (NTAPI *USB_IDLE_CALLBACK)( PVOID );
#endif

/* USB idle callback information */
#if (_WIN32_WINNT >= 0x0501)
typedef struct _USB_IDLE_CALLBACK_INFO {
    USB_IDLE_CALLBACK   IdleCallback;
    PVOID               IdleContext;
} USB_IDLE_CALLBACK_INFO;
typedef USB_IDLE_CALLBACK_INFO  *PUSB_IDLE_CALLBACK_INFO;
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __USBIODEF_H__ */
