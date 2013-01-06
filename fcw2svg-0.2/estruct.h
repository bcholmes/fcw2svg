#ifndef __ESTRUC_H_
#define __ESTRUC_H_

#pragma pack(1)

#include "geometry.h"
#include "XP/_MATDEF.H"

#define ET_Max		41		// highest entity type #
#define ET_MinI		0x80		// range of valid non-drawing
#define ET_MaxI		0x81		// entities

// 	===============================================================
// 	Structure common to all entity records
// 	(see IBMGR.CPY for EType=0 InfoBlocks - they don't have CStuff)
// 	---------------------------------------------------------------

typedef struct
{
	int	ERLen;		// entity record length
	unsigned char	EType;		// entity type code
	char	EFlags;		// erase/select bits
	char	EFlags2;	// extra flags
	unsigned char	EColor;		// entity color
	unsigned char	EColor2;	// fill (2nd) color
	char	EThick;		// pen thickness 0..25.4 mm
	short	WPlane;		// workplane (0 = XY plane)
	short	ELayer;		// layer
	short	ELStyle;	// line style (0=solid)
	short	GroupID;	// group id (0 = not grouped)
	short	EFStyle;	// fill style (0=hollow)
	float	LWidth;		// line width
	int	Tag;		// entity tag id
} CSTUFF;


#define EF_ERASED	0x80		// (old 5.163 files only!)
#define EF_Mark		0x20		// entity is highlighted
#define EF_NOSL		0x10		// ignore sublist (const SYMREF)

#define EF_CSREF	0x08		// color = color of SYMREF
#define EF_Share	0x04		// shared use flag

#define EF_A1		0x02		// arrow at T=1 end
#define EF_A0		0x01		// arrow at T=0 end

#define EF2_NOUTL   0x01  // no outline on fill


//	===============================================================
//	Entity class flags (returned by ECLASS handler in EAX)
//	===============================================================

//	Bits 0 and 1 specify how many parameters required to describe
//	a point within the entity

#define C_NONE	0x00000		// no point data in entity
#define C_PNT		0x00000		// point data
#define C_LIN		0x00001		// entity is linear (2D/3D line, arc, spline)
#define C_SRF		0x00002		// entity has surface (open cyl, filled poly)
#define C_VOL		0x00003		// entity encloses volume (sphere, solid)

#define C_FILL	0x00004		// bit 2 set=interior is solid or filled
#define C_3D		0x00008		// bit 3 set=3D, clear=2D
#define C_2D		0x00000		// bit 3 set=3D, clear=2D

#define C_CLS		0x00080		// bit 7 set=closed (circle or poly)
#define C_ANN		0x00100		// bit 8 set=annotation only, clear=model
#define C_COMP	0x00200		// bit 9 set=composite entity
#define C_EDGE	0x00400		// bit 10 set = entity supports EEdge svc
#define C_PLACE 0x00800   // supports EPlace

// 	===============================================================
// 	Entity handler support flags (returned by ECLASS handler in EDX)
// 	===============================================================
//
#define H_TRIM		0x00001		// supports trim
#define H_BND		0x00002		// supports bend
#define H_CUT		0x00004		// supports cut
#define H_DYNED		0x00008		// supports graphic edit
#define H_MATH		0x00010		// supports near, tan, t, etc.
#define H_NONE		0x00000		// supports nothing

// 	===============================================================
// 	Point2: 2d point entity
// 	---------------------------------------------------------------

#define ET_POINT2	1		// entity type code
#define C_POINT2	C_PNT
#define H_POINT2	H_NONE

typedef struct
{
	CSTUFF	CStuff;			// entity properties
	GPOINT2	Point;
} POINT2;

// 	---------------------------------------------------------------
// 	Line2: 2D line entity
// 	---------------------------------------------------------------

#define ET_LINE2	2		// entity type code
#define C_LINE2		C_LIN+C_EDGE
#define H_LINE2		H_MATH+H_TRIM+H_CUT

typedef struct
{
	CSTUFF	CStuff;			// entity properties
	GLINE2	Line;
} LINE2;

// 	---------------------------------------------------------------
// 	EType 3: 2D Path/Spline (open or closed) entity data
// 		 Length = overhead+Len(node list)
// 	---------------------------------------------------------------

#define ET_PATH2		3		// entity type code
#define EL_PATH2		Path2.Count	// length without node list
#define C_PATH2			C_LIN+C_EDGE
#define H_PATH2			H_MATH+H_CUT+H_TRIM

#define ET_IDPATH2		31		// future separate entity id #s
#define ET_IDPOLY2		32
#define ET_IDSPLINE2	33
#define ET_IDSPOLY2		34
#define ET_IDBEZIER2	35

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GPATH2  Path;
} PATH2;

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GBOX2  Path;
} BOX2;


// 	Values for Flags
//
// 	NL_CLS		0x80	// 1 = close node list (polygon)
// 	NL_SLD		0x40	// 1 = interior is solid (filled)
// 	NL_2D			0x00	// 2D node list (8 bytes per node)
// 	NL_2DW		0x01	// 2D node list with W parm (12 bytes per node)

// 	Note that SParm..EParm ranges 0..Count-1 for a path
// 	Note that SParm..EParm ranges 0..Count for a poly

// 	Values for Smoother Flags
//
// 	SM_NO		0	// no smoothing
// 	SM_CB		1	// Cubic B-Spline (as in FastCAD 2.x)
// 	SM_PB		2	// Parabolic Blend (through-point)
// 	SM_BZ		3	// Bezier


// 	---------------------------------------------------------------
// 	Etype 4: XP Custom Entity
// 	---------------------------------------------------------------

#define ET_XP			4		// entity type code
#define C_XP			0
#define H_XP			0

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	short		XPId;     // XP ID # for custom entity SVC
	char		XType;    // entity sub-type (if needed)
	char 		XFlags;   // sub-type flags (if needed)
										// xp-specific data starts here
} XPENT;

// 	---------------------------------------------------------------
// 	Etype 5: 2d Text
// 	---------------------------------------------------------------

#define ET_TEXT2	  5               // entity type code
#define EL_TEXT2		sizeof(Txt2)    // entity length (overhead)
#define C_TEXT2			C_PNT+C_ANN+C_EDGE
#define H_TEXT2			H_MATH

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GTEXT2	Text;
}TXT2;

// 	---------------------------------------------------------------
// 	Cir2: 2D Circle entity
// 	---------------------------------------------------------------

#define ET_CIR2			6		// entity type code
#define C_CIR2			C_LIN+C_CLS+C_EDGE
#define H_CIR2			H_MATH+H_CUT

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GCIR2		Circle;
}CIR2;

// 	---------------------------------------------------------------
// 	EType 7: 2D Arc
// 	---------------------------------------------------------------

#define ET_ARC2			7
#define EL_ARC2			sizeof(Arc2)
#define C_ARC2			C_LIN+C_EDGE
#define H_ARC2			H_MATH+H_CUT+H_TRIM

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GARC2		Arc;
}ARC2;

// 	---------------------------------------------------------------
// 	EType 8: 2d Ellipse
// 	---------------------------------------------------------------

#define ET_ELP2			8
#define C_ELP2			C_LIN+C_CLS+C_EDGE
#define H_ELP2			H_MATH+H_CUT

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GELP2		Elp;
}ELP2;

// 	---------------------------------------------------------------
// 	EType 9: 2d Elliptical Arc
// 	---------------------------------------------------------------

#define ET_ELA2			9
#define EL_ELA2			sizeof(ElA2)
#define C_ELA2			C_LIN+C_EDGE
#define H_ElA2			H_MATH+H_CUT

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GELA2		Ela;
}ELA2;

// 	---------------------------------------------------------------
// 	Etype 10: 2d Action Text (HotSpot & its macro text)
// 	---------------------------------------------------------------

#define ET_ACT2		  10               // entity type code
#define EL_ACT2			sizeof(Act2)    // entity length (overhead)
#define C_ACT2			C_PNT+C_ANN+C_EDGE
#define H_ACT2			H_MATH

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GPOINT2	p1;       // lower-left corner of hotspot
	GPOINT2	p2;
	GTEXT2	Text;
}ACT2;


// 	===============================================================
// 	CtrlP: Control Points Entity
// 	===============================================================

#define ET_CTRLP		12		// entity type code
#define C_CTRLP			0
#define H_CTRLP			0

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	
	GPOINT2 P1;			  // ctrl point 1
	GPOINT2 P2;       // ctrl point 2
	GPOINT2 P3;       // ctrl point 3
	DWORD   CFlags;  	// control type flags
	char CText[1];  	// control text
}CTRLP;

// 	Values for CtrlP.CFlags:

#define CP_ALN		 	 1		// align bearing with p1->p2
#define CP_CUT			 2		// cut at p1->p2
#define CP_SCALEY		 4		// scale Y to fit
#define CP_UDSCALE 	 8		// use dyntrak scale
#define CP_OFFSET		16		// offset from place point

//	---------------------------------------------------------------
//	Wall2: 2d wall entity
//	---------------------------------------------------------------

#define ET_WALL2		13		   // entity type code
#define C_WALL2			C_EDGE
#define H_WALL2			H_NONE

typedef struct 					// 2d wall node record
{
	WORD ID;							// node id #
	WORD nSpans;					// # spans connected to this node
	WORD nVisit;					// traversal counter
	GPOINT2 Origin;				// node location
}WALL2N;

typedef struct					// 2d wall node span exit record
{
	WORD ToID;						// exit to node #
	unsigned char Flags;
	float Thickness;			// exit thickness
	float Ang;						// exit angle
	DWORD XData;					// extra data
}WALL2S;


typedef struct
{
	CSTUFF	CStuff;				// entity properties

	WORD    NextID;				// next node id

	WALL2N  WData[0];			// List of nodes goes here
	                     	// ID=0=end of node list
}	WALL2;


//	Values for Wall2S.flags

#define Wall_Exit		1		// span exit has been taken

#define Wall_CF			0		// span is center from
#define Wall_CT			0		// span is center to
#define Wall_LF			4		// span is left from
#define Wall_LT			8		// span is left to
#define Wall_RF			8		// span is right from
#define Wall_RT			4		// span is right to


// 	---------------------------------------------------------------
// 	EType 14:  3D line entity
// 	---------------------------------------------------------------

#define ET_LINE3		14		// entity type code
#define C_LINE3			C_LIN
#define H_LINE3			H_MATH

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	GLINE3	Line;
} LINE3;

// 	---------------------------------------------------------------
// 	EType 15: 3D Path/Spline (open or closed) entity data
// 		 Length = overhead+Len(node list)
// 	---------------------------------------------------------------

#define ET_PATH3		15		// entity type code
#define C_PATH3		equ	C_LIN+C_EDGE+C_3D+C_SAFE
#define H_PATH3		equ	H_MATH3

typedef struct
{
	CSTUFF	CStuff;		// entity properties
// ---------------------------------------------- rest matches GPath2
	char SmType;			// smoother type
	char SRes;				// smoothing resolution
	float SParm;			// start parameter
	float EParm;			// end parameter
					 					// full draw = # nodes-1 if open
					 					//           = # nodes if closed
// ---------------------------------------------- rest matches GNL3
	short Count;			// # nodes in list
	char Flags;				// nodelist control flags
	char unused;			// unused
	GPOINT3 Nodes[0];
}PATH3;

typedef struct
{
	CSTUFF	CStuff;		// entity properties
// ---------------------------------------------- rest matches GPath2
	char SmType;			// smoother type
	char SRes;				// smoothing resolution
	float SParm;			// start parameter
	float EParm;			// end parameter
					 					// full draw = # nodes-1 if open
					 					//           = # nodes if closed
// ---------------------------------------------- rest matches GNL3
	short Count;			// # nodes in list
	unsigned char Flags;				// nodelist control flags
	char unused;			// unused
	GPOINT3 Nodes[3];
}TRI3;

typedef struct
{
	CSTUFF	CStuff;		// entity properties
// ---------------------------------------------- rest matches GPath2
	char SmType;			// smoother type
	char SRes;				// smoothing resolution
	float SParm;			// start parameter
	float EParm;			// end parameter
					 					// full draw = # nodes-1 if open
					 					//           = # nodes if closed
// ---------------------------------------------- rest matches GNL3
	short Count;			// # nodes in list
	char Flags;				// nodelist control flags
	char unused;			// unused
	GPOINT3 Nodes[4];
}RECT3;

// 	Values for Flags
//
// 	NL_CLS		80h	// 1 = close node list (polygon)
// 	NL_SLD		40h	// 1 = interior is solid (filled)
// 	NL_3D			02h	// 3D node list (12 bytes per node)
// 	NL_3DW		03h	// 3D node list with W parm (16 bytes per node)

// 	Note that SParm..EParm ranges 0..Count-1 for a path
// 	Note that SParm..EParm ranges 0..Count for a poly

// 	Values for Smoother Flags
//
// 	SM_NO		0	// no smoothing
// 	SM_CB		1	// Cubic B-Spline (as in FastCAD 2.x)
// 	SM_PB		2	// Parabolic Blend (through-point)
// 	SM_BZ		3	// Bezier
//

// 	---------------------------------------------------------------
// 	EType 17: 2D Multi-poly entity data (header)
// 	---------------------------------------------------------------

#define ET_MPOLY2		17		// entity type code
#define L_MPOLY2		sizeof(MPoly2)	// entity initial overhead
#define C_MPOLY2		C_SRF+C_COMP+C_CLS+C_2D+C_FILL+C_EDGE
#define H_MPOLY2		0		// no math

typedef struct
{
	CSTUFF	CStuff;		// entity properties
	short   MFlags;		// multipoly flags
}MPOLY2;

// 	A multipoly always has a sublist of the entities defining
// 	its edges.

// 	---------------------------------------------------------------
// 	EType 18: 2D Part or Group (header)
// 	---------------------------------------------------------------

#define ET_PART			18		// entity type code
#define L_PART			sizeof(Group)	// entity initial overhead
#define C_PART			0
#define H_PART			0		// no math

typedef struct
{
	CSTUFF	CStuff;		// entity properties
}PART;

// 	A part/group always has a sublist containing the entities
// 	contained in the part/group. This can include nested groups.

// 	When a part/group is unlocked, its entities are given a group
// 	ID # and exploded. This ID # is used to rebuild a group
// 	when it is again locked. This is CStuff.GroupID in
// 	all entities.

// 	---------------------------------------------------------------
// 	Etype 20: DimL2N - New linear dimension entity
// 	---------------------------------------------------------------

#define ET_DIML2N		20		// entity type code
#define C_DIML2N		C_PNT+C_ANN
#define H_DIML2N		0

typedef struct
{
	GPOINT2	p2;     // dimension point 2 (geo end)
	GPOINT2	p4;     // dimension point 4 (arw end 2)
	GPOINT2 TPos;   // forced text position
	float		TValue; // forced dim display value if <>0.0
									// else display dim=Dist2P(P2->P4)
}DIML2SET;

typedef struct
{
	CSTUFF	CStuff;		// entity properties

	short 	DTFont;		// dimension text font ID
	short 	AStyle;		// arrowhead style
	short 	DFlags;		// style flags
	float		DTHgt;		// dimension text height
	float		LdrExt;		// leader extends beyond dimension line
	float		LdrOfs;		// leader offset from geometry
	float		ALen;			// arrowhead length
	float		AHgt;			// arrowhead height
	float		TolP;			// +tolerance
	float		TolM;			// -tolerance
	float		Spacing;	// baseline spacing
	char		DTDecP;		// number of decimal places (0 to 9)
	char		DTFmt;		// prefix stg,0,suffix stg,0
	char		Text[32];   // (room for 31 characters max)

	short		NCount;		// number of dimension sets

	GPOINT2 p1;       // dimension point 1 (geo end)
	GPOINT2 p3;       // dimension point 3 (arw end 1)

	// 	The following DimL2Set repeats for NCount times:

	DIML2SET Sets[1];

}DIML2N;


// 	The following DFlags values are valid for linear dimensions:
// 	(Actual definition is in DStyles.CPY)

#define 	DS2_CEN			0x00	// text centered in dimension line
#define 	DS2_OVR			0x01	// text over dimension line/arc
#define 	DS2_UND			0x02	// text under dimension line/arc
#define 	DS2_LEFT		0x04	// text to left of dim line/arc
#define 	DS2_RIGHT		0x08	// text to right of dim line/arc
#define 	DS2_TXALN		0x10	// 1=dim text aligned/0=always horiz
#define 	DS2_ARWIN		0x20	// force inside arrows
#define 	DS2_TOL			0x40	// specify tolerancing
#define 	DS2_BSP			0x80	// baseline spacing enabled
//
// 	Shared DFlags bit values valid for linear dimensions only:

#define 	DS2_PRL			0x1000	// parallel dimension

// 	---------------------------------------------------------------
// 	Etype 21: DimA2 - NEW angular dimension entity
// 	---------------------------------------------------------------

#define ET_DIMA2N		21		// entity type code
#define C_DIMA2N	C_PNT+C_ANN
#define H_DIMA2N	0

typedef struct
{
	GARC2 Arc;      // Arc data

	float	L2Rad;				// dist to leader 2 start from center
	float	TPosX;				// user-spec text position
						 					// =0FFFFFFFFh if none
	float	TPosY;		
	float	TValue;				// user-fixed value (0.0=none)
 
}DIMA2SET;
	
typedef struct
{
	CSTUFF	CStuff;		// entity properties

	short 	DTFont;		// dimension text font ID
	short 	AStyle;		// arrowhead style
	short 	DFlags;		// style flags
	float		DTHgt;		// dimension text height
	float		LdrExt;		// leader extends beyond dimension line
	float		LdrOfs;		// leader offset from geometry
	float		ALen;			// arrowhead length
	float		AHgt;			// arrowhead height
	float		TolP;			// +tolerance
	float		TolM;			// -tolerance
	float		Spacing;	// baseline spacing
	char		DTDecP;		// number of decimal places (0 to 9)
	char		DTFmt;		// prefix stg,0,suffix stg,0
	char		Text[32];   // (room for 31 characters max)

	float	L1Rad;				// dist to leader 1 start from center
 
	WORD	NCount;		// number of dimension sets
 
// 	The following repeats for NCount sets

	DIMA2SET Sets[1];
 
}DIMA2N;


// 	---------------------------------------------------------------
// 	Etype 22: DimC2N - New Circular dimension entity
// 	---------------------------------------------------------------

#define ET_DIMC2N		22		// entity type code		

#define C_DIMC2N		C_PNT+C_ANN
#define H_DIMC2N		0

typedef struct
{
	CSTUFF	CStuff;		// entity properties

	short 	DTFont;		// dimension text font ID
	short 	AStyle;		// arrowhead style
	short 	DFlags;		// style flags
	float		DTHgt;		// dimension text height
	float		LdrExt;		// leader extends beyond dimension line
	float		LdrOfs;		// leader offset from geometry
	float		ALen;			// arrowhead length
	float		AHgt;			// arrowhead height
	float		TolP;			// +tolerance
	float		TolM;			// -tolerance
	float		Spacing;	// baseline spacing
	char		DTDecP;		// number of decimal places (0 to 9)
	char		DTFmt;		// prefix stg,0,suffix stg,0
	char		Text[32];   // (room for 31 characters max)

	GPOINT2 TPos;			// forced text position 
	float TValue;			// forced display value
 
	GPOINT2 Cen;			// center
	float Radius;			// radius
	float LdrAng;			// leader angle, radians
	float LdrLen;			// leader length (outside of conic)
}DIMC2N;

// 	The following DFlags values are valid for circular dimensions:
// 	(Actual definition is in DStyles.CPY)

// 	DS2_TXALN	equ	10h	// 1=dim text aligned/0=always horiz
// 	DS2_ARWIN	equ	20h	// force inside arrows
// 	DS2_TOL		equ	40h	// specify tolerancing
#define 	DS2_RDCM		0x100	// center mark
#define 	DS2_RDCL		0x200	// center lines
#define 	DS2_SCALE		0x400	// scale dim value by 
// 					// DStyle2.Spacing value

// 	Shared DFlags bit values valid for circular dimensions only:

#define 	DS2_DIA		0x4000	// diameter (else radius)
#define  	DS2_LDR		0x8000	// dimension has a leader


// 	---------------------------------------------------------------
// 	Etype 23: DimO2N - New ordinate dimension entity
// 	---------------------------------------------------------------

#define ET_DIMO2N		23		// entity type code

#define C_DIMO2N	C_PNT+C_ANN
#define H_DIMO2N	0
	
typedef struct
{
	CSTUFF	CStuff;		// entity properties

	short 	DTFont;		// dimension text font ID
	short 	AStyle;		// arrowhead style
	short 	DFlags;		// style flags
	float		DTHgt;		// dimension text height
	float		LdrExt;		// leader extends beyond dimension line
	float		LdrOfs;		// leader offset from geometry
	float		ALen;			// arrowhead length
	float		AHgt;			// arrowhead height
	float		TolP;			// +tolerance
	float		TolM;			// -tolerance
	float		Spacing;	// baseline spacing
	char		DTDecP;		// number of decimal places (0 to 9)
	char		DTFmt;		// prefix stg,0,suffix stg,0
	char		Text[32];   // (room for 31 characters max)

	WORD	nrldrs;		// # leader lines
 
	float	odbsx;				// baseline origin
	float	odbsy;		
	float	odorgl;				// distance to geometry origin
 
// 	For each leader, there is a set of two values:
 
	float	odispx;				// distance from odbsx,odbsy
	float	odispy;				// leader length
 
}DIMO2N;

// 	---------------------------------------------------------------
// 	Etype 28: SYMDEF Symbol Definition
// 	---------------------------------------------------------------

#define ET_SYMDEF		28		// entity type code
#define C_SYMDEF		 0
#define H_SYMDEF	 	 0

typedef struct
{
	CSTUFF CStuff;

	GPOINT3 Low;		// lowest x,y,z extents coordinate
	GPOINT3 Hi;   	// highest x,y,z extents coordinate

	unsigned int Flags;		// options/status flags
	char SName[32];	// ANSIZ symbol name
}SYMDEF;	

// 	---------------------------------------------------------------
// 	Etype 29: SYMREF Symbol Reference
// 	---------------------------------------------------------------

#define ET_SYMREF		29		// entity type code
#define C_SYMREF		0
#define H_SYMREF		0

typedef struct
{
	CSTUFF CStuff;

	GPOINT3 Low;		// lowest x,y,z extents coordinate
	GPOINT3 Hi;   	// highest x,y,z extents coordinate
 
	char SName[32];	// ANSIZ symbol name
	int DefAdr;   // run-time adrs of definition
	SYMTMAT TMat;		// SymDef -> World Coordinates TMAT
}SYMREF;

// 	If a symbol reference has attributes, the attribute
// 	reference entities are contained in a sublist of
// 	the symbol reference entity.

// 	---------------------------------------------------------------
// 	Etype 30: 2d Text Attribute
// 	---------------------------------------------------------------

#define ET_ATRIB2       30              // entity type code
#define EL_ATRIB2       sizeof(ATRIB2)  // entity length (overhead)
#define C_ATRIB2        C_PNT+C_ANN
#define H_ATRIB2        H_MATH
 
typedef struct
{
	CSTUFF CStuff;

	WORD  AtFlags;                // attribute flags
	DWORD TagOfst;                // offset of Tag Text
	DWORD PrmpOfst;               // offset of prompt text
	DWORD ValOfst;						    // offset of Value Text
 
	GTEXT2 Text;
}ATRIB2;

//        Values for Atrib2.AtFlags:

#define AT_NOPRMP       1               // constant value - no prompting
#define AT_HIDDEN       2               // attribute not displayed
#define AT_DSPTAG       4               // always display tag
#define AT_REF          0x8000          // atrib is in SYMREF
#define AT_NOTRAN       8               // no SYMREF transform

//        The Atrib2 header structure is followed by 0 or more
//        ANSIZ text strings, whose offsets from Atrib2.ERLen
//        are stored in TagOfst, ValOfst, and PrmpOfst. The Tag
//        text is stored first if it exists. (The first stored
//        text is displayed when the attribute is drawn outside
//        a symbol reference.) All strings are followed by a 00-NULL
//        end of string list byte.

//        All strings and their terminating NULL bytes, as well as
//        the end of string list byte, are included in the final
//        entity length.

//        When a symbol containing an attribute is inserted,
//        the prompt text is displayed and the data value is
//        entered. The Value text from the original attribute
//        definition is used as the default if no text is entered.
//        The symbol when drawn displays the value text.
//        If no prompt text is specified, the tag text is used as
//        a prompt.

//        If Atrib2.AtFlags has the AT_DSPTAG flag set, the attribute
//        always displays the tag next instead of the value text.

//        If Atrib2.AtFlags has the AT_NOPRMP flag set, the value
//        specified in the attribute definition is used and no
//        prompting occurs.

//        If Atrib2.AtFlags has the AT_HIDDEN flag set, no attribute
//        text is displayed in the SYMBOL REFERENCE.

//        Attributes in SYMDEFs are copied/included_in each SYMREF,
//        with the VALUE text first, (from default/entry etc.).
//        These copies are drawn in place of the Attributes in the SYMDEF.

// 	===============================================================
// 	EType 31..36: Reserved for change to path poly id #s
// 	---------------------------------------------------------------

// 	---------------------------------------------------------------
// 	Etype 40: XREF Definition
// 	---------------------------------------------------------------

#define ET_XREF			40		// entity type code

#define C_XREF			0
#define H_XREF			0

typedef struct
{
	CSTUFF CStuff;

	DWORD  XFlags;			// XREF flags (not used yet)
	void  *hDList;		  // handle to the Drawing List

	SYMTMAT TMat;		    // SymDef -> World Coordinates TMAT

	char FileName[1];   // source file name
}XREF;

// 	===============================================================
// 	Etype 41: SHEET Container Entity
// 	===============================================================

#define ET_SHEET		41			// entity type code
#define C_SHEET			0
#define H_SHEET			0

#define SHT_CUR			1					// 1 = sheet is current
#define SHT_VIS			2					// 2 = sheet is visible
#define SHT_NEW			0x40000		// 4 = new add (for cancel)

typedef struct
{
	CSTUFF CStuff;

	DWORD Status;				// Sheet status flags			= 	SHT_VIS
											// hi word = save for cancel of low word
						 					// valid flag bits are low word only
	char SName[64];			// sheet name
}SHEET;


// 	===============================================================
// 	Non-Drawing Entities - EType 80h ..0FFh
// 	===============================================================
// 	PASM: Print Assembly Main Entity Structure
// 	---------------------------------------------------------------
#define PAVer			0		// Structure Revision #
#define ET_PASM			80h		// entity type code


// 	===============================================================
// 	NOTE: Note entity structure
// 	===============================================================
#define NoteVer			0		// structure version #

#define ET_NOTE			0x81		// entity type code

typedef struct
{
	CSTUFF CStuff;

	unsigned char Version;		// version #
	unsigned char flags;			// options flags

	char NName[32];						// Note Name

	char NData[1];							// note data (ANSIZ multiline)
}NOTE;

// 	---------------------------------------------------------------
// 	Sublist Markers
// 	---------------------------------------------------------------
// 	An entity that has a sublist of entities has the sublist
// 	stored on disk immediately following its owner entity.
// 	It starts with a Marker 0 record, followed by the entities
// 	in the sublist, and ends with a Marker 1 entity.
//
// 	Note that this is only when the data is stored in a file
// 	image. When the drawing is in memory, sublists are accessed
// 	through sublist functions.
// 	---------------------------------------------------------------
//
// 	Mark0		struc			// sublist start marker
// 	ERLen		dword	5
// 	MType		db	0
// 	Mark0		ends
//
// 	Mark1		struc			// sublist end marker
// 	ERLen		dword	5
// 	MType		db	1
// 	Mark1		ends
//
///////////////////// Entrec definition ///////////////////////////////

#ifndef USING_CUSTOM_ENTITIES
typedef union
{
	CSTUFF CStuff;
	POINT2 Point;
	LINE2  Line;
	PATH2  Path;
	XPENT  XPEnt;
	TXT2   Txt;
	CIR2	 Cir;
	ARC2   Arc;
	ELP2   Elp;
	ELA2   ElA;
	ACT2   Act;
	MPOLY2 MPoly;
	PART	 Part;
	DIML2N DimL2N;
	DIMA2N DimA2N;
	DIMC2N DimC2N;
	DIMO2N DimO2N;
	SYMREF SymRef;
	SYMDEF SymDef;
	ATRIB2 Atrib;
	SHEET Sheet;
	CTRLP CtrlP;
	WALL2 Wall;
	NOTE Note;
	XREF XRef;
	LINE3 Line3;
	PATH3 Path3;
} *pENTREC;

#endif

// Macro to allocate space for structures that have dynamic length.
// Examples:
// 
//   A path named pPath with 4 nodes:    ESTRUC(PATH2, pPath, 4*8);
//   A text named pText with 12 chars:   ESTRUC(TEXT2, pText, 12);
//

#define ESTRUC(_Type, _Name, _ExtraBytes)  \
		  char _##_Name##Memory[sizeof(_Type)+_ExtraBytes]; \
			_Type *_Name = (_Type *)_##_Name##Memory;


#pragma pack()

#endif