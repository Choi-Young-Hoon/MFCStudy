﻿
// 01_HelloMFC.h: 01_HelloMFC 애플리케이션의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMy01HelloMFCApp:
// 이 클래스의 구현에 대해서는 01_HelloMFC.cpp을(를) 참조하세요.
//

class CMy01HelloMFCApp : public CWinApp
{
public:
	CMy01HelloMFCApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 구현입니다.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy01HelloMFCApp theApp;
