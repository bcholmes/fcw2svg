//  ===============================================================
//  DSTYLES2.CPY - New Dimension Style Data Structures & Macros
//  ===============================================================

//  Copyright 1997 Evolution Computing
//  All rights reserved
//  Written by Mike Riddle 6-12-97

//  ===============================================================
//  New Dimension Style Structure - included in Dim Entity Records
//  ===============================================================

#ifndef _DSTYLES_H_
#define _DSTYLES_H_

typedef struct
{
  short DTFont;			// dimension text font ID
  short AStyle;     // arrowhead style
  short DFlags;     // style flags
  float DTHgt;			// dimension text height
  float LdrExt;     // leader extends beyond dimension line
  float LdrOfs;     // leader offset from geometry
  float ALen;       // arrowhead length
  float AHgt;       // arrowhead height
  float TolP;       // +tolerance
  float TolM;       // -tolerance
  float Spacing;    // spacing (unused at present)
  char  DTDecP;     // number of decimal places (0 to 9)
  char  DTFmt[33];  // prefix stg,0,suffix stg,0
                    // (room for 31 characters max)
  char  DSName[32]; // Dim Style name (31 chrs max)
}DSTYLE2;

//  DFlags word: General drawing control flags

#define DS2_CEN			  0x00  // text centered in dimension line
#define DS2_OVR			  0x01  // text over dimension line/arc
#define DS2_UND			  0x02  // text under dimension line/arc
#define DS2_LEFT		  0x04  // text to left of dim line/arc
#define DS2_RIGHT		  0x08  // text to right of dim line/arc
							              // code depends on the above exact values
									          // (DStyle2:PosChange)(EDimC2-DoText:)
#define DS2_TXALN		  0x10  // 1=dimension text aligned/0=always horiz
#define DS2_ARWIN		  0x20  // force inside arrows (DimC only)
#define DS2_TOL			  0x40  // specify tolerancing
#define DS2_ACAD		  0x80	// dim source = AutoCAD
#define DS2_RDCM		 0x100  // center mark
#define DS2_RDCL		 0x200  // center lines
#define DS2_SCALE		 0x400  // scale dim value by DStyle2.Spacing value
#define DS2_TXONLY   0x800  // prefix/suffix text only - no dimvalue

//  Shared DFlags bit values valid for linear dimensions only:

#define DS2_PRL			0x1000  // parallel dimension

//  Shared DFlags bit values valid for linear dimensions only:

#define DS2_L1			0x1000  // has starting leader
#define DS2_L2			0x2000  // has ending leader

//  Shared DFlags bit values valid for circular dimensions only:

#define DS2_DIA			0x4000  // diameter (else radius)
#define DS2_LDR			0x8000  // dimension has a leader

//  Shared DFlags bit values valid for ordinate dimensions only:

#define DS2_VBase		0x0000  // vertical baseline
#define DS2_HBase		0x1000  // horizontal baseline
#define DS2_NDelta  0x2000  // negative At-Org delta
#define DS2_ODShift     12  // shift to put hbase/vbase/ndelta
                            // at bits 1 & 2

//  ===============================================================
//  DSTYIB2: New Dimension Styles Information block header
//  ===============================================================

#define CurDSTYIBVer2		 5   // current version #
										         // ver 5 added CurDSNr to ver 4

typedef struct
{
	int   ERLen;			// std info block header =SIZEOF(DSTYIB2)
	char  EType;	  	// EType = Info Block  	= ET_IB
	char  IType;			// IB type = IB_DSTYLE
	short Creator;		// XPID (0=core)
	int   AllocLen;	 	// allocation length (0=ERLen)
	short IBVer;			// DSTYIB version id
	short CurDSNr;	  // current DStyle #

	DSTYLE2 CurDS[1];	  // Current DStyle settings
}DSTYIB2;


#endif

