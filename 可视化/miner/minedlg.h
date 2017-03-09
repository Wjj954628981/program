// MineDlg.h : header file
//

#if !defined(AFX_MINEDLG_H__A9CDCEE8_B81F_11D2_B0BB_D010738FA02C__INCLUDED_)
#define AFX_MINEDLG_H__A9CDCEE8_B81F_11D2_B0BB_D010738FA02C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "LandMine.h"


/////////////////////////////////////////////////////////////////////////////
// CDigitCalculaor
class CDigitCalculator
{
private:
	int m_nMaxNumber;
	int m_nX,m_nY;
	long m_nCalculator;
	int m_nSepMics;
	void ShowOneDigit(int nWhichDigit, int nWhichBit);
	CWnd* m_pWnd;
	COLORREF m_crColor,m_crBkColor;
	CBrush Brush;
	CPen Pen1,Pen2,Pen3,Pen4;
public:
	CDigitCalculator()
	{
		Brush.CreateSolidBrush(RGB(0,0,0));
		Pen1.CreatePen(PS_SOLID,1,RGB(255,255,255));
		Pen2.CreatePen(PS_SOLID,1,RGB(128,128,128));
		Pen3.CreatePen(PS_SOLID,1,RGB(255,0,0));
		Pen4.CreatePen(PS_SOLID,1,RGB(0,0,0));
	};
	void Create(CWnd *pWnd,int nX,int nY,
		long lOriginal=0, int nMaxNumbers=3, int nSepMics=2, 
		COLORREF crColor=RGB(128,0,0),COLORREF crBkColor=RGB(0,0,0));
	void ShowDigit();
	void Increase();
	void Decrease();
	long GetNumber();
	void SetNumber(long lOriginal);
	void ReShow();
};

/////////////////////////////////////////////////////////////////////////////
// CDigitCalculaor
class CMyButton : public CButton
{
private:
	CBitmap *m_pBitmap,*m_pBitmapSel;

public:	

	virtual void DrawItem( LPDRAWITEMSTRUCT lpDrawItemStruct );
	void SetBitmap(CBitmap *pBitmap,CBitmap *pBitmapSel=NULL);
};

/////////////////////////////////////////////////////////////////////////////
// CMineDlg dialog

class CMineDlg : public CDialog
{
// Construction
public:
	CMineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMineDlg)
	enum { IDD = IDD_MINE_DIALOG };
	CMyButton	m_Face;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL m_DlgReSize;
	CDigitCalculator TimeCount;
	CDigitCalculator MineCount;
	CLandMine LandMine;
	CBitmap m_FaceNormal,m_FaceCry,m_FaceSad,m_LandMine,m_FaceHappy;
	HMENU m_hMainMenu;
	int bFail;
	BOOL bBothDown;		// both mouse button down
	BOOL bStart;
public:
	void OnCommandRestart();
	void OnCommandExit();
	void OnCommandAbout();
	void OnCommandPrimary();
	void OnCommandMiddle();
	void OnCommandAdvanced();
	void OnCommandCustom();
	afx_msg void OnUpdatePrimary(CCmdUI* pCmdUI);
	afx_msg void OnUpdateMiddle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAdvanced(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCustom(CCmdUI* pCmdUI);
	// Generated message map functions
	//{{AFX_MSG(CMineDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFace();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CCustom dialog

class CCustom : public CDialog
{
// Construction
public:
	CCustom(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCustom)
	enum { IDD = IDD_CUSTOM };
	int		m_MineNum;
	int		m_Width;
	int		m_Height;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustom)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCustom)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MINEDLG_H__A9CDCEE8_B81F_11D2_B0BB_D010738FA02C__INCLUDED_)
