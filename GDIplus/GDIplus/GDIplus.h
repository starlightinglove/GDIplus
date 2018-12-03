
// GDIplus.h: GDIplus 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.

//GDIplus 사용을 위한 추가
#pragma comment(lib, "gdiplus")

#include<gdiplus.h>
using namespace Gdiplus;

// CGDIplusApp:
// 이 클래스의 구현에 대해서는 GDIplus.cpp을(를) 참조하세요.
//

class CGDIplusApp : public CWinApp
{
public:
	CGDIplusApp() noexcept;
	// GDIplus 사용을 위한 추가
	ULONG_PTR m_gdiplusToken;

// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CGDIplusApp theApp;
