// DlgInput.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MySdi.h"
#include "DlgInput.h"
#include "afxdialogex.h"


// DlgInput �Ի���

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


// DlgInput ��Ϣ�������


void DlgInput::OnBnClickedRadio1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_color = 0;
}


void DlgInput::OnBnClickedRadio2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_color = 1;
}


void DlgInput::OnBnClickedRadio3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_color = 2;
}
