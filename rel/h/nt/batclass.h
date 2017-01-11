/*
 *  batclass.h  Battery class functions
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

#ifndef _BATCLASS_
#define _BATCLASS_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to specify battery class functions */
#ifndef _WINDOWS_
    #define BATTERYCLASSAPI DECLSPEC_IMPORT
#endif

/* Battery device I/O control codes */
#define IOCTL_BATTERY_QUERY_TAG \
    CTL_CODE( FILE_DEVICE_BATTERY, 0x0010, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_BATTERY_QUERY_INFORMATION \
    CTL_CODE( FILE_DEVICE_BATTERY, 0x0011, METHOD_BUFFERED, FILE_READ_ACCESS )
#define IOCTL_BATTERY_SET_INFORMATION \
    CTL_CODE( FILE_DEVICE_BATTERY, 0x0012, METHOD_BUFFERED, FILE_WRITE_ACCESS )
#define IOCTL_BATTERY_QUERY_STATUS \
    CTL_CODE( FILE_DEVICE_BATTERY, 0x0013, METHOD_BUFFERED, FILE_READ_ACCESS )

/* Battery tag special value */
#define BATTERY_TAG_INVALID 0L

/* Battery capability flags */
#define BATTERY_SYSTEM_BATTERY          0x80000000L
#define BATTERY_CAPACITY_RELATIVE       0x40000000L
#define BATTERY_IS_SHORT_TERM           0x20000000L
#define BATTERY_SET_CHARGE_SUPPORTED    0x00000001L
#define BATTERY_SET_DISCHARGE_SUPPORTED 0x00000002L

/* Battery capacity special value */
#define BATTERY_UNKNOWN_CAPACITY    0xFFFFFFFFL

/* Battery estimated time special value */
#define BATTERY_UNKNOWN_TIME    0xFFFFFFFFL

/* Maximum battery string size */
#define MAX_BATTERY_STRING_SIZE 128

/* Battery power state flags */
#define BATTERY_POWER_ON_LINE   0x00000001L
#define BATTERY_DISCHARGING     0x00000002L
#define BATTERY_CHARGING        0x00000004L
#define BATTERY_CRITICAL        0x00000008L

/* Special battery status values */
#define BATTERY_UNKNOWN_VOLTAGE 0xFFFFFFFFL
#define BATTERY_UNKNOWN_RATE    0x80000000L

/* Battery class version numbers */
#ifndef _WINDOWS_
    #define BATTERY_CLASS_MAJOR_VERSION 0x0001
    #define BATTERY_CLASS_MINOR_VERSION 0x0000
#endif

/* Battery query information levels */
typedef enum {
    BatteryInformation              = 0,
    BatteryGranularityInformation   = 1,
    BatteryTemperature              = 2,
    BatteryEstimatedTime            = 3,
    BatteryDeviceName               = 4,
    BatteryManufactureDate          = 5,
    BatteryManufactureName          = 6,
    BatteryUniqueID                 = 7,
    BatterySerialNumber             = 8
} BATTERY_QUERY_INFORMATION_LEVEL;

/* IOCTL_BATTERY_QUERY_INFORMATION parameters */
typedef struct _BATTERY_QUERY_INFORMATION {
    ULONG                           BatteryTag;
    BATTERY_QUERY_INFORMATION_LEVEL InformationLevel;
    LONG                            AtRate;
} BATTERY_QUERY_INFORMATION;
typedef BATTERY_QUERY_INFORMATION   *PBATTERY_QUERY_INFORMATION;

/* Battery information */
typedef struct _BATTERY_INFORMATION {
    ULONG   Capabilities;
    UCHAR   Technology;
    UCHAR   Reserved[3];
    UCHAR   Chemistry[4];
    ULONG   DesignedCapacity;
    ULONG   FullChargedCapacity;
    ULONG   DefaultAlert1;
    ULONG   DefaultAlert2;
    ULONG   CriticalBias;
    ULONG   CycleCount;
} BATTERY_INFORMATION;
typedef BATTERY_INFORMATION *PBATTERY_INFORMATION;

/* Battery reporting scale */
#if (NTDDI_VERSION < 0x05010000) && !defined( _NTPOAPI_ )
typedef struct {
    ULONG   Granularity;
    ULONG   Capacity;
} BATTERY_REPORTING_SCALE;
typedef BATTERY_REPORTING_SCALE *PBATTERY_REPORTING_SCALE;
#endif

/* Battery manufacture date */
typedef struct _BATTERY_MANUFACTURE_DATE {
    UCHAR   Day;
    UCHAR   Month;
    USHORT  Year;
} BATTERY_MANUFACTURE_DATE;
typedef BATTERY_MANUFACTURE_DATE    *PBATTERY_MANUFACTURE_DATE;

/* Battery set information levels */
typedef enum {
    BatteryCriticalBias = 0,
    BatteryCharge       = 1,
    BatteryDischarge    = 2
} BATTERY_SET_INFORMATION_LEVEL;

/* IOCTL_BATTERY_SET_INFORMATION parameters */
typedef struct _BATTERY_SET_INFORMATION {
    ULONG                           BatteryTag;
    BATTERY_SET_INFORMATION_LEVEL   InformationLevel;
    UCHAR                           Buffer[1];
} BATTERY_SET_INFORMATION;
typedef BATTERY_SET_INFORMATION *PBATTERY_SET_INFORMATION;

/* Battery wait status */
typedef struct _BATTERY_WAIT_STATUS {
    ULONG   BatteryTag;
    ULONG   Timeout;
    ULONG   PowerState;
    ULONG   LowCapacity;
    ULONG   HighCapacity;
} BATTERY_WAIT_STATUS;
typedef BATTERY_WAIT_STATUS *PBATTERY_WAIT_STATUS;

/* Battery status */
typedef struct _BATTERY_STATUS {
    ULONG   PowerState;
    ULONG   Capacity;
    ULONG   Voltage;
    LONG    Rate;
} BATTERY_STATUS;
typedef BATTERY_STATUS  *PBATTERY_STATUS;

/* Battery notification */
#ifndef _WINDOWS_
typedef struct {
    ULONG   PowerState;
    ULONG   LowCapacity;
    ULONG   HighCapacity;
} BATTERY_NOTIFY;
typedef BATTERY_NOTIFY  *PBATTERY_NOTIFY;
#endif

/* Battery class callbacks */
#ifndef _WINDOWS_
typedef NTSTATUS (NTAPI BCLASS_QUERY_TAG_CALLBACK)( PVOID, PULONG );
typedef NTSTATUS (NTAPI BCLASS_QUERY_INFORMATION_CALLBACK)( PVOID, ULONG, BATTERY_QUERY_INFORMATION_LEVEL, LONG, PVOID, ULONG, PULONG );
typedef NTSTATUS (NTAPI BCLASS_QUERY_STATUS_CALLBACK)( PVOID, ULONG, PBATTERY_STATUS );
typedef NTSTATUS (NTAPI BCLASS_SET_STATUS_NOTIFY_CALLBACK)( PVOID, ULONG, PBATTERY_NOTIFY );
typedef NTSTATUS (NTAPI BCLASS_SET_INFORMATION_CALLBACK)( PVOID, ULONG, BATTERY_SET_INFORMATION_LEVEL, PVOID );
typedef NTSTATUS (NTAPI BCLASS_DISABLE_STATUS_NOTIFY_CALLBACK)( PVOID );
typedef BCLASS_QUERY_TAG_CALLBACK               *PBCLASS_QUERY_TAG_CALLBACK;
typedef BCLASS_QUERY_INFORMATION_CALLBACK       *PBCLASS_QUERY_INFORMATION_CALLBACK;
typedef BCLASS_QUERY_STATUS_CALLBACK            *PBCLASS_QUERY_STATUS_CALLBACK;
typedef BCLASS_SET_STATUS_NOTIFY_CALLBACK       *PBCLASS_SET_STATUS_NOTIFY_CALLBACK;
typedef BCLASS_SET_INFORMATION_CALLBACK         *PBCLASS_SET_INFORMATION_CALLBACK;
typedef BCLASS_DISABLE_STATUS_NOTIFY_CALLBACK   *PBCLASS_DISABLE_STATUS_NOTIFY_CALLBACK;
typedef PBCLASS_QUERY_TAG_CALLBACK              BCLASS_QUERY_TAG;
typedef PBCLASS_QUERY_INFORMATION_CALLBACK      BCLASS_QUERY_INFORMATION;
typedef PBCLASS_QUERY_STATUS_CALLBACK           BCLASS_QUERY_STATUS;
typedef PBCLASS_SET_STATUS_NOTIFY_CALLBACK      BCLASS_SET_STATUS_NOTIFY;
typedef PBCLASS_SET_INFORMATION_CALLBACK        BCLASS_SET_INFORMATION;
typedef PBCLASS_DISABLE_STATUS_NOTIFY_CALLBACK  BCLASS_DISABLE_STATUS_NOTIFY;
#endif

/* Battery miniport information */
#ifndef _WINDOWS_
typedef struct {
    USHORT                          MajorVersion;
    USHORT                          MinorVersion;
    PVOID                           Context;
    BCLASS_QUERY_TAG                QueryTag;
    BCLASS_QUERY_INFORMATION        QueryInformation;
    BCLASS_SET_INFORMATION          SetInformation;
    BCLASS_QUERY_STATUS             QueryStatus;
    BCLASS_SET_STATUS_NOTIFY        SetStatusNotify;
    BCLASS_DISABLE_STATUS_NOTIFY    DisableStatusNotify;
    PDEVICE_OBJECT                  Pdo;
    PUNICODE_STRING                 DeviceName;
} BATTERY_MINIPORT_INFO;
typedef BATTERY_MINIPORT_INFO   *PBATTERY_MINIPORT_INFO;
#endif

/* Battery WMI status */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_STATUS {
    ULONG   Tag;
    ULONG   RemainingCapacity;
    LONG    ChargeRate;
    LONG    DischargeRate;
    ULONG   Voltage;
    BOOLEAN PowerOnline;
    BOOLEAN Charging;
    BOOLEAN Discharging;
    BOOLEAN Critical;
} BATTERY_WMI_STATUS;
typedef BATTERY_WMI_STATUS  *PBATTERY_WMI_STATUS;
#endif

/* Battery WMI runtime */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_RUNTIME {
    ULONG   Tag;
    ULONG   EstimatedRuntime;
} BATTERY_WMI_RUNTIME;
typedef BATTERY_WMI_RUNTIME *PBATTERY_WMI_RUNTIME;
#endif

/* Battery WMI temperature */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_TEMPERATURE {
    ULONG   Tag;
    ULONG   Temperature;
} BATTERY_WMI_TEMPERATURE;
typedef BATTERY_WMI_TEMPERATURE *PBATTERY_WMI_TEMPERATURE;
#endif

/* Battery WMI full charged capacity */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_FULL_CHARGED_CAPACITY {
    ULONG   Tag;
    ULONG   FullChargedCapacity;
} BATTERY_WMI_FULL_CHARGED_CAPACITY;
typedef BATTERY_WMI_FULL_CHARGED_CAPACITY   *PBATTERY_WMI_FULL_CHARGED_CAPACITY;
#endif

/* Battery WMI cycle count */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_CYCLE_COUNT {
    ULONG   Tag;
    ULONG   CycleCount;
} BATTERY_WMI_CYCLE_COUNT;
typedef BATTERY_WMI_CYCLE_COUNT *PBATTERY_WMI_CYCLE_COUNT;
#endif

/* Battery WMI static data */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_STATIC_DATA {
    ULONG                   Tag;
    WCHAR                   ManufactureDate[25];
    BATTERY_REPORTING_SCALE Granularity[4];
    ULONG                   Capabilities;
    UCHAR                   Technology;
    ULONG                   Chemistry;
    ULONG                   DesignedCapacity;
    ULONG                   DefaultAlert1;
    ULONG                   DefaultAlert2;
    ULONG                   CriticalBias;
    WCHAR                   Strings[1];
} BATTERY_WMI_STATIC_DATA;
typedef BATTERY_WMI_STATIC_DATA *PBATTERY_WMI_STATIC_DATA;
#endif

/* Battery WMI status change */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_WMI_STATUS_CHANGE {
    ULONG   Tag;
    BOOLEAN PowerOnline;
    BOOLEAN Charging;
    BOOLEAN Discharging;
    BOOLEAN Critical;
} BATTERY_WMI_STATUS_CHANGE;
typedef BATTERY_WMI_STATUS_CHANGE   *PBATTERY_WMI_STATUS_CHANGE;
#endif

/* Battery tag change */
#if (NTDDI_VERSION >= 0x05010000) && !defined( _WINDOWS_ )
typedef struct _BATTERY_TAG_CHANGE {
    ULONG   Tag;
} BATTERY_TAG_CHANGE;
typedef BATTERY_TAG_CHANGE  *PBATTERY_TAG_CHANGE;
#endif

/* Functions in BATTC.SYS */
#ifndef _WINDOWS_
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassInitializeDevice( PBATTERY_MINIPORT_INFO, PVOID * );
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassIoctl( PVOID, PIRP );
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassStatusNotify( PVOID );
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassUnload( PVOID );
#if (NTDDI_VERSION >= 0x05010000)
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassQueryWmiDataBlock( PVOID, PDEVICE_OBJECT, PIRP, ULONG, PULONG, ULONG, PUCHAR );
BATTERYCLASSAPI NTSTATUS NTAPI  BatteryClassSystemControl( PVOID, PVOID, PDEVICE_OBJECT, PIRP, PVOID );
#endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _BATCLASS_ */
