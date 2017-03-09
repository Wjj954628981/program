// rect_game.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "rect_game.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO:  �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_RECT_GAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RECT_GAME));

	// ����Ϣѭ��: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����:  MyRegisterClass()
//
//  Ŀ��:  ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RECT_GAME));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_RECT_GAME);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����:  InitInstance(HINSTANCE, int)
//
//   Ŀ��:  ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

/*   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);*/
   hWnd = CreateWindow(
	   szWindowClass,
	   szTitle,
	   WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, CW_USEDEFAULT,
	   500, 500,
	   NULL,
	   NULL,
	   hInstance,
	   NULL
	   );
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static RECT a, b, c, d;//�ĸ�Ҫ��ľ���
	static RECT m;//�ƶ��ľ���
	static POINT pt;
	static bool IsMove = false;
	static int time = 0;
	static int v = 5;
//	static int v1[]= { v, v };
//	static int v2[] = { -v, v };
//	static int v3[] = { v, -v };
//	static int v4[] = { -v, -v };
	RECT clientRect;
	HPEN hPen1 = CreatePen(PS_SOLID, 1, RGB(255,0,0));//��һ������Ϊ��ɫ
	HPEN hPen2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));//�ڶ�������Ϊ��ɫ
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 0, 0));//��ɫ
	HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 0, 255));//��ɫ
/*	if (a.left <= 0 || a.right >= 500)
		v1[0] = -v1[0];
	if (a.top <= 0 || a.bottom >= 500)
		v1[1] = -v1[1];*/
	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, 9999, 1, NULL);
		GetCursorPos(&pt);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��: 
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		time++;
		v = v + 0.01;

		//�����ƶ��ľ���
		SelectObject(hdc, hPen1);
		SelectObject(hdc, hBrush1);

		m.left = (clientRect.left + clientRect.right) / 2 - 20;
		m.top = (clientRect.bottom + clientRect.top) / 2 + 20;
		m.right = (clientRect.left + clientRect.right) / 2 + 20;
		m.bottom = (clientRect.bottom + clientRect.top) / 2 - 20;
		Rectangle(hdc, m.left, m.top, m.right, m.bottom);

		//�Լ������ĸ�����
		SelectObject(hdc, hPen2);
		SelectObject(hdc, hBrush2);

		a.left = clientRect.left + 10 + v * time;
		a.top = clientRect.top + 10 + v * time;
		a.right = clientRect.left + 70 + v * time;
		a.bottom = clientRect.top + 70 + v * time;
		Rectangle(hdc, a.left, a.top, a.right, a.bottom);

		b.left = clientRect.left + 300 - v * time;
		b.top = clientRect.top + v * time;
		b.right = clientRect.left + 360 - v * time;
		b.bottom = clientRect.top + 50 + v * time;
		Rectangle(hdc, b.left, b.top, b.right, b.bottom);

		c.left = clientRect.left + 10 + v * time;
		c.top = clientRect.top + 350 - v * time;
		c.right = clientRect.left + 40 + v * time;
		c.bottom = clientRect.top + 410 - v * time;
		Rectangle(hdc, c.left, c.top, c.right, c.bottom);

		d.left = clientRect.left + 370 - v * time;
		d.top = clientRect.top + 350 - v * time;
		d.right = clientRect.left + 460 - v * time;
		d.bottom = clientRect.top + 390 - v * time;
		Rectangle(hdc, d.left, d.top, d.right, d.bottom);

		// TODO:  �ڴ���������ͼ����...
		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:
		pt.x = LOWORD(lParam);
		pt.y = HIWORD(lParam);
		if (PtInRect(&m, pt))
		{
			IsMove = true;
		}
		else
		{
			IsMove = false;
		}
		break;
	case WM_LBUTTONUP:
		if (IsMove){
			pt.x = LOWORD(lParam);
			pt.y = HIWORD(lParam);
		}
		break;
	case WM_MOUSEMOVE:
		if (IsMove){

		}
	case WM_TIMER:
		if (wParam == 9999)
			InvalidateRect(hWnd, NULL, true);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
