// DragWork.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "test2.h"
#include "Windowsx.h"
#include "windows.h"
#include "tchar.h"

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
VOID                LinePaint(BOOL, HDC, HPEN, int, int, int, int);//绘制电路图线

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
	LoadString(hInstance, IDC_TEST2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化: 
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST2));

	// 主消息循环: 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
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

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST2));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_TEST2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

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
	static POINT ptOld, ptNew;//标记移动的坐标
	static POINT pt1, pt2, pt3, pt4, pt5, pt6,
		pt1Move, pt1New, pt1Last, pt2Move, pt2New, pt2Last,
		pt3Move, pt3New, pt3Last, pt4Move, pt4New, pt4Last,
		pt5Move, pt5New, pt5Last, pt6Move, pt6New, pt6Last;//绘制三条线段的坐标点
	static RECT rectOld, rectMove, rectNew, rectLast;//绘制大矩形
	static RECT rectOld1, rectMove1, rectNew1, rectLast1;//绘制小矩形
	static bool bIsMove = false;//判断是否移动
	HPEN hPen = CreatePen(PS_SOLID, 1, BLACK_PEN);//绘制电路图
	HPEN hPen1 = CreatePen(PS_SOLID, 1, WHITE_PEN);//擦除电路图

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
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
		// TODO:  在此添加任意绘图代码...
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		Rectangle(hdc, rectOld.left, rectOld.top, rectOld.right, rectOld.bottom);
		SelectObject(hdc, hPen);
		Rectangle(hdc, rectOld1.left, rectOld1.top, rectOld1.right, rectOld1.bottom);
		MoveToEx(hdc, pt1.x, pt1.y, NULL); LineTo(hdc, pt2.x, pt2.y);
		MoveToEx(hdc, pt3.x, pt3.y, NULL); LineTo(hdc, pt4.x, pt4.y);
		MoveToEx(hdc, pt5.x, pt5.y, NULL); LineTo(hdc, pt6.x, pt6.y);
		EndPaint(hWnd, &ps);
		break;
	case WM_RBUTTONDOWN:
		//绘制第一个矩形
		hdc = GetDC(hWnd);
		SetRect(&rectOld, 100, 100, 250, 300);//保存上次矩形的位置
		SetRect(&rectOld1, 150, 103, 200, 297);
		pt1.x = 102; pt1.y = 180; 	pt2.x = 150; pt2.y = 180;
		pt3.x = 102; pt3.y = 220; 	pt4.x = 150; pt4.y = 220;
		pt5.x = 200; pt5.y = 200; 	pt6.x = 248; pt6.y = 200;
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		Rectangle(hdc, rectOld.left, rectOld.top, rectOld.right, rectOld.bottom);
		SelectObject(hdc, hPen);
		Rectangle(hdc, rectOld1.left, rectOld1.top, rectOld1.right, rectOld1.bottom);
		MoveToEx(hdc, pt1.x, pt1.y, NULL); LineTo(hdc, pt2.x, pt2.y);
		MoveToEx(hdc, pt3.x, pt3.y, NULL); LineTo(hdc, pt4.x, pt4.y);
		MoveToEx(hdc, pt5.x, pt5.y, NULL); LineTo(hdc, pt6.x, pt6.y);
		ReleaseDC(hWnd, hdc);
		return 0;
	case WM_LBUTTONDOWN:
		//确定鼠标起始位置
		ptOld.x = GET_X_LPARAM(lParam);
		ptOld.y = GET_Y_LPARAM(lParam);
		if (PtInRect(&rectOld, ptOld))
		{
			bIsMove = true;
		}
		else
		{
			bIsMove = false;
		}
		return 0;
	case WM_LBUTTONUP:
		//确定鼠标释放位置
		if (bIsMove)
		{
			hdc = GetDC(hWnd);
			bIsMove = false;
			ptNew.x = GET_X_LPARAM(lParam);
			ptNew.y = GET_Y_LPARAM(lParam);
			rectNew.left = rectOld.left + (ptNew.x - ptOld.x);
			rectNew.top = rectOld.top + (ptNew.y - ptOld.y);
			rectNew.right = rectNew.left + 150;
			rectNew.bottom = rectNew.top + 200;
			rectNew1.left = rectOld1.left + (ptNew.x - ptOld.x);
			rectNew1.top = rectOld1.top + (ptNew.y - ptOld.y);
			rectNew1.right = rectNew1.left + 50;
			rectNew1.bottom = rectNew1.top + 194;
			pt1New.x = pt1.x + (ptNew.x - ptOld.x); pt1New.y = pt1.y + (ptNew.y - ptOld.y);
			pt2New.x = pt2.x + (ptNew.x - ptOld.x); pt2New.y = pt2.y + (ptNew.y - ptOld.y);
			pt3New.x = pt3.x + (ptNew.x - ptOld.x); pt3New.y = pt3.y + (ptNew.y - ptOld.y);
			pt4New.x = pt4.x + (ptNew.x - ptOld.x); pt4New.y = pt4.y + (ptNew.y - ptOld.y);
			pt5New.x = pt5.x + (ptNew.x - ptOld.x); pt5New.y = pt5.y + (ptNew.y - ptOld.y);
			pt6New.x = pt6.x + (ptNew.x - ptOld.x); pt6New.y = pt6.y + (ptNew.y - ptOld.y);

			CopyRect(&rectOld, &rectNew);
			CopyRect(&rectOld1, &rectNew1);
			pt1.x = pt1New.x; pt1.y = pt1New.y; pt2.x = pt2New.x; pt2.y = pt2New.y;
			pt3.x = pt3New.x; pt3.y = pt3New.y; pt4.x = pt4New.x; pt4.y = pt4New.y;
			pt5.x = pt5New.x; pt5.y = pt5New.y; pt6.x = pt6New.x; pt6.y = pt6New.y;
			InvalidateRect(hWnd, NULL, TRUE);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_MOUSEMOVE:
		if (bIsMove)
		{
			//鼠标移动画边框
			POINT ptMove;
			ptMove.x = GET_X_LPARAM(lParam);
			ptMove.y = GET_Y_LPARAM(lParam);
			rectMove.left = rectOld.left + (ptMove.x - ptOld.x);
			rectMove.top = rectOld.top + (ptMove.y - ptOld.y);
			rectMove.right = rectMove.left + 150;
			rectMove.bottom = rectMove.top + 200;
			rectMove1.left = rectOld1.left + (ptMove.x - ptOld.x);
			rectMove1.top = rectOld1.top + (ptMove.y - ptOld.y);
			rectMove1.right = rectMove1.left + 50;
			rectMove1.bottom = rectMove1.top + 194;
			pt1Move.x = pt1.x + (ptMove.x - ptOld.x); pt1Move.y = pt1.y + (ptMove.y - ptOld.y);
			pt2Move.x = pt2.x + (ptMove.x - ptOld.x); pt2Move.y = pt2.y + (ptMove.y - ptOld.y);
			pt3Move.x = pt3.x + (ptMove.x - ptOld.x); pt3Move.y = pt3.y + (ptMove.y - ptOld.y);
			pt4Move.x = pt4.x + (ptMove.x - ptOld.x); pt4Move.y = pt4.y + (ptMove.y - ptOld.y);
			pt5Move.x = pt5.x + (ptMove.x - ptOld.x); pt5Move.y = pt5.y + (ptMove.y - ptOld.y);
			pt6Move.x = pt6.x + (ptMove.x - ptOld.x); pt6Move.y = pt6.y + (ptMove.y - ptOld.y);

			hdc = GetDC(hWnd);
			//擦掉上一次的拖动的矩形轨迹
			SelectObject(hdc, GetStockObject(WHITE_PEN));
			SelectObject(hdc, GetStockObject(WHITE_BRUSH));
			Rectangle(hdc, rectLast.left, rectLast.top, rectLast.right, rectLast.bottom);

			////实时移动矩形
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			Rectangle(hdc, rectMove.left, rectMove.top, rectMove.right, rectMove.bottom);
			SelectObject(hdc, hPen);
			Rectangle(hdc, rectMove1.left, rectMove1.top, rectMove1.right, rectMove1.bottom);
			MoveToEx(hdc, pt1Move.x, pt1Move.y, NULL); LineTo(hdc, pt2Move.x, pt2Move.y);
			MoveToEx(hdc, pt3Move.x, pt3Move.y, NULL); LineTo(hdc, pt4Move.x, pt4Move.y);
			MoveToEx(hdc, pt5Move.x, pt5Move.y, NULL); LineTo(hdc, pt6Move.x, pt6Move.y);
			CopyRect(&rectLast, &rectMove);
			CopyRect(&rectLast1, &rectMove1);
			pt1Last.x = pt1Move.x; pt1Last.y = pt1Move.y; pt2Last.x = pt2Move.x; pt2Last.y = pt2Move.y;
			pt3Last.x = pt3Move.x; pt3Last.y = pt3Move.y; pt4Last.x = pt4Move.x; pt4Last.y = pt4Move.y;
			pt5Last.x = pt5Move.x; pt5Last.y = pt5Move.y; pt6Last.x = pt6Move.x; pt6Last.y = pt6Move.y;
		}
		return 0;
	case WM_CHAR:
		//处理按下空格键的旋转问题
		POINT center;
		center.x = (rectOld.left + rectOld.right) / 2;
		center.y = (rectOld.top + rectOld.bottom) / 2;
		INT X1, X2, Y1, Y2;
		if (wParam == VK_SPACE)
		{
			X1 = center.x + center.y - rectOld.bottom;//大矩形
			Y1 = rectOld.left - center.x + center.y;
			X2 = center.x + center.y - rectOld.top;
			Y2 = rectOld.right - center.x + center.y;
			rectOld.left = X1;
			rectOld.top = Y1;
			rectOld.right = X2;
			rectOld.bottom = Y2;

			X1 = center.x + center.y - rectOld1.bottom;//小矩形
			Y1 = rectOld1.left - center.x + center.y;
			X2 = center.x + center.y - rectOld1.top;
			Y2 = rectOld1.right - center.x + center.y;
			rectOld1.left = X1;
			rectOld1.top = Y1;
			rectOld1.right = X2;
			rectOld1.bottom = Y2;

			X1 = center.x + center.y - pt1.y;//线段1
			Y1 = pt1.x - center.x + center.y;
			X2 = center.x + center.y - pt2.y;
			Y2 = pt2.x - center.x + center.y;
			pt1.x = X1; pt1.y = Y1; pt2.x = X2; pt2.y = Y2;
			X1 = center.x + center.y - pt3.y;//线段2
			Y1 = pt3.x - center.x + center.y;
			X2 = center.x + center.y - pt4.y;
			Y2 = pt4.x - center.x + center.y;
			pt3.x = X1; pt3.y = Y1; pt4.x = X2; pt4.y = Y2;
			X1 = center.x + center.y - pt5.y;//线段3
			Y1 = pt5.x - center.x + center.y;
			X2 = center.x + center.y - pt6.y;
			Y2 = pt6.x - center.x + center.y;
			pt5.x = X1; pt5.y = Y1; pt6.x = X2; pt6.y = Y2;
		}
		InvalidateRect(hWnd, NULL, TRUE);
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