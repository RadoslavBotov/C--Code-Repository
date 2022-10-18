#pragma once
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class MyWindow
{
public:
	MyWindow();
	MyWindow(const MyWindow&) = delete;
	MyWindow operator = (const MyWindow&) = delete;
	~MyWindow();

	bool ProcessMessages();

private:
	const wchar_t* m_CLASS_NAME = L"Class_Name"; // smart pointer
	HINSTANCE m_hInstance;
	HWND m_hWnd;
};