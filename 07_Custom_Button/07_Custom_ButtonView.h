
// 07_Custom_ButtonView.h: CMy07CustomButtonView 클래스의 인터페이스
//

#pragma once

#include "CCustomButton.h"

class CMy07CustomButtonView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy07CustomButtonView() noexcept;
	DECLARE_DYNCREATE(CMy07CustomButtonView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY07_CUSTOM_BUTTON_FORM };
#endif

// 특성입니다.
public:
	CMy07CustomButtonDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMy07CustomButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

private:
	CCustomButton m_btnCustom;
public:
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 07_Custom_ButtonView.cpp의 디버그 버전
inline CMy07CustomButtonDoc* CMy07CustomButtonView::GetDocument() const
   { return reinterpret_cast<CMy07CustomButtonDoc*>(m_pDocument); }
#endif

