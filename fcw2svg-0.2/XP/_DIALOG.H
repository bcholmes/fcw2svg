/////////////////// _DIALOG.H - FastCAD-32 XP include file ///////////////
//
//	Written by Mike Riddle 5-26-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _DIALOG_H_
#define _DIALOG_H_

#define hDLG int		// dialog handle

#define XPDlog _XPDlog
int _stdcall XPDlog(hDLG pDlg,HINSTANCE hMod,int parm);

#define VCF_INVALID		1	// data is invalid
#define VCF_ENDDIALOG	2	// dialog should end
#define VCF_DBLCLICK	4	// item has been double-clicked

#define pDLGINIT void*
#define pDLGEND int*
//#define pDLGVALID int*
typedef int (_stdcall *pDLGVALID)(void);

typedef int (_stdcall *pDLGCMD)(void);

#define pDLGDRAW void*

hDLG _stdcall DefDlg(LPSTR DlgName,int Opts,int Hlp,\
		     pDLGINIT pInitF, pDLGEND pEndF, LPSTR CustHlp);

#define EDCTL _EDCTL
#define CHKCTL _CHKCTL
#define RBCTL _RBCTL
#define BTNCTL _BTNCTL
#define LSTCTL _LSTCTL
#define CMBCTL _CMBCTL

void _stdcall EDCTL(hDLG hDlg,int id,int Opt,int flags,int width,
		    void* VData,pDLGVALID pValidF);

void _stdcall CHKCTL(hDLG hDlg,int id,int Opt,int flags,
		    void* VData, int Mask, pDLGCMD pCmdF);

void _stdcall RBCTL(hDLG hDlg,int id,int Opt,int flags,
		    void* VData, int RetCode, pDLGCMD pCmdF);

void _stdcall BTNCTL(hDLG hDlg,int id,int Opt,int flags,
		     pDLGCMD pCmdF, pDLGDRAW pDrawF);

void _stdcall LSTCTL(hDLG hDlg,int id,int Opt,int flags,void* VData,
		     LPSTR VList,pDLGVALID pValidF,pDLGDRAW pDrawF);

void _stdcall CMBCTL(hDLG hDlg,int id,int Opt,int flags,void* VData,
		     LPSTR VList,pDLGVALID pValidF,pDLGDRAW pDrawF);


void _stdcall RelDlg(hDLG pDlg);

// ===================================================================

#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9

#define InfoBox _InfoBox
void _stdcall InfoBox(char *Text);
#define WarnBox _WarnBox
void _stdcall WarnBox(char *Text);
#define ErrorBox _ErrorBox
void _stdcall ErrorBox(char *Text);
#define QuestBox _QuestBox
int  _stdcall QuestBox(char *Text);
#define CancelBox _CancelBox
int  _stdcall CancelBox(char *Text);
#define RetryBox _RetryBox
int  _stdcall RetryBox(char *Text);
#define MsgBox _MsgBox
void _stdcall MsgBox(char *Text, char *Title);

//	TDLG Flags:
#define TE_SEL		0x0001	// auto-select text window contents
// Remaining flags	assume lpBuild->entity with text geometry after CStuff
#define TE_PROP		0x0010	// properties button (uses tspec dialog to edit text properties of entity)
#define TE_FILE		0x0020	// file button (forces entity flag to TD_FILE,
//				// gets file name via openfile)

#define TEdit _TEdit
char _stdcall TEdit(void *TextAdr, DWORD MaxLength, DWORD Flags);

#define GetDlgWin _GetDlgWin
HWND _stdcall GetDlgWin(void);

#define AddLstStr _AddLstStr
int _stdcall AddLstStr(int Control, char *Str);
#define ClrLstStr _ClrLstStr
void _stdcall ClrLstStr(int Control);
#define RstLstStr _RstLstStr
void _stdcall RstLstStr(int Control);
#define GetLstStr _GetLstStr
int _stdcall GetLstStr(int Control, char *Str);
#define FndLstStr _FndLstStr
int _stdcall FndLstStr(int Control, char *Str);
#define GetLstDta _GetLstDta
int _stdcall GetLstDta(int Control, int ItemNr);
#define SetLstDta _SetLstDta
int _stdcall SetLstDta(int Control, int ItemNr, int Value);

#define AddCmbStr _AddCmbStr
int _stdcall AddCmbStr(int Control, char *Str);
#define ClrCmbStr _ClrCmbStr
void _stdcall ClrCmbStr(int Control);
#define RstCmbStr _RstCmbStr
void _stdcall RstCmbStr(int Control);
#define GetCmbStr _GetCmbStr
int _stdcall GetCmbStr(int Control, char *Str);
#define FndCmbStr _FndCmbStr
int _stdcall FndCmbStr(int Control, char *Str);
#define GetCmbDta _GetCmbDta
int _stdcall GetCmbDta(int Control, int ItemNr);
#define SetCmbDta _SetCmbDta
int _stdcall SetCmbDta(int Control, int ItemNr, DWORD Value);

#define FocusCtl _FocusCtl
void _stdcall FocusCtl(int Control);
#define UpdCtl _UpdCtl
void _stdcall UpdCtl(int Control);
#define UpdCtlA _UpdCtlA
void _stdcall UpdCtlA(void);
#define HideCtl _HideCtl
void _stdcall HideCtl(int Control);
#define ShowCtl _ShowCtl
void _stdcall ShowCtl(int Control);
#define EnAbCtl _EnAbCtl
void _stdcall EnAbCtl(int Control);

#endif