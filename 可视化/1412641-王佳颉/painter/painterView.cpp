
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
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CpainterView 构造/析构

CpainterView::CpainterView()
{
	// TODO:  在此处添加构造代码
	b = FALSE;
	c = FALSE;

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
	for (int i = 0; i < pDoc->m_data.GetCount(); i++)
	{
		m_drawData = (DrawData *)(pDoc->m_data.GetAt(i));
		CRect rect(m_drawData->begin, m_drawData->end);
		CBrush brush;
		CPen pen;
		switch (m_drawData->colortype)
		{
		case 0:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			break;
		case 1:
			brush.CreateSolidBrush(RGB(0, 255, 0));
			pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
			break;
		case 2:
			brush.CreateSolidBrush(RGB(0, 0, 255));
			pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
			break;
		}
		pDC->SelectObject(brush);
		pDC->SelectObject(pen);
		switch (m_drawData->type)
		{
		case 0:
			pDC->Ellipse(rect);
			break;
		case 1:
			pDC->Rectangle(rect);
			break;
		}
		brush.DeleteObject();
		pen.DeleteObject();
	}
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
	CpainterDoc *pDoc=GetDocument();
	b = TRUE;
	/*POINT t = point;
	//判断按下的点是否在原来的图形里面，如果不在，则创建新图形；否则，进行移动
	for (int i = 0; i < pDoc->m_data.GetCount(); i++)
	{
		switch (pDoc->m_drawType)
		{
		case 0:
		{
				  CRgn rgnB;
				  rgnB.CreateEllipticRgn(m_drawData->begin.x, m_drawData->begin.y, m_drawData->end.x, m_drawData->end.y);
				  c = rgnB.PtInRegion(t);
		}
		case 1:
		{
				  CRect rc(m_drawData->begin, m_drawData->end);
				  c = rc.PtInRect(t);  
		}
		}
	}*/
//	if (c = FALSE){
		m_drawData = new DrawData;
		m = point;
		m_drawData->begin = m;
		m_drawData->type = pDoc->m_drawType;
		m_drawData->colortype = pDoc->m_colortype;
		CView::OnLButtonDown(nFlags, point);
//	}
}


void CpainterView::OnMouseMove(UINT nFlags, CPoint point)
{
// TODO:  在此添加消息处理程序代码和/或调用默认值
	CpainterDoc *pDoc = GetDocument();
	POINT t = point;
		if (c == TRUE)
		{

		}
	CView::OnMouseMove(nFlags, point);
}


void CpainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CpainterDoc *pDoc=GetDocument();
	b = FALSE;
//	if (c = FALSE)
//	{
		m_drawData->end = point;
		CClientDC dc(this);
		CRect rect(m_drawData->begin, m_drawData->end);
		CBrush brush;
		CPen pen;
		switch (m_drawData->colortype)
		{
		case 0:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			break;
		case 1:
			brush.CreateSolidBrush(RGB(0, 255, 0));
			pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
			break;
		case 2:
			brush.CreateSolidBrush(RGB(0, 0, 255));
			pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
			break;
		}
		dc.SelectObject(brush);
		dc.SelectObject(pen);
		switch (pDoc->m_drawType)
		{
		case 0:
			dc.Ellipse(rect);
			break;
		case 1:
			dc.Rectangle(rect);
			break;
		}
		pDoc->m_data.Add(m_drawData);
		brush.DeleteObject();
		pen.DeleteObject();
//	}
	//Invalidate(true);
	CView::OnLButtonUp(nFlags, point);
}
