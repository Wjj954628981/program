// Mine.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Mine.h"
#include "MineDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CPen Pen1,Pen2,Pen3,Pen4,Pen5,Pen6,Pen7;
/////////////////////////////////////////////////////////////////////////////
// CMineApp

BEGIN_MESSAGE_MAP(CMineApp, CWinApp)
	//{{AFX_MSG_MAP(CMineApp)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMineApp construction

CMineApp::CMineApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMineApp object

CMineApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMineApp initialization

BOOL CMineApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	DWORD LineStyle[2]={1,1};
	Pen1.CreatePen(PS_SOLID,1,RGB(128,128,128));
	Pen2.CreatePen(PS_SOLID,3,RGB(255,255,255));
	Pen3.CreatePen(PS_SOLID,1,RGB(255,255,255));
	Pen4.CreatePen(PS_SOLID,2,RGB(255,0,0));
	Pen5.CreatePen(PS_SOLID,2,RGB(128,0,0));
	Pen6.CreatePen(PS_SOLID,1,RGB(198,198,198));
	Pen7.CreatePen(PS_SOLID,1,RGB(0,0,0));
	
	CMineDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}




