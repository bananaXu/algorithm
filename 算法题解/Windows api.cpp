#include <windows.h>
#pragma comment (lib, "User32.lib")

HINSTANCE hinst;
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
LRESULT CALLBACK MainWndProc(HWND, UINT, WPARAM, LPARAM);

int WinMain(HINSTANCE hInstance,  
			HINSTANCE hPrevInstance,
			LPSTR lpCmdLine,
			int nCmdShow)
{
	WNDCLASSEX wcx; // 窗口类
	HWND hwnd; 		// 窗口句柄
	MSG msg; 		// 消息
	BOOL GotMessage; // 是否成功获得消息
	wcx.cbSize = sizeof(wcx);
	wcx.style = CS_HREDRAW|CS_VREDRAW;
	wcx.lpfnWndProc = MainWndProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInstance;
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcx.lpszMenuName = NULL;
	wcx.lpszClassName = "MainWClass";
	wcx.hIconSm = (HICON)LoadImage(hInstance, 
							       MAKEINTRESOURCE(5),
								   IMAGE_ICON,
								   GetSystemMetrics(SM_CXSMICON),
								   GetSystemMetrics(SM_CYSMICON),
								   LR_DEFAULTCOLOR);
	if (!RegisterClassEx(&wcx))
	{
		return 1;
	}
	hwnd = CreateWindow(
		"MainWClass",
		"CH 2-3",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(HWND) NULL,
		(HMENU) NULL,
		hInstance,
		(LPVOID) NULL);
	if (!hwnd)
	{
		return 1;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GotMessage = GetMessage(&msg, (HWND)NULL, 0, 0) != 0
		  && GotMessage != -1)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//MessageBox(NULL, TEXT("hello SHADIAO"), TEXT("消息对话框"), MB_OK);
	return msg.wParam;
} 

LRESULT CALLBACK MainWndProc(HWND hwnd, 
							 UINT uMsg, 
							 WPARAM wParam, 
							 LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			ExitThread(0);
			return 0;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}
