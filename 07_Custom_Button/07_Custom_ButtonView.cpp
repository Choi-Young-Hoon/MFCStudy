
// 07_Custom_ButtonView.cpp: CMy07CustomButtonView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "07_Custom_Button.h"
#endif

#include "07_Custom_ButtonDoc.h"
#include "07_Custom_ButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07CustomButtonView

IMPLEMENT_DYNCREATE(CMy07CustomButtonView, CFormView)

BEGIN_MESSAGE_MAP(CMy07CustomButtonView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy07CustomButtonView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy07CustomButtonView 생성/소멸

CMy07CustomButtonView::CMy07CustomButtonView() noexcept
	: CFormView(IDD_MY07_CUSTOM_BUTTON_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy07CustomButtonView::~CMy07CustomButtonView()
{
}

void CMy07CustomButtonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, this->m_btnCustom);
}

BOOL CMy07CustomButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy07CustomButtonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CMy07CustomButtonView 진단

#ifdef _DEBUG
void CMy07CustomButtonView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy07CustomButtonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy07CustomButtonDoc* CMy07CustomButtonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy07CustomButtonDoc)));
	return (CMy07CustomButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy07CustomButtonView 메시지 처리기


void CMy07CustomButtonView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MessageBox(_T("HELLO"), _T("WORLD"));
}
