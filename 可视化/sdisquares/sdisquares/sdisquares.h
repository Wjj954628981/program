
// sdisquares.h : sdisquares Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CsdisquaresApp:
// �йش����ʵ�֣������ sdisquares.cpp
//

class CsdisquaresApp : public CWinAppEx
{
public:
	CsdisquaresApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CsdisquaresApp theApp;
