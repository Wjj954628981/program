#pragma once


// DlgInput �Ի���

class DlgInput : public CDialog
{
	DECLARE_DYNAMIC(DlgInput)

public:
	DlgInput(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgInput();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	CString m_input;
	int m_color;
};
