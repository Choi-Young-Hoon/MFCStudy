
// 06_Controller_ButtonView.h: CMy06ControllerButtonView 클래스의 인터페이스
//

#pragma once


class CMy06ControllerButtonView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy06ControllerButtonView() noexcept;
	DECLARE_DYNCREATE(CMy06ControllerButtonView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY06_CONTROLLER_BUTTON_FORM };
#endif

// 특성입니다.
public:
	CMy06ControllerButtonDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy06ControllerButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedRadio2();
//	afx_msg void OnBnClickedRadio1();
//	afx_msg void OnBnClickedButton1();
	CButton m_checkBox;
	CButton m_3stateCheckBox;
	CButton m_radio1;
	CButton m_radio2;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 06_Controller_ButtonView.cpp의 디버그 버전
inline CMy06ControllerButtonDoc* CMy06ControllerButtonView::GetDocument() const
   { return reinterpret_cast<CMy06ControllerButtonDoc*>(m_pDocument); }
#endif

