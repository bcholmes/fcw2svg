#ifndef _MISC_H_
#define _MISC_H_

#define QKeyShift _QKeyShift
char _stdcall QKeyShift(void);
#define QKeyCtrlShift _QKeyCtrlShift
char _stdcall QKeyCtrlShift(void);
#define QKeyCtrl _QKeyCtrl
char _stdcall QKeyCtrl(void);

#define RscAdr _RscAdr
void * _stdcall RscAdr(void *RSC);

#define GetOpenFN _GetOpenFN
char _stdcall GetOpenFN(char *Title, GETFN *GetFN);
#define GetSaveFN _GetSaveFN
char _stdcall GetSaveFN(char *Title, GETFN *GetFN);

BOOL _stdcall _DlgGetFolderName(char* pTitle,char* pPath);

#define LoadFile _LoadFile
void * _stdcall LoadFile(char *FileName);
#define SaveFile _SaveFile
char _stdcall SaveFile(char *FileName, char *Buffer, int Count);

#define AllocMem _AllocMem
void * _stdcall AllocMem(int Size);
#define RelMem _RelMem
char _stdcall RelMem(void *Adr);
#define ResizeMem _ResizeMem
void * _stdcall ResizeMem(void *Adr, int NewSize);
#define CloneMem _CloneMem
void * _stdcall CloneMem(void *Adr);

#define GetScriptCopy _GetScriptCopy
void _stdcall GetScriptCopy(char FName);
#define GetScriptFile _GetScriptFile
void _stdcall GetScriptFile(char FName);
#define ExecScriptStg	_ExecScriptStg
void _stdcall ExecScriptStg(char *Stg);

#define GetAWAdr _GetAWAdr
DWIN * _stdcall GetAWAdr(void);	 

DWIN * _stdcall GetCurDWin(void);

#define PROT_CHG 1
#define PROT_PRINT 2
#define PROT_LYR 4

#define AskProtected _AskProtected
char _stdcall AskProtected(int Flags, void* hDList);
#define ChkProtected _ChkProtected
char _stdcall ChkProtected(int Flags, void* hDList);

// TSpecCmd runs the standard TSPECS command, changing the current settings

#define TSpecCmd _TSpecCmd
void _stdcall TSpecCmd(void);

// TSpecAlt runs the "change" text specs dialog
// Use GetTextSpecsAlt after it to post changes to text geometry

#define TSpecAlt _TSpecAlt
void _stdcall TSpecAlt(void);

// TSpecEd edits the specs in a given text geometry

#define TSpecEd _TSpecEd
void _stdcall TSpecEd(GTEXT2* pGeo);


void _stdcall Redraw(void);
void _stdcall RedrawCmd(void);
void _stdcall RedrawTools(void);
void _stdcall SaveCmd(void);
void _stdcall PrintCmd(void);
void _stdcall UpdScreenTools(void);

#define GetColorNr _GetColorNr
int _stdcall GetColorNr(void);
#define UseLStyle _UseLStyle 
void _stdcall UseLStyle(int Style);
#define StatusMsg _StatusMsg
void _stdcall StatusMsg(void *Msg);
#define RMGetValue _RMGetValue
void _stdcall RMGetValue(REGKEY *Pkt);
#define RMSetValue _RMSetValue
void _stdcall RMSetValue(REGKEY *Pkt);

#define SetVar _SetVar
void _stdcall SetVar(char *pLabel, char *pValue);

int _stdcall LockSet(int NewVal);

void _stdcall UpdScreenTools(void);
void _stdcall SetLike(pENTREC pCStuff);

void _stdcall SelSheet(SHEET *pSheet);
SHEET* _stdcall AddSheet(char *pName);
void _stdcall DelSheet(SHEET *pSheet);


int XPCALL GetAtchMode(void);
void XPCALL SetAtchMode(int Mode);

void XPCALL SetACADOptAdr(DWORD p);
void XPCALL DoACADOptDlg(void);

DWORD * _stdcall GetPalAdr(void);
void XPCALL DoOptionsDlg(void);
int XPCALL GetPickA(void);
void XPCALL SetPickA(DWORD v);
void XPCALL DevBkResize(void);
DWORD * XPCALL GetPalAdr(void);
void XPCALL DevMemBitmap(void);
void XPCALL DevSMemBitmap(void);
void XPCALL DoSelByDlg(void);
BOOL XPCALL GetXHStatus(void);
void XPCALL SetXHStatus(DWORD v);

void _stdcall _GoToLabel(char* pLabel);
DWORD * _stdcall GetErrFlagAdr(void);

char* _stdcall GetCurLayerName(void);
char* _stdcall GetCurLStyleName(void);
char* _stdcall GetCurFStyleName(void);

char* _stdcall GetCurSheetName(void);
char* _stdcall GetCurLWidthStg(void);
char* _stdcall GetCurPThickStg(void);
UINT _stdcall GetCurColorNr(void);
UINT _stdcall GetCurNSelected(void);

#endif
