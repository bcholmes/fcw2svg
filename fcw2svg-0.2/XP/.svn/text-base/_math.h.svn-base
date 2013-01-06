//////////////////// _MATH.H - FastCAD-32 XP include file ////////////////
//
//	Written by Mike Riddle 5-25-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATH_H_
#define _MATH_H_

#define M_PI   ((float)3.1415926535)
#define M_PI_2 ((float)3.1415926535/2)
#define M_PI_D 3.1415926535

#define Dist2P _Dist2P
float _stdcall Dist2P(float x1,float y1,float x2, float y2);
#define Angle _Angle
float _stdcall Angle(float x1,float y1,float x2, float y2);
#define ANorm _ANorm
float _stdcall ANorm(float Ang);
#define PConv _PConv
void _stdcall PConv(float x1,float y1,float dist, float angle, GPOINT2* pResult);
#define NearPL2 _NearPL2
void _stdcall NearPL2(float x1,float y1,GLINE2* pNearTo, GPOINT2* pResult);
#define DistP2L _DistP2L
float _stdcall DistP2L(float x1,float y1,GLINE2* pNearTo);

#define FNSame _FNSame
BOOL _stdcall FNSame(float* p1, float* p2);
#define FNSame2 _FNSame2
BOOL _stdcall FNSame2(GPOINT2* p1, GPOINT2* p2);
#define FNSame3 _FNSame3
BOOL _stdcall FNSame3(GPOINT3* p1, GPOINT3* p2);


//	----------------------------------------------------------------
//	The 2D Transform matrix is fit inside the general 3D matrix:
//
//	M11 | M12 |  xx |  0		Note that no 2D transforms
//	----|-----|-----|----		will change column 4 values.
//	M21 | M22 |  xx |  0		The transform routines take
//	----|-----|-----|----		advantage of this.
//	 xx |  xx |  xx | xx
//	----|-----|-----|----
//	M41 | M42 |  xx |  1
//
//	symbols only need to store the 1st 3 columns as the
//	4th column will always be [ 0 0 0 1] in a symbol.
//	----------------------------------------------------------------

typedef struct tagTM{
float	m11;
float	m21;
float	m31;
float	m41;
float	m12;
float	m22;
float	m32;
float	m42;
float	m13;
float	m23;
float	m33;
float	m43;
float	m14;
float	m24;
float	m34;
float	m44;
} TM;

typedef struct tagSTM{
float	m11;
float	m21;
float	m31;
float	m41;
float	m12;
float	m22;
float	m32;
float	m42;
float	m13;
float	m23;
float	m33;
float	m43;
} STM;

typedef TMAT* pTM;
typedef SYMTMAT* pSTM;

#define CTMI2 _CTMI2
void _stdcall CTMI2(void);
#define CTMPSH _CTMPSH
void _stdcall CTMPSH(void);
#define CTMPOP _CTMPOP
void _stdcall CTMPOP(void);
#define QNUCTM _QNUCTM
BOOL _stdcall QNUCTM(void);
#define LDCTM _LDCTM
void _stdcall LDCTM(pTM pArgTM);
#define STCTM _STCTM
void _stdcall STCTM(pTM pArgTM);
#define LDSymTM _LDSymTM
void _stdcall LDSymTM(pSTM pArgTM);
#define STSymTM _STSymTM
void _stdcall STSymTM(pSTM pArgTM);
#define UseSymTM _UseSymTM
void _stdcall UseSymTM(pSTM pArgTM);
#define TrnSymTM _TrnSymTM
void _stdcall TrnSymTM(pSTM pArgTM);
#define PREMUL2 _PREMUL2
void _stdcall PREMUL2(pTM pArgTM);
#define CTMMUL2 _CTMMUL2
void _stdcall CTMMUL2(pTM pArgTM);
#define MATTRN2 _MATTRN2
void _stdcall MATTRN2(pTM pArgTM, pTM pResult);
#define MATTRN2 _MATTRN2
void _stdcall MATTRN2(pTM pArgTM, pTM pResult);
#define CTMSPC2	_CTMSPC2
TSPEC2 * _stdcall CTMSPC2(void);

#define CTMT2 _CTMT2
void _stdcall CTMT2(float DispX, float DispY);
#define CTMR2 _CTMR2
void _stdcall CTMR2(float RXY);
#define CTMS2 _CTMS2
void _stdcall CTMS2(float ScaleX, float ScaleY);
#define CTMSHX2 _CTMSHX2
BOOL _stdcall CTMSHX2(float VX, float VY);
#define CTMSHY2 _CTMSHY2
BOOL _stdcall CTMSHY2(float VX, float VY);

#define PRET2 _PRET2
void _stdcall PRET2(float DispX, float DispY);
#define PRER2 _PRER2
void _stdcall PRER2(float RXY);
#define PRES2 _PRES2
void _stdcall PRES2(float ScaleX, float ScaleY);
#define PRESHX2 _PRESHX2
BOOL _stdcall PRESHX2(float VX, float VY);
#define PRESHY2 _PRESHY2
BOOL _stdcall PRESHY2(float VX, float VY);

#define TRNP2 _TRNP2
void _stdcall TRNP2(float X, float Y, GPOINT2* pResult);
#define TRNBA2 _TRNBA2
float _stdcall TRNBA2(float BA);
#define TRNDA2 _TRNDA2
void _stdcall TRNDA2(float Dist, float Ang, GPOINT2* pResult);
#define TRNEP2 _TRNEP2
void _stdcall TRNEP2(float Incl, float Ecc, float Radius, GPOINT3* pResult);

#define Sin _Sin
float _stdcall Sin(float Radians);
#define Cos _Cos
float _stdcall Cos(float Radians);
#define Tan _Tan
float _stdcall Tan(float Radians);
#define ATan2 _ATan2
float _stdcall ATan2(float X,float Y);
#define ASin _ASin
float _stdcall ASin(float Val);
#define ACos _ACos
float _stdcall ACos(float Val);
#define ATan _ATan
float _stdcall ATan(float Val);
#define Deg _Deg
float _stdcall Deg(float Radians);
#define Rad _Rad
float _stdcall Rad(float Degrees);
#define Rnd _Rnd
float _stdcall Rnd(float Increment, float Value);

#endif
