// FrameView.cpp : implementation of the CFrameView class
//

#include "stdafx.h"
#include "Frame.h"

#include "FrameDoc.h"
#include "FrameView.h"

#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>

#include "OpenGL3D.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

OpenGL3D gl3d;//����openGL��ͼ��ȫ�ֶ���
/////////////////////////////////////////////////////////////////////////////
// CFrameView

IMPLEMENT_DYNCREATE(CFrameView, CView)

BEGIN_MESSAGE_MAP(CFrameView, CView)
	//{{AFX_MSG_MAP(CFrameView)
	ON_COMMAND(ID_DRAW_2D, OnDraw2d)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_3D, OnDraw3d)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrameView construction/destruction

CFrameView::CFrameView()
{
	// TODO: add construction code here
	 m_bDrawTwoDimen=false;
	 m_bDraw3Dimen=false;
	 m_XRotate=0;
	 m_YRotate=0;
	 m_bRbuttonDown=false;
	 m_bRbuttonDown=false;

}

CFrameView::~CFrameView()
{
}

BOOL CFrameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |=WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFrameView drawing

void CFrameView::OnDraw(CDC* pDC)
{
	CFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFrameView printing

BOOL CFrameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFrameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFrameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFrameView diagnostics

#ifdef _DEBUG
void CFrameView::AssertValid() const
{
	CView::AssertValid();
}

void CFrameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFrameDoc* CFrameView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFrameDoc)));
	return (CFrameDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrameView message handlers



void CFrameView::OnDraw2d() 
{   CDC *pDC=GetDC();
	CFrameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if(pDoc->m_bFileOpen)
	{
	m_bDrawTwoDimen=true;
	m_bDraw3Dimen=false;   //���ñ�־���Ա�WM_PAINTʱ����

	int *m_pEle=pDoc->m_pEle;
	int MaxHeight=pDoc->MaxHeight;
	int MinHeight=pDoc->MinHeight;
	int m_nCol=pDoc->m_nCol;
	int m_nRow=pDoc->m_nRow;
	int m_fLeftTopX=pDoc->m_fLeftTopX;
	int m_fLeftTopY=pDoc->m_fLeftTopY;
	int m_fGridX=pDoc->m_fGridX;
	int m_fGridY=pDoc->m_fGridY;

    CRect rc;
	GetClientRect(&rc);
	int  nWidth,nHeight;

		nWidth=int(m_fGridX*m_nCol);
        nHeight=int(m_fGridY*m_nRow);
	
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg((rc.left+rc.right)/2,(rc.bottom+rc.top)/2);
	pDC->SetWindowOrg(0,0);
	pDC->SetViewportExt(rc.Width(),-rc.Height());
	pDC->SetWindowExt(nWidth*2,nHeight*2);

    int i,j,color=RGB(0,0,0);

	int IntervalCon = (MaxHeight-MinHeight)/14;


   for(i=0;i<m_nRow;i++)
   {   
	 for(j=0;j<m_nCol;j++)
	 {

		int  	x = (j-200)*m_fGridX;
		int 	y =( i-180)*m_fGridY;

       if(m_pEle[i*m_nCol+j] < MinHeight+IntervalCon*3)
		 {   
		   color=RGB(4,155,43);
		 } 
		 else if((m_pEle[i*m_nCol+j]>MinHeight+IntervalCon*3)
			     &&(m_pEle[i*m_nCol+j] < MinHeight+IntervalCon*6)) 
		 {
			 color=RGB(4,185,43);
		 }
		 else if ((m_pEle[i*m_nCol+j] > MinHeight+IntervalCon*6)
			 &&(m_pEle[i*m_nCol+j] < MinHeight+IntervalCon*7)) 
		 {
			 color=RGB(4,200,43);
		 }
         else if((m_pEle[i*m_nCol+j] > MinHeight+IntervalCon*7)
			 &&(m_pEle[i*m_nCol+j] < MinHeight+IntervalCon*10))
		 {
			 color=RGB(194,189,124);
		 }
		 else if((m_pEle[i*m_nCol+j] > MinHeight+IntervalCon*10)
			 &&(m_pEle[i*m_nCol+j] < MinHeight+IntervalCon*12))
		 {    
			 color=RGB(224,218,134);
		 }
		 else 
		 {   
			 color=RGB(245,241,200);
		 }
		  
		pDC->SetPixel(x,y,color);
	
	}  
   }
	}
	
}

void CFrameView::OnPaint() //�����ڱ�ѹ�ǻ�ʱ�ƶ�ʱ������
{
	CPaintDC dc(this); // device context for painting
	
    if( m_bDrawTwoDimen)
	CFrameView::OnDraw2d();
	if(m_bDraw3Dimen)
	CFrameView::OnDraw3d();
	// Do not call CView::OnPaint() for painting messages
}

void CFrameView::OnMouseMove(UINT nFlags, CPoint point) 
{
	
	CClientDC dc(this);
	OnPrepareDC(&dc);
	dc.DPtoLP(&point);

	CStatusBar* pStatus=(CStatusBar*)

    AfxGetApp()->m_pMainWnd->GetDescendantWindow(AFX_IDW_STATUS_BAR);

	CString str;
	str.Format("��ǰ���λ��x:%d,y:%d",point.x,point.y);
    if (pStatus) 
		pStatus->SetPaneText(0, str);
	

/*	if(m_bLbuttonDown)
	{
		gl3d.m_RotateX-=(float)(m_LbuttonDownPos.x-point.x)/3.0f;
		gl3d.m_RotateY-=(float)(m_LbuttonDownPos.y-point.y)/3.0f;
		m_LbuttonDownPos=point;
	}
	InvalidateRect(NULL,false);*/

	CView::OnMouseMove(nFlags, point);	
	//CView::OnMouseMove(nFlags, point);
}

void CFrameView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	
	CView::OnPrepareDC(pDC, pInfo);
}

void CFrameView::OnDraw3d() //������ά���γ���
{
	// TODO: Add your command handler code here
	m_bDraw3Dimen=true; //���ñ�־����wm_paintʱ����
	m_bDrawTwoDimen=false;

	CFrameDoc* pDoc = GetDocument();
	CDC *pDC=GetDC();        //����gl3d��OpenGL3D���һ��ȫ�ֱ���
	
	gl3d.Init(pDC);         //��ʼ��OpenGL

	wglMakeCurrent(pDC->m_hDC,gl3d.m_hRC);//��RC��DC��������
	//����3D�������ɵĳ���
	gl3d.Draw3D(pDoc->m_pEle,pDoc->m_nCol,pDoc->m_nRow,pDoc->MaxHeight,pDoc->MinHeight);
    SwapBuffers(pDC->m_hDC);//����ǰ�󻺴�
	wglMakeCurrent(NULL,NULL);


	
}

int CFrameView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
		if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here	
	return 0;
}



void CFrameView::OnSize(UINT nType, int cx, int cy) 
{   //�����ڵĴ�С���ı�ʱ������
	CView::OnSize(nType, cx, cy);
	CDC *pDC=GetDC();
	wglMakeCurrent(pDC->m_hDC,m_hRC);//ʹ����rcΪ��ǰ������
	GLsizei width,height;
	GLdouble aspect;
	width=cx;
	height=cy;
	if(cy==0)
		aspect=(GLdouble)width;
	else
		aspect=(GLdouble)width/(GLdouble)height;
	glViewport(0,0,width,height);//�ӿڱ任
	glLoadIdentity();

	wglMakeCurrent(NULL,NULL);

}

void CFrameView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bDraw3Dimen)
	{
	gl3d.m_RotateAngle+=5;//ÿ��һ��ʱ�佫��ת�Ƕ�����5��

	InvalidateRect(NULL,FALSE);
	}
	CView::OnTimer(nIDEvent);
}

void CFrameView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	m_bRbuttonDown!=m_bRbuttonDown;
	if(1)//m_bRbuttonDown)
	{
	    SetTimer(1,100,NULL);
	}
	else//����Ҽ�������ת
	{
		KillTimer(0);
	}

	
	CView::OnRButtonDown(nFlags, point);
}

void CFrameView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
//	m_bLbuttonDown=true;
//	m_LbuttonDownPos=point;
	
	KillTimer(1);//����ر���ת
	CView::OnLButtonDown(nFlags, point);
}

void CFrameView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  // m_bLbuttonDown=false;	
	CView::OnLButtonUp(nFlags, point);
}
