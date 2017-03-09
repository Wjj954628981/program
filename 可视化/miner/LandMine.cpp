#include "stdafx.h"
#include "Resource.h"
#include "LandMine.h"
extern CPen Pen1,Pen2,Pen3,Pen4,Pen5,Pen6,Pen7;

void CMineButton::DrawItem(BOOL bFail)
{
	
	RECT rect;
	rect.left = m_nX;
	rect.top = m_nY;
	rect.right = m_nX+14;
	rect.bottom = m_nY+14;
	CClientDC ClientDC(m_pParent);
	ClientDC.SetBkColor(RGB(198,198,198));

	ClientDC.SelectStockObject(LTGRAY_BRUSH);
	ClientDC.SelectObject(Pen6);
	ClientDC.Rectangle(&rect);

	if(m_nStatus==MS_OPEN || bFail && m_nStatus==MS_FLAG && m_nMineNum>=0)
	{
		switch(m_nMineNum)
		{
		case 1:
			ClientDC.SetTextColor(RGB(0,128,0));
			break;

		case 2:
			ClientDC.SetTextColor(RGB(0,128,128));
			break;
			
		case 3:
			ClientDC.SetTextColor(RGB(0,0,128));
			break;
			
		case 4:
			ClientDC.SetTextColor(RGB(0,128,0));
			break;
			
		case 5:
			ClientDC.SetTextColor(RGB(128,0,0));
			break;
			
		case 6:
			ClientDC.SetTextColor(RGB(0,255,0));
			break;
			
		case 7:
			ClientDC.SetTextColor(RGB(128,128,0));
			break;
			
		case 8:
			ClientDC.SetTextColor(RGB(255,0,255));
			break;
		}
		char cTmp[2]={0,0};
		if(m_nMineNum>0)
		{
			cTmp[0]=m_nMineNum+'0';
			ClientDC.DrawText(cTmp,-1,&rect,DT_CENTER|DT_VCENTER);
		}
		int nI;

		ClientDC.SelectObject(Pen6);
		ClientDC.SetBkColor(RGB(198,198,198));
		ClientDC.SelectStockObject(NULL_BRUSH);
		ClientDC.Rectangle(rect.left,rect.top,rect.right+1,rect.bottom+1);
		for(nI=rect.left;nI<rect.right+1;nI=nI+2)
			ClientDC.SetPixel(nI,rect.bottom+1,RGB(0,0,0));
		for(nI=rect.top;nI<rect.bottom+1;nI=nI+2)
			ClientDC.SetPixel(rect.right+1,nI,RGB(0,0,0));		
		if(bFail && m_nStatus==MS_FLAG && m_nMineNum!=-1)
		{
			ClientDC.SelectObject(Pen4);
			ClientDC.MoveTo(rect.left+1,rect.top+1);
			ClientDC.LineTo(rect.right-1,rect.bottom-1);
			ClientDC.MoveTo(rect.right-1,rect.top+1);
			ClientDC.LineTo(rect.left+1,rect.bottom-1);	
		}
		return;
	}
	
	if(bFail==1 && m_nMineNum==-1)
	{
		CBitmap Bitmap;
		if(m_nStatus!=MS_EXPLODE)
			Bitmap.LoadBitmap(IDB_MINE);
		else
			Bitmap.LoadBitmap(IDB_MINEEXPLODE);

		// draw the whole button
		CDC memDC;
		memDC.CreateCompatibleDC(&ClientDC);
		CBitmap* pOld = memDC.SelectObject(&Bitmap);
		if (pOld == NULL)
			return;     // destructors will clean up

		
		ClientDC.BitBlt(rect.left, rect.top,16,16,
			&memDC, 0, 0, SRCCOPY);
		memDC.SelectObject(pOld);
		int nI;
		for(nI=rect.left;nI<rect.right+1;nI=nI+2)
			ClientDC.SetPixel(nI,rect.bottom+1,RGB(0,0,0));
		for(nI=rect.top;nI<rect.bottom+1;nI=nI+2)
			ClientDC.SetPixel(rect.right+1,nI,RGB(0,0,0));
		
		return;
	}
	
	if (m_nStatus == MS_QUEST)
	{
		ClientDC.SetTextColor(RGB(0,0,128));
		ClientDC.SetBkColor(RGB(198,198,198));
		ClientDC.DrawText("?",1,&rect,DT_CENTER|DT_VCENTER);
	}
	else
	{
		if(m_nStatus == MS_FLAG)
		{

			CBitmap Bitmap;
			Bitmap.LoadBitmap(IDB_FLAG);
			
			// draw the whole button
			CDC memDC;
			memDC.CreateCompatibleDC(&ClientDC);
			CBitmap* pOld = memDC.SelectObject(&Bitmap);
			if (pOld == NULL)
				return;     // destructors will clean up
			
			
			ClientDC.BitBlt(rect.left, rect.top,14,14,
				&memDC, 0, 0, SRCCOPY);
			memDC.SelectObject(pOld);
			
		}
	}
	ClientDC.SelectObject(Pen3);
	ClientDC.MoveTo(rect.right,rect.top);
	ClientDC.LineTo(rect.left,rect.top);
	ClientDC.LineTo(rect.left,rect.bottom);
	ClientDC.SelectObject(Pen7);
	ClientDC.LineTo(rect.right,rect.bottom);
	ClientDC.LineTo(rect.right,rect.top);
	
}

void CMineButton::ButtonDown(int Status)
{
	RECT rect;
	rect.left = m_nX;
	rect.top = m_nY;
	rect.right = m_nX+15;
	rect.bottom = m_nY+15;
	CClientDC ClientDC(m_pParent);

	if(Status==1)
	{
		ClientDC.SelectObject(Pen6);
		ClientDC.SetBkColor(RGB(198,198,198));
		ClientDC.SelectStockObject(NULL_BRUSH);
		ClientDC.Rectangle(&rect);
		int nI;
		for(nI=rect.left;nI<rect.right;nI=nI+2)
			ClientDC.SetPixel(nI,rect.bottom,RGB(0,0,0));
		for(nI=rect.top;nI<rect.bottom;nI=nI+2)
			ClientDC.SetPixel(rect.right,nI,RGB(0,0,0));
	}
	else
	{
		ClientDC.SelectObject(Pen6);
		ClientDC.MoveTo(rect.left,rect.bottom);
		ClientDC.LineTo(rect.right,rect.bottom);
		ClientDC.LineTo(rect.right,rect.top+1);

		DrawItem(FALSE);
	}

}
int CMineButton::OpenMine()
{
	if(m_nStatus==MS_NORMAL || m_nStatus==MS_QUEST)
	{

		if (m_nMineNum != -1)
		{
			m_nStatus = MS_OPEN;
			DrawItem(FALSE);
			if(m_nMineNum == 0)
				return 0;
			else
				return 1;
		}
		else
		{
			m_nStatus = MS_EXPLODE;
			DrawItem(TRUE);		//Fail
			return -1;
		}
	}
	return 1;
};


void CLandMine::Create(int nRow,int nCol,int nMineNum,int nX,int nY,CWnd *pParent)
{
	m_pParent = pParent;
	m_nX = nX;
	m_nY = nY;
	Reset(nRow,nCol,nMineNum);
}	
void CLandMine::ReDraw(int bFail)
{
int nI;
	for(nI=0;nI<m_nRow*m_nCol;nI++)
		m_aLandMine[nI]->DrawItem(bFail);
}
void CLandMine::Reset(int nRow,int nCol,int nMineNum)
{
	int nI;
	RECT rect;
	for(nI=0;nI<m_nRow*m_nCol;nI++)
	{
		if (m_aLandMine[nI]!=NULL)
			delete m_aLandMine[nI];
	}
	for(nI=0;nI<nRow*nCol;nI++)
	{
		
		rect.left = m_nX+nI%nCol*16+1;
		rect.top = m_nY+nI/nCol*16+1;
		//rect.right = m_nX+nI/nCol*16+15;
		//rect.bottom = m_nY+nI%nCol*16+15;
		m_aLandMine[nI] = new CMineButton;
		m_aLandMine[nI]->Create(m_pParent,rect.left,rect.top);
		m_aLandMine[nI]->SetStatus(MS_NORMAL);
	//	m_aLandMine[nI]->SetMineNum(0);
	}
	m_nRow = nRow;
	m_nCol = nCol;
	m_nMineNum = nMineNum;
	
	int nCurMines=0;
	int nCurMine;
	srand( (unsigned)time( NULL ));
//	srand(1);
	while(nCurMines<m_nMineNum)
	{
		nCurMine=rand()%(m_nRow*m_nCol);
		if(m_aLandMine[nCurMine]->GetMineNum() != -1)
		{
			m_aLandMine[nCurMine]->SetMineNum(-1);
			int nMineRound,nMineRound1;
			//right;
			nMineRound = GetRight(nCurMine);
			if(nMineRound>=0)
			{
				if (m_aLandMine[nMineRound]->GetMineNum() != -1)
					++(*m_aLandMine[nMineRound]);
				//right top
				nMineRound1 = GetTop(nMineRound);
				if(nMineRound1>=0 && m_aLandMine[nMineRound1]->GetMineNum() != -1)
				{
					++(*m_aLandMine[nMineRound1]);
				}
				//right bottom
				nMineRound1 = GetBottom(nMineRound);
				if(nMineRound1>=0 && m_aLandMine[nMineRound1]->GetMineNum() != -1)
				{
					++(*m_aLandMine[nMineRound1]);
				}
			}			
			//left
			nMineRound = GetLeft(nCurMine);
			if(nMineRound>=0)
			{
				if(m_aLandMine[nMineRound]->GetMineNum() != -1)
					++(*m_aLandMine[nMineRound]);
		
				//Left top
				nMineRound1 = GetTop(nMineRound);
				if(nMineRound1>=0 && m_aLandMine[nMineRound1]->GetMineNum() != -1)
				{
					++(*m_aLandMine[nMineRound1]);
				}
				
				//Left bottom
				nMineRound1 = GetBottom(nMineRound);
				if(nMineRound1>=0 && m_aLandMine[nMineRound1]->GetMineNum() != -1)
				{
					++(*m_aLandMine[nMineRound1]);
				}
			}
			//Top
			nMineRound = GetTop(nCurMine);
			if(nMineRound>=0 && m_aLandMine[nMineRound]->GetMineNum() != -1)
			{
				++(*m_aLandMine[nMineRound]);
			}

			//Bottom
			nMineRound = GetBottom(nCurMine);
			if(nMineRound>=0 && m_aLandMine[nMineRound]->GetMineNum() != -1)
			{
				++(*m_aLandMine[nMineRound]);
			}
			nCurMines++;
		}
	}
}
void CLandMine::LButtonDown(CPoint point)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if (nRow >= m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY )
	{
		m_nOldMine = -1;
		return;
	}
	if(nCol<m_nCol && nRow<m_nRow 
		&& (m_aLandMine[nCurMine]->GetStatus()==MS_NORMAL || m_aLandMine[nCurMine]->GetStatus()==MS_QUEST))
	{
		m_aLandMine[nCurMine]->ButtonDown(1);
		m_nOldMine = nCurMine;
	}
};
int CLandMine::LButtonUp(CPoint point)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if (nRow >= m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY)
		return 0;
	BOOL nStatus = OpenMine(nCurMine);
	if(nStatus==FALSE)
	{	int nI;
		for(nI=0;nI<m_nRow*m_nCol;nI++)
		{
			if(m_aLandMine[nI]->GetMineNum() == -1)
				m_aLandMine[nI]->DrawItem(TRUE);
			if(m_aLandMine[nI]->GetStatus() == MS_FLAG)
				m_aLandMine[nI]->DrawItem(TRUE);
		}
		return -1;
	}
	return 1;

}

BOOL CLandMine::OpenMine(int nCurMine)
{
	int nRoundMine,nRoundMine1;
	int aMine[500];
	int nTop=0,nTail=0;
	
	aMine[nTop++] = nCurMine;
	
	while(nTop!=nTail)
	{
		int nCurrent=aMine[nTail];
		nTail = (nTail+1)%500;
		switch(m_aLandMine[nCurrent]->OpenMine())
		{
		case 0:		// Mine number is zero
			nRoundMine = GetLeft(nCurrent);
			if(nRoundMine!=-1)
			{
				aMine[nTop] = nRoundMine;
				nTop = (nTop+1)%500;
				nRoundMine1 = GetTop(nRoundMine);
				if(nRoundMine1!=-1)
				{
					aMine[nTop] = nRoundMine1;
					nTop = (nTop+1)%500;
					nRoundMine1 = GetTop(nRoundMine);
				}
				nRoundMine1 = GetBottom(nRoundMine);
				if(nRoundMine1!=-1)
				{
					aMine[nTop] = nRoundMine1;
					nTop = (nTop+1)%500;
					nRoundMine1 = GetTop(nRoundMine);
				}
			}
			nRoundMine = GetRight(nCurrent);
			if(nRoundMine!=-1)
			{	
				aMine[nTop] = nRoundMine;
				nTop = (nTop+1)%500;
				nRoundMine1 = GetTop(nRoundMine);
				if(nRoundMine1!=-1)
				{
					aMine[nTop] = nRoundMine1;
					nTop = (nTop+1)%500;
					nRoundMine1 = GetTop(nRoundMine);
				}
				nRoundMine1 = GetBottom(nRoundMine);
				if(nRoundMine1!=-1)
				{
					aMine[nTop] = nRoundMine1;
					nTop = (nTop+1)%500;
					nRoundMine1 = GetTop(nRoundMine);
				}
			}
			nRoundMine = GetTop(nCurrent);
			if(nRoundMine!=-1)
			{	
				aMine[nTop] = nRoundMine;
				nTop = (nTop+1)%500;
			}
			nRoundMine = GetBottom(nCurrent);
			if(nRoundMine!=-1)
			{
				aMine[nTop] = nRoundMine;
				nTop = (nTop+1)%500;
			}
			break;
		case 1:
			break;
		case -1:
			return FALSE;		// fail
		}
	}
	return TRUE;
}

BOOL CLandMine::IsSuccess()
{
	int nI,nStatus;
	for(nI=0;nI<m_nRow*m_nCol;nI++)
	{
		nStatus = m_aLandMine[nI]->GetStatus();
		if(nStatus != MS_OPEN)
		{
			if(!(nStatus==MS_FLAG && m_aLandMine[nI]->GetMineNum()==-1))
				return 0;			// not finish
		}
		
	}
	return 1;		// success
}
void CLandMine::MouseMove(CPoint point,int bBothDown)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if(nRow>=m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY)
	{
		nCurMine = -1;
	}
	if(bBothDown==0)
	{
		if (m_nOldMine != nCurMine)
		{
			if (m_nOldMine>=0)
				m_aLandMine[m_nOldMine]->ButtonDown(0);
			if (nCurMine>=0)
			{
				m_aLandMine[nCurMine]->ButtonDown(1);
				
			}
			m_nOldMine = nCurMine;
		}
	}
	else
		if(bBothDown==2)		
		{
			if (m_nOldMine != nCurMine)
			{
				int aOldMineTest[9],nOldMineTest=m_nMineTest;
				int nI,nJ;
				for(nI=0;nI<m_nMineTest;nI++)
				{
					aOldMineTest[nI] = m_aMineTest[nI];
				}
				if(nCurMine>=0)
				{
					BOOL bFound;							
					RndBtShdDn(nCurMine);
					
					for(nI=0;nI<m_nMineTest;nI++)
					{
						bFound = FALSE;
						for(nJ=0;nJ<nOldMineTest;nJ++)
						{
							if(m_aMineTest[nI] <= aOldMineTest[nJ])
							{
								if(m_aMineTest[nI] == aOldMineTest[nJ])
								{
									aOldMineTest[nJ] = -1;
									bFound = TRUE;
								}
								break;
							}
							
						}
						if(!bFound)
							m_aLandMine[m_aMineTest[nI]]->ButtonDown(1);
					};
				}
				else
					m_nMineTest = 0;
				if(m_nOldMine>=0)
				{
					for(nI=0;nI<nOldMineTest;nI++)
					{
						if(aOldMineTest[nI] != -1)
							m_aLandMine[aOldMineTest[nI]]->ButtonDown(0);
					}
				}
				m_nOldMine = nCurMine;
			}
		}
		
}
void CLandMine::BothButtonDown(CPoint point)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if (nRow >= m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY )
		return;
	if(nCol<m_nCol && nRow<m_nRow)
	{
		RndBtShdDn(nCurMine);
		if(m_nMineTest>0)
		{
			int nI;
			for(nI=0;nI<m_nMineTest;nI++)
			{
				m_aLandMine[m_aMineTest[nI]]->ButtonDown(1);
			}
		}
		m_nOldMine = nCurMine;
	}
	else
		m_nOldMine = -1;
}
int CLandMine::BothButtonUp(CPoint point)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if (nRow >= m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY )
		return 0;
	if (m_aLandMine[nCurMine]->GetStatus()==MS_OPEN)
	{
		
		int nMineRound,nMineRound1,nMineLeft=0,nNotOpen=0;
		int aMineWillOpen[8];
		nMineRound = GetLeft(nCurMine);
		if(nMineRound>=0)
		{
			if(m_aLandMine[nMineRound]->GetStatus()==MS_FLAG)
				nMineLeft++;
			aMineWillOpen[nNotOpen++] = nMineRound;
			nMineRound1 = GetTop(nMineRound);
			if(nMineRound1>=0)
			{
				if(m_aLandMine[nMineRound1]->GetStatus()==MS_FLAG)
					nMineLeft++;
				aMineWillOpen[nNotOpen++] = nMineRound1;
			}
			nMineRound1 = GetBottom(nMineRound);
			if(nMineRound1>=0)
			{
				if(m_aLandMine[nMineRound1]->GetStatus()==MS_FLAG)
					nMineLeft++;
				aMineWillOpen[nNotOpen++] = nMineRound1;
			}
		}
		nMineRound = GetRight(nCurMine);
		if(nMineRound>=0)
		{
			if(m_aLandMine[nMineRound]->GetStatus()==MS_FLAG)
				nMineLeft++;
			aMineWillOpen[nNotOpen++] = nMineRound;
			nMineRound1 = GetTop(nMineRound);
			if(nMineRound1>=0)
			{
				if(m_aLandMine[nMineRound1]->GetStatus()==MS_FLAG)
					nMineLeft++;
				aMineWillOpen[nNotOpen++] = nMineRound1;
			}
			nMineRound1 = GetBottom(nMineRound);
			if(nMineRound1>=0)
			{
				if(m_aLandMine[nMineRound1]->GetStatus()==MS_FLAG)
					nMineLeft++;
				aMineWillOpen[nNotOpen++] = nMineRound1;
			}
		}
		nMineRound = GetTop(nCurMine);
		if(nMineRound>=0)
		{
			if(nMineRound>=0 && m_aLandMine[nMineRound]->GetStatus()==MS_FLAG)
				nMineLeft++;
			aMineWillOpen[nNotOpen++] = nMineRound;
		}
		nMineRound = GetBottom(nCurMine);
		if(nMineRound>=0)
		{
			
			if(nMineRound>=0 && m_aLandMine[nMineRound]->GetStatus()==MS_FLAG)
				nMineLeft++;
			aMineWillOpen[nNotOpen++] = nMineRound;
		}
		if (nMineLeft>=m_aLandMine[nCurMine]->GetMineNum())
		{
			int nI,nStatus;
			for(nI=0;nI<nNotOpen;nI++)
			{
				nStatus = OpenMine(aMineWillOpen[nI]);
				if(nStatus==FALSE)
				{
					
					int nI;
					for(nI=0;nI<m_nRow*m_nCol;nI++)
					{
						if(m_aLandMine[nI]->GetMineNum() == -1)
							m_aLandMine[nI]->DrawItem(TRUE);
						if(m_aLandMine[nI]->GetStatus() == MS_FLAG)
							m_aLandMine[nI]->DrawItem(TRUE);
					}
					return -1;
				}

			}
		}
		else
		{
			int nI;
			for(nI=0;nI<m_nMineTest;nI++)
			{
				m_aLandMine[m_aMineTest[nI]]->ButtonDown(0);
			}
		}
	}
	else
	{
		int nI;
		for(nI=0;nI<m_nMineTest;nI++)
		{
			m_aLandMine[m_aMineTest[nI]]->ButtonDown(0);
		}
	}
	return 0;
}
int CLandMine::RButtonDown(CPoint point)
{
	int nCol=(point.x-m_nX)/16;
	int nRow=(point.y-m_nY)/16;
	int nCurMine = nCol+nRow*m_nCol;
	if (nRow >= m_nRow || nCol>=m_nCol || point.x<m_nX || point.y<m_nY )
		return 0;
	if(m_aLandMine[nCurMine]->GetStatus() != MS_OPEN)
	{
		MINESTATUS nStatus;
		nStatus = m_aLandMine[nCurMine]->GetStatus();
		switch(nStatus)
		{
		case MS_FLAG:
			m_aLandMine[nCurMine]->SetStatus(MS_QUEST);
			m_aLandMine[nCurMine]->DrawItem(FALSE);
			return 1;
		case MS_QUEST:
			m_aLandMine[nCurMine]->SetStatus(MS_NORMAL);
			m_aLandMine[nCurMine]->DrawItem(FALSE);
			return 0;
		case MS_NORMAL:
			m_aLandMine[nCurMine]->SetStatus(MS_FLAG);
			m_aLandMine[nCurMine]->DrawItem(FALSE);
			return -1;
		}
		
	}
	return 0;
}


void CLandMine::RndBtShdDn(int nCurMine)
{
	m_nMineTest = 0;
	int nMineRound,nMineRound1,nMineRound2;
	
	nMineRound1 = GetLeft(nCurMine);
	nMineRound2 = GetRight(nCurMine);
	if(nMineRound1>=0)
	{
		nMineRound = GetTop(nMineRound1);
		if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
		{
			m_aMineTest[m_nMineTest++] = nMineRound;		//left top
		}
	}
	nMineRound = GetTop(nCurMine);
	if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
	{
		m_aMineTest[m_nMineTest++] = nMineRound;		//top
	}
	
	if(nMineRound2>=0)
	{
		nMineRound = GetTop(nMineRound2);
		if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
		{
			m_aMineTest[m_nMineTest++] = nMineRound;		//right top
		}
	}
	if(nMineRound1>=0 && (m_aLandMine[nMineRound1]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound1]->GetStatus()==MS_QUEST))
		m_aMineTest[m_nMineTest++] = nMineRound1;		//left
	if(m_aLandMine[nCurMine]->GetStatus() == MS_NORMAL ||m_aLandMine[nCurMine]->GetStatus() == MS_QUEST)
		m_aMineTest[m_nMineTest++] = nCurMine;			//current
	if(nMineRound2>=0 && (m_aLandMine[nMineRound2]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound2]->GetStatus()==MS_QUEST))
		m_aMineTest[m_nMineTest++] = nMineRound2;		//right
	
	if(nMineRound1>=0)
	{
		nMineRound = GetBottom(nMineRound1);
		if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
		{
			m_aMineTest[m_nMineTest++] = nMineRound;		//left bot
		}
		
	}
	
	nMineRound = GetBottom(nCurMine);
	if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
	{
		m_aMineTest[m_nMineTest++] = nMineRound;		//bot
	}
	
	if(nMineRound2>=0)
	{
		nMineRound = GetBottom(nMineRound2);
		if(nMineRound>=0 && (m_aLandMine[nMineRound]->GetStatus()==MS_NORMAL || m_aLandMine[nMineRound]->GetStatus()==MS_QUEST))
		{
			m_aMineTest[m_nMineTest++] = nMineRound;		//right bot
		}
	}
		
};