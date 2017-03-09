
// MySdiDoc.cpp : CMySdiDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CMySdiDoc ����/����

CMySdiDoc::CMySdiDoc()
: m_str(_T("Width:\nColor:"))
{
	// TODO:  �ڴ����һ���Թ������

}

CMySdiDoc::~CMySdiDoc()
{
}

BOOL CMySdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	m_str = _T("Width:\nColor:");
	return TRUE;
}




// CMySdiDoc ���л�

void CMySdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
		ar << m_str;
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
		ar >> m_str;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMySdiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
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

// ������������֧��
void CMySdiDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CMySdiDoc ���

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


// CMySdiDoc ����


void CMySdiDoc::OnChangetext()
{
	// TODO:  �ڴ���������������
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
