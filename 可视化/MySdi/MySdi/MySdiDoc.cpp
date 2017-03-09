
// MySdiDoc.cpp : CMySdiDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MySdi.h"
#endif

#include "MySdiDoc.h"

#include <propkey.h>

#include "DlgInput.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMySdiDoc

IMPLEMENT_DYNCREATE(CMySdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySdiDoc, CDocument)
	ON_COMMAND(ID_CHANGETEXT, &CMySdiDoc::OnChangetext)
END_MESSAGE_MAP()


// CMySdiDoc 构造/析构

CMySdiDoc::CMySdiDoc()
: m_str(_T("Width:\nColor:"))
{
	// TODO:  在此添加一次性构造代码

}

CMySdiDoc::~CMySdiDoc()
{
}

BOOL CMySdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	m_str = _T("Width:\nColor:");
	return TRUE;
}




// CMySdiDoc 序列化

void CMySdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
		ar << m_str;
	}
	else
	{
		// TODO:  在此添加加载代码
		ar >> m_str;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CMySdiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CMySdiDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CMySdiDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMySdiDoc 诊断

#ifdef _DEBUG
void CMySdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMySdiDoc 命令


void CMySdiDoc::OnChangetext()
{
	// TODO:  在此添加命令处理程序代码
	DlgInput dlg;
	if (dlg.DoModal() == IDOK)
	{
		//m_str = _T("Width:/nColor:"dlg.m_input,dlg.m_color);
		CString k;
		if (dlg.m_color == 0)
		{
			k = "Red";
		}
		if (dlg.m_color == 1)
		{
			k = "Green";
		}
		if (dlg.m_color == 2)
		{
			k = "Blue";
		}
		m_str = _T("Width:\nColor:");
		UpdateAllViews(NULL);
	}
}
