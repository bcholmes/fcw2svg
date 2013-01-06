//  ================================================================================
//  IHeightMap.h - Height Map Object Interface
//  --------------------------------------------------------------------------------
//  Copyright © 2011 Evolution Computing, Inc.
//  All Rights Reserved
//  --------------------------------------------------------------------------------
//	A height map is an X * Y array, like a bitmap, where each value
//	represents a height rather than a pixel color. Each value is a float.
//	Initially after loading, values range from 0..0xffff for 16-bit data, and
//	0..0xff for 8-bit data sources.

//	The data can be offset and ranged as desired
//	Normalized height maps have values ranging from 0.0 to 1.0 for low to high
//  ================================================================================
#ifndef _IHEIGHTMAP_H
#define _IHEIGHTMAP_H

//	==============================================================================
//	Defined Message identifiers:
//	==============================================================================

#define MSGC_HGTMAP			0x00001F00

#define MSG_HMapIsValid		MSGC_HGTMAP+0	// true if valid data after load
#define MSG_HMapBfrAdr		MSGC_HGTMAP+1	// get pointer to height map buffer
#define MSG_HMapWidth		MSGC_HGTMAP+2	// width in pixels
#define MSG_HMapHeight		MSGC_HGTMAP+3	// height in pixels
#define MSG_HMapMax			MSGC_HGTMAP+4	// get maximum value of data
#define MSG_HMapMin			MSGC_HGTMAP+5	// get minimum value of data
#define MSG_HMapOffset		MSGC_HGTMAP+6	// offset all data values
#define MSG_HMapScale		MSGC_HGTMAP+7	// scale all data values
#define MSG_HMapNormalize	MSGC_HGTMAP+8	// scale and offset all data values
#define MSG_HMap2Image		MSGC_HGTMAP+9	// create colorized IImage from height map

//	==============================================================================
//	inline Interface Class for IHeightMap Object
//	==============================================================================

class IHeightMap : public IMObject
{
public:
	//	get height map buffer
	inline float* HMapBfrAdr(void)
	{ return (float*)Msg(MSG_HMapBfrAdr);}

	//	get height map nr of vertical rows
	inline UINT HMapWidth(void)
	{ return (UINT)Msg(MSG_HMapWidth);}

	//	get height map buffer
	inline UINT HMapHeight(void)
	{ return (UINT)Msg(MSG_HMapHeight);}

	//	get height map max value
	inline void HMapMax(float* pValue)
	{Msg(MSG_HMapMax,pValue);}

	//	get height map min value
	inline void HMapMin(float* pValue)
	{Msg(MSG_HMapMin,pValue);}

	//	offset height map values
	inline void HMapOffset(float ofst)
	{Msg(MSG_HMapOffset,ofst);}

	//	scale height map values
	inline void HMapScale(float scale)
	{Msg(MSG_HMapScale,scale);}

	//	scale height map values
	inline void HMapNormalize(void)
	{Msg(MSG_HMapNormalize);}

	//	convert height map to color-scaled image
	inline IImage* HMap2Image(float* pColorScaleTable)
	{return (IImage*)Msg(MSG_HMap2Image,pColorScaleTable);}
};

//	==============================================================================
//	class factory:
//	==============================================================================

//	link against v8Access:
IHeightMap* MakeIHeightMap(CHAR* pFileName);
//	link against fcw32:
IHeightMap* MakeHeightMap(CHAR* pFileName);

#endif
//	==============================================================================
