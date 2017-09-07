#include <Windows.h>
#include <tchar.h>
#include <time.h>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd) {

    WNDCLASSEX wcex;
    memset(&wcex, 0, sizeof(wcex));

    wcex.cbSize = sizeof(wcex);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hInstance = hInstance;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIconSm = NULL;
    wcex.lpszMenuName = NULL;
    wcex.lpfnWndProc = WndProc;
    wcex.lpszClassName = L"drawPro";

    RegisterClassEx(&wcex);

    HWND hWnd = CreateWindow(wcex.lpszClassName, wcex.lpszClassName,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
        MessageBox(NULL, L"can't create window", L"error", MB_ICONERROR | MB_OK);
        return -1;
    }

    ShowWindow(hWnd, SW_SHOW);

    MSG msg;
    memset(&msg, 0, sizeof(msg));

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    time_t mTime;
    static HANDLE hTimer;
    static LPSTR str;
    static wchar_t wstr[256];
    RECT rt = {10, 10, 400, 30};
    INT border = 2;

    switch (uMsg)
    {
    case WM_CREATE:
        hTimer = (HANDLE)SetTimer(hWnd, 1, 1000, NULL);
        str = "";
        SendMessage(hWnd, WM_TIMER, 1, 0);
        break;

    case WM_TIMER:
        time(&mTime);
        str = ctime(&mTime);
        mbstowcs(wstr, str, strlen(str));    
        wstr[strlen(str) - 1] = '\0';
        InvalidateRect(hWnd, &rt, TRUE);
        break;

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);        
        //Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
        TextOut(hdc, rt.left, rt.top, wstr, strlen(str) - 1);
        MoveToEx(hdc, rt.left - border, rt.top - border, NULL);
        LineTo(hdc, rt.right + border, rt.top - border);
        LineTo(hdc, rt.right + border, rt.bottom + border);
        LineTo(hdc, rt.left - border, rt.bottom + border);
        LineTo(hdc, rt.left - border, rt.top - border);
        //DrawText(HDC hDC, LPCTSTR lpString, int nCount, LPRECT lpRect, UINT uFormat);
        //DrawText(hdc, wstr, lstrlen(wstr), rect, 100);
        EndPaint(hWnd, &ps);
        break;

    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}