#pragma once


// DlgPainter �Ի���

class DlgPainter : public CDialog
{
	DECLARE_DYNAMIC(DlgPainter)

public:
	DlgPainter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgPainter();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
