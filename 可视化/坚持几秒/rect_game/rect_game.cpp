// rect_game.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "rect_game.h"

#define MAX_LOADSTRING 100

// 全局变量: 
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明: 
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

 	// TODO:  在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_RECT_GAME, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RECT_GAME));

	// 主消息循环: 
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
//  函数:  MyRegisterClass()
//
//  目的:  注册窗口类。
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
//   函数:  InitInstance(HINSTANCE, int)
//
//   目的:  保存实例句柄并创建主窗口
//
//   注释: 
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

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
//  函数:  WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static RECT a, b, c, d;//四个要躲的矩形
	static RECT m;//移动的矩形
	static POINT pt;
	static bool IsMove = false;
	static int time = 0;
	static int v = 5;
//	static int v1[]= { v, v };
//	static int v2[] = { -v, v };
//	static int v3[] = { v, -v };
//	static int v4[] = { -v, -v };
	RECT clientRect;
	HPEN hPen1 = CreatePen(PS_SOLID, 1, RGB(255,0,0));//第一个画笔为红色
	HPEN hPen2 = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));//第二个画笔为蓝色
	HBRUSH hBrush1 = CreateSolidBrush(RGB(255, 0, 0));//蓝色
	HBRUSH hBrush2 = CreateSolidBrush(RGB(0, 0, 255));//蓝色
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
		// 分析菜单选择: 
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

		//可以移动的矩形
		SelectObject(hdc, hPen1);
		SelectObject(hdc, hBrush1);

		m.left = (clientRect.left + clientRect.right) / 2 - 20;
		m.top = (clientRect.bottom + clientRect.top) / 2 + 20;
		m.right = (clientRect.left + clientRect.right) / 2 + 20;
		m.bottom = (clientRect.bottom + clientRect.top) / 2 - 20;
		Rectangle(hdc, m.left, m.top, m.right, m.bottom);

		//自己动的四个矩形
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

		// TODO:  在此添加任意绘图代码...
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

// “关于”框的消息处理程序。
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
