//	===================================================================
//	_IImage.h - ARGB Bitmap Image Interface for BmpTools images
//	-------------------------------------------------------------------
//	Copyright ©2003-2004 Michael Riddle
//	All rights reserved
//	===================================================================
#ifndef _IImage_H
#define _IImage_H

#define XPSVC _declspec (dllexport)

class _IImage;
extern "C" void _stdcall ShearFillSetup(_IImage* hImage,float hshear,float vshear,
	float realHzSize,float realVertSize,GPOINT2* pDOrg);

extern "C" void _stdcall ShearFillClear(void);

enum _IMGFILETYPE { _IMGFILE_BAD=0, _IMGFILE_BMP=1,_IMGFILE_PNG=2,_IMGFILE_ICO=3,
					_IMGFILE_PFIMG=4, _IMGFILE_JPG=5, _IMGFILE_TIFF=6 };

enum IMGXFRMODE {IMGX_COPY=0,IMGX_TCOLOR=1,
				 IMGX_ALPHA=2,IMGX_PREALPHA=3,IMGX_ULTCOLOR=4};

struct _IMGINFO
{
	UINT*	pBits;
	UINT	width;
	UINT	height;
	UINT	nPixBytes;
	UINT	nRowSize;
};

struct RRECT
{
	float	left;
	float	top;
	float	right;
	float	bottom;
};

typedef bool (_stdcall *PBMPCLIPPED)(int x,int y);

//	Use GetCurImgInfo() to get a pointer to the _IMGINFO for the current
//	DevU to draw to during EDraw
extern "C" _IMGINFO* _stdcall GetCurImgInfo(void);

class _IImage
{
public:
	virtual ~_IImage(void) {}
	virtual _IImage* Copy(void)=0;
//
	virtual bool Save(CHAR* szFileName)=0;
	virtual int Width(void)=0;
	virtual int Height(void)=0;
//
	virtual _IMGINFO* GetImageInfo(void)=0;
	virtual UCHAR* GetBitsPtr(void)=0;
	virtual int GetRowSize(void)=0;
	virtual UCHAR* GetPixelPtr(int x,int y)=0;
	virtual void SetPixel(int x,int y,UINT color)=0;
	virtual void XfrPixel(UINT* pDest,UINT* pSrc,IMGXFRMODE nType)=0;
//
	virtual HBITMAP GetBitmap(void)=0;
	virtual HDC GetBitmapDC(void)=0;
	virtual bool IsAlpha(void)=0;
	virtual void SetTColor(UINT color)=0;
	virtual UINT GetTColor(void)=0;
//
	virtual void Clear(UINT nColor)=0;
	virtual void ClearI(_IMGINFO* pInfo,UINT nColor)=0;
	virtual void DoPreMulAlpha(void)=0;
	virtual void SetAlpha(UCHAR alpha)=0;
	virtual void SetAlphaI(_IMGINFO* pInfo,UCHAR alpha)=0;
//
//	These functions draw to a WIN32 device object
//	and should only be used for final device transfers
//
	virtual void DrawDC(HDC hdcDest,int atx,int aty)=0;
	virtual void DrawDCWH(HDC hdcDest,int atx,int aty,int dwid,int dhgt)=0;
	virtual void DrawExact(HDC hdcDest,int atx,int aty,int wid,int hgt)=0;
//
//	these functions do not use WIN32 APIs for the transfer
//	to avoid the false-color edge generation on stretch
//	The draw to an _IImage object
//	They should be used for all operations except the final draw
//
	virtual void Scale(_IImage* hImage,int atx,int aty,int dwid,int dhgt)=0;
	virtual void Stretch(_IImage* hImage,RECT* pDRect,RECT* pSRect,
					IMGXFRMODE nType,PBMPCLIPPED pBClip)=0;
	virtual void Rotate(_IImage* hImage,int atx,int aty,int dwid,int dhgt,
					double rang,RECT* pSRect,IMGXFRMODE nType)=0;
//
	virtual void ScaleI(_IMGINFO* pInfo,int atx,int aty,int dwid,int dhgt)=0;
	virtual void StretchI(_IMGINFO* pInfo,RECT* pDRect,RECT* pSRect,
					IMGXFRMODE nType,PBMPCLIPPED pBClip)=0;
	virtual void RotateI(_IMGINFO* pInfo,int atx,int aty,int dwid,int dhgt,
					double rang,RECT* pSRect,IMGXFRMODE nType)=0;
//
//	these are copy and stretch analogs
//
	virtual void Draw(_IImage* hImage,int atx,int aty)=0;
	virtual void DrawWH(_IImage* hImage,int atx,int aty,int dwid,int dhgt)=0;
	virtual void DrawI(_IMGINFO* pInfo,int atx,int aty)=0;
	virtual void DrawWHI(_IMGINFO* pInfo,int atx,int aty,int dwid,int dhgt)=0;

	virtual void ShearI(_IMGINFO* pInfo,int atx,int aty,int dwid,int dhgt,
					double rang,RECT* pSRect,IMGXFRMODE nType)=0;

	virtual void RotateClip(_IMGINFO* pInfo,int atx,int aty,int dwid,int dhgt,
					double rang,RECT* pSRect,IMGXFRMODE nType,PBMPCLIPPED pBClip)=0;

	virtual void ShearFill(_IMGINFO* pInfo,
		RRECT* pRRect,RECT* pDRect,POINT* pDOrg,POINT* pSOrg,
		float hshear,float vshear,float RealHzSize,float RealVertSize,
		IMGXFRMODE nType,PBMPCLIPPED pBClip)=0;
};

//	external access functions

extern "C" _IImage* _stdcall NewImage(int sizex,int sizey);

//	these functions can be intercepted for caching - use them
extern "C" _IImage* _stdcall FetchImage(CHAR* szFileName);
extern "C" void _stdcall ReleaseImage(_IImage* hImage);

//	these are direct functions - use them to implement a cache
extern "C" _IImage*  _stdcall MakeImage(CHAR* szFileName);
extern "C" void  _stdcall DelImage(_IImage* hImage);
//	filename .type determines format of bits
extern "C" void  _stdcall MakeImageMem(CHAR* szFileName,CHAR* pBmpData,int nBmpData);
extern "C" void  _stdcall SaveImageMem(CHAR* szFileName,CHAR* pBmpData,int nBmpData);

//	to setup intercepts for FetchImage and ReleaseImage to
//	implement a cache, put these in your DLLMain function:

//	SetBmpToolsAdr(MyFetchImageSvc,4);
//	SetBmpToolsAdr(MyReleaseImageSvc,5);

XPSVC _IImage* MakeDwgImage(UINT nWidth,UINT nHeight,EXTENTS2* pExtents);

XPSVC _IImage* LoadImgFile(char* pFileName);
XPSVC _IImage* LoadImgFromMem(char* pImgName,void* pBfr,UINT nBytes);
XPSVC bool SaveImgFile(char* pFileName,_IImage *hImage);
XPSVC UINT SaveImgToMem(_IImage* hImage,char* pImageName,void** ppBfr);

#endif
//	===================================================================
