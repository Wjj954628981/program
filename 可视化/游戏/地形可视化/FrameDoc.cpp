// FrameDoc.cpp : implementation of the CFrameDoc class
//

#include "stdafx.h"
#include "Frame.h"

#include "FrameDoc.h"
#include <fstream.h>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrameDoc

IMPLEMENT_DYNCREATE(CFrameDoc, CDocument)

BEGIN_MESSAGE_MAP(CFrameDoc, CDocument)
	//{{AFX_MSG_MAP(CFrameDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrameDoc construction/destruction

CFrameDoc::CFrameDoc()
{
	// TODO: add one-time construction code here
  m_bFileOpen=false;

}

CFrameDoc::~CFrameDoc()
{
}

BOOL CFrameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFrameDoc serialization

void CFrameDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFrameDoc diagnostics

#ifdef _DEBUG
void CFrameDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFrameDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFrameDoc commands



BOOL CFrameDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	TerrainFileName=lpszPathName;

	if(TerrainFileName)
		m_bFileOpen=true;


	ifstream is(TerrainFileName);
	if(is.bad())
		 return FALSE;
	char message[300];
	is.seekg(0,ios::beg);

	//is.getline(message,sizeof(message)-1,'\n');
	/*LONG nCurZ[10];
	  int nFields=sscanf(message,"%d%d%d%d%d%d%d%d%d%d",
	  &nCurZ[0],&nCurZ[1],&nCurZ[2],&nCurZ[3],&nCurZ[4],
	  &nCurZ[5],&nCurZ[6],&nCurZ[7],&nCurZ[8],&nCurZ[9]);*/
	is.getline(message,sizeof(message)-1,'\n');
	if(lstrcmpi(message,"NSDTF-DEM")!=0)
	{
	    AfxMessageBox("当前DEM文件非国家空间数据交换格式");
		return FALSE;
	}
	is.getline(message,sizeof(message)-1,'\n');
	is.getline(message,sizeof(message)-1,'\n');
	is.getline(message,sizeof(message)-1,'\n');
	is.getline(message,sizeof(message)-1,'\n');

	is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%f",&m_fLeftTopX);
    is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%f",&m_fLeftTopY);

	is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%f",&m_fGridX);
    is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%f",&m_fGridY);

	is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%d",&m_nRow);
    is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%d",&m_nCol);

	is.getline(message,sizeof(message)-1,'\n');
	sscanf(message,"%d",&m_nScale);

	is.getline(message,sizeof(message)-1,'\n');

	if(fabs(m_fGridX-m_fGridY)>0.0001)
	{
		AfxMessageBox("系统要求DEM为正方形格网");
		return FALSE;
	}

    m_pEle=new int[m_nRow*m_nCol];



	int i,j,k;
	MaxHeight=0;
	MinHeight=10000000;
	for(i=0;i<m_nRow;i++)
	{
		LONG nRowPos=i*m_nCol;
		int nCharRowofCol;
		if(m_nCol%10==0)
			nCharRowofCol=m_nCol/10;
		else
			nCharRowofCol=m_nCol/10+1;
		int nCurZ[10];
		for(j=0;j<nCharRowofCol;j++)
		{
			is.getline(message,sizeof(message)-1,'\n');
            int nFields=sscanf(message,"%d%d%d%d%d%d%d%d%d%d",
	        &nCurZ[0],&nCurZ[1],&nCurZ[2],&nCurZ[3],&nCurZ[4],
	        &nCurZ[5],&nCurZ[6],&nCurZ[7],&nCurZ[8],&nCurZ[9]);

            int k;
			for(k=0;k<nFields;k++)
			{
			    int nPos_of_Point;
				nPos_of_Point=nRowPos+j*10+k;
				m_pEle[nPos_of_Point]=nCurZ[k];

				//寻找高程的最大和最小值
				if(m_pEle[nPos_of_Point] > MaxHeight)
					MaxHeight=m_pEle[nPos_of_Point];
				if(m_pEle[nPos_of_Point] < MinHeight)
					MinHeight=m_pEle[nPos_of_Point];
			}
		}
	}

	 	AfxMessageBox("数据已成功读取!");

     is.close();
	
	// TODO: Add your specialized creation code here
	
	return TRUE;
}
