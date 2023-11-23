#include <afxwin.h>

#include "pch.h"

#include "CCustomButton.h"

CCustomButton::CCustomButton() {
	this->m_backgroundColor = Gdiplus::Color(255, 64, 64, 64);
	this->m_borderColor		= Gdiplus::Color(255, 128, 128, 128);
	this->m_textColor		= Gdiplus::Color(255, 255, 255, 255);

	this->m_fTextSize = 15;
	this->m_strText = _T("Button");
}

CCustomButton::~CCustomButton() {

}

void CCustomButton::SetBackgroundColor(int a, int r, int g, int b) {
	this->m_backgroundColor = Gdiplus::Color(a, r, g, b);
}

void CCustomButton::SetBorderColor(int a, int r, int g, int b) {
	this->m_borderColor = Gdiplus::Color(a, r, g, b);
}

void CCustomButton::SetTextColor(int a, int r, int g, int b) {
	this->m_textColor = Gdiplus::Color(a, r, g, b);
}

void CCustomButton::SetTextSize(float size) {
	this->m_fTextSize = size;
}

void CCustomButton::OnPaint() {
	CPaintDC dc(this);

	CRect rect;
	GetClientRect(&rect);

	Gdiplus::Bitmap bmp(rect.Width(), rect.Height());
	Gdiplus::Graphics memoryGraphics(&bmp);
	this->DrawBackground(&memoryGraphics);
	this->DrawBorder(&memoryGraphics);
	this->DrawText2(&memoryGraphics);

	Gdiplus::Graphics mainGraphics(dc.GetSafeHdc());
	mainGraphics.DrawImage(&bmp, 0, 0);
}

void CCustomButton::DrawBackground(Gdiplus::Graphics* graphics) {
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::SolidBrush brush(this->m_backgroundColor);
	graphics->FillRectangle(&brush, rect.left, rect.top, rect.right, rect.bottom);
}

void CCustomButton::DrawBorder(Gdiplus::Graphics* graphics) {
	CRect rect;
	GetClientRect(&rect);
	
	Gdiplus::Pen pen(this->m_borderColor, 1);
	graphics->DrawRectangle(&pen, rect.left, rect.top, rect.Width(), rect.Height());
}

void CCustomButton::DrawText2(Gdiplus::Graphics* graphics) {
	CRect rect;
	GetClientRect(&rect);

	Gdiplus::StringFormat stringAlign;
	stringAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
	stringAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::FontFamily fontfam(_T("Arial"));
	Gdiplus::Font font(&fontfam, m_fTextSize, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

	Gdiplus::SolidBrush brush(this->m_textColor);
	Gdiplus::RectF gdiRect(rect.left, rect.top, rect.Width(), rect.Height());
	graphics->DrawString(this->m_strText, this->m_strText.GetLength(), &font, gdiRect, &stringAlign, &brush);
}

BEGIN_MESSAGE_MAP(CCustomButton, CButton)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


void CCustomButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->SetBackgroundColor(255, 255, 0, 0);
	CButton::OnLButtonDown(nFlags, point);
}


void CCustomButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->SetBackgroundColor(255, 0, 255, 0);
	CButton::OnLButtonUp(nFlags, point);
}
