
// painterView.cpp : CpainterView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "painter.h"
#endif

#include "painterDoc.h"
#include "painterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CpainterView

IMPLEMENT_DYNCREATE(CpainterView, CView)

BEGIN_MESSAGE_MAP(CpainterView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CpainterView 构造/析构

CpainterView::CpainterView()
{
	// TODO:  在此处添加构造代码
	b = FALSE;

}

CpainterView::~CpainterView()
{
}

BOOL CpainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CpainterView 绘制

void CpainterView::OnDraw(CDC* pDC)
{
	CpainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	/*CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(HOLLOW_BRUSH));
	dc.SelectObject(brush);
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(pen);
	CRect rect(m, n);
	if (b == TRUE)
	{
		switch (pDoc->m_drawType)
		{
		case 0:
			dc.MoveTo(m);
			dc.LineTo(n);
			break;
		case 1:
			dc.Ellipse(rect);
			break;
		case 2:
			dc.Rectangle(rect);
			break;
		}
	}
	brush->DeleteObject();
	pen.DeleteObject();*/


	CRect rect,mrect;
	mrect.SetRect(m, n);
	GetClientRect(&rect);
	CDC MemDC;
	CBitmap MemBitmap;
	MemDC.CreateCompatibleDC(pDC);
	MemBitmap.CreateCompatibleBitmap(&MemDC, rect.Width(), rect.Height());
	MemDC.SelectObject(MemBitmap);
	MemDC.FillSolidRect(rect, RGB(255, 255, 0));
	if (b == TRUE)
	{
		switch (pDoc->m_drawType)
		{
		case 0:
			MemDC.MoveTo(m);
			MemDC.LineTo(n);
			break;
		case 1:
			MemDC.Ellipse(mrect);
			break;
		case 2:
			MemDC.Rectangle(mrect);
			break;
		}
	}
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &MemDC, 0, 0, SRCCOPY);
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();
}


// CpainterView 打印

BOOL CpainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CpainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CpainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CpainterView 诊断

#ifdef _DEBUG
void CpainterView::AssertValid() const
{
	CView::AssertValid();
}

void CpainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpainterDoc* CpainterView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpainterDoc)));
	return (CpainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CpainterView 消息处理程序


void CpainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m = point;
	n = point;
	b = TRUE;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CpainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (b)
	{
		n = point;
		Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}


void CpainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (this == GetCapture())
	{
		ReleaseCapture();
	}
	b = FALSE;
	//Invalidate(FALSE);
	CView::OnLButtonUp(nFlags, point);
}

BOOL CpainterView::OnEraseBkgnd(CDC* pDC)
{
	//return CDialogEx::OnEraseBkgnd(pDC);不需要重绘背景  
	return TRUE;
}