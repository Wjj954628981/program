// DlgPainter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "painter.h"
#include "DlgPainter.h"
#include "afxdialogex.h"


// DlgPainter �Ի���

IMPLEMENT_DYNAMIC(DlgPainter, CDialog)

DlgPainter::DlgPainter(CWnd* pParent /*=NULL*/)
	: CDialog(DlgPainter::IDD, pParent)
{

}

DlgPainter::~DlgPainter()
{
}

void DlgPainter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgPainter, CDialog)
END_MESSAGE_MAP()


// DlgPainter ��Ϣ�������
