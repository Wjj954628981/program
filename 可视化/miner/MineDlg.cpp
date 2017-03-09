// MineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mine.h"
#include "MineDlg.h"
#include "GDIObjects.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CPen Pen1,Pen2,Pen3,Pen4,Pen5,Pen6,Pen7;
int nDigitFont[11][7]={
	{ 1, 2, 3, 4, 5, 6,-7},
	{-1,-2, 3, 4,-5,-6,-7},
	{-1, 2, 3,-4, 5, 6, 7},
	{-1, 2, 3, 4, 5,-6, 7},
	{ 1,-2, 3, 4,-5,-6, 7},
	{ 1, 2,-3, 4, 5,-6, 7},
	{ 1, 2,-3, 4, 5, 6, 7},
	{-1, 2, 3, 4,-5,-6,-7},
	{ 1, 2, 3, 4, 5, 6, 7},
	{ 1, 2, 3, 4, 5,-6, 7},
	{-1,-2,-3,-4,-5,-6, 7}
};
/////////////////////////////////////////////////////////////////////////////
// CDigitCalculator
void CDigitCalculator::Create(CWnd *pWnd,int nX,int nY,
		long lOriginal, int nMaxNumbers, int nSepMics, 
		COLORREF crColor,COLORREF crBkColor)
{
	m_nMaxNumber = nMaxNumbers;
	m_nSepMics = nSepMics;
	m_nX = nX;
	m_nY = nY;
	m_pWnd = pWnd;
	m_nCalculator = lOriginal;
	m_crColor = crColor;
	m_crBkColor = crBkColor;
	
}

void CDigitCalculator::ReShow()
{
	CClientDC ClientDC(m_pWnd);
	ClientDC.SelectObject(&Brush);
	ClientDC.SelectObject(&Pen1);
	ClientDC.Rectangle(m_nX,m_nY,
						m_nX+(11+m_nSepMics)*m_nMaxNumber+m_nSepMics,
						m_nY+25);
	
	ClientDC.SelectObject(&Pen2);
	ClientDC.SelectStockObject(NULL_BRUSH);
	ClientDC.MoveTo(m_nX,m_nY+25);
	ClientDC.LineTo(m_nX,m_nY);
	ClientDC.LineTo(m_nX+(11+m_nSepMics)*m_nMaxNumber+m_nSepMics,m_nY);
	ShowDigit();
}

void CDigitCalculator::ShowOneDigit(int nWhichDigit,int nWhichBit)
{
	CClientDC ClientDC(m_pWnd);
	int nI;
	for (nI=0;nI<7;nI++)
	{
		char nTmp = nDigitFont[nWhichDigit][nI];
		if(nTmp>0)
		{
			ClientDC.SelectObject(&Pen3);
		}
		else
		{
			ClientDC.SelectObject(&Pen4);
			nTmp = -nTmp;
		}
		ClientDC.SelectStockObject(NULL_BRUSH);
		
		int	nStartPosX, nStartPosY,	nJ;

		switch(nTmp)
		{
		case 1:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics;
			nStartPosY = m_nY+3;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX+nJ,nStartPosY+nJ);
				ClientDC.LineTo(nStartPosX+nJ,nStartPosY-nJ+9);
			}
			break;
		case 2:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics+1;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX+nJ,m_nY+nJ+2);
				ClientDC.LineTo(nStartPosX-nJ+9,m_nY+nJ+2);
			}
			break;
		case 3:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics+10;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX-nJ,m_nY+nJ+3);
				ClientDC.LineTo(nStartPosX-nJ,m_nY-nJ+9+3);
			}
			break;
		case 4:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+10+m_nSepMics;
			nStartPosY = m_nY+13;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX-nJ,nStartPosY+nJ);
				ClientDC.LineTo(nStartPosX-nJ,nStartPosY-nJ+9);
			}
			break;
		case 5:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics+1;
			nStartPosY = m_nY+22;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX+nJ,nStartPosY-nJ);
				ClientDC.LineTo(nStartPosX-nJ+9,nStartPosY-nJ);
			}
			break;
		case 6:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics;
			nStartPosY = m_nY+13;
			for (nJ=0;nJ<3;nJ++)
			{
				ClientDC.MoveTo(nStartPosX+nJ,nStartPosY+nJ);
				ClientDC.LineTo(nStartPosX+nJ,nStartPosY-nJ+9);
			}
			break;
			
		case 7:
			nStartPosX = m_nX+(11+m_nSepMics)*nWhichBit+m_nSepMics+1;
			nStartPosY = m_nY+12;
			ClientDC.MoveTo(nStartPosX,nStartPosY);
			ClientDC.LineTo(nStartPosX+9,nStartPosY);

			ClientDC.MoveTo(nStartPosX+1,nStartPosY+1);
			ClientDC.LineTo(nStartPosX+8,nStartPosY+1);

			ClientDC.MoveTo(nStartPosX+1,nStartPosY-1);
			ClientDC.LineTo(nStartPosX+8,nStartPosY-1);
			break;
		}
	}
}

void CDigitCalculator::ShowDigit()
{
	int nI,nJ;
	char cTmp[20];
	if(m_nCalculator<0)
	{
		nJ=1;
		ShowOneDigit(10,0);
		sprintf(cTmp,"%d",-m_nCalculator);
	}
	else
	{
		nJ=0;
		sprintf(cTmp,"%d",m_nCalculator);
	}
	int nLen=strlen(cTmp);
	for (nI=0;nJ<m_nMaxNumber;nJ++)
	{
		if(nJ>=m_nMaxNumber-nLen)
		{
			ShowOneDigit(cTmp[nI]-'0',nJ);
			nI++;
		}
		else
			ShowOneDigit(0,nJ);
	}
}

void CDigitCalculator::Increase()
{
	m_nCalculator++;
	ShowDigit();
}

void CDigitCalculator::Decrease()
{
	m_nCalculator--;
	ShowDigit();
}

long CDigitCalculator::GetNumber()
{
	return m_nCalculator;
}
void CDigitCalculator::SetNumber(long lOriginal)
{
	m_nCalculator = lOriginal;
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



void CMyButton::DrawItem( LPDRAWITEMSTRUCT lpDIS)
{
	// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = m_pBitmap;
	CPen m_Pen1,m_Pen2;
	m_Pen1.CreatePen(PS_SOLID,1,RGB(128,128,128));
	m_Pen2.CreatePen(PS_SOLID,1,RGB(255,255,255));
	UINT state = lpDIS->itemState;
	if ((state & ODS_SELECTED) && m_pBitmapSel->m_hObject != NULL)
		pBitmap = m_pBitmapSel;

	// draw the whole button
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap* pOld = memDC.SelectObject(pBitmap);
	if (pOld == NULL)
		return;     // destructors will clean up

	CRect rect;
	rect.CopyRect(&lpDIS->rcItem);
	if (state & ODS_SELECTED)
	{
		pDC->BitBlt(rect.left+4, rect.top+2, rect.Width()-3, rect.Height()-3,
			&memDC, 0, 0, SRCCOPY);
		memDC.SelectObject(pOld);
		pDC->SelectObject(m_Pen1);
		pDC->MoveTo(rect.right-1,0);
		pDC->LineTo(0,0);
		pDC->LineTo(0,rect.bottom-1);
		pDC->SelectObject(m_Pen2);
		pDC->LineTo(rect.right-1,rect.bottom-1);
		pDC->LineTo(rect.right-1,0);
	}
	else
	{
		pDC->BitBlt(rect.left+3, rect.top+3, rect.Width()-3, rect.Height()-3,
			&memDC, 0, 0, SRCCOPY);
		memDC.SelectObject(pOld);
		pDC->SelectObject(m_Pen2);
		pDC->MoveTo(rect.right-1,0);
		pDC->LineTo(0,0);
		pDC->LineTo(0,rect.bottom-1);
		pDC->SelectObject(m_Pen1);
		pDC->LineTo(rect.right-1,rect.bottom-1);
		pDC->LineTo(rect.right-1,0);
	}
};
void CMyButton::SetBitmap(CBitmap *pBitmap,CBitmap *pBitmapSel)
{
	m_pBitmap = pBitmap;
	if (pBitmapSel==NULL)
		m_pBitmapSel = pBitmap;
	Invalidate();
};



/////////////////////////////////////////////////////////////////////////////
// CMineDlg dialog

CMineDlg::CMineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMineDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMineDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CMineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMineDlg)
	DDX_Control(pDX, IDC_FACE, m_Face);
	//}}AFX_DATA_MAP
}

void CMineDlg::OnCommandExit()
{
	EndDialog(1);
}
void CMineDlg::OnCommandAbout()
{
	CAboutDlg ABOUT;
	ABOUT.DoModal();
}
void CMineDlg::OnCommandRestart()
{
	bFail = FALSE;
	if(bStart)
		KillTimer(1);
	bStart = FALSE;
	LandMine.Reset(LandMine.GetRow(),LandMine.GetCol(),LandMine.GetMineNum());
	TimeCount.SetNumber(0);
	MineCount.SetNumber(LandMine.GetMineNum());
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}
void CMineDlg::OnCommandPrimary()
{
	LandMine.Reset(8,8,10);
	m_DlgReSize=TRUE;
	if(bStart)
		KillTimer(1);
	bFail = FALSE;
	bBothDown = FALSE;
	bStart = FALSE;
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}
void CMineDlg::OnCommandMiddle()
{
	LandMine.Reset(16,16,40);
	m_DlgReSize=TRUE;
	if(bStart)
		KillTimer(1);
	bFail = FALSE;
	bBothDown = FALSE;
	bStart = FALSE;
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}
void CMineDlg::OnCommandAdvanced()
{
	LandMine.Reset(16,30,100);
	m_DlgReSize=TRUE;
	if(bStart)
		KillTimer(1);
	bFail = FALSE;
	bBothDown = FALSE;
	bStart = FALSE;
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}
void CMineDlg::OnCommandCustom()
{
	m_DlgReSize=TRUE;
	if(bStart)
		KillTimer(1);
	CCustom CustomDlg;
	CustomDlg.m_Height = LandMine.GetRow();
	CustomDlg.m_Width = LandMine.GetCol();
	CustomDlg.m_MineNum = LandMine.GetMineNum();
	CustomDlg.DoModal();
	LandMine.Reset(CustomDlg.m_Height,CustomDlg.m_Width,CustomDlg.m_MineNum);
	bFail = FALSE;
	bBothDown = FALSE;
	bStart = FALSE;
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}

afx_msg void CMineDlg::OnUpdatePrimary(CCmdUI* pCmdUI)
{
	::CheckMenuItem( m_hMainMenu,IDM_ADVANCED,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_CUSTOM,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_PRIMARY,MF_CHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_MIDDLE,MF_UNCHECKED);

};

afx_msg void CMineDlg::OnUpdateMiddle(CCmdUI* pCmdUI)
{
	::CheckMenuItem( m_hMainMenu,IDM_ADVANCED,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_CUSTOM,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_PRIMARY,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_MIDDLE,MF_CHECKED);

};
afx_msg void CMineDlg::OnUpdateAdvanced(CCmdUI* pCmdUI)
{
	::CheckMenuItem( m_hMainMenu,IDM_ADVANCED,MF_CHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_CUSTOM,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_PRIMARY,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_MIDDLE,MF_UNCHECKED);
};
afx_msg void CMineDlg::OnUpdateCustom(CCmdUI* pCmdUI)
{
	::CheckMenuItem( m_hMainMenu,IDM_ADVANCED,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_CUSTOM,MF_CHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_PRIMARY,MF_UNCHECKED);
	::CheckMenuItem( m_hMainMenu,IDM_MIDDLE,MF_UNCHECKED);
};

BEGIN_MESSAGE_MAP(CMineDlg, CDialog)
	//{{AFX_MSG_MAP(CMineDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_FACE, OnFace)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_COMMAND(IDM_RESTART,OnCommandRestart)
	ON_COMMAND(IDM_EXIT,OnCommandExit)
	ON_COMMAND(IDM_ABOUT,OnCommandAbout)
	ON_COMMAND(IDM_PRIMARY,OnCommandPrimary)
	ON_UPDATE_COMMAND_UI(IDM_PRIMARY,OnUpdatePrimary)
	ON_COMMAND(IDM_MIDDLE,OnCommandMiddle)
	ON_UPDATE_COMMAND_UI(IDM_MIDDLE,OnUpdateMiddle)
	ON_COMMAND(IDM_ADVANCED,OnCommandAdvanced)
	ON_UPDATE_COMMAND_UI(IDM_ADVANCED,OnUpdateAdvanced)
	ON_COMMAND(IDM_CUSTOM,OnCommandCustom)
	ON_UPDATE_COMMAND_UI(IDM_CUSTOM,OnUpdateCustom)
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMineDlg message handlers

BOOL CMineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CMenu MainMenu;
	if(!MainMenu.LoadMenu(IDR_MAINFRAME))
	{
		AfxMessageBox("Can't load main menu!",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	SetMenu(&MainMenu);
	m_hMainMenu=MainMenu.Detach();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	int nRow=10, nCol=10, nMineNum=10;
	bStart = FALSE;
	bFail = FALSE;
	bBothDown = FALSE;
	LandMine.Create(nRow,nCol,nMineNum,12,53,this);
	m_DlgReSize = TRUE;
	
	if(m_FaceNormal.LoadBitmap(IDB_NORMAL) &&
		m_FaceCry.LoadBitmap(IDB_CRY) &&
		m_FaceSad.LoadBitmap(IDB_SAD) &&
		m_FaceHappy.LoadBitmap(IDB_HAPPY))
	{
		m_Face.SetBitmap(&m_FaceNormal);
		return TRUE;  // return TRUE  unless you set the focus to a control
	}
	else
	{
		AfxMessageBox("Can't load Bitmap!",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMineDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
	if(m_DlgReSize)
	{
		int nRow,nCol,nMineNum;
		nRow = LandMine.GetRow();
		nCol = LandMine.GetCol();
		nMineNum = LandMine.GetMineNum();
		RECT DlgRect;
		GetWindowRect(&DlgRect);
		SetWindowPos(&wndTop,DlgRect.left,DlgRect.top,
			16*nCol+30, 109+16*nRow, SWP_NOMOVE);
		MineCount.Create(this,17,15,nMineNum,3);
		GetClientRect(&DlgRect);
		TimeCount.Create(this,DlgRect.right-58,15,0,3);
		m_Face.SetWindowPos(&wndTop,(DlgRect.right-27)/2,14,
		27,27,SWP_FRAMECHANGED);
		m_DlgReSize = FALSE;
	}
	RECT ClientRect;
	GetClientRect(&ClientRect);
	CClientDC ClientDC(this);

	//drawing the whole area
	ClientDC.SelectObject(Pen2);
	ClientDC.MoveTo(ClientRect.right-3,1);
	ClientDC.LineTo(1,1);
	ClientDC.LineTo(1,ClientRect.bottom-1);
	
	ClientDC.SelectObject(Pen1);
	ClientDC.MoveTo(ClientRect.right-2,1);
	ClientDC.LineTo(ClientRect.right-2,ClientRect.bottom-1);
	ClientDC.LineTo(1,ClientRect.bottom-1);
	ClientDC.MoveTo(ClientRect.right-3,2);
	ClientDC.LineTo(ClientRect.right-3,ClientRect.bottom-2);
	ClientDC.LineTo(2,ClientRect.bottom-2);

	//drwaing status area
	ClientDC.MoveTo(ClientRect.right-10,9);
	ClientDC.LineTo(10,9);
	ClientDC.LineTo(10,44);
	ClientDC.MoveTo(ClientRect.right-11,10);
	ClientDC.LineTo(11,10);
	ClientDC.LineTo(11,43);
	
	ClientDC.SelectObject(Pen3);
	ClientDC.LineTo(ClientRect.right-11,43);
	ClientDC.LineTo(ClientRect.right-11,10);
	ClientDC.MoveTo(10,44);
	ClientDC.LineTo(ClientRect.right-10,44);
	ClientDC.LineTo(ClientRect.right-10,9);
	
	//drawing the mine area
	ClientDC.MoveTo(ClientRect.right-10,51);
	ClientDC.LineTo(ClientRect.right-10,ClientRect.bottom-9);
	ClientDC.LineTo(10,ClientRect.bottom-9);
	ClientDC.MoveTo(ClientRect.right-11,52);
	ClientDC.LineTo(ClientRect.right-11,ClientRect.bottom-10);
	ClientDC.LineTo(11,ClientRect.bottom-10);
	ClientDC.SelectObject(Pen1);
	ClientDC.MoveTo(ClientRect.right-10,51);
	ClientDC.LineTo(10,51);
	ClientDC.LineTo(10,ClientRect.bottom-9);
	ClientDC.MoveTo(ClientRect.right-11,52);
	ClientDC.LineTo(11,52);
	ClientDC.LineTo(11,ClientRect.bottom-10);


	MineCount.ReShow();
	TimeCount.ReShow();
	LandMine.ReDraw(bFail);
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMineDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMineDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent==1)
		TimeCount.Increase();
	CDialog::OnTimer(nIDEvent);
}



void CMineDlg::OnFace() 
{
	// TODO: Add your control notification handler code here
	bFail = FALSE;
	if(bStart)
		KillTimer(1);
	bStart = FALSE;
	LandMine.Reset(LandMine.GetRow(),LandMine.GetCol(),LandMine.GetMineNum());
	TimeCount.SetNumber(0);
	MineCount.SetNumber(LandMine.GetMineNum());
	m_Face.SetBitmap(&m_FaceNormal);
	RedrawWindow();
}

void CMineDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFail==0)
	{
		m_Face.SetBitmap(&m_FaceCry);
		if(nFlags&MK_RBUTTON)
		{	
			bBothDown = 2;
			LandMine.BothButtonDown(point);
		}
		else
		{
			bBothDown = FALSE;
			LandMine.LButtonDown(point);
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CMineDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFail==0)
	{
		if(nFlags&MK_LBUTTON)
			if(nFlags&MK_RBUTTON)
				LandMine.MouseMove(point,2);    // both key down
			else
				LandMine.MouseMove(point,0);    //left key down
			else
				LandMine.MouseMove(point,1);		//right key down
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CMineDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFail==0)
	{
		m_Face.SetBitmap(&m_FaceNormal);
		if(bBothDown)
		{
			bBothDown--;
			int nStatus = LandMine.BothButtonUp(point);
			if(nStatus==-1)
			{
				bFail = TRUE;
				KillTimer(1);
				m_Face.SetBitmap(&m_FaceSad);
			}
			else
				if(LandMine.IsSuccess())
				{	
					KillTimer(1);
					m_Face.SetBitmap(&m_FaceHappy);
					AfxMessageBox("祝贺您!挖雷任务胜利完成!",MB_OK);
					bFail = -1;
				}
		}
		else
		{
			int nStatus = LandMine.LButtonUp(point);
			if(nStatus==-1)
			{
				bFail = TRUE;
				KillTimer(1);
				m_Face.SetBitmap(&m_FaceSad);
			}
			else
				if(LandMine.IsSuccess())
				{	
					KillTimer(1);
					m_Face.SetBitmap(&m_FaceHappy);
					AfxMessageBox("祝贺您!挖雷任务胜利完成!",MB_OK);
					bFail = -1;
				}
		}
		if(!bStart)
		{
			bStart = TRUE;
			SetTimer(1, 1000, NULL);
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CMineDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFail==0)
	{
		if(nFlags&MK_LBUTTON)
		{	bBothDown = 2;
			LandMine.BothButtonDown(point);
		}
		else
		{
			bBothDown = FALSE;
			switch(LandMine.RButtonDown(point))
			{
			case 0:
				break;
			case 1:
				MineCount.Increase();
				break;
			case -1:
				MineCount.Decrease();
				break;
			};
		}
		if(LandMine.IsSuccess())
		{	
			KillTimer(1);
			m_Face.SetBitmap(&m_FaceHappy);
			AfxMessageBox("祝贺您!挖雷任务胜利完成!",MB_OK);
			bFail = -1;
		}

	}
	CDialog::OnRButtonDown(nFlags, point);
}


void CMineDlg::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	OnRButtonDown(nFlags,point);
	CDialog::OnRButtonDblClk(nFlags, point);
}


void CMineDlg::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFail==0)
	{
		if(bBothDown)
		{
			bBothDown--;
			if(LandMine.BothButtonUp(point)==-1)
				bFail = TRUE;
			else
				if(LandMine.IsSuccess())
				{	
					KillTimer(1);
					AfxMessageBox("祝贺您!挖雷任务胜利完成!",MB_OK);
					bFail = -1;
				}
		}
	}
	
	CDialog::OnRButtonUp(nFlags, point);
}
/////////////////////////////////////////////////////////////////////////////
// CCustom dialog


CCustom::CCustom(CWnd* pParent /*=NULL*/)
	: CDialog(CCustom::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCustom)

	//}}AFX_DATA_INIT
}


void CCustom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCustom)
	DDX_Text(pDX, IDC_WIDTH, m_Width);
	DDV_MinMaxInt(pDX, m_Width, 1, 30);
	DDX_Text(pDX, IDC_HEIGHT, m_Height);
	DDV_MinMaxInt(pDX, m_Height, 1, 30);
	DDX_Text(pDX, IDC_MINENUM, m_MineNum);
	DDV_MinMaxInt(pDX, m_MineNum, 1, m_Height*m_Width-1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCustom, CDialog)
	//{{AFX_MSG_MAP(CCustom)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCustom message handlers

BOOL CCustom::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	::SendMessage(::GetDlgItem(m_hWnd,IDC_HEIGHT),
		EM_LIMITTEXT,
		(WPARAM)2,
	    (LPARAM)0);
	::SendMessage(::GetDlgItem(m_hWnd,IDC_WIDTH),
		EM_LIMITTEXT,
		(WPARAM)2,
	    (LPARAM)0);
	::SendMessage(::GetDlgItem(m_hWnd,IDC_MINENUM),
		EM_LIMITTEXT,
		(WPARAM)3,
	    (LPARAM)0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


