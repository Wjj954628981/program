#if !defined(AFX_LANDMINE_H__A9CDCEE6_B81F_11D2_B0BB_D010738FA02C__INCLUDED_)
#define AFX_LANDMINE_H__A9CDCEE6_B81F_11D2_B0BB_D010738FA02C__INCLUDED_

typedef enum{ MS_NORMAL,MS_OPEN,MS_FLAG,MS_QUEST,MS_EXPLODE} MINESTATUS;

class CMineButton
{
private:
	MINESTATUS m_nStatus;
	int m_nMineNum;
	CWnd *m_pParent;
	int m_nX,m_nY;
public:	
	CMineButton()
	{
		m_nMineNum = 0;
	}
	void Create(CWnd *pParent,int nX,int nY,int nMineNum=0)
	{
		m_pParent = pParent;
		m_nMineNum = nMineNum;
		m_nStatus = MS_NORMAL;
		m_nX = nX;
		m_nY = nY;

	}
	int OpenMine();
	void SetStatus(MINESTATUS nStatus)
	{
		m_nStatus = nStatus;
	}
	MINESTATUS GetStatus()
	{
		return m_nStatus;
	}
	void SetMineNum(int nMineNum)
	{
		m_nMineNum = nMineNum;
	}
	int GetMineNum()
	{
		return m_nMineNum;
	}
	void operator ++()
	{
		++m_nMineNum;
	//	return m_nMineNum;
	}
	void DrawItem(BOOL bFail=TRUE);
	void ButtonDown(int Status);
};


class CLandMine
{
private:
	int m_nRow,m_nCol;
	int m_nMineNum;
	int m_nX,m_nY;
	int m_nOldMine;
	int m_aMineTest[9];
	int m_nMineTest;
	CMineButton *m_aLandMine[10000];
	CWnd *m_pParent;

public:
	
	CLandMine()
	{
		m_nRow=m_nCol=m_nMineNum=0;
	};
	~CLandMine()
	{
		int nI;
		for(nI=0;nI<m_nRow*m_nCol;nI++)
		{
			delete m_aLandMine[nI];
		}
	}
	void Create(int nRow,int nCol,int nMineNum,int nX,int nY,CWnd *pParent);
	void Reset(int nRow,int nCol,int nMineNum);
	void ReDraw(BOOL bFail);
	void LButtonDown(CPoint point);
	void BothButtonDown(CPoint point);
	int  RButtonDown(CPoint point);
	void MouseMove(CPoint point,int bBothDown);
	int LButtonUp(CPoint point);
	int BothButtonUp(CPoint point);
	BOOL OpenMine(int nCurMine);
	BOOL IsSuccess();
	void RndBtShdDn(int nCurMine);
	int GetRow()
	{
		return m_nRow;
	}
	int GetCol()
	{
		return m_nCol;
	}
	int GetMineNum()
	{
		return m_nMineNum;
	}
	int GetRight(int nCurMine)
	{
		if ((nCurMine+1)%m_nCol>0)
			return nCurMine+1;
		else
			return -1;
	}
	int GetLeft(int nCurMine)
	{
		if (nCurMine%m_nCol>0)
			return nCurMine-1;
		else
			return -1;
	}
	int GetTop(int nCurMine)
	{
		if(nCurMine-m_nCol<0)
			return -1;
		else
			return nCurMine-m_nCol;
	}
	int GetBottom(int nCurMine)
	{
		if(m_nCol*m_nRow>m_nCol+nCurMine)
			return nCurMine+m_nCol;
		else
			return -1;

	}

};

#endif /* !define AFX_LANDMINE_H__A9CDCEE6_B81F_11D2_B0BB_D010738FA02C__INCLUDED_ */