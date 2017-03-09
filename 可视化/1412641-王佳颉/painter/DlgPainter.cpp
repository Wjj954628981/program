// DlgPainter.cpp : 实现文件
//

#include "stdafx.h"
#include "painter.h"
#include "DlgPainter.h"
#include "afxdialogex.h"


// DlgPainter 对话框

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


// DlgPainter 消息处理程序
