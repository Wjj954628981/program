
// MySdiView.cpp : CMySdiView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MySdi.h"
#endif

#include "MySdiDoc.h"
#include "MySdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMySdiView

IMPLEMENT_DYNCREATE(CMySdiView, CView)

BEGIN_MESSAGE_MAP(CMySdiView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMySdiView ����/����

CMySdiView::CMySdiView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMySdiView::~CMySdiView()
{
}

BOOL CMySdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMySdiView ����

void CMySdiView::OnDraw(CDC* pDC)
{
	CMySdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	//�����
	CRect rectClient;
	GetClientRect(rectClient);
	CSize sizeClient = rectClient.Size();
	CString str = pDoc->m_str;
	CSize sizeTextExtent = pDC->GetTextExtent(str);
	pDC->TextOut((sizeClient.cx - sizeTextExtent.cx) / 2, (sizeClient.cy - sizeTextExtent.cy) / 2, str);


	//�ؼ���ͼ
	/*CRect rc;
	CWnd *pWin = GetDlgItem(IDD_DIALOG1);//��ȡ�ÿؼ���ָ�룬�Ϳ��ԶԸÿؼ�ֱ�Ӳ�����
	CDC *pDc = pWin->GetDC();//��ȡ�ÿؼ��Ļ���
	//���˻���������������ɵĻ�ͼ�ˣ�����ô������ô����
	pWin->GetClientRect(&rc);
	CBrush myBrush;
	myBrush.CreateSolidBrush(RGB(192, 250, 233));
	pDc->FillRect(rc, &myBrush);*/
}


// CMySdiView ��ӡ

BOOL CMySdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMySdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMySdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMySdiView ���

#ifdef _DEBUG
void CMySdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMySdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySdiDoc* CMySdiView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySdiDoc)));
	return (CMySdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySdiView ��Ϣ�������
