/*
 *  ntpoapi.h   NT power functions
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

#ifndef _NTPOAPI_
#define _NTPOAPI_

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Power performance scale */
#define POWER_PERF_SCALE    100

/* Macros to convert between performance levels and percentages */
#define PERF_LEVEL_TO_PERCENT( x )  (((x) * 1000) / (POWER_PERF_SCALE * 10))
#define PERCENT_TO_PERF_LEVEL( x )  (((x) * POWER_PERF_SCALE * 10) / 1000)

/* Maximum power state handler type */
#define POWER_STATE_HANDLER_TYPE_MAX    8

/* Idle handler flags */
#define IDLE_HANDLER_USING_HYPERVISOR   0x00000001L

/* Idle state flags */
#define IDLE_STATE_FLAGS_C1_HLT     0x00000001L
#define IDLE_STATE_FLAGS_C1_IO_HLT  0x00000002L
#define IDLE_STATE_FLAGS_IO         0x00000004L
#define IDLE_STATE_FLAGS_MWAIT      0x00000008L

/* Processor state types */
#define PROCESSOR_STATE_TYPE_PERFORMANCE    0x01
#define PROCESSOR_STATE_TYPE_THROTTLE       0x02

/* Number of idle buckets */
#define PROC_IDLE_BUCKET_COUNT      6
#define PROC_IDLE_BUCKET_COUNT_EX   16

/* Coordination types */
#define ACPI_PPM_SOFTWARE_ALL   0xFC
#define ACPI_PPM_SOFTWARE_ANY   0xFD
#define ACPI_PPM_HARDWARE_ALL   0xFE
#define MS_PPM_SOFTWARE_ALL     0x01

/* Power action policy flags */
#define POWER_ACTION_QUERY_ALLOWED      0x00000001L
#define POWER_ACTION_UI_ALLOWED         0x00000002L
#define POWER_ACTION_OVERRIDE_APPS      0x00000004L
#define POWER_ACTION_PSEUDO_TRANSITION  0x08000000L
#define POWER_ACTION_LIGHTEST_FIRST     0x10000000L
#define POWER_ACTION_LOCK_CONSOLE       0x20000000L
#define POWER_ACTION_DISABLE_WAKES      0x40000000L
#define POWER_ACTION_CRITICAL           0x80000000L

/* Power action policy event code flags */
#define POWER_LEVEL_USER_NOTIFY_TEXT        0x00000001L
#define POWER_LEVEL_USER_NOTIFY_SOUND       0x00000002L
#define POWER_LEVEL_USER_NOTIFY_EXEC        0x00000004L
#define POWER_USER_NOTIFY_BUTTON            0x00000008L
#define POWER_USER_NOTIFY_SHUTDOWN          0x00000010L
#define POWER_USER_NOTIFY_FORCED_SHUTDOWN   0x00000020L
#define POWER_FORCE_TRIGGER_RESET           0x80000000L

/* Battery discharge flags */
#define BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK  0x00000007
#define BATTERY_DISCHARGE_FLAGS_ENABLE          0x80000000

/* Maximum number of discharge policies */
#define NUM_DISCHARGE_POLICIES  4

/* Discharge policy indices */
#define DISCHARGE_POLICY_CRITICAL   0
#define DISCHARGE_POLICY_LOW        1

/* Maximum number of processor idle state policies */
#define PROCESSOR_IDLESTATE_POLICY_COUNT    3

/* Throttling policies */
#define PO_THROTTLE_NONE        0
#define PO_THROTTLE_CONSTANT    1
#define PO_THROTTLE_DEGRADE     2
#define PO_THROTTLE_ADAPTIVE    3
#define PO_THROTTLE_MAXIMUM     4

/* Processor performance state policy flags */
#define PERFSTATE_POLICY_CHANGE_IDEAL   0
#define PERFSTATE_POLICY_CHANGE_SINGLE  1
#define PERFSTATE_POLICY_CHANGE_ROCKET  2
#define PERFSTATE_POLICY_CHANGE_MAX     PERFSTATE_POLICY_CHANGE_ROCKET

/* Winlogon flags */
#define WINLOGON_LOCK_ON_SLEEP  0x00000001L

/* Power reason codes */
#define SPSD_REASON_NONE                    0x00000000L
#define SPSD_REASON_NOBIOSSUPPORT           0x00000001L
#define SPSD_REASON_BIOSINCOMPATIBLE        0x00000002L
#define SPSD_REASON_NOOSPM                  0x00000003L
#define SPSD_REASON_LEGACYDRIVER            0x00000004L
#define SPSD_REASON_HIBERSTACK              0x00000005L
#define SPSD_REASON_HIBERFILE               0x00000006L
#define SPSD_REASON_POINTERNAL              0x00000007L
#define SPSD_REASON_MEMORYLIMIT             0x00000008L
#define SPSD_REASON_MPOVERRIDE              0x00000009L
#define SPSD_REASON_DRIVERDOWNGRADE         0x0000000AL
#define SPSD_REASON_PREVIOUSATTEMPTFAILED   0x0000000BL
#define SPSD_REASON_UNKNOWN                 0x0000000CL
#define SPSD_REASON_INTERNALLYDISABLED      0x0000000DL
#define SPSD_REASON_DISABLEDBYPOLICY        0x0000000EL
#define SPSD_REASON_UPGRADEINPROGRESS       0x0000000FL

/* Logging types */
#define LOGGING_TYPE_SPSD               0x00000001L
#define LOGGING_TYPE_POWERTRANSITION    0x00000002L

/* Power state handler types */
typedef enum {
    PowerStateSleeping1         = 0,
    PowerStateSleeping2         = 1,
    PowerStateSleeping3         = 2,
    PowerStateSleeping4         = 3,
    PowerStateShutdownOff       = 4,
    PowerStateShutdownReset     = 5,
    PowerStateSleeping4Firmware = 6,
    PowerStateMaximum           = 7
} POWER_STATE_HANDLER_TYPE;
typedef POWER_STATE_HANDLER_TYPE    *PPOWER_STATE_HANDLER_TYPE;

/* Enter state handlers */
typedef NTSTATUS (NTAPI ENTER_STATE_SYSTEM_HANDLER)( PVOID );
typedef ENTER_STATE_SYSTEM_HANDLER  *PENTER_STATE_SYSTEM_HANDLER;
typedef NTSTATUS (NTAPI ENTER_STATE_HANDLER)( PVOID, PENTER_STATE_SYSTEM_HANDLER, PVOID, LONG, LONG volatile * );
typedef ENTER_STATE_HANDLER         *PENTER_STATE_HANDLER;
#if (NTDDI_VERSION >= 0x05010000)
typedef NTSTATUS (NTAPI ENTER_STATE_NOTIFY_HANDLER)( POWER_STATE_HANDLER_TYPE, PVOID, BOOLEAN );
typedef ENTER_STATE_NOTIFY_HANDLER  *PENTER_STATE_NOTIFY_HANDLER;
#endif

/* Power state handler */
typedef struct {
    POWER_STATE_HANDLER_TYPE    Type;
    BOOLEAN                     RtcWake;
    UCHAR                       Spare[3];
    PENTER_STATE_HANDLER        Handler;
    PVOID                       Context;
} POWER_STATE_HANDLER;
typedef POWER_STATE_HANDLER *PPOWER_STATE_HANDLER;

/* Power state notify handler */
#if (NTDDI_VERSION >= 0x05010000)
typedef struct {
    PENTER_STATE_NOTIFY_HANDLER Handler;
    PVOID                       Context;
} POWER_STATE_NOTIFY_HANDLER;
typedef POWER_STATE_NOTIFY_HANDLER  *PPOWER_STATE_NOTIFY_HANDLER;
#endif

/* Processor idle times */
typedef struct {
    ULONG64 StartTime;
    ULONG64 EndTime;
    ULONG   Reserved[4];
} PROCESSOR_IDLE_TIMES;
typedef PROCESSOR_IDLE_TIMES    *PPROCESSOR_IDLE_TIMES;

/* Processor idle handler */
typedef NTSTATUS (FASTCALL PROCESSOR_IDLE_HANDLER)( ULONG_PTR, PPROCESSOR_IDLE_TIMES );
typedef NTSTATUS (FASTCALL *PPROCESSOR_IDLE_HANDLER_EX)( PVOID, ULONG );
typedef PROCESSOR_IDLE_HANDLER  *PPROCESSOR_IDLE_HANDLER;

/* Processor idle state */
typedef struct _PROCESSOR_IDLE_STATE {
    UCHAR                   StateType;
    ULONG                   StateFlags;
    ULONG                   HardwareLatency;
    ULONG                   Power;
    ULONG_PTR               Context;
    PPROCESSOR_IDLE_HANDLER Handler;
} PROCESSOR_IDLE_STATE;
typedef PROCESSOR_IDLE_STATE    *PPROCESSOR_IDLE_STATE;

/* Processor idle state (extended version) */
typedef struct _PROCESSOR_IDLE_STATE_EX {
    UCHAR                       StateType;
    ULONG                       StateFlags;
    ULONG                       HardwareLatency;
    ULONG                       Power;
    PVOID                       Context;
    PPROCESSOR_IDLE_HANDLER_EX  Handler;
} PROCESSOR_IDLE_STATE_EX;
typedef PROCESSOR_IDLE_STATE_EX *PPROCESSOR_IDLE_STATE_EX;

/* Processor idle states */
typedef struct _PROCESSOR_IDLE_STATES {
    ULONG                   Size;
    ULONG                   Revision;
    ULONG                   Count;
    ULONG                   Type;
    KAFFINITY               TargetProcessors;
    PROCESSOR_IDLE_STATE    State[ANYSIZE_ARRAY];
} PROCESSOR_IDLE_STATES;
typedef PROCESSOR_IDLE_STATES   *PPROCESSOR_IDLE_STATES;

/* Processor idle states (extended version) */
typedef struct _PROCESSOR_IDLE_STATES_EX {
    ULONG                   Size;
    ULONG                   Revision;
    ULONG                   Count;
    ULONG                   Type;
    KAFFINITY               TargetProcessors;
    PROCESSOR_IDLE_STATE_EX State[ANYSIZE_ARRAY];
} PROCESSOR_IDLE_STATES_EX;
typedef PROCESSOR_IDLE_STATES_EX    *PPROCESSOR_IDLE_STATES_EX;

/* WMI legacy performance state */
typedef struct {
    ULONG   Frequency;
    ULONG   Flags;
    ULONG   PercentFrequency;
} PPM_WMI_LEGACY_PERFSTATE;
typedef PPM_WMI_LEGACY_PERFSTATE    *PPPM_WMI_LEGACY_PERFSTATE;

/* WMI idle state */
typedef struct {
    ULONG   Latency;
    ULONG   Power;
    ULONG   TimeCheck;
    UCHAR   PromotePercent;
    UCHAR   DemotePercent;
    UCHAR   StateType;
    UCHAR   Reserved;
    ULONG   StateFlags;
    ULONG   Context;
    ULONG   IdleHandler;
    ULONG   Reserved1;
} PPM_WMI_IDLE_STATE;
typedef PPM_WMI_IDLE_STATE  *PPPM_WMI_IDLE_STATE;

/* WMI idle state array */
typedef struct {
    ULONG               Type;
    ULONG               Count;
    ULONG               TargetState;
    ULONG               OldState;
    ULONG64             TargetProcessors;
    PPM_WMI_IDLE_STATE  State[ANYSIZE_ARRAY];
} PPM_WMI_IDLE_STATES;
typedef PPM_WMI_IDLE_STATES *PPPM_WMI_IDLE_STATES;

/* WMI idle state array (extended version) */
typedef struct {
    ULONG               Type;
    ULONG               Count;
    ULONG               TargetState;
    ULONG               OldState;
    PVOID               TargetProcessors;
    PPM_WMI_IDLE_STATE  State[ANYSIZE_ARRAY];
} PPM_WMI_IDLE_STATES_EX;
typedef PPM_WMI_IDLE_STATES_EX  *PPPM_WMI_IDLE_STATES_EX;

/* WMI performance state */
typedef struct {
    ULONG   Frequency;
    ULONG   Power;
    UCHAR   PercentFrequency;
    UCHAR   IncreaseLevel;
    UCHAR   DecreaseLevel;
    UCHAR   Type;
    ULONG   IncreaseTime;
    ULONG   DecreaseTime;
    ULONG64 Control;
    ULONG64 Status;
    ULONG   HitCount;
    ULONG   Reserved1;
    ULONG64 Reserved2;
    ULONG64 Reserved3;
} PPM_WMI_PERF_STATE;
typedef PPM_WMI_PERF_STATE  *PPPM_WMI_PERF_STATE;

/* WMI performance state array */
typedef struct {
    ULONG               Count;
    ULONG               MaxFrequency;
    ULONG               CurrentState;
    ULONG               MaxPerfState;
    ULONG               MinPerfState;
    ULONG               LowestPerfState;
    ULONG               ThermalConstraint;
    UCHAR               BusyAdjThreshold;
    UCHAR               PolicyType;
    UCHAR               Type;
    UCHAR               Reserved;
    ULONG               TimerInterval;
    ULONG64             TargetProcessors;
    ULONG               PStateHandler;
    ULONG               PStateContext;
    ULONG               TStateHandler;
    ULONG               TStateContext;
    ULONG               FeedbackHandler;
    ULONG               Reserved1;
    ULONG64             Reserved2;
    PPM_WMI_PERF_STATE  State[ANYSIZE_ARRAY];
} PPM_WMI_PERF_STATES;
typedef PPM_WMI_PERF_STATES *PPPM_WMI_PERF_STATES;

/* WMI performance state array (extended version) */
typedef struct {
    ULONG               Count;
    ULONG               MaxFrequency;
    ULONG               CurrentState;
    ULONG               MaxPerfState;
    ULONG               MinPerfState;
    ULONG               LowestPerfState;
    ULONG               ThermalConstraint;
    UCHAR               BusyAdjThreshold;
    UCHAR               PolicyType;
    UCHAR               Type;
    UCHAR               Reserved;
    ULONG               TimerInterval;
    PVOID               TargetProcessors;
    ULONG               PStateHandler;
    ULONG               PStateContext;
    ULONG               TStateHandler;
    ULONG               TStateContext;
    ULONG               FeedbackHandler;
    ULONG               Reserved1;
    ULONG64             Reserved2;
    PPM_WMI_PERF_STATE  State[ANYSIZE_ARRAY];
} PPM_WMI_PERF_STATES_EX;
typedef PPM_WMI_PERF_STATES_EX  *PPPM_WMI_PERF_STATES_EX;

/* Idle state accounting information */
typedef struct {
    ULONG   IdleTransitions;
    ULONG   FailedTransitions;
    ULONG   InvalidBucketIndex;
    ULONG64 TotalTime;
    ULONG   IdleTimeBuckets[PROC_IDLE_BUCKET_COUNT];
} PPM_IDLE_STATE_ACCOUNTING;
typedef PPM_IDLE_STATE_ACCOUNTING   *PPPM_IDLE_STATE_ACCOUNTING;

/* Idle accounting information */
typedef struct {
    ULONG                       StateCount;
    ULONG                       TotalTransitions;
    ULONG                       ResetCount;
    ULONG64                     StartTime;
    PPM_IDLE_STATE_ACCOUNTING   State[ANYSIZE_ARRAY];
} PPM_IDLE_ACCOUNTING;
typedef PPM_IDLE_ACCOUNTING *PPPM_IDLE_ACCOUNTING;

/* Idle state bucket (extended version) */
typedef struct {
    ULONG64 TotalTimeUs;
    ULONG   MinTimeUs;
    ULONG   MaxTimeUs;
    ULONG   Count;
} PPM_IDLE_STATE_BUCKET_EX;
typedef PPM_IDLE_STATE_BUCKET_EX    *PPPM_IDLE_STATE_BUCKET_EX;

/* Idle state accounting information (extended version) */
typedef struct {
    ULONG64                     TotalTime;
    ULONG                       IdleTransitions;
    ULONG                       FailedTransitions;
    ULONG                       InvalidBucketIndex;
    ULONG                       MinTimeUs;
    ULONG                       MaxTimeUs;
    PPM_IDLE_STATE_BUCKET_EX    IdleTimeBuckets[PROC_IDLE_BUCKET_COUNT_EX];
} PPM_IDLE_STATE_ACCOUNTING_EX;
typedef PPM_IDLE_STATE_ACCOUNTING_EX    *PPPM_IDLE_STATE_ACCOUNTING_EX;

/* Idle accounting information (extended version) */
typedef struct {
    ULONG                           StateCount;
    ULONG                           TotalTransitions;
    ULONG                           ResetCount;
    ULONG64                         StartTime;
    PPM_IDLE_STATE_ACCOUNTING_EX    State[ANYSIZE_ARRAY];
} PPM_IDLE_ACCOUNTING_EX;
typedef PPM_IDLE_ACCOUNTING_EX  *PPPM_IDLE_ACCOUNTING_EX;

/* Performance state event */
typedef struct {
    ULONG   State;
    ULONG   Status;
    ULONG   Latency;
    ULONG   Speed;
    ULONG   Processor;
} PPM_PERFSTATE_EVENT;
typedef PPM_PERFSTATE_EVENT *PPPM_PERFSTATE_EVENT;

/* Performance state domain event */
typedef struct {
    ULONG   State;
    ULONG   Latency;
    ULONG   Speed;
    ULONG64 Processors;
} PPM_PERFSTATE_DOMAIN_EVENT;
typedef PPM_PERFSTATE_DOMAIN_EVENT  *PPPM_PERFSTATE_DOMAIN_EVENT;

/* Idle state event */
typedef struct {
    ULONG   NewState;
    ULONG   OldState;
    ULONG64 Processors;
} PPM_IDLESTATE_EVENT;
typedef PPM_IDLESTATE_EVENT *PPPM_IDLESTATE_EVENT;

/* Thermal change event */
typedef struct {
    ULONG   ThermalConstraint;
    ULONG64 Processors;
} PPM_THERMALCHANGE_EVENT;
typedef PPM_THERMALCHANGE_EVENT *PPPM_THERMALCHANGE_EVENT;

/* Thermal policy event */
typedef struct {
    UCHAR   Mode;
    ULONG64 Processors;
} PPM_THERMAL_POLICY_EVENT;
typedef PPM_THERMAL_POLICY_EVENT    *PPPM_THERMAL_POLICY_EVENT;

/* Power action policy */
typedef struct {
    POWER_ACTION    Action;
    ULONG           Flags;
    ULONG           EventCode;
} POWER_ACTION_POLICY;
typedef POWER_ACTION_POLICY *PPOWER_ACTION_POLICY;

/* System power level */
typedef struct {
    BOOLEAN             Enable;
    UCHAR               Spare[3];
    ULONG               BatteryLevel;
    POWER_ACTION_POLICY PowerPolicy;
    SYSTEM_POWER_STATE  MinSystemState;
} SYSTEM_POWER_LEVEL;
typedef SYSTEM_POWER_LEVEL  *PSYSTEM_POWER_LEVEL;

/* System power policy */
typedef struct _SYSTEM_POWER_POLICY {
    ULONG               Revision;
    POWER_ACTION_POLICY PowerButton;
    POWER_ACTION_POLICY SleepButton;
    POWER_ACTION_POLICY LidClose;
    SYSTEM_POWER_STATE  LidOpenWake;
    ULONG               Reserved;
    POWER_ACTION_POLICY Idle;
    ULONG               IdleTimeout;
    UCHAR               IdleSensitivity;
    UCHAR               DynamicThrottle;
    UCHAR               Spare2[2];
    SYSTEM_POWER_STATE  MinSleep;
    SYSTEM_POWER_STATE  MaxSleep;
    SYSTEM_POWER_STATE  ReducedLatencySleep;
    ULONG               WinLogonFlags;
    ULONG               Spare3;
    ULONG               DozeS4Timeout;
    ULONG               BroadcastCapacityResolution;
    SYSTEM_POWER_LEVEL  DischargePolicy[NUM_DISCHARGE_POLICIES];
    ULONG               VideoTimeout;
    BOOLEAN             VideoDimDisplay;
    ULONG               VideoReserved[3];
    ULONG               SpindownTimeout;
    BOOLEAN             OptimizeForPower;
    UCHAR               FanThrottleTolerance;
    UCHAR               ForcedThrottle;
    UCHAR               MinThrottle;
    POWER_ACTION_POLICY OverThrottled;
} SYSTEM_POWER_POLICY;
typedef SYSTEM_POWER_POLICY *PSYSTEM_POWER_POLICY;

/* Processor idle state information */
typedef struct {
    ULONG   TimeCheck;
    UCHAR   DemotePercent;
    UCHAR   PromotePercent;
    UCHAR   Spare[2];
} PROCESSOR_IDLESTATE_INFO;
typedef PROCESSOR_IDLESTATE_INFO    *PPROCESSOR_IDLESTATE_INFO;

/* Processor idle state policy */
typedef struct {
    USHORT                      Revision;
    union {
        USHORT  AsUSHORT;
        struct {
            USHORT  AllowScaling    : 1;
            USHORT  Disabled        : 1;
            USHORT  Reserved        : 14;
        };
    } Flags;
    ULONG                       PolicyCount;
    PROCESSOR_IDLESTATE_INFO    Policy[PROCESSOR_IDLESTATE_POLICY_COUNT];
} PROCESSOR_IDLESTATE_POLICY;
typedef PROCESSOR_IDLESTATE_POLICY  *PPROCESSOR_IDLESTATE_POLICY;

/* Processor power policy information */
typedef struct _PROCESSOR_POWER_POLICY_INFO {
    ULONG   TimeCheck;
    ULONG   DemoteLimit;
    ULONG   PromoteLimit;
    UCHAR   DemotePercent;
    UCHAR   PromotePercent;
    UCHAR   Spare[2];
    ULONG   AllowDemotion   : 1;
    ULONG   AllowPromotion  : 1;
    ULONG   Reserved        : 30;
} PROCESSOR_POWER_POLICY_INFO;
typedef PROCESSOR_POWER_POLICY_INFO *PPROCESSOR_POWER_POLICY_INFO;

/* Processor power policy */
typedef struct _PROCESSOR_POWER_POLICY {
    ULONG                       Revision;
    UCHAR                       DynamicThrottle;
    UCHAR                       Spare[3];
    ULONG                       DisableCStates  : 1;
    ULONG                       Reserved        : 31;
    ULONG                       PolicyCount;
    PROCESSOR_POWER_POLICY_INFO Policy[3];
} PROCESSOR_POWER_POLICY;
typedef PROCESSOR_POWER_POLICY  *PPROCESSOR_POWER_POLICY;

/* Processor performance state policy */
typedef struct {
    ULONG   Revision;
    UCHAR   MaxThrottle;
    UCHAR   MinThrottle;
    UCHAR   BusyAdjThreshold;
    union {
        UCHAR   Spare;
        union {
            UCHAR   AsUCHAR;
            struct {
                UCHAR   NoDomainAccounting  : 1;
                UCHAR   IncreasePolicy      : 2;
                UCHAR   DecreasePolicy      : 2;
                UCHAR   Reserved            : 3;
            } DUMMYSTRUCTNAME;
        } Flags;
    } DUMMYUNIONNAME;
    ULONG   TimeCheck;
    ULONG   IncreaseTime;
    ULONG   DecreaseTime;
    ULONG   IncreasePercent;
    ULONG   DecreasePercent;
} PROCESSOR_PERFSTATE_POLICY;
typedef PROCESSOR_PERFSTATE_POLICY  *PPROCESSOR_PERFSTATE_POLICY;

/* Administrator power policy */
typedef struct _ADMINISTRATOR_POWER_POLICY {
    SYSTEM_POWER_STATE  MinSleep;
    SYSTEM_POWER_STATE  MaxSleep;
    ULONG               MinVideoTimeout;
    ULONG               MaxVideoTimeout;
    ULONG               MinSpindownTimeout;
    ULONG               MaxSpindownTimeout;
} ADMINISTRATOR_POWER_POLICY;
typedef ADMINISTRATOR_POWER_POLICY  *PADMINISTRATOR_POWER_POLICY;

/* System power capabilities */
typedef struct {
    BOOLEAN                 PowerButtonPresent;
    BOOLEAN                 SleepButtonPresent;
    BOOLEAN                 LidPresent;
    BOOLEAN                 SystemS1;
    BOOLEAN                 SystemS2;
    BOOLEAN                 SystemS3;
    BOOLEAN                 SystemS4;
    BOOLEAN                 SystemS5;
    BOOLEAN                 HiberFilePresent;
    BOOLEAN                 FullWake;
    BOOLEAN                 VideoDimPresent;
    BOOLEAN                 ApmPresent;
    BOOLEAN                 UpsPresent;
    BOOLEAN                 ThermalControl;
    BOOLEAN                 ProcessorThrottle;
    UCHAR                   ProcessorMinThrottle;
#if (NTDDI_VERSION >= 0x05010000)
    UCHAR                   ProcessorMaxThrottle;
    BOOLEAN                 FastSystemS4;
    UCHAR                   spare2[3];
#else
    UCHAR                   ProcessorThrottleScale;
    UCHAR                   spare2[4];
#endif
    BOOLEAN                 DiskSpinDown;
    UCHAR                   spare3[8];
    BOOLEAN                 SystemBatteriesPresent;
    BOOLEAN                 BatteriesAreShortTerm;
    BATTERY_REPORTING_SCALE BatteryScale[3];
    SYSTEM_POWER_STATE      AcOnLineWake;
    SYSTEM_POWER_STATE      SoftLidWake;
    SYSTEM_POWER_STATE      RtcWake;
    SYSTEM_POWER_STATE      MinDeviceWakeState;
    SYSTEM_POWER_STATE      DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES;
typedef SYSTEM_POWER_CAPABILITIES   *PSYSTEM_POWER_CAPABILITIES;

/* System battery state */
typedef struct {
    BOOLEAN AcOnLine;
    BOOLEAN BatteryPresent;
    BOOLEAN Charging;
    BOOLEAN Discharging;
    BOOLEAN Spare1[4];
    ULONG   MaxCapacity;
    ULONG   RemainingCapacity;
    ULONG   Rate;
    ULONG   EstimatedTime;
    ULONG   DefaultAlert1;
    ULONG   DefaultAlert2;
} SYSTEM_BATTERY_STATE;
typedef SYSTEM_BATTERY_STATE    *PSYSTEM_BATTERY_STATE;

/* System power state disable reason */
typedef struct _SYSTEM_POWER_STATE_DISABLE_REASON {
    BOOLEAN AffectedState[POWER_STATE_HANDLER_TYPE_MAX];
    ULONG   PowerReasonCode;
    ULONG   PowerReasonLength;
} SYSTEM_POWER_STATE_DISABLE_REASON;
typedef SYSTEM_POWER_STATE_DISABLE_REASON   *PSYSTEM_POWER_STATE_DISABLE_REASON;

/* System power logging entry */
typedef struct _SYSTEM_POWER_LOGGING_ENTRY {
    ULONG   LoggingType;
    PVOID   LoggingEntry;
} SYSTEM_POWER_LOGGING_ENTRY;
typedef SYSTEM_POWER_LOGGING_ENTRY  *PSYSTEM_POWER_LOGGING_ENTRY;

/* Processor idle function */
#if (NTDDI_VERSION < 0x05010000)
typedef VOID (FASTCALL PROCESSOR_IDLE_FUNCTION)( struct _PROCESSOR_POWER_STATE * );
typedef PROCESSOR_IDLE_FUNCTION *PPROCESSOR_IDLE_FUNCTION;
#endif

/* Processor power state */
#if (NTDDI_VERSION < 0x05010000)
typedef struct _PROCESSOR_POWER_STATE {
    PPROCESSOR_IDLE_FUNCTION    IdleFunction;
    ULONG                       Idle0KernelTimeLimit;
    ULONG                       Idle0LastTime;
    PVOID                       IdleState;
    ULONGLONG                   LastCheck;
    PROCESSOR_IDLE_TIMES        IdleTimes;
    ULONG                       IdleTime1;
    ULONG                       PromotionCheck;
    ULONG                       IdleTime2;
    UCHAR                       CurrentThrottle;
    UCHAR                       ThrottleLimit;
    UCHAR                       Spare1[2];
    ULONG                       SetMember;
    PVOID                       AbortThrottle;
    ULONGLONG                   DebugDelta;
    ULONG                       DebugCount;
    ULONG                       LastSysTime;
    ULONG                       Spare2[10];
} PROCESSOR_POWER_STATE;
typedef PROCESSOR_POWER_STATE   *PPROCESSOR_POWER_STATE;
#endif

/* Processor power information */
typedef struct _PROCESSOR_POWER_INFORMATION {
    ULONG   Number;
    ULONG   MaxMhz;
    ULONG   CurrentMhz;
    ULONG   MhzLimit;
    ULONG   MaxIdleState;
    ULONG   CurrentIdleState;
} PROCESSOR_POWER_INFORMATION;
typedef PROCESSOR_POWER_INFORMATION *PPROCESSOR_POWER_INFORMATION;

/* System power information */
typedef struct _SYSTEM_POWER_INFORMATION {
    ULONG   MaxIdlenessAllowed;
    ULONG   Idleness;
    ULONG   TimeRemaining;
    UCHAR   CoolingMode;
} SYSTEM_POWER_INFORMATION;
typedef SYSTEM_POWER_INFORMATION    *PSYSTEM_POWER_INFORMATION;

/* System hibernation file information */
typedef struct _SYSTEM_HIBERFILE_INFORMATION {
    ULONG           NumberOfMcbPairs;
    LARGE_INTEGER   Mcb[1];
} SYSTEM_HIBERFILE_INFORMATION;
typedef SYSTEM_HIBERFILE_INFORMATION    *PSYSTEM_HIBERFILE_INFORMATION;

/* Requester types */
#if (NTDDI_VERSION >= 0x06010000)
typedef enum _REQUESTER_TYPE {
    KernelRequester             = 0,
    UserProcessRequester        = 1,
    UserSharedServiceRequester  = 2
} REQUESTER_TYPE;
typedef REQUESTER_TYPE  *PREQUESTER_TYPE;
#endif

/* Reason buffer */
#if (NTDDI_VERSION >= 0x06010000)
typedef struct _REASON_BUFFER {
    ULONG   Flags;
    union {
        struct {
            SIZE_T  ResourceFileNameOffset;
            USHORT  ResourceReasonId;
            ULONG   StringCount;
            SIZE_T  SubstitutionStringsOffset;
        };
        SIZE_T  SimpleStringOffset;
    };
} REASON_BUFFER;
typedef REASON_BUFFER   *PREASON_BUFFER;
#endif

/* Diagnostic buffer */
#if (NTDDI_VERSION >= 0x06010000)
typedef struct _DIAGNOSTIC_BUFFER {
    SIZE_T          Size;
    REQUESTER_TYPE  CallerType;
    union {
        struct {
            SIZE_T  ProcessImageNameOffset;
            ULONG   ProcessId;
            ULONG   ServiceTag;
        };
        struct {
            SIZE_T  DeviceDescriptionOffset;
            SIZE_T  DevicePathOffset;
        };
    };
    SIZE_T          ReasonOffset;
} DIAGNOSTIC_BUFFER;
typedef DIAGNOSTIC_BUFFER   *PDIAGNOSTIC_BUFFER;
#endif

/* Wake timer information */
#if (NTDDI_VERSION >= 0x06010000)
typedef struct _WAKE_TIMER_INFO {
    SIZE_T              OffsetToNext;
    ULARGE_INTEGER      DueTime;
    ULONG               Period;
    DIAGNOSTIC_BUFFER   ReasonContext;
} WAKE_TIMER_INFO;
typedef WAKE_TIMER_INFO *PWAKE_TIMER_INFO;
#endif

/* Power wake source types */
typedef enum {
    DeviceWakeSourceType    = 0,
    FixedWakeSourceType     = 1,
    TimerWakeSourceType     = 2
} PO_WAKE_SOURCE_TYPE;
typedef PO_WAKE_SOURCE_TYPE *PPO_WAKE_SOURCE_TYPE;

/* Power fixed wake source types */
typedef enum {
    FixedWakeSourcePowerButton      = 0,
    FixedWakeSourceSleepButton      = 1,
    FixedWakeSourceRtc              = 2,
    FixedWakeSourceDozeToHibernate  = 3
} PO_FIXED_WAKE_SOURCE_TYPE;
typedef PO_FIXED_WAKE_SOURCE_TYPE   *PPO_FIXED_WAKE_SOURCE_TYPE;

/* Power wake source handler */
typedef struct _PO_WAKE_SOURCE_HEADER {
    PO_WAKE_SOURCE_TYPE Type;
    ULONG               Size;
} PO_WAKE_SOURCE_HEADER;
typedef PO_WAKE_SOURCE_HEADER   *PPO_WAKE_SOURCE_HEADER;

/* Power wake source device */
typedef struct _PO_WAKE_SOURCE_DEVICE {
    PO_WAKE_SOURCE_HEADER   Header;
    WCHAR                   InstancePath[ANYSIZE_ARRAY];
} PO_WAKE_SOURCE_DEVICE;
typedef PO_WAKE_SOURCE_DEVICE   *PPO_WAKE_SOURCE_DEVICE;

/* Power wake source fixed */
typedef struct _PO_WAKE_SOURCE_FIXED {
    PO_WAKE_SOURCE_HEADER       Header;
    PO_FIXED_WAKE_SOURCE_TYPE   FixedWakeSourceType;
} PO_WAKE_SOURCE_FIXED;
typedef PO_WAKE_SOURCE_FIXED    *PPO_WAKE_SOURCE_FIXED;

/* Power wake source timer */
#if (NTDDI_VERSION >= 0x06010000)
typedef struct _PO_WAKE_SOURCE_TIMER {
    PO_WAKE_SOURCE_HEADER   Header;
    DIAGNOSTIC_BUFFER       Reason;
} PO_WAKE_SOURCE_TIMER;
typedef PO_WAKE_SOURCE_TIMER    *PPO_WAKE_SOURCE_TIMER;
#endif

/* Power wake source information */
typedef struct _PO_WAKE_SOURCE_INFO {
    ULONG   Count;
    ULONG   Offsets[ANYSIZE_ARRAY];
} PO_WAKE_SOURCE_INFO;
typedef PO_WAKE_SOURCE_INFO *PPO_WAKE_SOURCE_INFO;

/* Power wake source history */
typedef struct _PO_WAKE_SOURCE_HISTORY {
    ULONG   Count;
    ULONG   Offsets[ANYSIZE_ARRAY];
} PO_WAKE_SOURCE_HISTORY;
typedef PO_WAKE_SOURCE_HISTORY  *PPO_WAKE_SOURCE_HISTORY;

/* System call functions in NTDLL.DLL */
NTSYSCALLAPI NTSTATUS NTAPI NtGetDevicePowerState( HANDLE, DEVICE_POWER_STATE * );
NTSYSCALLAPI NTSTATUS NTAPI NtInitiatePowerAction( POWER_ACTION, SYSTEM_POWER_STATE, ULONG, BOOLEAN );
NTSYSCALLAPI NTSTATUS NTAPI NtIsSystemResumeAutomatic( VOID );
NTSYSCALLAPI NTSTATUS NTAPI NtPowerInformation( POWER_INFORMATION_LEVEL, PVOID, ULONG, PVOID, ULONG );
NTSYSCALLAPI NTSTATUS NTAPI NtSetSystemPowerState( POWER_ACTION, SYSTEM_POWER_STATE, ULONG );
NTSYSCALLAPI NTSTATUS NTAPI NtSetThreadExecutionState( EXECUTION_STATE, PEXECUTION_STATE );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _NTPOAPI_ */
