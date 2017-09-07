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
    static WCHAR str[256];
    int len;

    static int x = 100;
    static int y = 100;

    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
            x -= 8;
            break;
        case VK_RIGHT:
            x += 8;
            break;
        case VK_UP:
            y -= 8;
            break;
        case VK_DOWN:
            y += 8;
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_CHAR:
        if ((WCHAR)wParam == 8)
        {
            len = lstrlen(str);
            str[--len] = 0;
        }
        else
        {
            len = lstrlen(str);
            str[len] = (WCHAR)wParam;
            str[len + 1] = 0;
        }        
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc, 10, 10, str, lstrlen(str));
        EndPaint(hWnd, &ps);
        break;
    case WM_LBUTTONDOWN:
        
        break;
    }


    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}