// ExamProg3Exercise2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "ExamProg3Exercise2.h"
#include <windowsx.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

std::vector<POINT> g_PointsVec;
std::vector<POINT> g_CenterPoints;
constexpr int g_Radius(75);
constexpr int g_AmountOfPointsPerShape(7);

static_assert(g_AmountOfPointsPerShape % 2 != 0, "amountOfPoints is even this variable has to be odd");

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
    LoadStringW(hInstance, IDC_EXAMPROG3EXERCISE2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAMPROG3EXERCISE2));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAMPROG3EXERCISE2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAMPROG3EXERCISE2);
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
        //calculate the point and add them to the vector
        const float angleBetweenPoints{ (2.f * static_cast<float>(M_PI)) / g_AmountOfPointsPerShape };
        const float currentAngle{};

        for (int index{}; index < g_AmountOfPointsPerShape; ++index)
        {
            g_PointsVec.push_back({ GET_X_LPARAM(lParam) + (long)(g_Radius * cos(M_PI_2 + angleBetweenPoints * index)), GET_Y_LPARAM(lParam) + (long)(g_Radius * sin(M_PI_2 + angleBetweenPoints * index)) });
        }

        g_CenterPoints.push_back({ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) });
        
        InvalidateRect(hWnd, NULL, true);
    }
    break;
    case WM_RBUTTONUP:
    {
        g_PointsVec.clear();
        g_CenterPoints.clear();
        InvalidateRect(hWnd, NULL, true);
    }
    break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...

            HPEN blackPen = CreatePen(PS_SOLID, 3, RGB(80, 80, 50));
            HPEN oldPen = (HPEN)SelectObject(hdc, blackPen);

            HBRUSH whitekBrush = CreateSolidBrush(RGB(255, 255, 255));
            HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, whitekBrush);

            for (int index{}; index < g_CenterPoints.size(); ++index)
            {
                Ellipse(hdc, g_CenterPoints[index].x - g_Radius, g_CenterPoints[index].y - g_Radius, g_CenterPoints[index].x + g_Radius, g_CenterPoints[index].y + g_Radius);
            }

            SelectObject(hdc, oldBrush);
            DeleteObject(whitekBrush);

            HBRUSH blackBrush = CreateSolidBrush(RGB(80, 80, 50));
            oldBrush = (HBRUSH)SelectObject(hdc, blackBrush);

            const size_t amountOfShapes(g_PointsVec.size() / g_AmountOfPointsPerShape);

            for (int index{}; index < g_PointsVec.size(); index += g_AmountOfPointsPerShape)
            {
                for (int pointIndex{}; pointIndex < g_AmountOfPointsPerShape; ++pointIndex)
                {
                    MoveToEx(hdc, g_PointsVec[index + pointIndex].x, g_PointsVec[index + pointIndex].y, 0);
                    if (pointIndex != g_AmountOfPointsPerShape)
                    {
                        if (pointIndex == g_AmountOfPointsPerShape - 1)
                        {
                            LineTo(hdc, g_PointsVec[index + pointIndex - g_AmountOfPointsPerShape + 2].x, g_PointsVec[index + pointIndex - g_AmountOfPointsPerShape + 2].y);
                        }
                        else if (pointIndex == g_AmountOfPointsPerShape - 2)
                        {
                            LineTo(hdc, g_PointsVec[index + pointIndex - g_AmountOfPointsPerShape + 2].x, g_PointsVec[index + pointIndex - g_AmountOfPointsPerShape + 2].y);
                        }
                        else
                        {
                            LineTo(hdc, g_PointsVec[index + pointIndex + 2].x, g_PointsVec[index + pointIndex + 2].y);
                        }
                    }
                    Ellipse(hdc, g_PointsVec[index + pointIndex].x - 2, g_PointsVec[index + pointIndex].y - 2, g_PointsVec[index + pointIndex].x + 2, g_PointsVec[index + pointIndex].y + 2);
                }
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
