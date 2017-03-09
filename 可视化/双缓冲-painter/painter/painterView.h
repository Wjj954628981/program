
// painterView.h : CpainterView 类的接口
//

#pragma once


class CpainterView : public CView
{
protected: // 仅从序列化创建
	CpainterView();
	DECLARE_DYNCREATE(CpainterView)

// 特性
public:
	CpainterDoc* GetDocument() const;

// 操作
public:
	POINT m, n;
	BOOL b;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CpainterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // painterView.cpp 中的调试版本
inline CpainterDoc* CpainterView::GetDocument() const
   { return reinterpret_cast<CpainterDoc*>(m_pDocument); }
#endif

