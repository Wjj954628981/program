
// sdisquaresView.cpp : CsdisquaresView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "sdisquares.h"
#endif

#include "sdisquaresDoc.h"
#include "sdisquaresView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsdisquaresView

IMPLEMENT_DYNCREATE(CsdisquaresView, CView)

BEGIN_MESSAGE_MAP(CsdisquaresView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CsdisquaresView 构造/析构

CsdisquaresView::CsdisquaresView()
{
	// TODO:  在此处添加构造代码

}

CsdisquaresView::~CsdisquaresView()
{
}

BOOL CsdisquaresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CsdisquaresView 绘制

void CsdisquaresView::OnDraw(CDC* /*pDC*/)
{
	CsdisquaresDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(HOLLOW_BRUSH));
	dc.SelectObject(brush);
	//边框
	dc.MoveTo(10, 10);
	dc.LineTo(10, 410);
	dc.MoveTo(10, 10);
	dc.LineTo(410, 10);
	dc.MoveTo(410, 10);
	dc.LineTo(410, 410);
	dc.MoveTo(10, 410);
	dc.LineTo(410, 410);
	//横竖线
	dc.MoveTo(10, 110);
	dc.LineTo(410, 110);
	dc.MoveTo(10, 210);
	dc.LineTo(410, 210);
	dc.MoveTo(10, 310);
	dc.LineTo(410, 310);

	dc.MoveTo(110, 10);
	dc.LineTo(110, 410);
	dc.MoveTo(210, 10);
	dc.LineTo(210, 410);
	dc.MoveTo(310, 10);
	dc.LineTo(310, 410);
}


// CsdisquaresView 打印

BOOL CsdisquaresView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CsdisquaresView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CsdisquaresView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CsdisquaresView 诊断

#ifdef _DEBUG
void CsdisquaresView::AssertValid() const
{
	CView::AssertValid();
}

void CsdisquaresView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsdisquaresDoc* CsdisquaresView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsdisquaresDoc)));
	return (CsdisquaresDoc*)m_pDocument;
}
#endif //_DEBUG


// CsdisquaresView 消息处理程序


void CsdisquaresView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CsdisquaresDoc* pDoc = GetDocument();
	m_drawData = new DrawData;
	m_drawData.begin = point;
	CClientDC dc(this);
	CBrush brush;
	switch(pDoc->m_drawColor){
		case 0:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			break;
		case 1:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			break;
		case 2:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			break;
		case 3:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			break;
	}
	dc.SelectObject(brush);
	m_drawData.color = pDoc->m_drawColor;
	brush.DeleteObject();
	Invalidate(true);
	CView::OnLButtonDown(nFlags, point);
}
