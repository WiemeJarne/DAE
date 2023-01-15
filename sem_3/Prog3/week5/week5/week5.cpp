// week5.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "week5.h"
#include <windowsx.h>
#include <sstream>
#include <vector>


std::vector<POINT> g_PointsVec;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WEEK5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WEEK5));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WEEK5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WEEK5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
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
        }
        break;
    case WM_LBUTTONUP:
        {
#ifdef _UNICODE
        std::wstringstream buffer;
#else
        std::stringstream buffer;
#endif
        
            //buffer << GET_X_LPARAM(lParam) << TEXT(", ") << GET_Y_LPARAM(lParam);
            //MessageBox(NULL, buffer.str().c_str(), TEXT("mouse location"), MB_OK);

            g_PointsVec.push_back({ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) });
            InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_RBUTTONUP:
    {
        g_PointsVec.clear();
        InvalidateRect(hWnd, NULL, true);
    }
    break;
    case WM_ACTIVATE:
    {
        if (wParam == WA_ACTIVE)
        {
            //MessageBox(NULL, TEXT("window is active"), TEXT("window activated"), MB_OK);
            SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)TEXT("Active"));
        }
        else
        {
            SendMessage(hWnd, WM_SETTEXT, 0, (LPARAM)TEXT("Inactive go away"));
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        HPEN blackPen = CreatePen(PS_SOLID, 1, RGB(80, 80, 50));
        HPEN oldPen = (HPEN)SelectObject(hdc, blackPen);

        HBRUSH blackBrush = CreateSolidBrush(RGB(80, 80, 50));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blackBrush);

        int amountOfPointPerShape{ 3 };

        for(int index{}; index < static_cast<int>(g_PointsVec.size()); ++index)
        {
            if((index + 1) % amountOfPointPerShape == 1)
            {
                MoveToEx(hdc, g_PointsVec[index].x, g_PointsVec[index].y, 0);
                Ellipse(hdc, g_PointsVec[index].x - 2, g_PointsVec[index].y - 2, g_PointsVec[index].x + 2, g_PointsVec[index].y + 2);
            }
            else if((index + 1) % amountOfPointPerShape == 2)
            {
                LineTo(hdc, g_PointsVec[index].x, g_PointsVec[index ].y);
                Ellipse(hdc, g_PointsVec[index].x - 2, g_PointsVec[index].y - 2, g_PointsVec[index].x + 2, g_PointsVec[index].y + 2);
            }
            else if((index + 1) % amountOfPointPerShape == 0)
            {
                LineTo(hdc, g_PointsVec[index].x, g_PointsVec[index].y);
                Ellipse(hdc, g_PointsVec[index].x - 2, g_PointsVec[index].y - 2, g_PointsVec[index].x + 2, g_PointsVec[index].y + 2);

            	LineTo(hdc, g_PointsVec[index - 2].x, g_PointsVec[index - 2].y);
            	Ellipse(hdc, g_PointsVec[index].x - 2, g_PointsVec[index].y - 2, g_PointsVec[index].x + 2, g_PointsVec[index].y + 2);
            }
            wchar_t buffer[32];
            _itow_s(amountOfPointPerShape, buffer, 10);
            SetWindowText(hWnd, buffer);
        }


        SelectObject(hdc, oldBrush);
        DeleteObject(blackBrush);

        SelectObject(hdc, oldPen);
        DeleteObject(blackPen);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
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
