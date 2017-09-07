#include<Windows.h>
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd) {

    WNDCLASSEX wcex;
    memset(&wcex, 0, sizeof(wcex));

    wcex.cbSize = sizeof(wcex);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
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
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 10, 10, L"안녕하신지라?", lstrlen(L"안녕하신지라?"));
        EndPaint(hWnd, &ps);
        break;
    case WM_LBUTTONDOWN:
        hdc = GetDC(hWnd);        
        TextOut(hdc, 100, 100, L"안녕하신지라?", lstrlen(L"안녕하신지라?"));
        //SetTextAlign(hdc, TA_RIGHT);
        TextOut(hdc, 100, 200, L"hello", lstrlen(L"hello"));
        //int DrawText(HDC hDC, LPCTSTR lpString, int nCount, LPRECT lpRect, UINT uFormat);
        ReleaseDC(hWnd, hdc);
        //EndPaint(hWnd, &ps);
        break;
    }


    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}