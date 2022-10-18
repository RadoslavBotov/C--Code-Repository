#include <math.h>
#include <iostream>
#include "MyWindow.h"
#include "RenderState.h"

double map(double number, double input_start, double input_end, double output_start, double output_end)
{
	double r = input_end - input_start;
	double R = output_end - output_start;

	double x = number - input_start;
	double y = (R / r) * x;

	return output_start + y;
}

//===========================================================================================

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	{
		if (MessageBox(hWnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
			DestroyWindow(hWnd);
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hWnd, &ps);
	}
	return 0;

	case WM_SIZE:
	{
		RECT rect;
		GetClientRect(hWnd, &rect);

		my_render_state.allocateMemory(rect.right - rect.left, rect.bottom - rect.top);
	}
	return 0;

	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return TRUE;
}

MyWindow::MyWindow()
	: m_hInstance(GetModuleHandle(nullptr))
{	
	WNDCLASS wndClass = {};
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpszClassName = m_CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	//DWORD myStyle = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	DWORD myStyle =  WS_OVERLAPPEDWINDOW;

	unsigned width = 400;
	unsigned height = 400;

	RECT rect;
	rect.left = 300;
	rect.top = 300;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, myStyle, false);

	m_hWnd = CreateWindowEx(
		0,								// Optional window styles.
		m_CLASS_NAME,					// Window class
		L"Title",						// Window text
		myStyle,						// Window style
		rect.left,						// Size and position
		rect.top,						// ...
		rect.right - rect.left,			// ...
		rect.bottom - rect.top,			// ...
		NULL,							// Parent window 
		NULL,							// Menu
		m_hInstance,					// Instance handle
		NULL							// Additional application data
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

MyWindow::~MyWindow()
{
	UnregisterClass(m_CLASS_NAME, m_hInstance);
}

bool MyWindow::ProcessMessages()
{
	// Input
	if (m_hWnd == NULL)
		return false;

	MSG msg = {};
	HDC hdc = GetDC(m_hWnd);
	
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		// messages
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Simulate
	unsigned int* pixel = (unsigned int*)my_render_state.m_bMemory;
	for (size_t y = 0; y < my_render_state.m_wHeight; y++)
		for (size_t x = 0; x < my_render_state.m_wWidth; x++)
			*pixel++ = map(x * y, 0, my_render_state.m_wHeight * my_render_state.m_wWidth, 0, 255);

	// Render
	StretchDIBits(
		hdc,					// hdc
		0,						// xDest
		0,						// yDest
		my_render_state.m_wWidth,		// DestWidth
		my_render_state.m_wHeight,		// DestHeigth
		0,						// xSrc
		0,						// ySrc
		my_render_state.m_wWidth,		// SrcWidth
		my_render_state.m_wHeight,		// SrcHeight
		my_render_state.m_bMemory,		// *lpBits
		&my_render_state.m_bitmapInfo,	// *lpbmi
		DIB_RGB_COLORS,			// iUsage
		SRCCOPY					// rop
	);

	return true;
}