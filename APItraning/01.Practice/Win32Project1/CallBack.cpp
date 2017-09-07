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
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
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

void CALLBACK TimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
    HDC hdc;
    int i;
    hdc = GetDC(hWnd);
    srand((unsigned)time(NULL));
    for (i = 0; i < 100 ; ++i)
    {
        SetPixel(hdc, rand()%500, rand()%500,
            RGB(rand()%256, rand()%256, rand()%256));
    }
    ReleaseDC(hWnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        SetTimer(hWnd, 1, 100, (TIMERPROC)TimerProc);
        break;
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}