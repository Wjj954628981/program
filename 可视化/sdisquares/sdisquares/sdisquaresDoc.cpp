
// sdisquaresDoc.cpp : CsdisquaresDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "sdisquares.h"
#endif

#include "sdisquaresDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "afxmsg_.h"
// CsdisquaresDoc

IMPLEMENT_DYNCREATE(CsdisquaresDoc, CDocument)

BEGIN_MESSAGE_MAP(CsdisquaresDoc, CDocument)
	ON_COMMAND_RANGE(IDC_COLOR_RED, IDC_COLOR_YELLO, &CsdisquaresDoc::OnChangeDrawColor)
END_MESSAGE_MAP()


// CsdisquaresDoc 构造/析构

CsdisquaresDoc::CsdisquaresDoc()
{
	// TODO:  在此添加一次性构造代码

}

CsdisquaresDoc::~CsdisquaresDoc()
{
}

BOOL CsdisquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CsdisquaresDoc 序列化

void CsdisquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
		int size = m_data.GetCount();
		ar << size;
		int i;
		for (i = 0; i < size; i++){
			DrawData *data = (DrawData*)m_data.GetAt(i);
			ar << data->begin.x;
			ar << data->begin.y;
			ar << data->color;
		}
	}
	else
	{
		// TODO:  在此添加加载代码
		int size;
		ar >> size;
		int i;
		m_data.RemoveAll();
		for (i = 0; i < size; i++){
			DrawData *data = new DrawData;
			ar >> data->begin.x;
			ar >> data->begin.y;
			ar >> data->color;
			m_data.Add(data);
		}
		UpdateAllViews(NULL);
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CsdisquaresDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CsdisquaresDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CsdisquaresDoc::SetSearchContent(const CString& value)
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

// CsdisquaresDoc 诊断

#ifdef _DEBUG
void CsdisquaresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CsdisquaresDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CsdisquaresDoc 命令

void CsdisquaresDoc::OnChangeDrawColor(UINT nID)
{
	m_drawColor = nID - IDC_COLOR_RED;
}