
// sdisquaresView.h : CsdisquaresView ��Ľӿ�
//

#pragma once


class CsdisquaresView : public CView
{
protected: // �������л�����
	CsdisquaresView();
	DECLARE_DYNCREATE(CsdisquaresView)

// ����
public:
	CsdisquaresDoc* GetDocument() const;

// ����
public:
	DrawData m_drawData;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CsdisquaresView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // sdisquaresView.cpp �еĵ��԰汾
inline CsdisquaresDoc* CsdisquaresView::GetDocument() const
   { return reinterpret_cast<CsdisquaresDoc*>(m_pDocument); }
#endif

