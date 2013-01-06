#ifndef _MYSVC_H_
#define _MYSVC_H_

#ifndef NO_FABS
double fabs(double);
#endif

char CarrySet(void);

void SwapPt(GPOINT2 *P1, GPOINT2 *P2);
void SwapFloat(float *F1, float *F2);
void SwapInt(int *I1, int *I2);

// Ex-functions

float AngleEx(GPOINT2 *p1, GPOINT2 *p2);
float Dist2PEx(GPOINT2 *p1, GPOINT2 *p2);
void NewCsrOrgEx(GPOINT2 *Pt);
void PConvEx(GPOINT2 *Pt,float dist, float angle, GPOINT2 *Res);
float DistP2LEx(GPOINT2 *Pt, GLINE2* pNearTo);
void NearPL2Ex(GPOINT2 *Pt,GLINE2* pNearTo, GPOINT2* pResult);
void SetEachPickViewEx(GPOINT2 *Pt);
pENTREC ECut2Ex(pENTREC pEntRec, GPOINT2 *Pt);
BOOL ENearT2Ex(pENTREC pEntRec, GPOINT2 *Pt, int flag, float* pResult);
void TRNP2Ex(GPOINT2 *Pt);
void SetStretchViewEx(GPOINT2 *p1, GPOINT2 *p2);
void SetStretchViewEx2(GLINE2 *l);

DWORD MarkChangedEx(DWORD **pDwgChanged);

// For compatibility

#define IBlkSVC _IBlkSVC
void IBlkSVC(int IBlk, int Service, void *Address);

#define DsAbCtl _DsAbCtl
void DsAbCtl(int Ctl);

// New

#define GetLstStrN _GetLstStrN
BOOL _stdcall GetLstStrN(int Control, int ItemNr, char *Str);

// Custom dialog boxes

#define AllocTool _AllocTool
#define DevUseOwnerDraw _DevUseOwnerDraw
#define DevUseRepaint _DevUseRepaint
#define DevUseColor _DevUseColor
#define DevUseColorE _DevUseColorE
#define DevUseBkColor _DevUseBkColor
#define DevSRect _DevSRect
#define DevHRect _DevHRect
#define DrawButton _DrawButton
#define DevVText _DevVText
#define DevCText _DevCText
#define DevSLine _DevSLine
#define SetODView _SetODView
#define SetBMView _SetBMView

#define TranP2 _TranP2
#define	TrnTxt2 _TrnTxt2
#define XCheckP2 _XCheckP2
#define XCheckTx2 _XCheckTx2
#define SCkP2 _SCkP2
#define PkLine2 _PkLine2
#define PkPath2 _PkPath2
#define PkCir2 _PkCir2
#define PkElp2 _PkElp2
#define PkPoint2 _PkPoint2
#define RectNotInPkWin _RectNotInPkWin

#define GetLSName _GetLSName
#define GetFSName _GetFSName
#define GetLStyleNr _GetLStyleNr
#define FindFSAdr _FindFSAdr

#define Tx2Len _Tx2Len
#define Tx2BoxExt _Tx2BoxExt
#define Tx2Box _Tx2Box

#define SetWinPickView _SetWinPickView

#define GetOpenPath _GetOpenPath
#define FullFileName _FullFileName
#define EDraw1 _EDraw1
#define GetFontName _GetFontName
#define DevFont _DevFont
#define ExecScriptCopy _ExecScriptCopy
#define IntLE2 _IntLE2
#define GetFStyleNr _GetFStyleNr
#define InsSymRef _InsSymRef
#define FindNearInt _FindNearInt
#define ECalTtoS _ECalTtoS
#define ECalStoT _ECalStoT
#define StMatch _StMatch
#define FExist _FExist
#define StType _StType
#define StCopy _StCopy

#define RListInit _RListInit
#define RListPush _RListPush
#define RListRmv _RListRmv

#define SetRectView _SetRectView
#define PkTxt2 _PkTxt2

int  XPCALL AllocTool(int Dist, void *pTool, void *pCtrl, void *pTake);
void XPCALL DevUseOwnerDraw(LPDRAWITEMSTRUCT lpdis);
void XPCALL DevUseRepaint(HDC hDC, HWND hWnd);
DWORD XPCALL DevUseColor(int Color);
DWORD XPCALL DevUseColorE(int Color);
void XPCALL DevUseBkColor(int Color);
void XPCALL DevSRect(RECT *Rect);
void XPCALL DevHRect(RECT *Rect);
void XPCALL DrawButton(BTN *Btn);
void XPCALL DevVText(char *Text, RECT *Rect);
void XPCALL DevCText(char *Text, RECT *Rect);
void XPCALL DevSLine(RECT *Rect);
void XPCALL SetODView(GPOINT2 *Low, GPOINT2 *High, LPDRAWITEMSTRUCT lpdis);
void XPCALL SetBMView(GPOINT2 *Low, GPOINT2 *High, RECT *Rect);

void XPCALL TranP2(GPOINT2 *Pt);
void XPCALL _TrnTxt2(GTEXT2 *Txt);
void XPCALL XCheckP2(GPOINT2 *Pt);
void XPCALL _XCheckTx2(GTEXT2 *Txt);
BOOL XPCALL SCkP2(GPOINT2 *Pt);
BOOL _stdcall PkPoint2(GPOINT2 *Pt);
BOOL _stdcall PkLine2(GLINE2 *Line);
BOOL _stdcall PkPath2(GPATH2 *Path);
BOOL _stdcall PkCir2(GCIR2 *Cir);
BOOL _stdcall PkElp2(GELP2 *Elp);
BOOL _stdcall RectNotInPkWin(GPOINT2 *Low, GPOINT2 *High);


extern "C"
{
	void _stdcall ClearCursors(void);
	void _stdcall DevUsePrior(void);
	void _stdcall DStyleCmd2(void);
	void _stdcall DevSetDraw(void);
	void _stdcall DevSetXOR(void);

	void _stdcall SnapOn(void);
	void _stdcall SnapOff(void);
	void _stdcall GridOn(void);
	void _stdcall GridOff(void);
	void _stdcall OrthoOn(void);
	void _stdcall OrthoOff(void);

	int _stdcall DevGetState(void);
}

char *XPCALL GetLSName(int ID);
char *XPCALL GetFSName(int ID);
int   XPCALL GetLStyleNr(char *S);
int   XPCALL FindFSAdr(char *S);

float XPCALL Tx2Len(GTEXT2 *p);
GNLIST2 *XPCALL Tx2BoxExt(GTEXT2 *p);
GNLIST2 *XPCALL Tx2Box(GTEXT2 *p);

void XPCALL SetWinPickView(GPOINT2 *P1, GPOINT2 *P2);

char XPCALL GetOpenPath(char *Title, GETFN *GetFN);
char *XPCALL FullFileName(char *InFile, char *OutFile);

void XPCALL EDraw1(pENTREC pEntRec);

char *XPCALL GetFontName(int Number);

HGDIOBJ XPCALL DevFont(HGDIOBJ Number);
void XPCALL ExecScriptCopy(char *s);

int XPCALL IntLE2(GLINE2 *Line, GELP2 *Elp, GPOINT2 *Ints);
int XPCALL GetFStyleNr(char *Name);

int XPCALL UpdGrid(void);

void XPCALL InsSymRef(SYMDEF *pSym, hDLIST hDList);

int XPCALL FindNearInt(pENTREC p1, pENTREC p2, GPOINT2 *Pt);
float ECalTtoS(pENTREC pEntRec, float S);
float ECalStoT(pENTREC pEntRec, float T);

BOOL XPCALL StMatch(char *Pattern, char *Str);

BOOL XPCALL FExist(char *pFileName);
void XPCALL StType(char *pExt, char *pFileName);
int XPCALL StCopy(char *pSource, char *pDest);

BOOL XPCALL RListInit(RECSTACK *pStack, int Count);
BOOL XPCALL RListPush(RECSTACK *pStack, void *pRec);
BOOL XPCALL RListRmv(RECSTACK *pStack, int AtAdr);

void XPCALL SetRectView(float LowX, float LowY, float HighX, float HighY, RECT *pRect);
BOOL XPCALL _PkTxt2(GTEXT2 *pText);

#endif
