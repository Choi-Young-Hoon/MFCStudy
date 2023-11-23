
// 06_Controller_ButtonView.cpp: CMy06ControllerButtonView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "06_Controller_Button.h"
#endif

#include "06_Controller_ButtonDoc.h"
#include "06_Controller_ButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy06ControllerButtonView

IMPLEMENT_DYNCREATE(CMy06ControllerButtonView, CFormView)

BEGIN_MESSAGE_MAP(CMy06ControllerButtonView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
//	ON_BN_CLICKED(IDC_RADIO2, &CMy06ControllerButtonView::OnBnClickedRadio2)
//	ON_BN_CLICKED(IDC_RADIO1, &CMy06ControllerButtonView::OnBnClickedRadio1)
//ON_BN_CLICKED(IDC_BUTTON1, &CMy06ControllerButtonView::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON1, &CMy06ControllerButtonView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMy06ControllerButtonView 생성/소멸

CMy06ControllerButtonView::CMy06ControllerButtonView() noexcept
	: CFormView(IDD_MY06_CONTROLLER_BUTTON_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy06ControllerButtonView::~CMy06ControllerButtonView()
{
}

void CMy06ControllerButtonView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkBox);
	DDX_Control(pDX, IDC_CHECK2, m_3stateCheckBox);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
}

BOOL CMy06ControllerButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy06ControllerButtonView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	this->m_checkBox.SetCheck(1);
	this->m_3stateCheckBox.SetCheck(2);
	this->m_radio2.SetCheck(1);
}


// CMy06ControllerButtonView 인쇄

BOOL CMy06ControllerButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy06ControllerButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy06ControllerButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy06ControllerButtonView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMy06ControllerButtonView 진단

#ifdef _DEBUG
void CMy06ControllerButtonView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy06ControllerButtonView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy06ControllerButtonDoc* CMy06ControllerButtonView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy06ControllerButtonDoc)));
	return (CMy06ControllerButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy06ControllerButtonView 메시지 처리기


//void CMy06ControllerButtonView::OnBnClickedRadio2()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


//void CMy06ControllerButtonView::OnBnClickedRadio1()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


//void CMy06ControllerButtonView::OnBnClickedButton1()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}


void CMy06ControllerButtonView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int stateCheckBox = m_checkBox.GetCheck();
	int state3State = m_3stateCheckBox.GetCheck();
	int stateRadio1 = m_radio1.GetCheck();
	int stateRadio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태: %d, %d, %d, %d"), stateCheckBox, state3State, stateRadio1, stateRadio2);
	MessageBox(str, _T("Button 예제"), MB_ICONINFORMATION);
}
