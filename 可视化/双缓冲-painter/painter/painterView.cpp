
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
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CpainterView ����/����

CpainterView::CpainterView()
{
	// TODO:  �ڴ˴���ӹ������
	b = FALSE;

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
	m = point;
	n = point;
	b = TRUE;
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CpainterView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (b)
	{
		n = point;
		Invalidate(FALSE);
	}
	CView::OnMouseMove(nFlags, point);
}


void CpainterView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	//return CDialogEx::OnEraseBkgnd(pDC);����Ҫ�ػ汳��  
	return TRUE;
}