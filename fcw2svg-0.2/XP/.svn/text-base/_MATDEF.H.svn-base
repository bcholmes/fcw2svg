//	================================================================
// 	MATDEF.CPY - Transform Matrix Definitions
// 	================================================================
//
// 	Copyright (C) 1988-1995 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 2/6/88
// 	Revised 11-6-91 for FCAD 3.0
// 	Ken Hill: Added TSPEC2 structure 1/22/93
// 	Susan Montooth: Win32 mods 10/27/95
//


// 	----------------------------------------------------------------
// 	The 2D Transform matrix is fit inside the general 3D matrix:
//
// 	M11 | M12 |  xx |  0		Note that no 2D transforms
// 	----|-----|-----|----		will change column 4 values.
// 	M21 | M22 |  xx |  0		The transform routines take
// 	----|-----|-----|----		advantage of this.
// 	 xx |  xx |  xx | xx
// 	----|-----|-----|----
// 	M41 | M42 |  xx |  1
//
// 	symbols only need to store the 1st 3 columns as the
// 	4th column will always be [ 0 0 0 1] in a symbol.
// 	----------------------------------------------------------------

#ifndef _MATDEF_H_
#define _MATDEF_H_

#define MatSiz		64		// matrix size in bytes
#define PMatSiz		48		// 4 rows x 3 columns partial size

typedef struct  		// identity matrix is default
{
	float m11;    		// first column
	float m21;
	float m31;
	float m41;
	float m12;		    // second column
	float m22;
	float m32;
	float m42;
	float m13;    		// third column
	float m23;
	float m33;
	float m43;
	float m14;		    // fourth column
	float m24;
	float m34;
	float m44;
}TMAT;

typedef struct    	// SYMBOL TMat (last always [0 0 0 1])
{
	float m11;    		// first column
	float m21;
	float m31;
	float m41;
	float m12;    		// second column
	float m22;
	float m32;
	float m42;
	float m13;		    // third column
	float m23;
	float m33;
	float m43;
}SYMTMAT;


typedef struct
{
	float ScaleX;			// scale x by factor
	float ScaleY;			// scale y by factor (negative if mirrored)
	float ShearYX;		// shear y to vector ShearYX,ShearYY
	float ShearYY;
	float Rotate;
	float DeltaX;			// move by DeltaX, DeltaY
	float DeltaY;
}TSPEC2;

typedef struct
{
	float ScaleX;			// scale x by factor
	float ScaleY;			// scale y by factor (negative if mirrored)
	float ScaleZ;
	float ShearYX;		// shear y to vector ShearYX,ShearYY
	float ShearYY;
	float ShearYZ;
	float RotXY;			// rotate planes
	float RotYZ;
	float RotZX;
	float DeltaX;			// move by DeltaX, DeltaY
	float DeltaY;
	float DeltaZ;
}TSPEC3;

// 	3d CTM components in terms of a 2D work plane
typedef struct
{
	float RZX;				// Rotations in various planes
	float RYZ;
	float RXY;
	float OrgX;				// work plan origin in space
	float OrgY;
	float OrgZ;
	float ScaleX;			// scale x by factor
	float ScaleY;			// scale y by factor (negative if mirrored)
	float ShearYX;		// shear y to vector ShearYX,ShearYY
	float ShearYY;
}WPSPEC;

#define SYMDEEP		32	// depth of nested symbol stack

#endif
