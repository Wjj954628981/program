
// MySdiView.h : CMySdiView ��Ľӿ�
//

#pragma once


class CMySdiView : public CView
{
protected: // �������л�����
	CMySdiView();
	DECLARE_DYNCREATE(CMySdiView)

// ����
public:
	CMySdiDoc* GetDocument() const;

// ����
public:

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
	virtual ~CMySdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MySdiView.cpp �еĵ��԰汾
inline CMySdiDoc* CMySdiView::GetDocument() const
   { return reinterpret_cast<CMySdiDoc*>(m_pDocument); }
#endif

