
// 07_Custom_Button.h: 07_Custom_Button 애플리케이션의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH에 대해 이 파일을 포함하기 전에 'pch.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.


// CMy07CustomButtonApp:
// 이 클래스의 구현에 대해서는 07_Custom_Button.cpp을(를) 참조하세요.
//

class CMy07CustomButtonApp : public CWinApp
{
public:
	CMy07CustomButtonApp() noexcept;


// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	ULONG_PTR m_gdiplusToken;
};

extern CMy07CustomButtonApp theApp;
