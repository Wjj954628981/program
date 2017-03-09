// DlgInput.cpp : 实现文件
//

#include "stdafx.h"
#include "MySdi.h"
#include "DlgInput.h"
#include "afxdialogex.h"


// DlgInput 对话框

IMPLEMENT_DYNAMIC(DlgInput, CDialog)

DlgInput::DlgInput(CWnd* pParent /*=NULL*/)
	: CDialog(DlgInput::IDD, pParent)
	, m_input(_T(""))
	, m_color(0)
{

}

DlgInput::~DlgInput()
{
}

void DlgInput::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Radio(pDX, IDC_RADIO1, m_color);
}


BEGIN_MESSAGE_MAP(DlgInput, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, &DlgInput::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DlgInput::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &DlgInput::OnBnClickedRadio3)
END_MESSAGE_MAP()


// DlgInput 消息处理程序


void DlgInput::OnBnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_color = 0;
}


void DlgInput::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_color = 1;
}


void DlgInput::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_color = 2;
}
