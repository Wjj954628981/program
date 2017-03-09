
// sdisquaresDoc.h : CsdisquaresDoc ��Ľӿ�
//


#pragma once
#include"DrawData.h"

class CsdisquaresDoc : public CDocument
{
protected: // �������л�����
	CsdisquaresDoc();
	DECLARE_DYNCREATE(CsdisquaresDoc)

// ����
public:
	CPtrArray m_data;
	int m_drawColor = 0;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CsdisquaresDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnChangeDrawColor(UINT nID);
};
