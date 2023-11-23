#pragma once

#include <afxwin.h>
#include <gdiplus.h>

#include "pch.h"

class CCustomButton : public CButton {
public:
	explicit CCustomButton();
	virtual ~CCustomButton();

public:
	void SetBackgroundColor(int a, int r, int g, int b);
	void SetBorderColor(int a, int r, int g, int b);
	void SetTextColor(int a, int r, int g, int b);
	void SetTextSize(float size);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();

private:
	void DrawBackground(Gdiplus::Graphics* graphics);
	void DrawBorder(Gdiplus::Graphics* graphics);
	void DrawText2(Gdiplus::Graphics* graphics);

private:
	Gdiplus::Color m_backgroundColor;
	Gdiplus::Color m_borderColor;
	Gdiplus::Color m_textColor;

	float m_fTextSize;
	CString m_strText;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};