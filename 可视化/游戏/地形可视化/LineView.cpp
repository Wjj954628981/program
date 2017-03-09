// LineView.cpp : implementation file
//

#include "stdafx.h"
#include "Frame.h"
#include "MainFrm.h"
#include "LineView.h"
#include "FrameDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "OpenGL3D.h"

/////////////////////////////////////////////////////////////////////////////
// CLineView

IMPLEMENT_DYNCREATE(CLineView, CFormView)

CLineView::CLineView()
	: CFormView(CLineView::IDD)
{
	//{{AFX_DATA_INIT(CLineView)
	m_bRotateX = FALSE;
	m_bRotateY = FALSE;
	m_bRotateZ = FALSE;
	//}}AFX_DATA_INIT
}

CLineView::~CLineView()
{
}

void CLineView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineView)
	DDX_Check(pDX, IDC_RotateX, m_bRotateX);
	DDX_Check(pDX, IDC_RotateY, m_bRotateY);
	DDX_Check(pDX, IDC_RotateZ, m_bRotateZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLineView, CFormView)
	//{{AFX_MSG_MAP(CLineView)
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_RotateX, OnRotateX)
	ON_BN_CLICKED(IDC_RotateY, OnRotateY)
	ON_BN_CLICKED(IDC_RotateZ, OnRotateZ)
	ON_COMMAND(ID_DRAW_3D, OnDraw3d)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineView diagnostics

#ifdef _DEBUG
void CLineView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLineView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineView message handlers




void CLineView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	CRect rect;
//	CFrameApp *pApp=(CFrameApp *)AfxGetApp();
//	m_bRotateX.GetWindowRect(&rect);

	
	CFormView::OnLButtonUp(nFlags, point);
}

CView * CLineView::GetFrameView()
{
	CFrameApp *pApp=(CFrameApp *)AfxGetApp();
	CMainFrame *pFrame=(CMainFrame *)pApp->m_pMainWnd;
	CView *pView=(CView *)pFrame->m_wndSplitter1.GetPane(0,1);

	return pView;

}

void CLineView::OnRotateX() 
{
	// TODO: Add your control notification handler code here
	OpenGL3D gl3d;
	m_bRotateX!=m_bRotateX;
	if(0==m_RotateX)
		m_RotateX=1;
	else
		m_RotateX=0;

}

void CLineView::OnRotateY() 
{
	// TODO: Add your control notification handler code here
	OpenGL3D gl3d;
	m_bRotateY!=m_bRotateY;
	if(0==m_RotateY)
		m_RotateY=1;
	else
		m_RotateY=0;

	
}

void CLineView::OnRotateZ() 
{
	// TODO: Add your control notification handler code here
	OpenGL3D gl3d;
	m_bRotateZ!=m_bRotateZ;
	if(0==m_RotateZ)
		m_RotateZ=1;
	else
		m_RotateZ=0;

	
}

void CLineView::OnDraw3d() 
{
	// TODO: Add your command handler code here
//	CFrameView *pView=(CFrameView *)GetActiveView();
//	pView->OnDraw3d();
	
}
