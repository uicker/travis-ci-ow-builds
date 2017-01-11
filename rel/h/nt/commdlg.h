/*
 *  commdlg.h   Common dialog functions
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

#ifndef _INC_COMMDLG
#define _INC_COMMDLG

#ifndef _ENABLE_AUTODEPEND
 #pragma read_only_file
#endif

#include <prsht.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Macro to specify common dialog functions */
#define WINCOMMDLGAPI   DECLSPEC_IMPORT

/* These macro is used by other macros to invoke SendMessage().  It is shared with
 * several other header files.
 */
#ifndef SNDMSG
    #ifdef __cplusplus
        #define SNDMSG  ::SendMessage
    #else
        #define SNDMSG  SendMessage
    #endif
#endif

/* The following macros make it possible to disable nameless unions in certain structures
 * by defining NONAMELESSUNION.  They are shared with several other header files.
 */
#ifndef DUMMYUNIONNAME
    #ifdef NONAMELESSUNION
        #define DUMMYUNIONNAME  u
        #define DUMMYUNIONNAME2 u2
        #define DUMMYUNIONNAME3 u3
        #define DUMMYUNIONNAME4 u4
        #define DUMMYUNIONNAME5 u5
    #else
        #define DUMMYUNIONNAME
        #define DUMMYUNIONNAME2
        #define DUMMYUNIONNAME3
        #define DUMMYUNIONNAME4
        #define DUMMYUNIONNAME5
    #endif
#endif

/* Macro to calculate structure sizes */
#define CDSIZEOF_STRUCT( x, p ) \
    (((int)((LPBYTE)(&((x *)0)->p) - ((LPBYTE)((x *)0)))) + sizeof( ((x *)0)->p ))

/* GetOpenFileName() flags */
#define OFN_READONLY                0x00000001L
#define OFN_OVERWRITEPROMPT         0x00000002L
#define OFN_HIDEREADONLY            0x00000004L
#define OFN_NOCHANGEDIR             0x00000008L
#define OFN_SHOWHELP                0x00000010L
#define OFN_ENABLEHOOK              0x00000020L
#define OFN_ENABLETEMPLATE          0x00000040L
#define OFN_ENABLETEMPLATEHANDLE    0x00000080L
#define OFN_NOVALIDATE              0x00000100L
#define OFN_ALLOWMULTISELECT        0x00000200L
#define OFN_EXTENSIONDIFFERENT      0x00000400L
#define OFN_PATHMUSTEXIST           0x00000800L
#define OFN_FILEMUSTEXIST           0x00001000L
#define OFN_CREATEPROMPT            0x00002000L
#define OFN_SHAREAWARE              0x00004000L
#define OFN_NOREADONLYRETURN        0x00008000L
#define OFN_NOTESTFILECREATE        0x00010000L
#define OFN_NONETWORKBUTTON         0x00020000L
#define OFN_NOLONGNAMES             0x00040000L
#if (WINVER >= 0x0400)
    #define OFN_EXPLORER            0x00080000L
    #define OFN_NODEREFERENCELINKS  0x00100000L
    #define OFN_LONGNAMES           0x00200000L
    #define OFN_ENABLEINCLUDENOTIFY 0x00400000L
    #define OFN_ENABLESIZING        0x00800000L
#endif
#if (_WIN32_WINNT >= 0x0500)
    #define OFN_DONTADDTORECENT     0x02000000L
    #define OFN_FORCESHOWHIDDEN     0x10000000L
#endif

/* GetOpenFileName() extended flags */
#if (_WIN32_WINNT >= 0x0500)
    #define OFN_EX_NOPLACESBAR  0x00000001L
#endif

/* GetOpenFileName() registered message return values */
#define OFN_SHAREFALLTHROUGH    2L
#define OFN_SHARENOWARN         1L
#define OFN_SHAREWARN           0L

/* Common dialog notifications */
#ifndef CDN_FIRST
    #define CDN_FIRST       (0U - 601U)
    #define CDN_LAST        (0U - 699U)
#endif
#define CDN_INITDONE        (CDN_FIRST - 0)
#define CDN_SELCHANGE       (CDN_FIRST - 1)
#define CDN_FOLDERCHANGE    (CDN_FIRST - 2)
#define CDN_SHAREVIOLATION  (CDN_FIRST - 3)
#define CDN_HELP            (CDN_FIRST - 4)
#define CDN_FILEOK          (CDN_FIRST - 5)
#define CDN_TYPECHANGE      (CDN_FIRST - 6)
#if (NTDDI_VERSION >= 0x05000000)
    #define CDN_INCLUDEITEM (CDN_FIRST - 7)
#endif

/* Common dialog messages */
#define CDM_FIRST           (WM_USER + 100)
#define CDM_LAST            (WM_USER + 200)
#define CDM_GETSPEC         (CDM_FIRST + 0)
#define CDM_GETFILEPATH     (CDM_FIRST + 1)
#define CDM_GETFOLDERPATH   (CDM_FIRST + 2)
#define CDM_GETFOLDERIDLIST (CDM_FIRST + 3)
#define CDM_SETCONTROLTEXT  (CDM_FIRST + 4)
#define CDM_HIDECONTROL     (CDM_FIRST + 5)
#define CDM_SETDEFEXT       (CDM_FIRST + 6)

/* ChooseColor() flags */
#define CC_RGBINIT              0x00000001L
#define CC_FULLOPEN             0x00000002L
#define CC_PREVENTFULLOPEN      0x00000004L
#define CC_SHOWHELP             0x00000008L
#define CC_ENABLEHOOK           0x00000010L
#define CC_ENABLETEMPLATE       0x00000020L
#define CC_ENABLETEMPLATEHANDLE 0x00000040L
#if (WINVER >= 0x0400)
    #define CC_SOLIDCOLOR       0x00000080L
    #define CC_ANYCOLOR         0x00000100L
#endif

/* FindText() and ReplaceText() flags */
#define FR_DOWN                 0x00000001L
#define FR_WHOLEWORD            0x00000002L
#define FR_MATCHCASE            0x00000004L
#define FR_FINDNEXT             0x00000008L
#define FR_REPLACE              0x00000010L
#define FR_REPLACEALL           0x00000020L
#define FR_DIALOGTERM           0x00000040L
#define FR_SHOWHELP             0x00000080L
#define FR_ENABLEHOOK           0x00000100L
#define FR_ENABLETEMPLATE       0x00000200L
#define FR_NOUPDOWN             0x00000400L
#define FR_NOMATCHCASE          0x00000800L
#define FR_NOWHOLEWORD          0x00001000L
#define FR_ENABLETEMPLATEHANDLE 0x00002000L
#define FR_HIDEUPDOWN           0x00004000L
#define FR_HIDEMATCHCASE        0x00008000L
#define FR_HIDEWHOLEWORD        0x00010000L
#if (NTDDI_VERSION >= 0x05000000)
    #define FR_RAW              0x00020000L
    #define FR_MATCHDIAC        0x20000000L
    #define FR_MATCHKASHIDA     0x40000000L
    #define FR_MATCHHALEFHAMZA  0x80000000L
#endif

/* ChooseFont() flags */
#define CF_SCREENFONTS          0x00000001L
#define CF_PRINTERFONTS         0x00000002L
#define CF_BOTH                 (CF_SCREENFONTS | CF_PRINTERFONTS)
#define CF_SHOWHELP             0x00000004L
#define CF_ENABLEHOOK           0x00000008L
#define CF_ENABLETEMPLATE       0x00000010L
#define CF_ENABLETEMPLATEHANDLE 0x00000020L
#define CF_INITTOLOGFONTSTRUCT  0x00000040L
#define CF_USESTYLE             0x00000080L
#define CF_EFFECTS              0x00000100L
#define CF_APPLY                0x00000200L
#define CF_ANSIONLY             0x00000400L
#if (WINVER >= 0x0400)
    #define CF_SCRIPTSONLY      CF_ANSIONLY
#endif
#define CF_NOVECTORFONTS        0x00000800L
#define CF_NOOEMFONTS           CF_NOVECTORFONTS
#define CF_NOSIMULATIONS        0x00001000L
#define CF_LIMITSIZE            0x00002000L
#define CF_FIXEDPITCHONLY       0x00004000L
#define CF_WYSIWYG              0x00008000L
#define CF_FORCEFONTEXIST       0x00010000L
#define CF_SCALABLEONLY         0x00020000L
#define CF_TTONLY               0x00040000L
#define CF_NOFACESEL            0x00080000L
#define CF_NOSTYLESEL           0x00100000L
#define CF_NOSIZESEL            0x00200000L
#if (WINVER >= 0x0400)
    #define CF_SELECTSCRIPT     0x00400000L
    #define CF_NOSCRIPTSEL      0x00800000L
    #define CF_NOVERTFONTS      0x01000000L
#endif
#if (WINVER >= 0x0601)
    #define CF_INACTIVEFONTS    0x02000000L
#endif

/* Font type flags */
#define SIMULATED_FONTTYPE  0x00008000L
#define PRINTER_FONTTYPE    0x00004000L
#define SCREEN_FONTTYPE     0x00002000L
#define BOLD_FONTTYPE       0x00000100L
#define ITALIC_FONTTYPE     0x00000200L
#define REGULAR_FONTTYPE    0x00000400L
#if (NTDDI_VERSION >= 0x05000000)
    #define PS_OPENTYPE_FONTTYPE    0x00010000L
    #define TT_OPENTYPE_FONTTYPE    0x00020000L
    #define TYPE1_FONTTYPE          0x00040000L
#endif
#if (WINVER >= 0x0601)
    #define SYMBOL_FONTTYPE         0x00080000L
#endif

/* Font dialog messages */
#define WM_CHOOSEFONT_GETLOGFONT        (WM_USER + 1)
#if (NTDDI_VERSION >= 0x05000000)
    #define WM_CHOOSEFONT_SETLOGFONT    (WM_USER + 101)
    #define WM_CHOOSEFONT_SETFLAGS      (WM_USER + 102)
#endif

/* Common dialog registered messages */
#define LBSELCHSTRINGA  "commdlg_LBSelChangedNotify"
#define LBSELCHSTRINGW  L"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGA  "commdlg_ShareViolation"
#define SHAREVISTRINGW  L"commdlg_ShareViolation"
#define FILEOKSTRINGA   "commdlg_FileNameOK"
#define FILEOKSTRINGW   L"commdlg_FileNameOK"
#define COLOROKSTRINGA  "commdlg_ColorOK"
#define COLOROKSTRINGW  L"commdlg_ColorOK"
#define SETRGBSTRINGA   "commdlg_SetRGBColor"
#define SETRGBSTRINGW   L"commdlg_SetRGBColor"
#define HELPMSGSTRINGA  "commdlg_help"
#define HELPMSGSTRINGW  L"commdlg_help"
#define FINDMSGSTRINGA  "commdlg_FindReplace"
#define FINDMSGSTRINGW  L"commdlg_FindReplace"
#ifdef UNICODE
    #define LBSELCHSTRING   LBSELCHSTRINGW
    #define SHAREVISTRING   SHAREVISTRINGW
    #define FILEOKSTRING    FILEOKSTRINGW
    #define COLOROKSTRING   COLOROKSTRINGW
    #define SETRGBSTRING    SETRGBSTRINGW
    #define HELPMSGSTRING   HELPMSGSTRINGW
    #define FINDMSGSTRING   FINDMSGSTRINGW
#else
    #define LBSELCHSTRING   LBSELCHSTRINGA
    #define SHAREVISTRING   SHAREVISTRINGA
    #define FILEOKSTRING    FILEOKSTRINGA
    #define COLOROKSTRING   COLOROKSTRINGA
    #define SETRGBSTRING    SETRGBSTRINGA
    #define HELPMSGSTRING   HELPMSGSTRINGA
    #define FINDMSGSTRING   FINDMSGSTRINGA
#endif

/* Common dialog list box change types */
#define CD_LBSELNOITEMS (-1)
#define CD_LBSELCHANGE  0
#define CD_LBSELSUB     1
#define CD_LBSELADD     2

/* PrintDlg() flags */
#define PD_ALLPAGES                     0x00000000L
#define PD_SELECTION                    0x00000001L
#define PD_PAGENUMS                     0x00000002L
#define PD_NOSELECTION                  0x00000004L
#define PD_NOPAGENUMS                   0x00000008L
#define PD_COLLATE                      0x00000010L
#define PD_PRINTTOFILE                  0x00000020L
#define PD_PRINTSETUP                   0x00000040L
#define PD_NOWARNING                    0x00000080L
#define PD_RETURNDC                     0x00000100L
#define PD_RETURNIC                     0x00000200L
#define PD_RETURNDEFAULT                0x00000400L
#define PD_SHOWHELP                     0x00000800L
#define PD_ENABLEPRINTHOOK              0x00001000L
#define PD_ENABLESETUPHOOK              0x00002000L
#define PD_ENABLEPRINTTEMPLATE          0x00004000L
#define PD_ENABLESETUPTEMPLATE          0x00008000L
#define PD_ENABLEPRINTTEMPLATEHANDLE    0x00010000L
#define PD_ENABLESETUPTEMPLATEHANDLE    0x00020000L
#define PD_USEDEVMODECOPIES             0x00040000L
#define PD_USEDEVMODECOPIESANDCOLLATE   0x00040000L
#define PD_DISABLEPRINTTOFILE           0x00080000L
#define PD_HIDEPRINTTOFILE              0x00100000L
#define PD_NONETWORKBUTTON              0x00200000L
#if (WINVER >= 0x0500)
    #define PD_CURRENTPAGE              0x00400000L
    #define PD_NOCURRENTPAGE            0x00800000L
    #define PD_EXCLUSIONFLAGS           0x01000000L
    #define PD_USELARGETEMPLATE         0x10000000L
#endif

/* PrintDlgEx() exclusion flags */
#if (WINVER >= 0x0500)
    #define PD_EXCL_COPIESANDCOLLATE    (DM_COPIES | DM_COLLATE)
#endif

/* PrintDlgEx() start page special value */
#if (WINVER >= 0x0500)
    #define START_PAGE_GENERAL  0xFFFFFFFFL
#endif

/* PrintDlgEx() return values */
#if (WINVER >= 0x0500)
    #define PD_RESULT_CANCEL    0L
    #define PD_RESULT_PRINT     1L
    #define PD_RESULT_APPLY     2L
#endif

/* Device names flags */
#define DN_DEFAULTPRN   0x0001

/* Page setup dialog messages */
#if (WINVER >= 0x0400)
    #define WM_PSD_PAGESETUPDLG     (WM_USER + 0)
    #define WM_PSD_FULLPAGERECT     (WM_USER + 1)
    #define WM_PSD_MINMARGINRECT    (WM_USER + 2)
    #define WM_PSD_MARGINRECT       (WM_USER + 3)
    #define WM_PSD_GREEKTEXTRECT    (WM_USER + 4)
    #define WM_PSD_ENVSTAMPRECT     (WM_USER + 5)
    #define WM_PSD_YAFULLPAGERECT   (WM_USER + 6)
#endif

/* PageSetupDlg() flags */
#if (WINVER >= 0x0400)
    #define PSD_DEFAULTMINMARGINS               0x00000000L
    #define PSD_INWININIINTLMEASURE             0x00000000L
    #define PSD_MINMARGINS                      0x00000001L
    #define PSD_MARGINS                         0x00000002L
    #define PSD_INTHOUSANDTHSOFINCHES           0x00000004L
    #define PSD_INHUNDREDTHSOFMILLIMETERS       0x00000008L
    #define PSD_DISABLEMARGINS                  0x00000010L
    #define PSD_DISABLEPRINTER                  0x00000020L
    #define PSD_NOWARNING                       0x00000080L
    #define PSD_DISABLEORIENTATION              0x00000100L
    #define PSD_RETURNDEFAULT                   0x00000400L
    #define PSD_DISABLEPAPER                    0x00000200L
    #define PSD_SHOWHELP                        0x00000800L
    #define PSD_ENABLEPAGESETUPHOOK             0x00002000L
    #define PSD_ENABLEPAGESETUPTEMPLATE         0x00008000L
    #define PSD_ENABLEPAGESETUPTEMPLATEHANDLE   0x00020000L
    #define PSD_ENABLEPAGEPAINTHOOK             0x00040000L
    #define PSD_DISABLEPAGEPAINTING             0x00080000L
    #define PSD_NONETWORKBUTTON                 0x00200000L
#endif

/* Common dialog hook functions */
typedef UINT_PTR (CALLBACK *LPOFNHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPCCHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPFRHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPCFHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPPRINTHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPSETUPHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
#if (WINVER >= 0x0400)
typedef UINT_PTR (CALLBACK *LPPAGEPAINTHOOK)( HWND, UINT, WPARAM, LPARAM );
typedef UINT_PTR (CALLBACK *LPPAGESETUPHOOK)( HWND, UINT, WPARAM, LPARAM );
#endif

/* All structures in this file get one-byte packing. */
#include <pshpack1.h>

/* GetOpenFileName() parameters as of Windows NT 4.0 */
typedef struct tagOFN_NT4 {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    LPCSTR          lpstrFilter;
    LPSTR           lpstrCustomFilter;
    DWORD           nMaxCustFilter;
    DWORD           nFilterIndex;
    LPSTR           lpstrFile;
    DWORD           nMaxFile;
    LPSTR           lpstrFileTitle;
    DWORD           nMaxFileTitle;
    LPCSTR          lpstrInitialDir;
    LPCSTR          lpstrTitle;
    DWORD           Flags;
    WORD            nFileOffset;
    WORD            nFileExtension;
    LPCSTR          lpstrDefExt;
    LPARAM          lCustData;
    LPOFNHOOKPROC   lpfnHook;
    LPCSTR          lpTemplateName;
} OPENFILENAME_NT4A;
typedef OPENFILENAME_NT4A   *LPOPENFILENAME_NT4A;
typedef struct tagOFN_NT4W {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    LPCWSTR         lpstrFilter;
    LPWSTR          lpstrCustomFilter;
    DWORD           nMaxCustFilter;
    DWORD           nFilterIndex;
    LPWSTR          lpstrFile;
    DWORD           nMaxFile;
    LPWSTR          lpstrFileTitle;
    DWORD           nMaxFileTitle;
    LPCWSTR         lpstrInitialDir;
    LPCWSTR         lpstrTitle;
    DWORD           Flags;
    WORD            nFileOffset;
    WORD            nFileExtension;
    LPCWSTR         lpstrDefExt;
    LPARAM          lCustData;
    LPOFNHOOKPROC   lpfnHook;
    LPCWSTR         lpTemplateName;
} OPENFILENAME_NT4W;
typedef OPENFILENAME_NT4W   *LPOPENFILENAME_NT4W;
#ifdef UNICODE
typedef OPENFILENAME_NT4W   OPENFILENAME_NT4;
typedef LPOPENFILENAME_NT4W LPOPENFILENAME_NT4;
#else
typedef OPENFILENAME_NT4A   OPENFILENAME_NT4;
typedef LPOPENFILENAME_NT4A LPOPENFILENAME_NT4;
#endif

/* GetOpenFileName() parameters */
typedef struct tagOFNA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    LPCSTR          lpstrFilter;
    LPSTR           lpstrCustomFilter;
    DWORD           nMaxCustFilter;
    DWORD           nFilterIndex;
    LPSTR           lpstrFile;
    DWORD           nMaxFile;
    LPSTR           lpstrFileTitle;
    DWORD           nMaxFileTitle;
    LPCSTR          lpstrInitialDir;
    LPCSTR          lpstrTitle;
    DWORD           Flags;
    WORD            nFileOffset;
    WORD            nFileExtension;
    LPCSTR          lpstrDefExt;
    LPARAM          lCustData;
    LPOFNHOOKPROC   lpfnHook;
    LPCSTR          lpTemplateName;
#if (_WIN32_WINNT >= 0x0500)
    void            *pvReserved;
    DWORD           dwReserved;
    DWORD           FlagsEx;
#endif
} OPENFILENAMEA;
typedef OPENFILENAMEA   *LPOPENFILENAMEA;
typedef struct tagOFNW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    LPCWSTR         lpstrFilter;
    LPWSTR          lpstrCustomFilter;
    DWORD           nMaxCustFilter;
    DWORD           nFilterIndex;
    LPWSTR          lpstrFile;
    DWORD           nMaxFile;
    LPWSTR          lpstrFileTitle;
    DWORD           nMaxFileTitle;
    LPCWSTR         lpstrInitialDir;
    LPCWSTR         lpstrTitle;
    DWORD           Flags;
    WORD            nFileOffset;
    WORD            nFileExtension;
    LPCWSTR         lpstrDefExt;
    LPARAM          lCustData;
    LPOFNHOOKPROC   lpfnHook;
    LPCWSTR         lpTemplateName;
#if (_WIN32_WINNT >= 0x0500)
    void            *pvReserved;
    DWORD           dwReserved;
    DWORD           FlagsEx;
#endif
} OPENFILENAMEW;
typedef OPENFILENAMEW   *LPOPENFILENAMEW;
#ifdef UNICODE
typedef OPENFILENAMEW   OPENFILENAME;
typedef LPOPENFILENAMEW LPOPENFILENAME;
#else
typedef OPENFILENAMEA   OPENFILENAME;
typedef LPOPENFILENAMEA LPOPENFILENAME;
#endif

/* GetOpenFileName() notification parameters */
#if (WINVER >= 0x0400)
typedef struct _OFNOTIFYA {
    NMHDR           hdr;
    LPOPENFILENAMEA lpOFN;
    LPSTR           pszFile;
} OFNOTIFYA;
typedef OFNOTIFYA   *LPOFNOTIFYA;
typedef struct _OFNOTIFYW {
    NMHDR           hdr;
    LPOPENFILENAMEW lpOFN;
    LPWSTR          pszFile;
} OFNOTIFYW;
typedef OFNOTIFYW   *LPOFNOTIFYW;
#ifdef UNICODE
typedef OFNOTIFYW   OFNOTIFY;
typedef LPOFNOTIFYW LPOFNOTIFY;
#else
typedef OFNOTIFYA   OFNOTIFY;
typedef LPOFNOTIFYA LPOFNOTIFY;
#endif
#endif

/* GetOpenFileName() notification parameters (extended version) */
#if (WINVER >= 0x0400)
typedef struct _OFNOTIFYEXA {
    NMHDR           hdr;
    LPOPENFILENAMEA lpOFN;
    LPVOID          psf;
    LPVOID          pidl;
} OFNOTIFYEXA;
typedef OFNOTIFYEXA     *LPOFNOTIFYEXA;
typedef struct _OFNOTIFYEXW {
    NMHDR           hdr;
    LPOPENFILENAMEW lpOFN;
    LPVOID          psf;
    LPVOID          pidl;
} OFNOTIFYEXW;
typedef OFNOTIFYEXW     *LPOFNOTIFYEXW;
#ifdef UNICODE
typedef OFNOTIFYEXW     OFNOTIFYEX;
typedef LPOFNOTIFYEXW   LPOFNOTIFYEX;
#else
typedef OFNOTIFYEXA     OFNOTIFYEX;
typedef LPOFNOTIFYEXA   LPOFNOTIFYEX;
#endif
#endif

/* ChooseColor() parameters */
typedef struct tagCHOOSECOLORA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HWND            hInstance;
    COLORREF        rgbResult;
    COLORREF        *lpCustColors;
    DWORD           Flags;
    LPARAM          lCustData;
    LPCCHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
} CHOOSECOLORA;
typedef CHOOSECOLORA    *LPCHOOSECOLORA;
typedef struct tagCHOOSECOLORW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HWND            hInstance;
    COLORREF        rgbResult;
    COLORREF        *lpCustColors;
    DWORD           Flags;
    LPARAM          lCustData;
    LPCCHOOKPROC    lpfnHook;
    LPCWSTR         lpTemplateName;
} CHOOSECOLORW;
typedef CHOOSECOLORW    *LPCHOOSECOLORW;
#ifdef UNICODE
typedef CHOOSECOLORW    CHOOSECOLOR;
typedef LPCHOOSECOLORW  LPCHOOSECOLOR;
#else
typedef CHOOSECOLORA    CHOOSECOLOR;
typedef LPCHOOSECOLORA  LPCHOOSECOLOR;
#endif

/* FindText() and ReplaceText() parameters */
typedef struct tagFINDREPLACEA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    DWORD           Flags;
    LPSTR           lpstrFindWhat;
    LPSTR           lpstrReplaceWith;
    WORD            wFindWhatLen;
    WORD            wReplaceWithLen;
    LPARAM          lCustData;
    LPFRHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
} FINDREPLACEA;
typedef FINDREPLACEA    *LPFINDREPLACEA;
typedef struct tagFINDREPLACEW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    DWORD           Flags;
    LPWSTR          lpstrFindWhat;
    LPWSTR          lpstrReplaceWith;
    WORD            wFindWhatLen;
    WORD            wReplaceWithLen;
    LPARAM          lCustData;
    LPFRHOOKPROC    lpfnHook;
    LPCWSTR         lpTemplateName;
} FINDREPLACEW;
typedef FINDREPLACEW    *LPFINDREPLACEW;
#ifdef UNICODE
typedef FINDREPLACEW    FINDREPLACE;
typedef LPFINDREPLACEW  LPFINDREPLACE;
#else
typedef FINDREPLACEA    FINDREPLACE;
typedef LPFINDREPLACEA  LPFINDREPLACE;
#endif

/* ChooseFont() parameters */
typedef struct tagCHOOSEFONTA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HDC             hDC;
    LPLOGFONTA      lpLogFont;
    INT             iPointSize;
    DWORD           Flags;
    COLORREF        rgbColors;
    LPARAM          lCustData;
    LPCFHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
    HINSTANCE       hInstance;
    LPSTR           lpszStyle;
    WORD            nFontType;
    WORD            __MISSING_ALIGNMENT__;
    INT             nSizeMin;
    INT             nSizeMax;
} CHOOSEFONTA;
typedef CHOOSEFONTA     *LPCHOOSEFONTA;
typedef struct tagCHOOSEFONTW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HDC             hDC;
    LPLOGFONTW      lpLogFont;
    INT             iPointSize;
    DWORD           Flags;
    COLORREF        rgbColors;
    LPARAM          lCustData;
    LPCFHOOKPROC    lpfnHook;
    LPCWSTR         lpTemplateName;
    HINSTANCE       hInstance;
    LPWSTR          lpszStyle;
    WORD            nFontType;
    WORD            __MISSING_ALIGNMENT__;
    INT             nSizeMin;
    INT             nSizeMax;
} CHOOSEFONTW;
typedef CHOOSEFONTW     *LPCHOOSEFONTW;
#ifdef UNICODE
typedef CHOOSEFONTW     CHOOSEFONT;
typedef LPCHOOSEFONTW   LPCHOOSEFONT;
#else
typedef CHOOSEFONTA     CHOOSEFONT;
typedef LPCHOOSEFONTA   LPCHOOSEFONT;
#endif

/* PrintDlg() parameters */
typedef struct tagPDA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    HDC             hDC;
    DWORD           Flags;
    WORD            nFromPage;
    WORD            nToPage;
    WORD            nMinPage;
    WORD            nMaxPage;
    WORD            nCopies;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPRINTHOOKPROC lpfnPrintHook;
    LPSETUPHOOKPROC lpfnSetupHook;
    LPCSTR          lpPrintTemplateName;
    LPCSTR          lpSetupTemplateName;
    HGLOBAL         hPrintTemplate;
    HGLOBAL         hSetupTemplate;
} PRINTDLGA;
typedef PRINTDLGA   *LPPRINTDLGA;
typedef struct tagPDW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    HDC             hDC;
    DWORD           Flags;
    WORD            nFromPage;
    WORD            nToPage;
    WORD            nMinPage;
    WORD            nMaxPage;
    WORD            nCopies;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPRINTHOOKPROC lpfnPrintHook;
    LPSETUPHOOKPROC lpfnSetupHook;
    LPCWSTR         lpPrintTemplateName;
    LPCWSTR         lpSetupTemplateName;
    HGLOBAL         hPrintTemplate;
    HGLOBAL         hSetupTemplate;
} PRINTDLGW;
typedef PRINTDLGW   *LPPRINTDLGW;
#ifdef UNICODE
typedef PRINTDLGW   PRINTDLG;
typedef LPPRINTDLGW LPPRINTDLG;
#else
typedef PRINTDLGA   PRINTDLG;
typedef LPPRINTDLGA LPPRINTDLG;
#endif

/* Print page range */
#if (WINVER >= 0x0500) && defined( STDMETHOD )
typedef struct tagPRINTPAGERANGE {
    DWORD   nFromPage;
    DWORD   nToPage;
} PRINTPAGERANGE;
typedef PRINTPAGERANGE          *LPPRINTPAGERANGE;
typedef const PRINTPAGERANGE    *PCPRINTPAGERANGE;
#endif

/* PrintDlgEx() parameters */
#if (WINVER >= 0x0500) && defined( STDMETHOD )
typedef struct tagPDEXA {
    DWORD               lStructSize;
    HWND                hwndOwner;
    HGLOBAL             hDevMode;
    HGLOBAL             hDevNames;
    HDC                 hDC;
    DWORD               Flags;
    DWORD               Flags2;
    DWORD               ExclusionFlags;
    DWORD               nPageRanges;
    DWORD               nMaxPageRanges;
    LPPRINTPAGERANGE    lpPageRanges;
    DWORD               nMinPage;
    DWORD               nMaxPage;
    DWORD               nCopies;
    HINSTANCE           hInstance;
    LPCSTR              lpPrintTemplateName;
    LPUNKNOWN           lpCallback;
    DWORD               nPropertyPages;
    HPROPSHEETPAGE      *lphPropertyPages;
    DWORD               nStartPage;
    DWORD               dwResultAction;
} PRINTDLGEXA;
typedef PRINTDLGEXA     *LPPRINTDLGEXA;
typedef struct tagPDEXW {
    DWORD               lStructSize;
    HWND                hwndOwner;
    HGLOBAL             hDevMode;
    HGLOBAL             hDevNames;
    HDC                 hDC;
    DWORD               Flags;
    DWORD               Flags2;
    DWORD               ExclusionFlags;
    DWORD               nPageRanges;
    DWORD               nMaxPageRanges;
    LPPRINTPAGERANGE    lpPageRanges;
    DWORD               nMinPage;
    DWORD               nMaxPage;
    DWORD               nCopies;
    HINSTANCE           hInstance;
    LPCWSTR             lpPrintTemplateName;
    LPUNKNOWN           lpCallback;
    DWORD               nPropertyPages;
    HPROPSHEETPAGE      *lphPropertyPages;
    DWORD               nStartPage;
    DWORD               dwResultAction;
} PRINTDLGEXW;
typedef PRINTDLGEXW     *LPPRINTDLGEXW;
#ifdef UNICODE
typedef PRINTDLGEXW     PRINTDLGEX;
typedef LPPRINTDLGEXW   LPPRINTDLGEX;
#else
typedef PRINTDLGEXA     PRINTDLGEX;
typedef LPPRINTDLGEXA   LPPRINTDLGEX;
#endif
#endif

/* Device names */
typedef struct tagDEVNAMES {
    WORD    wDriverOffset;
    WORD    wDeviceOffset;
    WORD    wOutputOffset;
    WORD    wDefault;
} DEVNAMES;
typedef DEVNAMES        *LPDEVNAMES;
typedef const DEVNAMES  *PCDEVNAMES;

/* PageSetupDlg() parameters */
#if (WINVER >= 0x0400)
typedef struct tagPSDA {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    DWORD           Flags;
    POINT           ptPaperSize;
    RECT            rtMinMargin;
    RECT            rtMargin;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCSTR          lpPageSetupTemplateName;
    HGLOBAL         hPageSetupTemplate;
} PAGESETUPDLGA;
typedef PAGESETUPDLGA   *LPPAGESETUPDLGA;
typedef struct tagPSDW {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    DWORD           Flags;
    POINT           ptPaperSize;
    RECT            rtMinMargin;
    RECT            rtMargin;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPAGESETUPHOOK lpfnPageSetupHook;
    LPPAGEPAINTHOOK lpfnPagePaintHook;
    LPCWSTR         lpPageSetupTemplateName;
    HGLOBAL         hPageSetupTemplate;
} PAGESETUPDLGW;
typedef PAGESETUPDLGW   *LPPAGESETUPDLGW;
#ifdef UNICODE
typedef PAGESETUPDLGW   PAGESETUPDLG;
typedef LPPAGESETUPDLGW LPPAGESETUPDLG;
#else
typedef PAGESETUPDLGA   PAGESETUPDLG;
typedef LPPAGESETUPDLGA LPPAGESETUPDLG;
#endif
#endif

/* Structure sizes */
#if (_WIN32_WINNT >= 0x0500)
    #define OPENFILENAME_SIZE_VERSION_400A \
        CDSIZEOF_STRUCT( OPENFILENAMEA, lpTemplateName )
    #define OPENFILENAME_SIZE_VERSION_400W \
        CDSIZEOF_STRUCT( OPENFILENAMEW, lpTemplateName )
#endif
#ifdef UNICODE
    #if (_WIN32_WINNT >= 0x0500)
        #define OPENFILENAME_SIZE_VERSION_400   OPENFILENAME_SIZE_VERSION_400W
    #endif
#else
    #if (_WIN32_WINNT >= 0x0500)
        #define OPENFILENAME_SIZE_VERSION_400   OPENFILENAME_SIZE_VERSION_400A
    #endif
#endif

/* Revert to default packing. */
#include <poppack.h>

/* IPrintDialogCallback interface */
#if (WINVER >= 0x0500) && defined( STDMETHOD )
#undef INTERFACE
#define INTERFACE   IPrintDialogCallback
DECLARE_INTERFACE_( IPrintDialogCallback, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;
    
    /* IPrintDialogCallback methods */
    STDMETHOD( InitDone )( THIS ) PURE;
    STDMETHOD( SelectionChange )( THIS ) PURE;
    STDMETHOD( HandleMessage )( THIS_ HWND, UINT, WPARAM, LPARAM, LRESULT * ) PURE;
};
#endif

/* IPrintDialogServices interface */
#if (WINVER >= 0x0500) && defined( STDMETHOD )
#undef INTERFACE
#define INTERFACE   IPrintDialogServices
DECLARE_INTERFACE_( IPrintDialogServices, IUnknown ) {
    /* IUnknown methods */
    STDMETHOD( QueryInterface )( THIS_ REFIID, void ** ) PURE;
    STDMETHOD_( ULONG, AddRef )( THIS ) PURE;
    STDMETHOD_( ULONG, Release )( THIS ) PURE;

    /* IPrintDialogServices methods */
    STDMETHOD( GetCurrentDevMode )( THIS_ LPDEVMODE, UINT * ) PURE;
    STDMETHOD( GetCurrentPrinterName )( THIS_ LPWSTR, UINT * ) PURE;
    STDMETHOD( GetCurrentPortName )( THIS_ LPWSTR, UINT * ) PURE;
};
#endif

/* Functions in COMDLG32.DLL */
WINCOMMDLGAPI BOOL APIENTRY     ChooseColorA( LPCHOOSECOLORA );
WINCOMMDLGAPI BOOL APIENTRY     ChooseColorW( LPCHOOSECOLORW );
WINCOMMDLGAPI BOOL APIENTRY     ChooseFontA( LPCHOOSEFONTA );
WINCOMMDLGAPI BOOL APIENTRY     ChooseFontW( LPCHOOSEFONTW );
WINCOMMDLGAPI DWORD APIENTRY    CommDlgExtendedError( VOID );
WINCOMMDLGAPI HWND APIENTRY     FindTextA( LPFINDREPLACEA );
WINCOMMDLGAPI HWND APIENTRY     FindTextW( LPFINDREPLACEW );
WINCOMMDLGAPI short APIENTRY    GetFileTitleA( LPCSTR, LPSTR, WORD );
WINCOMMDLGAPI short APIENTRY    GetFileTitleW( LPCWSTR, LPWSTR, WORD );
WINCOMMDLGAPI BOOL APIENTRY     GetOpenFileNameA( LPOPENFILENAMEA );
WINCOMMDLGAPI BOOL APIENTRY     GetOpenFileNameW( LPOPENFILENAMEW );
WINCOMMDLGAPI BOOL APIENTRY     GetSaveFileNameA( LPOPENFILENAMEA );
WINCOMMDLGAPI BOOL APIENTRY     GetSaveFileNameW( LPOPENFILENAMEW );
WINCOMMDLGAPI BOOL APIENTRY     PrintDlgA( LPPRINTDLGA );
WINCOMMDLGAPI BOOL APIENTRY     PrintDlgW( LPPRINTDLGW );
WINCOMMDLGAPI HWND APIENTRY     ReplaceTextA( LPFINDREPLACEA );
WINCOMMDLGAPI HWND APIENTRY     ReplaceTextW( LPFINDREPLACEW );
#if (WINVER >= 0x0400)
WINCOMMDLGAPI BOOL APIENTRY     PageSetupDlgA( LPPAGESETUPDLGA );
WINCOMMDLGAPI BOOL APIENTRY     PageSetupDlgW( LPPAGESETUPDLGW );
#endif
#if (WINVER >= 0x0500) && defined( STDMETHOD )
WINCOMMDLGAPI HRESULT APIENTRY  PrintDlgExA( LPPRINTDLGEXA );
WINCOMMDLGAPI HRESULT APIENTRY  PrintDlgExW( LPPRINTDLGEXW );
#endif

/* Functions implemented as macros */
#define CommDlg_OpenSave_GetSpecA( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETSPEC, (WPARAM)(p1), (LPARAM)(LPSTR)(p2) )
#define CommDlg_OpenSave_GetSpecW( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETSPEC, (WPARAM)(p1), (LPARAM)(LPWSTR)(p2) )
#define CommDlg_OpenSave_GetFilePathA( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETFILEPATH, (WPARAM)(p1), (LPARAM)(LPSTR)(p2) )
#define CommDlg_OpenSave_GetFilePathW( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETFILEPATH, (WPARAM)(p1), (LPARAM)(LPWSTR)(p2) )
#define CommDlg_OpenSave_GetFolderPathA( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETFOLDERPATH, (WPARAM)(p1), (LPARAM)(LPSTR)(p2) )
#define CommDlg_OpenSave_GetFolderPathW( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETFOLDERPATH, (WPARAM)(p1), (LPARAM)(LPWSTR)(p2) )
#define CommDlg_OpenSave_GetFolderIDList( x, p1, p2 ) \
    (int)SNDMSG( x, CDM_GETFOLDERIDLIST, (WPARAM)(p1), (LPARAM)(LPVOID)(p2) )
#define CommDlg_OpenSave_SetControlText( x, p1, p2 ) \
    (void)SNDMSG( x, CDM_SETCONTROLTEXT, (WPARAM)(p1), (LPARAM)(LPSTR)(p2) )
#define CommDlg_OpenSave_HideControl( x, p ) \
    (void)SNDMSG( x, CDM_HIDECONTROL, (WPARAM)(p), 0L )
#define CommDlg_OpenSave_SetDefExt( x, p ) \
    (void)SNDMSG( x, CDM_SETDEFEXT, 0, (LPARAM)(LPSTR)(p) )

/* Map generic function names to the appropriate ANSI or Unicode version. */
#ifdef UNICODE
    #define ChooseColor                     ChooseColorW
    #define ChooseFont                      ChooseFontW
    #define CommDlg_OpenSave_GetFilePath    CommDlg_OpenSave_GetFilePathW
    #define CommDlg_OpenSave_GetFolderPath  CommDlg_OpenSave_GetFolderPathW
    #define CommDlg_OpenSave_GetSpec        CommDlg_OpenSave_GetSpecW
    #define FindText                        FindTextW
    #define GetFileTitle                    GetFileTitleW
    #define GetOpenFileName                 GetOpenFileNameW
    #define GetSaveFileName                 GetSaveFileNameW
    #define PrintDlg                        PrintDlgW
    #define ReplaceText                     ReplaceTextW
    #if (WINVER >= 0x0400)
        #define PageSetupDlg                PageSetupDlgW
    #endif
    #if (WINVER >= 0x0500) && defined( STDMETHOD )
        #define PrintDlgEx                  PrintDlgExW
    #endif
#else
    #define ChooseColor                     ChooseColorA
    #define ChooseFont                      ChooseFontA
    #define CommDlg_OpenSave_GetFilePath    CommDlg_OpenSave_GetFilePathA
    #define CommDlg_OpenSave_GetFolderPath  CommDlg_OpenSave_GetFolderPathA
    #define CommDlg_OpenSave_GetSpec        CommDlg_OpenSave_GetSpecA
    #define FindText                        FindTextA
    #define GetFileTitle                    GetFileTitleA
    #define GetOpenFileName                 GetOpenFileNameA
    #define GetSaveFileName                 GetSaveFileNameA
    #define PrintDlg                        PrintDlgA
    #define ReplaceText                     ReplaceTextA
    #if (WINVER >= 0x0400)
        #define PageSetupDlg                PageSetupDlgA
    #endif
    #if (WINVER >= 0x0500) && defined( STDMETHOD )
        #define PrintDlgEx                  PrintDlgExA
    #endif
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

/* GUIDs */
EXTERN_C const IID  __cdecl IID_IPrintDialogCallback;
EXTERN_C const IID  __cdecl IID_IPrintDialogServices;

#endif /* _INC_COMMDLG */
