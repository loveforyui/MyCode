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

        //값	설명
        //IDABORT	Abort버튼을 눌렀다.
        //IDCANCEL	Cancel 버튼을 눌렀다.
        //IDIGNORE	Ignore 버튼을 눌렀다.
        //IDNO	No버튼을 눌렀다.
        //IDOK	OK 버튼을 눌렀다.
        //IDRETRY	Retry 버튼을 눌렀다.
        //IDYES	Yes 버튼을 눌렀다.
        //만약 사용자에게 게임을 계속할 것인가를 묻고 싶다면 다음과 같이 코드를 작성하면 된다.

        //if (MessageBox(hWnd, "게임을 계속 하겠습니까", "질문", MB_YESNO) == IDYES) {
        //    // 게임 계속 처리
        //}
        //else {
        //    // 게임 중지
        //}
        break;
    }


    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}