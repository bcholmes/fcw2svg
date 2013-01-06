
#include <windows.h>
extern "C"
{
	#pragma warning( disable : 4200 )  
  #include <xp.h>
}

extern "C"
{

int _stdcall FindNearInt(void);
void _stdcall ECalTtoS(void);
void _stdcall ECalStoT(void);
int _stdcall GetLstStrN(void);

void _stdcall AllocTool(void);
void _stdcall DevUseOwnerDraw(void);
void _stdcall DevUseRepaint(void);
DWORD _stdcall DevUseColor(void);
DWORD _stdcall DevUseColorE(void);
void _stdcall DevUseBkColor(void);
void _stdcall DevSRect(void);
void _stdcall DevHRect(void);
void _stdcall DrawButton(void);
void _stdcall DevVText(void);
void _stdcall DevCText(void);
void _stdcall DevSLine(void);
void _stdcall SetODView(void);
void _stdcall SetBMView(void);

void _stdcall TranP2(void);
void _stdcall TrnTxt2(void);

void _stdcall XCheckP2(void);
void _stdcall	XCheckTx2(void);
void _stdcall SCkP2(void);
void _stdcall PkPoint2(void);
void _stdcall PkLine2(void);
void _stdcall PkPath2(void);
void _stdcall PkCir2(void);
void _stdcall PkElp2(void);

void _stdcall GetLSName(void);
void _stdcall GetFSName(void);
void _stdcall GetLStyleNr(void);
void _stdcall FindFSAdr(void);

void _stdcall Tx2Len(void);
void _stdcall Tx2Box(void);
void _stdcall Tx2BoxExt(void);

void _stdcall SetWinPickView(void);

void _stdcall GetOpenPath(void);	
char *_stdcall FullFileName(void);
void _stdcall EDraw1(void);
void _stdcall GetFontName(void);
void *_stdcall DevFont(void);
void _stdcall ExecScriptCopy(void);

int _stdcall IntLE2(void);
int _stdcall GetFStyleNr(void);
void _stdcall InsSymRef(void);
int _stdcall FindNearInt(void);

int _stdcall StMatch(void);
void _stdcall StType(void);
void _stdcall StCopy(void);
void _stdcall FExist(void);

void _stdcall RListInit(void);
void _stdcall RListPush(void);
void _stdcall RListRmv(void);

void _stdcall SetRectView(void);
void _stdcall PkTxt2(void);

void _stdcall IBlkSVC(void);
void _stdcall DsAbCtl(void);

}

char CarrySet(void)
{
	__asm jc CarrySet_True;
	return FALSE;	 
CarrySet_True:;
	return TRUE;
}

void SwapPt(GPOINT2 *P1, GPOINT2 *P2)
{
	GPOINT2 Pt;

	Pt=*P1;
	*P1=*P2;
	*P2=Pt;
}

void SwapFloat(float *F1, float *F2)
{
	float Ft;

	Ft=*F1;
	*F1=*F2;
	*F2=Ft;
}

void SwapInt(int *I1, int *I2)
{
	int It;

	It=*I1;
	*I1=*I2;
	*I2=It;
}

//////////// Ex-functions /////////////////////////////

float AngleEx(GPOINT2 *p1, GPOINT2 *p2)
{
	return Angle(p1->x, p1->y, p2->x, p2->y);
}

float Dist2PEx(GPOINT2 *p1, GPOINT2 *p2)
{
	return Dist2P(p1->x, p1->y, p2->x, p2->y);
}

void NewCsrOrgEx(GPOINT2 *Pt)
{
	NewCsrOrg(Pt->x, Pt->y);
}

void PConvEx(GPOINT2 *Pt,float dist, float angle, GPOINT2 *Res)
{
	PConv(Pt->x, Pt->y, dist, angle, Res);
}

float DistP2LEx(GPOINT2 *Pt, GLINE2* pNearTo)
{
	return DistP2L(Pt->x, Pt->y, pNearTo);
}

void NearPL2Ex(GPOINT2 *Pt, GLINE2* pNearTo, GPOINT2* pResult)
{
	NearPL2(Pt->x, Pt->y, pNearTo, pResult);
}

void SetEachPickViewEx(GPOINT2 *Pt)
{
	SetEachPickView(Pt->x, Pt->y);
}

pENTREC ECut2Ex(pENTREC pEntRec, GPOINT2 *Pt)
{
	return ECut2(pEntRec, Pt->x, Pt->y);
}

BOOL ENearT2Ex(pENTREC pEntRec, GPOINT2 *Pt, int flag, float* pResult)
{
	return ENearT2(pEntRec, Pt->x, Pt->y, flag, pResult);
}

void TRNP2Ex(GPOINT2 *Pt)
{
	TRNP2(Pt->x, Pt->y, Pt);
}

void SetStretchViewEx(GPOINT2 *p1, GPOINT2 *p2)
{
	SetStretchView(p1->x, p1->y, p2->x, p2->y);
}

void SetStretchViewEx2(GLINE2 *l)
{
	SetStretchView(l->p1.x, l->p1.y, l->p2.x, l->p2.y);
}

//		SVC	MarkChanged		// save prior dwg changed
//		mov	pDwgChanged,edx
//		mov	PriorDwgChanged,eax

DWORD MarkChangedEx(DWORD **pDwgChanged)
{
	DWORD PriorValue;
	DWORD *pAddress;

	PriorValue=MarkChanged();

	__asm mov pAddress, edx;

	if(pDwgChanged)
		*pDwgChanged=pAddress;

	return PriorValue;
}

//////////////////////////////////////////////////////////

//// Stuff to include in the toolkit (here in meanwhile)


//int _stdcall GetColorNr(void);
/*
int _GetColorNr(void)
{
	int Color;
	
	Color=GetColorNr();
	__asm jc GetColorNrNone;
	return Color;
GetColorNrNone:
	return -1;
}
*/
void _IBlkSVC(int IBlk, int Service, void *Address)
{
	__asm mov eax, IBlk;
	__asm mov ebx, Service;  
	__asm mov esi, Address;
	
	IBlkSVC();
}

void _DsAbCtl(int Ctl)
{
	__asm mov eax, Ctl;
	DsAbCtl();
}

#ifdef VIEWER

int XPCALL AddLayer(char *LayerName)
{
	return 1;
}

#endif

#ifdef EASYCAD

int XPCALL AddLayer(char *LayerName)
{
	LYRIB *Layers;
	LAYER *OL;

	struct
	{
		int RLen;						// 																= sizeof(LAYER)
		short ID;						// layer ID word
		short flags;					// layer status flags
		short ParentID;				// -1 = leaf, else ID of parent layer
		char LName[256];			// ANSIZ layer name (var length)
	}NL;

	if((NL.ID=GetLayerNr(LayerName))<255)
	{
		lstrcpy(NL.LName, LayerName);

		NL.RLen=11+lstrlen(NL.LName);
		NL.ParentID=-1;
		NL.flags=0;

		Layers=GetIBlk(IB_LAYER);
		SizeIBlk(IB_LAYER, Layers->ERLen+NL.RLen);
		Layers=GetIBlk(IB_LAYER);
		Layers->ERLen+=NL.RLen;
		NL.ID=Layers->NextID++;
		for(OL=Layers->Layers; OL->RLen!=0; OL=(LAYER *)((DWORD)OL+OL->RLen))
					;
		CopyMemory(OL, &NL, NL.RLen);
		OL=(LAYER *)((DWORD)OL+OL->RLen);
		OL->RLen=0;

		_IBlkSVC(IB_LAYER, 3, Layers);
	}
	GetHeaderAdr()->Layer=NL.ID;
	UpdScreenTools();

	return NL.ID;
}

#endif


BOOL _stdcall _GetLstStrN(int Control, int ItemNr, char *s)
{
	__asm mov eax, Control;
	__asm mov ecx, ItemNr;
	__asm mov esi, s;
	return GetLstStrN();
}



////////////////////////////////////////////////////////////

int XPCALL _AllocTool(int Dist, void *pTool, void *pCtrl, void *pTake)
{
	__asm mov	eax, Dist;		
	__asm mov	ebx, pTool;
	__asm mov esi, pCtrl;
	__asm mov edi, pTake;
	AllocTool();
	return CarrySet();
}

void XPCALL _DevUseOwnerDraw(LPDRAWITEMSTRUCT lpdis)
{
	__asm mov edi, lpdis;
	DevUseOwnerDraw();
}

void XPCALL _DevUseRepaint(HDC hDC, HWND hWnd)
{
	__asm mov eax, hDC;
	__asm mov ecx, hWnd;
	DevUseRepaint();
}

DWORD XPCALL _DevUseColor(int Color)
{
	__asm mov eax, Color;
	return DevUseColor();
}

DWORD XPCALL _DevUseColorE(int Color)
{
	__asm mov eax, Color;
	return DevUseColorE();
}

void XPCALL _DevUseBkColor(int Color)
{
	__asm mov eax, Color;
	DevUseBkColor();
}

void XPCALL _DevSRect(RECT *Rect)
{
	__asm mov esi, Rect;
	DevSRect();
}

void XPCALL _DevHRect(RECT *Rect)
{
	__asm mov esi, Rect;
	DevHRect();
}

void XPCALL _DrawButton(BTN *Btn)
{
	__asm mov esi, Btn;
	DrawButton();
}

void XPCALL _DevVText(char *Text, RECT *Rect)
{
	__asm mov esi, Text;
	__asm mov edi, Rect;
	DevVText();
}

void XPCALL _DevCText(char *Text, RECT *Rect)
{
	__asm mov esi, Text;
	__asm mov edi, Rect;
	DevCText();
}

void XPCALL _DevSLine(RECT *Rect)
{
	__asm mov esi, Rect;
	DevSLine();
}

void XPCALL _SetODView(GPOINT2 *Low, GPOINT2 *High, LPDRAWITEMSTRUCT lpdis)
{
	float fTmp;
	
	fTmp=Low->x;    __asm fld fTmp;
	fTmp=Low->y;    __asm fld fTmp;
	fTmp=High->x;   __asm fld fTmp;
	fTmp=High->y;   __asm fld fTmp;
	__asm mov esi, lpdis;

	SetODView();
}

void XPCALL _SetBMView(GPOINT2 *Low, GPOINT2 *High, RECT *Rect)
{
	float fTmp;
	
	fTmp=Low->x;    __asm fld fTmp;
	fTmp=Low->y;    __asm fld fTmp;
	fTmp=High->x;   __asm fld fTmp;
	fTmp=High->y;   __asm fld fTmp;
	__asm mov esi, Rect;

	SetBMView();
}

void XPCALL _TranP2(GPOINT2 *Pt)
{
	__asm mov esi, Pt;
	TranP2();
}

void XPCALL _TrnTxt2(GTEXT2 *Txt)
{
	__asm mov esi, Txt;
	TrnTxt2();
}

void XPCALL _XCheckP2(GPOINT2 *Pt)
{
	__asm mov esi, Pt;
	XCheckP2();
}

void XPCALL _XCheckTx2(GTEXT2 *Txt)
{
	__asm mov esi, Txt;
	XCheckTx2();
}


BOOL XPCALL _SCkP2(GPOINT2 *Pt)
{
	__asm mov esi, Pt;
	SCkP2();
	return CarrySet();
}

BOOL _stdcall _PkPoint2(GPOINT2 *Pt)
{
	__asm mov esi, Pt;
	PkPoint2();
	return CarrySet();
}

BOOL _stdcall _PkLine2(GLINE2 *Line)
{
	__asm mov esi, Line;
	PkLine2();
	return CarrySet();
}

BOOL _stdcall _PkPath2(GPATH2 *Path)
{
	__asm mov esi, Path;
	PkPath2();
	return CarrySet();
}

BOOL _stdcall _PkCir2(GCIR2 *Cir)
{
	__asm mov esi, Cir;
	PkCir2();
	return CarrySet();
}

BOOL _stdcall _PkElp2(GELP2 *Elp)
{
	__asm mov esi, Elp;
	PkElp2();
	return CarrySet();
}


char *_stdcall _GetLSName(int ID)
{
	char *rc;

	__asm mov eax, ID;
	GetLSName();
	__asm mov rc, esi;
	return CarrySet() ? NULL : rc;
}

char *_stdcall _GetFSName(int ID)
{
	char *rc;

	__asm mov eax, ID;
	GetFSName();
	__asm mov rc, esi;
	return CarrySet() ? NULL : rc;
}

int _stdcall _GetLStyleNr(char *S)
{
	int ID;

	__asm mov esi, S;
	GetLStyleNr();
	__asm mov ID, eax;
	return CarrySet() ? -1 : ID;
}

int _stdcall _FindFSAdr(char *S)
{
	FSTY *ID;

	__asm mov esi, S;
	FindFSAdr();
	__asm mov ID, edi;
	return CarrySet() ? -1 : ID->ID;
}

float _stdcall _Tx2Len(GTEXT2 *p)
{
	float L;

	__asm mov esi, p;
	Tx2Len();
	if(!CarrySet())
	{
		__asm fstp L;
		return L;
	}

	return -1;
}

GNLIST2 *_stdcall _Tx2Box(GTEXT2 *p)
{
	GNLIST2 *Rc;

	__asm mov esi, p;
	Tx2Box();
	if(!CarrySet())
	{
		__asm mov Rc, esi;
		return Rc;
	}
	return NULL;
}

GNLIST2 *_stdcall _Tx2BoxExt(GTEXT2 *p)
{
	GNLIST2 *Rc;

	__asm mov esi, p;
	Tx2BoxExt();
	if(!CarrySet())
	{
		__asm mov Rc, esi;
		return Rc;
	}
	return NULL;
}


void _stdcall _SetWinPickView(GPOINT2 *P1, GPOINT2 *P2)
{
	float tmp;
	tmp=P1->x; __asm fld tmp;
	tmp=P1->y; __asm fld tmp;
	tmp=P2->x; __asm fld tmp;
	tmp=P2->y; __asm fld tmp;

	SetWinPickView();
}


char _stdcall _GetOpenPath(char *Title, GETFN *GetFN)
{
  __asm mov esi, Title;
  __asm mov edi, GetFN;
  GetOpenPath();
  return !CarrySet();
}

char *_stdcall _FullFileName(char *InFile, char *OutFile)
{
	char *Name;

	__asm mov esi, InFile;
	__asm mov edi, OutFile;
	Name=FullFileName();
	return !CarrySet() ? Name : NULL;
}

void _stdcall _EDraw1(pENTREC pEntRec)
{
	__asm mov esi, pEntRec;
	EDraw1();
}

char *_stdcall _GetFontName(int Number)
{
	char *Name;

	__asm mov eax, Number;
	GetFontName();
	__asm mov Name, esi;

	return CarrySet() ? NULL : Name;
}

HGDIOBJ _stdcall _DevFont(HGDIOBJ Number)
{
	__asm mov eax, Number;
	return DevFont();
}

void _stdcall _ExecScriptCopy(char *s)
{
	__asm mov esi, s;
	ExecScriptCopy();
}

int _stdcall _IntLE2(GLINE2 *Line, GELP2 *Elp, GPOINT2 *Ints)
{
	__asm mov esi, Line;
	__asm mov edi, Elp;
	__asm mov ebx, Ints;
	return IntLE2();
}


// Name = NULL will trigger dialog
int _stdcall _GetFStyleNr(char *Name)
{
	int rc;

	__asm mov esi, Name;
	rc=GetFStyleNr();

	return CarrySet() ? -1 : rc;
}

void _stdcall _InsSymRef(SYMDEF *pSym, hDLIST hDList)
{
	__asm mov esi, pSym;
	__asm mov edi, hDList;
	InsSymRef();
}


int XPCALL _FindNearInt(pENTREC p1, pENTREC p2, GPOINT2 *Pt)
{
	GPOINT2 *pPt;

	__asm mov esi, p1;
	__asm mov edi, p2;
	__asm mov ebx, Pt;
	FindNearInt();
	__asm mov pPt, ebx;

	if(!CarrySet())
	{
		*Pt=*pPt;
		return TRUE;
	}
	return FALSE;
}

float _ECalTtoS(pENTREC pEntRec, float S)
{
	__asm mov esi, pEntRec;
	__asm fld S;
	ECalTtoS();
	if(!CarrySet())
		__asm fstp S;

	return S;
}


float _ECalStoT(pENTREC pEntRec, float T)
{
	__asm mov esi, pEntRec;
	__asm fld T;
	ECalStoT();
	if(!CarrySet())
		__asm fstp T;

	return T;
}

#ifndef EASYCAD
#ifndef VIEWER
BOOL XPCALL _StMatch(char *pPattern, char *pStr)
{
	__asm mov esi, pPattern;
	__asm mov edi, pStr;

	return StMatch();
}
#else
BOOL XPCALL _StMatch(char *pPattern, char *pStr)
{
	return FALSE;
}
#endif
#endif

void XPCALL _StType(char *pExt, char *pFileName)
{
	__asm mov esi, pExt;
	__asm mov edi, pFileName;

	StType();
}

BOOL XPCALL _FExist(char *pFileName)
{
	__asm mov esi, pFileName;

	FExist();

	return !CarrySet();
}

int XPCALL _StCopy(char *pSource, char *pDest)
{
	int Count;

	__asm mov esi, pSource;
	__asm mov edi, pDest;

	StCopy();

	__asm mov Count, ecx;

	return Count;
}

// 	RListInit - Initialize Record List
// 	---------------------------------------------------------------
// 	Entry:	ESI -> Record List Structure
// 		ECX =  max # of bytes in RList
// 	Exit:	Carry SET if unable to initialize (not enough memory)

BOOL XPCALL _RListInit(RECSTACK *pStack, int Count)
{
	__asm mov esi, pStack;
	__asm mov ecx, Count;

	RListInit();

	return !CarrySet();
}

// 	RListPush - Push Record to Record List
// 	---------------------------------------------------------------
// 	Entry:	ESI -> Record List Structure
// 		EDI -> Record to push
// 	Exit:	Carry SET if unable to push

BOOL XPCALL _RListPush(RECSTACK *pStack, void *pRec)
{
	__asm mov esi, pStack;
	__asm mov edi, pRec;

	RListPush();

	return !CarrySet();
}

// 	RListRmv - Remove Record from Record List
// 	---------------------------------------------------------------
// 	Entry:	ESI -> Record List Structure
// 		EBX = position in list of record to remove (AtAdr)
// 	Exit:	Carry SET if unable to remove (empty or invalid record)

BOOL XPCALL _RListRmv(RECSTACK *pStack, int AtAdr)
{
	__asm mov esi, pStack;
	__asm mov ebx, AtAdr;

	RListRmv();

	return !CarrySet();
}

void _stdcall _SetRectView(float LowX, float LowY, float HighX, float HighY, RECT *pRect)
{
	__asm fld LowX;
	__asm fld LowY;
	__asm fld HighX;
	__asm fld HighY;
	__asm mov esi, pRect;
	SetRectView();
}

BOOL XPCALL _PkTxt2(GTEXT2 *pText)
{
	__asm mov esi, pText;
	PkTxt2();
	
	return CarrySet();
}
