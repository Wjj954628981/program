#pragma once


// DlgPainter 对话框

class DlgPainter : public CDialog
{
	DECLARE_DYNAMIC(DlgPainter)

public:
	DlgPainter(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgPainter();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
