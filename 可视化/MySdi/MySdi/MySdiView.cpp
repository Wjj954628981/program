
// MySdiView.cpp : CMySdiView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMySdiView 构造/析构

CMySdiView::CMySdiView()
{
	// TODO:  在此处添加构造代码

}

CMySdiView::~CMySdiView()
{
}

BOOL CMySdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMySdiView 绘制

void CMySdiView::OnDraw(CDC* pDC)
{
	CMySdiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	//输出字
	CRect rectClient;
	GetClientRect(rectClient);
	CSize sizeClient = rectClient.Size();
	CString str = pDoc->m_str;
	CSize sizeTextExtent = pDC->GetTextExtent(str);
	pDC->TextOut((sizeClient.cx - sizeTextExtent.cx) / 2, (sizeClient.cy - sizeTextExtent.cy) / 2, str);


	//控件画图
	/*CRect rc;
	CWnd *pWin = GetDlgItem(IDD_DIALOG1);//获取该控件的指针，就可以对该控件直接操作了
	CDC *pDc = pWin->GetDC();//获取该控件的画布
	//有了画布，下面可以自由的画图了，想怎么画就怎么话，
	pWin->GetClientRect(&rc);
	CBrush myBrush;
	myBrush.CreateSolidBrush(RGB(192, 250, 233));
	pDc->FillRect(rc, &myBrush);*/
}


// CMySdiView 打印

BOOL CMySdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMySdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMySdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMySdiView 诊断

#ifdef _DEBUG
void CMySdiView::AssertValid() const
{
	CView::AssertValid();
}

void CMySdiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySdiDoc* CMySdiView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySdiDoc)));
	return (CMySdiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMySdiView 消息处理程序
