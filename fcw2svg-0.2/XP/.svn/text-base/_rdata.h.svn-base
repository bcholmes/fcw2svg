///////// _RDATA.H - RDATA Packets - FastCAD-32 XP include file ///////////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

typedef void (_stdcall *PRCVPROC)(int Result,int Result2,int Result3);
typedef void (_stdcall *PVERPROC)(void);
typedef void (_stdcall *PCTXTPROC)(void);

#define DYNCSR2(x) ((DWORD) x)

typedef struct tagRDATA{
DWORD		len;		// length of structure
char		dtype;		// RD_xxx data type
PCMDPROC	RBProc;		// right button pressed procedure
DWORD		flags;		// RDF_xxx options flags
DWORD		*dadr;		// data store address (0=don't)
DWORD		*prmp;		// prompt FormSt packet
DWORD		CsrProc;	// RDC_xxx cursor type code
PRCVPROC	RcvProc;	// Data Receive Procedure
PVERPROC	XDta;		// extra data (verify data proc)
PCTXTPROC	CtxtProc;	// context procedure [F2]
DWORD		HelpNum;	// Help context id
DWORD		*HelpFile;	// Help file name
DWORD		keysink;	// 0 = prompt line	
} RDATA;

//  Data type codes for RDATA.dtype:

#define RD_2DC		0	// 2d coordinate
#define RD_Real4	1	// real value
#define RD_TxWord	2	// text string (line if RDF_SPACEOK)
#define RD_Pick		3	// std entity selection (no return data)
#define RD_Pick1	4	// single entity esi->entity, edi->pk point
 				//  entity can NOT be on frozen layer
#define RD_Win		5	// 2 -2d coord, lower left pt,
 				//    then upper right (like GLine2)
 				//    points have been sorted.
#define RD_Disp		6	// Real distance displacement
 				// returns DeltaX,DeltaY 2d cordinate
#define RD_Int2		7	// signed word number
#define RD_Int4		8	// signed dword number
#define RD_Dist		9	// real drawing distance REAL4 value
#define RD_Brng		10	// bearing angle in radians, 0 right, ccw+
#define RD_AngW		11	// Angle width in radians, ccw+
#define RD_Scale	12	// real4 scale factor
#define RD_PickRef	13	// single entity esi->entity, edi->pk point
 				//  entity can be on frozen layer
#define RD_Color	14	// dword color number (0..255)
#define RD_Layer	15	// dword layer ID #
#define RD_LStyle	16	// dword line style id #
#define RD_FStyle	21	// dword fill style id #
#define RD_3DC		30	// 3d coordinate
#define RD_Win2			22	// 2nd point of RD_Win (1st provided)
#define RD_PickI		23	// RD_Pick, but R/O is ok
 
#define RD_3dC			30	// 3d coordinate
#define RD_Disp3		31	// 3d distance displacement
								 				// returns DeltaX, DeltaY, DeltaZ coordinate
#define RD_Win3			32	// 3d window, lowest X,Y,Z the highest X,Y,Z
#define RD_Dist3		33	// real drawing distance REAL4 value
#define RD_Win23		34	// 3d window, start at 2nd point

// 	Following are for systems window mgmt only:

#define RD_DWinC		19	// main screen window placement
#define RD_DWinID		20	// select window id #

// CsrProc standard cursor codes:

#define RDC_NONE	0	// no visible csr
#define RDC_ARROW	1	// arrow
#define RDC_WAIT	2	// hourglass
#define RDC_XH		3	// real 2d crosshairs
#define RDC_RBAND	4	// real 2d rubberband
#define RDC_WIN		5	// real window cursor
#define RDC_PICK	6	// entity select cursor
#define RDC_XHOPT	7	// crosshairs IF required
#define RDC_FINGER	8	// finger cursor
#define RDC_XH3		9	// real 3d crosshairs
#define RDC_RBAND3	10	// real 3d rubberband
#define RDC_DEPTH3	11	// real 3d depth mode cursor

// Flag values for RDATA.flags:

#define RDF_NONE	0		// no flags
#define RDF_NOVARX	0x0010	// no variable expansion
//					0x0020	// reserved (FT_EBX)
//					0x0040	// reserved (FT_Ent)
//					0x0080	// reserved (FT_Ptr)
#define RDF_NOLOCK	0x0100	// snap/ortho prohibited
							// (RDF_NOLOCK overrides RDF_ORTHO)
#define RDF_ORTHO	0x0200	// ortho lock allowed
#define RDF_ALOCK	0x0400	// angle-lock desired
#define RDF_SPACEOK	0x0800	// spaces are data, not delim
#define RDF_LIVE	0x1000	// live-input until DAV
#define RDF_LIVEDLY	0x2000	// postpone live until end of script
#define RDF_1OK		0x4000	// ok to return just 1 real
#define RDF_RBPROP	0x8000	// RT btn = win properties
#define RDF_SAMEX	0x10000	// use prior X
#define RDF_SAMEY	0x20000	// use prior Y
#define RDF_SAMEZ	0x40000	// use prior Z
#define RDF_FRZOK	0x80000	// read only - frozen ok
#define RDF_NOORTHO	0x100000  // no ortho but snap ok
#define RDF_NOATCH	0x200000  // no attach allowed
#define RDF_KEEPSC	0x400000  // if script data, ; not change to CR
#define RDF_ATCHCSR	0x800000  // add pick box to cursor (mod attach)
#define RDF_MUSTORTHO 0x1000000 // force ortho on for this point
#define	RDF_C		  0x2000000	// callbacks are C functions

//	Data valid codes sent to RcvProc
 
#define X_OK		0	// EAX = 0 if data ok
#define X_DFLT		1	// EAX = 1 if data default
#define X_CAN		2	// EAX = 2 if data cancel
#define X_BAD		3	// EAX = 3 if data bad
#define X_ONE		4	// EAX = 4 if only 1 val of 2 or 3
	 			//    must set RDF_1OK to get this

#define ReqData _ReqData
void _stdcall ReqData(RDATA *pkt);

#define NewCsrOrg _NewCsrOrg
void _stdcall NewCsrOrg(float x, float y);

#define AbortEdit _AbortEdit
void _stdcall AbortEdit();

//////////////////////////////////////////////////////////////////////////
//	DYNTRAK definitions
//////////////////////////////////////////////////////////////////////////

typedef struct tagDPAK{
float		CsrX;		// current cursor position
float		CsrY;
float		CsrZ;
float		X;		// object origin
float		Y;
float		Z;
float		LastX;		// last cursor position
float		LastY;
float		LastZ;
float		RotXY;		// object rotation
float		RotYZ;
float		RotZX;
float		AngW;		// Angle Width
float		Dist;		// Object height or distance moved
float		ScaleX;		// Object scale
float		ScaleY;
float		ScaleZ;
int		ScrX;		// screen pixel coordinates
int		ScrY;
char		DynFlag;	// flags
char		PendRotF;	// pending rotation flag
char		AllowOp;	// allowed operations
char		DynDflt;	// default operations
} DPAK;

typedef DPAK* pDPAK;
 
#define DN_Hgt		1	// Get height when CTRL key down
#define DN_Rot		2	// Get rotation when CTRL-SHIFT key down
#define	DN_Drag		4	// Get position when SHIFT key down
#define	DN_Dist		8	// Get distance when control key down
#define	DN_AngW		16	// Get Angle Width
#define	DN_Scale	32	// Get scale factor
#define	DN_First	128	// Flag first dynamic cursor call

#define InitDynTrak _InitDynTrak
void _stdcall InitDynTrak(float X,float Y,float S,float RXY, int Allow,int Default);
#define DynTrak _DynTrak
pDPAK _stdcall DynTrak(float X,float Y, int ScrnX, int ScrnY);
