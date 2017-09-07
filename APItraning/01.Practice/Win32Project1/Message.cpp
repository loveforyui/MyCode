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
        
        break;
    case WM_LBUTTONDOWN:
        MessageBox(hWnd,L"Clicked L button", L"MessageBox", MB_OK);
        // MB_OK
        // MB_ABORTRETRYIGNORE
        // MB_OKCANCEL
        // MB_RETRYCANCEL
        // MB_YESNO
        // MB_TESNOCANCEL

        //��	����
        //IDABORT	Abort��ư�� ������.
        //IDCANCEL	Cancel ��ư�� ������.
        //IDIGNORE	Ignore ��ư�� ������.
        //IDNO	No��ư�� ������.
        //IDOK	OK ��ư�� ������.
        //IDRETRY	Retry ��ư�� ������.
        //IDYES	Yes ��ư�� ������.
        //���� ����ڿ��� ������ ����� ���ΰ��� ���� �ʹٸ� ������ ���� �ڵ带 �ۼ��ϸ� �ȴ�.

        //if (MessageBox(hWnd, "������ ��� �ϰڽ��ϱ�", "����", MB_YESNO) == IDYES) {
        //    // ���� ��� ó��
        //}
        //else {
        //    // ���� ����
        //}
        break;
    }


    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}