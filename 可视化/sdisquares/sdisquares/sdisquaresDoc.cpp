
// sdisquaresDoc.cpp : CsdisquaresDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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


// CsdisquaresDoc ����/����

CsdisquaresDoc::CsdisquaresDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CsdisquaresDoc::~CsdisquaresDoc()
{
}

BOOL CsdisquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CsdisquaresDoc ���л�

void CsdisquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
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
		// TODO:  �ڴ���Ӽ��ش���
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

// ����ͼ��֧��
void CsdisquaresDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CsdisquaresDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
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

// CsdisquaresDoc ���

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


// CsdisquaresDoc ����

void CsdisquaresDoc::OnChangeDrawColor(UINT nID)
{
	m_drawColor = nID - IDC_COLOR_RED;
}