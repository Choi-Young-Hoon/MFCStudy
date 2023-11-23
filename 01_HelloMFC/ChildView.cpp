
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "01_HelloMFC.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC textOutDC(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오
	
	// TextOut() 출력
	textOutDC.TextOutW(50, 50, CString(_T("안녕하세요")));

	// DrawText() 출력
	CRect rect;
	GetClientRect(&rect);

	textOutDC.SetTextColor(RGB(255, 0, 0));
	textOutDC.SetBkColor(RGB(255, 255, 0));
	textOutDC.DrawText(CString("DrawText() 연습1 [1]"), &rect, 0);
	textOutDC.DrawText(CString("DrawText() 연습2 [2]"), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	textOutDC.SetTextAlign(TA_CENTER); // 가운데 정렬 방식으로 변경
	textOutDC.SetTextColor(RGB(0, 0, 255)); // 글자 파란색으로 변경
	textOutDC.SetBkColor(RGB(0, 255, 0)); // 배경을 초록색으로 지정.
	textOutDC.TextOut(rect.right / 2, 3 * rect.bottom / 4, CString("TextOut 함수를 연습합니다."));


}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);

	CWnd::OnLButtonDown(nFlags, point);
}
