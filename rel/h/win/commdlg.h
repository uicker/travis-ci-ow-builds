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

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack( push, 1 )

/* ChooseColor() flags */
#define CC_RGBINIT              0x00000001L
#define CC_FULLOPEN             0x00000002L
#define CC_PREVENTFULLOPEN      0x00000004L
#define CC_SHOWHELP             0x00000008L
#define CC_ENABLEHOOK           0x00000010L
#define CC_ENABLETEMPLATE       0x00000020L
#define CC_ENABLETEMPLATEHANDLE 0x00000040L

/* Common dialog list box change types */
#define CD_LBSELNOITEMS (-1)
#define CD_LBSELCHANGE  0
#define CD_LBSELSUB     1
#define CD_LBSELADD     2

/* ChooseFont() flags */
#define CF_SCREENFONTS          0x00000001L
#define CF_PRINTERFONTS         0x00000002L
#define CF_BOTH                 0x00000003L
#define CF_SHOWHELP             0x00000004L
#define CF_ENABLEHOOK           0x00000008L
#define CF_ENABLETEMPLATE       0x00000010L
#define CF_ENABLETEMPLATEHANDLE 0x00000020L
#define CF_INITTOLOGFONTSTRUCT  0x00000040L
#define CF_USESTYLE             0x00000080L
#define CF_EFFECTS              0x00000100L
#define CF_APPLY                0x00000200L
#define CF_ANSIONLY             0x00000400L
#define CF_SCRIPTSONLY          CF_ANSIONLY
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

/* Device name flags */
#define DN_DEFAULTPRN   1

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

/* GetOpenFileName() registered message return values */
#define OFN_SHAREWARN           0
#define OFN_SHARENOWARN         1
#define OFN_SHAREFALLTHROUGH    2

/* GetOpenFileName() flags */
#define OFN_READONLY                    0x00000001L
#define OFN_OVERWRITEPROMPT             0x00000002L
#define OFN_HIDEREADONLY                0x00000004L
#define OFN_NOCHANGEDIR                 0x00000008L
#define OFN_SHOWHELP                    0x00000010L
#define OFN_ENABLEHOOK                  0x00000020L
#define OFN_ENABLETEMPLATE              0x00000040L
#define OFN_ENABLETEMPLATEHANDLE        0x00000080L
#define OFN_NOVALIDATE                  0x00000100L
#define OFN_ALLOWMULTISELECT            0x00000200L
#define OFN_EXTENSIONDIFFERENT          0x00000400L
#define OFN_PATHMUSTEXIST               0x00000800L
#define OFN_FILEMUSTEXIST               0x00001000L
#define OFN_CREATEPROMPT                0x00002000L
#define OFN_SHAREAWARE                  0x00004000L
#define OFN_NOREADONLYRETURN            0x00008000L
#define OFN_NOTESTFILECREATE            0x00010000L
#define OFN_NONETWORKBUTTON             0x00020000L
#define OFN_NOLONGNAMES                 0x00040000L
#define OFN_EXPLORER                    0x00080000L
#define OFN_NODEREFERENCELINKS          0x00100000L
#define OFN_LONGNAMES                   0x00200000L

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
#define PD_DISABLEPRINTTOFILE           0x00080000L
#define PD_HIDEPRINTTOFILE              0x00100000L
#define PD_NONETWORKBUTTON              0x00200000L

/* Font type flags */
#define BOLD_FONTTYPE           0x0100
#define ITALIC_FONTTYPE         0x0200
#define REGULAR_FONTTYPE        0x0400
#define SCREEN_FONTTYPE         0x2000
#define PRINTER_FONTTYPE        0x4000
#define SIMULATED_FONTTYPE      0x8000

/* Font dialog messages */
#define WM_CHOOSEFONT_GETLOGFONT    (WM_USER + 1)

#ifndef RC_INVOKED

/* Common dialog hook functions */
typedef UINT (CALLBACK *__CDHOOKPROC)( HWND, UINT, WPARAM, LPARAM );
typedef __CDHOOKPROC    LPCCHOOKPROC;
typedef __CDHOOKPROC    LPCFHOOKPROC;
typedef __CDHOOKPROC    LPFRHOOKPROC;
typedef __CDHOOKPROC    LPOFNHOOKPROC;
typedef __CDHOOKPROC    LPSETUPHOOKPROC;
typedef __CDHOOKPROC    LPPRINTHOOKPROC;

/* ChooseColor() parameters */
typedef struct tagCHOOSECOLOR {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HWND            hInstance;
    COLORREF        rgbResult;
    COLORREF FAR    *lpCustColors;
    DWORD           Flags;
    LPARAM          lCustData;
    LPCCHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
} CHOOSECOLOR;
typedef CHOOSECOLOR FAR *LPCHOOSECOLOR;

/* ChooseFont() parameters */
typedef struct tagCHOOSEFONT {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HDC             hDC;
    LPLOGFONT       lpLogFont;
    int             iPointSize;
    DWORD           Flags;
    COLORREF        rgbColors;
    LPARAM          lCustData;
    LPCFHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
    HINSTANCE       hInstance;
    LPSTR           lpszStyle;
    UINT            nFontType;
    int             nSizeMin;
    int             nSizeMax;
} CHOOSEFONT;
typedef CHOOSEFONT FAR  *LPCHOOSEFONT;

/* Device names */
typedef struct tagDEVNAMES {
    UINT    wDriverOffset;
    UINT    wDeviceOffset;
    UINT    wOutputOffset;
    UINT    wDefault;
} DEVNAMES;
typedef DEVNAMES FAR    *LPDEVNAMES;

/* FindText() and ReplaceText() parameters */
typedef struct tagFINDREPLACE {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HINSTANCE       hInstance;
    DWORD           Flags;
    LPSTR           lpstrFindWhat;
    LPSTR           lpstrReplaceWith;
    UINT            wFindWhatLen;
    UINT            wReplaceWithLen;
    LPARAM          lCustData;
    LPFRHOOKPROC    lpfnHook;
    LPCSTR          lpTemplateName;
} FINDREPLACE;
typedef FINDREPLACE FAR *LPFINDREPLACE;

/* GetOpenFileName() parameters */
typedef struct tagOFN {
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
    UINT            nFileOffset;
    UINT            nFileExtension;
    LPCSTR          lpstrDefExt;
    LPARAM          lCustData;
    LPOFNHOOKPROC   lpfnHook;
    LPCSTR          lpTemplateName;
} OPENFILENAME;
typedef OPENFILENAME FAR    *LPOPENFILENAME;

/* PrintDlg() parameters */
typedef struct tagPD {
    DWORD           lStructSize;
    HWND            hwndOwner;
    HGLOBAL         hDevMode;
    HGLOBAL         hDevNames;
    HDC             hDC;
    DWORD           Flags;
    UINT            nFromPage;
    UINT            nToPage;
    UINT            nMinPage;
    UINT            nMaxPage;
    UINT            nCopies;
    HINSTANCE       hInstance;
    LPARAM          lCustData;
    LPPRINTHOOKPROC lpfnPrintHook;
    LPSETUPHOOKPROC lpfnSetupHook;
    LPCSTR          lpPrintTemplateName;
    LPCSTR          lpSetupTemplateName;
    HGLOBAL         hPrintTemplate;
    HGLOBAL         hSetupTemplate;
} PRINTDLG;
typedef PRINTDLG FAR    *LPPRINTDLG;

/* Functions in COMMDLG.DLL */
BOOL WINAPI     ChooseColor( LPCHOOSECOLOR );
BOOL WINAPI     ChooseFont( LPCHOOSEFONT );
DWORD WINAPI    CommDlgExtendedError( void );
HWND WINAPI     FindText( LPFINDREPLACE );
short WINAPI    GetFileTitle( LPCSTR, LPSTR, UINT );
BOOL WINAPI     GetOpenFileName( LPOPENFILENAME );
BOOL WINAPI     GetSaveFileName( LPOPENFILENAME );
BOOL WINAPI     PrintDlg( LPPRINTDLG );
HWND WINAPI     ReplaceText( LPFINDREPLACE );

#endif /* RC_INVOKED */

#pragma pack( pop )

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _INC_COMMDLG */
