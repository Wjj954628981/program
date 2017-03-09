
// painterView.cpp : CpainterView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CpainterView ����/����

CpainterView::CpainterView()
{
	// TODO:  �ڴ˴���ӹ������
	b = FALSE;
	c = FALSE;

}

CpainterView::~CpainterView()
{
}

BOOL CpainterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CpainterView ����

void CpainterView::OnDraw(CDC* pDC)
{
	CpainterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CpainterView ��ӡ

BOOL CpainterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CpainterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CpainterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CpainterView ���

#ifdef _DEBUG
void CpainterView::AssertValid() const
{
	CView::AssertValid();
}

void CpainterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CpainterDoc* CpainterView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CpainterDoc)));
	return (CpainterDoc*)m_pDocument;
}
#endif //_DEBUG


// CpainterView ��Ϣ�������


void CpainterView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CpainterDoc *pDoc=GetDocument();
	b = TRUE;
	/*POINT t = point;
	//�жϰ��µĵ��Ƿ���ԭ����ͼ�����棬������ڣ��򴴽���ͼ�Σ����򣬽����ƶ�
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
// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CpainterDoc *pDoc = GetDocument();
	POINT t = point;
		if (c == TRUE)
		{

		}
	CView::OnMouseMove(nFlags, point);
}


void CpainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
