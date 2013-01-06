//////// _FORMST.H - FormSt Packets - FastCAD-32 XP include file //////////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#define RSC(x) ((char *)x) // use this to pass equates in place of addresses

typedef struct 
{
	DWORD					*vadr;	// var adrs/RSCID
	unsigned char	tcode;	// type code
	unsigned char	jcode;	// justification code
	unsigned char	fwid;		// field width
	unsigned char	ndecp;	// decimal places
} ItemFmt;

//	Data type codes for tcode:

#define FT_Ptr	0x80		// pointer to data flag
#define FT_Ent	0x40		// var is offset in current entity
#define FT_EBX	0x20		// var is offset from EBX on entry to FORMST

#define FT_MASK	0x0000001F	// mask for data type code only

#define FT_Stg		0	// ASCIIZ string
#define FT_UDec1	1	// unsigned byte
#define FT_UDec2	2	// unsigned word
#define FT_UDec4	3	// unsigned dword
#define FT_Dec2		4	// signed word
#define FT_Dec4		5	// signed dword
#define FT_Hex1		6	// hex byte
#define FT_Hex2		7	// hex word
#define FT_Hex4		8	// hex dword
#define FT_Real4	9	// dword real
#define FT_Real8	10	// qword real
#define FT_2dC4		11	// 2d dword X,Y dword coordinate
#define FT_2dC8		12	// 2d dword X,Y qword coordinate
#define FT_3dC4		13	// 3d dword X,Y,Z dword coordinate
#define FT_3dC8		14	// 3d dword X,Y,Z qword coordinate
#define FT_Dist4	15	// dword real distance
#define FT_Dist8	16	// qword real distance
#define FT_Brng		17	// dword real bearing angle
#define FT_AngW		18	// dword real angle width
#define	FT_Area4	19	// dword real area
#define	FT_Area8	20	// qword real area

//  Justification codes for jcode:

#define FJ_Var		0	// variable width field
#define FJ_Left		1	// left justified
#define FJ_Cen		2	// center justified
#define FJ_Right	4	// right justified

//  Special handling codes for ndecp:

#define FDP_User	0xFF	// current user-sel # dec place
#define	FDP_Dim		0xFE	// current user-sel dimension # dec pl.

//  Special destination codes for *dest data

#define FD_Prompt	1	// prompt bar
#define FD_TxWin	2	// current text window
#define FD_MsgBox	3	// Message Box (generic, no icons)
#define FD_InfoBox	4	// Info icon message box
#define FD_WarnBox	5	// Warning (! icon) message box
#define FD_ErrorBox	6	// Critical error message box
#define FD_QuestBox	7	// Question (yes/no) message box
#define FD_CancelBox	8	// Yes/No/Cancel message box
#define FD_RetryBox	9	// Retry/Cancel message box
#define FD_DlgInit	10	// Dlg Box title
#define FD_Status	11	// Status bar

#define FormSt _FormSt
int _stdcall FormSt(void *pkt,char *dest);

#define FORMST(_name,_patrn) \
	struct _##_name##tag { char* _szpatrn; } _name = { _patrn };

#define FORMSTPKT(_name,_patrn,_count) \
	struct _##_name##_tag { char* _sz##_name##; ItemFmt _item [_count];}\
	_name = {_patrn, { 

#define ITEMFMT(_var,_ft,_just,_width,_dp) \
	{(DWORD*)&_var,_ft,_just,_width,_dp},

#define FORMSTEND \
}};
