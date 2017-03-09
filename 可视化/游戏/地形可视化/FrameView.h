// FrameView.h : interface of the CFrameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEVIEW_H__D9E18022_1B44_44CC_9773_80F885E2BABA__INCLUDED_)
#define AFX_FRAMEVIEW_H__D9E18022_1B44_44CC_9773_80F885E2BABA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFrameView : public CView
{
protected: // create from serialization only
	CFrameView();
	DECLARE_DYNCREATE(CFrameView)

// Attributes
public:
	CFrameDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bRbuttonDown;//检查鼠标是否又击
	BOOL m_bLbuttonDown;
	CPoint m_LbuttonDownPos;
	float m_YRotate;
	float m_XRotate;
	virtual ~CFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
public:
	HGLRC m_hRC;
	BOOL m_bDrawTwoDimen;
	BOOL m_bDraw3Dimen;
	//{{AFX_MSG(CFrameView)
	afx_msg void OnDraw2d();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDraw3d();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FrameView.cpp
inline CFrameDoc* CFrameView::GetDocument()
   { return (CFrameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEVIEW_H__D9E18022_1B44_44CC_9773_80F885E2BABA__INCLUDED_)
