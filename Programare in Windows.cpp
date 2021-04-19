/*Aplicație Windows, în centrul zonei Client al căreia este afișat un mesaj. 
La redimensionarea ferestrei, mesajul trebuie să fie afișat în centrul zonei Client*/

#include<Windows.h>
LRESULT WINAPI WndProc(HWND hwnd,UINT msg,WPARAM wparam,LPARAM lparam) {
PAINTSTRUCT ps;
HDC hdc;
	
switch (msg) { 
case WM_PAINT: {
 hdc = BeginPaint(hwnd, &ps);
 SetTextAlign(hdc, TA_CENTER);
 TextOut(hdc, ps.rcPaint.right / 2, ps.rcPaint.bottom / 2, 
L"Hello, Windows!", 15);
 EndPaint(hwnd, &ps);
 return 0L;
 } 
		
case WM_DESTROY: {
 PostQuitMessage(0);
 break; 
 } 
		
default: 
 return DefWindowProc(hwnd, msg, wparam, lparam);
 } 
} 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR
lpCmdLine, int nCmdShow) {HWND hwnd;
MSG msg;
WNDCLASSEX wc;
wc.style = CS_HREDRAW | CS_VREDRAW; 
wc.cbSize = sizeof(WNDCLASSEX);
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor = LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
wc.hInstance = hInstance; 
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.lpfnWndProc = WndProc;
wc.lpszMenuName = NULL; 
wc.lpszClassName = L"WinMainClasa"; 
RegisterClassEx(&wc);

hwnd = CreateWindow( 
 wc.lpszClassName,
 L"App", 
 WS_OVERLAPPEDWINDOW, 
 0, 0, 640, 480,
 NULL, NULL, hInstance, NULL);
 
ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);

while (GetMessage(&msg, NULL, 0, 0)) {
 TranslateMessage(&msg);
 DispatchMessage(&msg);
 } 
return msg.wParam;
}
