
// painterView.h : CpainterView ��Ľӿ�
//

#pragma once


class CpainterView : public CView
{
protected: // �������л�����
	CpainterView();
	DECLARE_DYNCREATE(CpainterView)

// ����
public:
	CpainterDoc* GetDocument() const;

// ����
public:
	POINT m, n;
	BOOL b;

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
	virtual ~CpainterView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // painterView.cpp �еĵ��԰汾
inline CpainterDoc* CpainterView::GetDocument() const
   { return reinterpret_cast<CpainterDoc*>(m_pDocument); }
#endif

