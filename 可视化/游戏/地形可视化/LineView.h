#if !defined(AFX_LINEVIEW_H__75025E07_2538_4690_B030_DCC0A36263A2__INCLUDED_)
#define AFX_LINEVIEW_H__75025E07_2538_4690_B030_DCC0A36263A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#include "OpenGL3D.h"
#endif

class CLineView : public CFormView
{
protected:
	CLineView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLineView)

// Form Data
public:
	//{{AFX_DATA(CLineView)
	enum { IDD = IDD_DIALOG1 };
	BOOL	m_bRotateX;
	BOOL	m_bRotateY;
	BOOL	m_bRotateZ;
	//}}AFX_DATA

// Attributes
public:


// Operations
public:
	CView * GetFrameView();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLineView)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRotateX();
	afx_msg void OnRotateY();
	afx_msg void OnRotateZ();
	afx_msg void OnDraw3d();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEVIEW_H__75025E07_2538_4690_B030_DCC0A36263A2__INCLUDED_)
