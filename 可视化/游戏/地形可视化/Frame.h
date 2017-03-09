// Frame.h : main header file for the FRAME application
//

#if !defined(AFX_FRAME_H__C4425636_8973_4B57_9E56_C3C868AD2280__INCLUDED_)
#define AFX_FRAME_H__C4425636_8973_4B57_9E56_C3C868AD2280__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFrameApp:
// See Frame.cpp for the implementation of this class
//

class CFrameApp : public CWinApp
{
public:
	CFrameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFrameApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAME_H__C4425636_8973_4B57_9E56_C3C868AD2280__INCLUDED_)
