
// sdisquaresView.cpp : CsdisquaresView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CsdisquaresView ����/����

CsdisquaresView::CsdisquaresView()
{
	// TODO:  �ڴ˴���ӹ������

}

CsdisquaresView::~CsdisquaresView()
{
}

BOOL CsdisquaresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsdisquaresView ����

void CsdisquaresView::OnDraw(CDC* /*pDC*/)
{
	CsdisquaresDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(HOLLOW_BRUSH));
	dc.SelectObject(brush);
	//�߿�
	dc.MoveTo(10, 10);
	dc.LineTo(10, 410);
	dc.MoveTo(10, 10);
	dc.LineTo(410, 10);
	dc.MoveTo(410, 10);
	dc.LineTo(410, 410);
	dc.MoveTo(10, 410);
	dc.LineTo(410, 410);
	//������
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


// CsdisquaresView ��ӡ

BOOL CsdisquaresView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CsdisquaresView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CsdisquaresView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CsdisquaresView ���

#ifdef _DEBUG
void CsdisquaresView::AssertValid() const
{
	CView::AssertValid();
}

void CsdisquaresView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsdisquaresDoc* CsdisquaresView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsdisquaresDoc)));
	return (CsdisquaresDoc*)m_pDocument;
}
#endif //_DEBUG


// CsdisquaresView ��Ϣ�������


void CsdisquaresView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
