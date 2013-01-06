/////////////////////////////////////////////////////
#define SHEET void
//#include <windows.h>
//#include <xp.h>

#include <Extend/MySvc.c>
// External functions

#undef ENearT2
#undef IntL2
#undef IntLC2
#undef IntCC2
#undef Angle
#undef Dist2P
#undef QKeyShift
#undef QKeyCtrlShift
#undef QKeyCtrl
#undef RscAdr
#undef DPath2
#undef GetIBlk
#undef RegIBlk
#undef SizeIBlk
#undef DelIBlk
#undef ReadIBlk
#undef RestoreIBlk
//#undef IBlkSVC
#undef GetHeaderAdr
#undef AskLayerHidden
#undef AskLayerFrozen
#undef GetLayerName
#undef GetLayerNr
#undef InfoBox
#undef WarnBox
#undef ErrorBox
#undef QuestBox
#undef RetryBox
#undef CancelBox
#undef MsgBox
#undef GetOpenFN
#undef GetSaveFN
#undef SIN
#undef COS
#undef RND
#undef NewTag
#undef PointOnLine
#undef TEdit
#undef GetTextSpecs
#undef GetTextSpecsAlt
#undef AddCmbStr
#undef AddLstStr
#undef ClrCmbStr
#undef ClrDefBtn
#undef ClrLstStr
#undef Dlog
#undef DsAbCtl
#undef EnAbCtl
#undef FndCmbStr
#undef FndLstStr
#undef FocusCtl
#undef GetCmbStr
#undef GetCmbStrN
#undef GetLstDta
#undef GetLstStr
#undef GetLstStrN
#undef HideCtl
#undef RstCmbStr
#undef RstLstStr
#undef SelEdCtl
#undef SetCtlText
#undef SetDefBtn
#undef SetDlgTitle
#undef SetLstDta
#undef ShowCtl
#undef UpdCtl
#undef SetCmbDta
#undef GetCmbDta
#undef SetDlgOwner
#undef LoadFile
#undef SaveFile
#undef AllocMem
#undef RelMem
#undef ResizeMem
#undef CloneMem
#undef InsertBytes
#undef RemoveBytes
#undef ResizeBytes
#undef FindAllInts
#undef ENearT2
#undef StatusMsg
#undef ExecScriptStg
#undef RMGetValue
#undef RMSetValue

int  _stdcall IntL2(void);
int  _stdcall IntLC2(void);
int  _stdcall IntCC2(void);
void _stdcall Angle(void);
void _stdcall Dist2P(void);
void _stdcall QKeyShift(void);
void _stdcall QKeyCtrlShift(void);
void _stdcall QKeyCtrl(void);
void _stdcall RscAdr(void);
void _stdcall DPath2(void);
void _stdcall GetIBlk(void);
void _stdcall RegIBlk(void);
void _stdcall SizeIBlk(void);
void _stdcall DelIBlk(void);
void _stdcall ReadIBlk(void);
void _stdcall RestoreIBlk(void);
//void _stdcall IBlkSVC(void);
void _stdcall GetHeaderAdr(void);
void _stdcall AskLayerHidden(void);
void _stdcall AskLayerFrozen(void);
void _stdcall GetLayerName(void);
void _stdcall GetLayerNr(void);

void _stdcall InfoBox(void);
void _stdcall WarnBox(void);
void _stdcall ErrorBox(void);
int  _stdcall QuestBox(void);
int  _stdcall RetryBox(void);
int  _stdcall CancelBox(void);
void _stdcall MsgBox(void);

void _stdcall GetOpenFN(void);
void _stdcall GetSaveFN(void);

void _stdcall SIN(void);
void _stdcall COS(void);
void _stdcall RND(void);

void _stdcall NewTag(void);
void _stdcall PointOnLine(void);
void _stdcall TEdit(void);
void _stdcall GetTextSpecs(void);
void _stdcall GetTextSpecsAlt(void);

void _stdcall AddCmbStr(void);
int  _stdcall AddLstStr(void);
void _stdcall ClrCmbStr(void);
void _stdcall ClrDefBtn(void);
void _stdcall ClrLstStr(void);
void _stdcall Dlog(void);
void _stdcall DsAbCtl(void);
void _stdcall EnAbCtl(void);
void _stdcall FndCmbStr(void);
void _stdcall FndLstStr(void);
void _stdcall FocusCtl(void);
void _stdcall GetCmbStr(void);
void _stdcall GetCmbStrN(void);
void _stdcall GetLstDta(void);
void _stdcall GetLstStr(void);
void _stdcall GetLstStrN(void);
void _stdcall HideCtl(void);
void _stdcall RstCmbStr(void);
void _stdcall RstLstStr(void);
void _stdcall SelEdCtl(void);
void _stdcall SetCtlText(void);
void _stdcall SetDefBtn(void);
void _stdcall SetDlgTitle(void);
void _stdcall SetLstDta(void);
void _stdcall ShowCtl(void);
void _stdcall UpdCtl(void);
void _stdcall SetCmbDta(void);
void _stdcall GetCmbDta(void);
void _stdcall SetDlgOwner(void);

int  _stdcall LoadFile(void);
void _stdcall SaveFile(void);
void _stdcall AllocMem(void);
void _stdcall RelMem(void);
void _stdcall ResizeMem(void);
void _stdcall CloneMem(void);
void _stdcall InsertBytes(void);
void _stdcall RemoveBytes(void);
void _stdcall ResizeBytes(void);

void _stdcall FindAllInts(void);
void _stdcall ENearT2(void);
void _stdcall StatusMsg(void);
void _stdcall ExecScriptStg(void);
void _stdcall RMGetValue(void);
void _stdcall RMSetValue(void);

/////////////////////////////////////////////////////
/*
char CarrySet(void)
{
	__asm jc CarrySet_True;
	return FALSE;
CarrySet_True:;
	return TRUE;
}

*/
int _stdcall _IntL2(GLINE2 *Line1, GLINE2 *Line2, GPOINT2 *Cross)
{
	__asm mov esi, Line1;
	__asm mov edi, Line2;
	__asm mov ebx, Cross;
	return IntL2();
}

int _stdcall _IntLC2(GLINE2 *Line, GCIR2 *Circle, GPOINT2 *Cross)
{
	__asm mov esi, Line;
	__asm mov edi, Circle;
	__asm mov ebx, Cross;
	return IntLC2();
}

int _stdcall _IntCC2(GCIR2 *Cir1, GCIR2 *Cir2, GPOINT2 *Cross)
{
	__asm mov esi, Cir1;
	__asm mov edi, Cir2;
	__asm mov ebx, Cross;
	return IntCC2();
}


char _stdcall _QKeyShift(void)
{
	QKeyShift();
	return CarrySet();
}

char _stdcall _QKeyCtrlShift(void)
{
	QKeyCtrlShift();
	return CarrySet();
}

char _stdcall _QKeyCtrl(void)
{
	QKeyCtrl();
	return CarrySet();
}

void *_stdcall _RscAdr(void *RSC)
{
	void *RAdr;
	__asm mov esi, RSC;
	RscAdr();
	__asm mov RAdr, esi
	return RAdr;
}	

void *_stdcall _GetIBlk(int IBlk)
{
	void *rc;
	
	__asm mov eax, IBlk;
	GetIBlk();
	__asm mov rc, esi;
	return CarrySet() ? NULL : rc;
}

char _stdcall _RegIBlk(int IBlk, void *Adr)
{
	__asm mov eax, IBlk;
	__asm mov esi, Adr;   // Ska inte skickas med!!!
	GetIBlk();
	return CarrySet();
}


char _stdcall _SizeIBlk(int IBlk, int NewSize)
{

	__asm mov eax, IBlk;
	__asm mov ecx, NewSize;
	
	SizeIBlk();
	return CarrySet();
}

char _stdcall _DelIBlk(int IBlk)
{

	__asm mov eax, IBlk;
	
	DelIBlk();
	return CarrySet();
}

char _stdcall _ReadIBlk(char *Address)
{

//	__asm mov eax, IBlk;
	__asm mov esi, Address;
	
	ReadIBlk();
	return CarrySet();
}

char _stdcall _RestoreIBlk(char *Address)
{

//	__asm mov eax, IBlk;
	__asm mov esi, Address;
	
	RestoreIBlk();
	return CarrySet();
}
/*
void _stdcall _IBlkSVC(int IBlk, int Service, void *Address)
{
	__asm mov eax, IBlk;
	__asm mov ebx, Service;  
	__asm mov esi, Address;
	
	IBlkSVC();
}
*/
HDR *_stdcall _GetHeaderAdr(void)
{
	void *rc;

	GetHeaderAdr();
	__asm mov rc, esi;
	return rc;
}

char _stdcall _AskLayerHidden(int Layer)
{
	__asm mov eax, Layer;
	AskLayerHidden();
	return CarrySet();
}
char _stdcall _AskLayerFrozen(int Layer)
{
	__asm mov eax, Layer;
	AskLayerFrozen();
	return CarrySet();
}

char *_stdcall _GetLayerName(int Layer)
{
	char *rc;

	__asm mov eax, Layer;
	GetLayerName();
	__asm mov rc, esi;
	return CarrySet() ? NULL : rc;
}

int _stdcall _GetLayerNr(char *LayerName)
{
	int Layer;

	__asm mov esi, LayerName;
	GetLayerNr();
	__asm mov Layer, eax;
	return CarrySet() ? -1 : Layer;
}

void _stdcall _InfoBox(char *Text)
{
	__asm mov esi, Text;
	InfoBox();
}

void _stdcall _WarnBox(char *Text)
{
	__asm mov esi, Text;
	WarnBox();
}

void _stdcall _ErrorBox(char *Text)
{
	__asm mov esi, Text;
	ErrorBox();
}

int  _stdcall _QuestBox(char *Text)
{
	__asm mov esi, Text;
	return QuestBox();
}

int  _stdcall _RetryBox(char *Text)
{
	__asm mov esi, Text;
	return RetryBox();
}

int  _stdcall _CancelBox(char *Text)
{
	__asm mov esi, Text;
	return CancelBox();
}

void _stdcall _MsgBox(char *Text, char *Title)
{
	__asm mov esi, Text;
	__asm mov edi, Title;

	MsgBox();
}

char _stdcall _GetOpenFN(char *Title, GETFN *GetFN)
{
	__asm mov esi, Title;
	__asm mov edi, GetFN;
	GetOpenFN();
	return CarrySet();
}

char _stdcall _GetSaveFN(char *Title, GETFN *GetFN)
{
	__asm mov esi, Title;
	__asm mov edi, GetFN;
	GetSaveFN();
	return CarrySet();
}


float _stdcall _Cos(float Deg)
{
	float rc;

	__asm fld Deg;
	COS();
	__asm fstp rc;

	return rc;
}

float _stdcall _Sin(float Deg)
{
	float rc;

	__asm fld Deg;
	SIN();
	__asm fstp rc;

	return rc;
}

float _stdcall _Rnd(float Increment, float Value)
{
	float rc;

	__asm fld Increment;
	__asm fld Value;
	RND();
	__asm fstp rc;

	return rc;
}

void _stdcall _NewTag(CSTUFF *CStuff)
{
	__asm mov esi, CStuff;
	NewTag();
}

char _stdcall _PointOnLine(GPOINT2 *Pt, GLINE2 *Line)
{
	float A;

	A = Pt->x;	__asm fld A;
	A = Pt->y;	__asm fld A;
	
	__asm mov esi, Line;
	PointOnLine();

	return CarrySet();
}

//	---------------------------------------------------------------
//	TDLG packet for SVC TEdit (Text-edit)   - from dialog.cpy
//	---------------------------------------------------------------

typedef struct
{
	DWORD TxtAdr;		// ->Text to edit
	DWORD MaxChar;  // max bytes
	DWORD Flags;		// see below
	DWORD TtlAdr;		// ->title string (0="Edit Text")
	DWORD HelpID;		// help context # (0=contents pg)
	DWORD HelpFile;	// ->help file name (0=ours)
}TDLG;

//	TDLG Flags:
#define TE_SEL		0x0001	// auto-select text window contents
                          // Remaining flags	assume lpBuild->entity with text geometry after CStuff
#define TE_PROP		0x0010	// properties button (uses tspec dialog to edit text properties of entity)
#define TE_FILE		0x0020	// file button (forces entity flag to TD_FILE, gets file name via openfile)

char _stdcall _TEdit(void *TextAdr, DWORD MaxLength, DWORD Flags)
{
	// No local variables since we call this from 
	TDLG EditText = {(DWORD)TextAdr, MaxLength, Flags, 0, 0, 0}, 
	     *pEditText=&EditText;

	__asm mov esi, pEditText;
  TEdit();
	return !CarrySet();
}

// Text should point to short font which is followed by GTEXT2
void _stdcall _GetTextSpecs(void *Text)  
{
	__asm mov esi, Text;
	GetTextSpecs();
}

// Text should point to short font which is followed by GTEXT2
char _stdcall _GetTextSpecsAlt(void *Text)  
{
	__asm mov esi, Text;
	GetTextSpecsAlt();
	return CarrySet();
}

//void _stdcall AddCmbStr(void);
int _stdcall _AddLstStr(int Control, char *Text)
{
	__asm mov eax, Control;
	__asm mov esi, Text;
	return AddLstStr();
}
//void _stdcall ClrCmbStr(void);
//void _stdcall ClrDefBtn(void);
void _stdcall _ClrLstStr(int Control)
{
	__asm mov eax, Control;
	ClrLstStr();
}
//void _stdcall Dlog(void);
//void _stdcall DsAbCtl(void);
//void _stdcall EnAbCtl(void);
//void _stdcall FndCmbStr(void);
//void _stdcall FndLstStr(void);
void _stdcall _FocusCtl(int Control)
{
	__asm mov eax, Control;
	FocusCtl();
}
//void _stdcall GetCmbStr(void);
//void _stdcall GetCmbStrN(void);
//void _stdcall GetLstDta(void);
//void _stdcall GetLstStr(void);
//void _stdcall GetLstStrN(void);
//void _stdcall HideCtl(void);
//void _stdcall RstCmbStr(void);
void _stdcall _RstLstStr(int Control)
{
	__asm mov eax, Control;
	RstLstStr();
}

//void _stdcall SelEdCtl(void);
//void _stdcall SetCtlText(void);
//void _stdcall SetDefBtn(void);
//void _stdcall SetDlgTitle(void);
//void _stdcall SetLstDta(void);
//void _stdcall ShowCtl(void);
void _stdcall _UpdCtl(int Control)
{
	__asm mov eax, Control;
	UpdCtl();
}
//void _stdcall SetCmbDta(void);
//void _stdcall GetCmbDta(void);
//void _stdcall SetDlgOwner(void);

void * _stdcall _LoadFile(char *FileName)
{
	int Count;
	char *Adr;
	__asm mov esi, FileName;
	Adr=(char *)LoadFile();
	__asm mov Count, ecx;
	return CarrySet() ? NULL : Adr;
}
char _stdcall _SaveFile(char *FileName, char *Buffer, int Count)
{
	__asm mov esi, Buffer;
	__asm mov edi, FileName;
	__asm mov ecx, Count;
	SaveFile();
	return CarrySet();
}

void *_stdcall _AllocMem(int Count)
{
	void *rc;

	__asm mov eax, Count;
	AllocMem();
	__asm mov rc, esi;

	return CarrySet() ? NULL : rc;
}

char _stdcall _RelMem(void *Adr)
{
	__asm mov esi, Adr;
	RelMem();
	return CarrySet();
}

void *_stdcall _ResizeMem(void *Adr, int NewSize)
{
	void *rc;

	__asm mov esi, Adr;
	__asm mov eax, NewSize;
	ResizeMem();
	__asm mov rc, esi;

	return CarrySet() ? NULL : rc;
}

void *_stdcall _CloneMem(void *Adr)
{
	void *rc;

	__asm mov esi, Adr;
	CloneMem();
	__asm mov rc, esi;

	return CarrySet() ? NULL : rc;
}


int _stdcall _FindAllInts(pENTREC p1, pENTREC p2, GPOINT2 **Ints)
{
	int rc;
	GPOINT2 *tInts;

	__asm mov esi, p1;
	__asm mov edi, p2;
	FindAllInts();
	__asm jc FindAllIntsDone;
	__asm mov rc, eax;
	__asm mov tInts, ebx;
	*Ints=tInts;
	return rc;
FindAllIntsDone:
	return 0;
}
/*
char _stdcall _ENearT2(pENTREC pEntRec, float X, float Y, int Typ, float *T)
{
	float fTmp;

	__asm fld X;
	__asm fld Y;
	__asm mov eax, Typ;
	__asm mov esi, pEntRec;
	ENearT2();
	if(CarrySet())
		return TRUE;
	__asm fstp fTmp;
	*T=fTmp;
	return FALSE;
}
*/

void _stdcall _StatusMsg(void *Adr)
{
	__asm mov esi, Adr;
	StatusMsg();
}

void _stdcall _ExecScriptStg(char *Adr)
{
	__asm mov esi, Adr;
	ExecScriptStg();
}
						  
void _stdcall _RMGetValue(REGKEY *Pkt)
{
	__asm mov esi, Pkt;
	RMGetValue();
}

void _stdcall _RMSetValue(REGKEY *Pkt)
{
	__asm mov esi, Pkt;
	RMSetValue();
}


