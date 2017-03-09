// FrameDoc.h : interface of the CFrameDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEDOC_H__EAF77653_6CD6_4A78_88FA_D8577EA4A17F__INCLUDED_)
#define AFX_FRAMEDOC_H__EAF77653_6CD6_4A78_88FA_D8577EA4A17F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFrameDoc : public CDocument
{
protected: // create from serialization only
	CFrameDoc();
	DECLARE_DYNCREATE(CFrameDoc)

// Attributes
public:

	BOOL m_bFileOpen;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFrameDoc();
	int* m_pEle; //�߳̾���ָ��
	int m_nRow;                     //DEM��������
	int m_nCol; 
	int MaxHeight;
	int MinHeight;
	float m_fLeftTopX;               //DEM���Ͻ�X,Y������
	float m_fLeftTopY;
	float m_fGridX;                  //DEM X��Y����ı߳�
	float m_fGridY;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//BOOL m_bFileOpen;
	CString TerrainFileName;

	                   //DEM��������
	int m_nScale;//DEM �߳�ֵ�ķŴ���
    
	
	
	//{{AFX_MSG(CFrameDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEDOC_H__EAF77653_6CD6_4A78_88FA_D8577EA4A17F__INCLUDED_)
