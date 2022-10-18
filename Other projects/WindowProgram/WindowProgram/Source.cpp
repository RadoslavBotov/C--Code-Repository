#include<iostream>
#include<Windows.h>
using namespace std;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (uMsg)
    {
    case WM_CLOSE:
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        {
           PAINTSTRUCT ps;
           HDC hdc = BeginPaint(hWnd, &ps);
           FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
           EndPaint(hWnd, &ps);
        }
        return 0;

    default:
        result = DefWindowProc(hWnd, uMsg, wParam, lParam);
        break;
    }

    return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Window_Class";

    WNDCLASS window_class = { };

    window_class.lpfnWndProc = WindowProc;
    window_class.hInstance = hInstance;
    window_class.lpszClassName = CLASS_NAME;

    RegisterClass(&window_class);

    // Create the window.

    HWND hWnd = CreateWindowEx(
        0,                          // Optional window styles.
        CLASS_NAME,                 // Window class
        L"Title",                   // Window text
        WS_OVERLAPPEDWINDOW,        // Window style
        CW_USEDEFAULT,              // Size and position
        CW_USEDEFAULT,              //
        CW_USEDEFAULT,              //
        CW_USEDEFAULT,              //
        NULL,                       // Parent window    
        NULL,                       // Menu
        hInstance,                  // Instance handle
        NULL                        // Additional application data
    );

    if (hWnd == NULL)
    {
        return 0;
    }

    ShowWindow(hWnd, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}