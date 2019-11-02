#include "Window.h"

void Window::Create(void)
{
	// ウィンドウの変数の作成
	WNDCLASSEX window = {};

	// 自分のサイズを入れる
	window.cbSize = sizeof(WNDCLASSEX);

	//ウィンドウプロシージャの指定
	window.lpfnWndProc = (WNDPROC)WindowProcedure;

	//ウィンドウの名前を指定
	window.lpszClassName = "DX12_GPU_Particle";

	//ウィンドウメニューの名前を指定
	window.lpszMenuName = "DX12_GPU_Particle";

	//ウィンドウの書き直しをするか
	window.style = CS_HREDRAW | CS_VREDRAW;

	//ウィンドウの登録
	RegisterClassEx(&window);

	//ウィンドウサイズの設定
	_windowSize.bottom = 800;
	_windowSize.left = 0;
	_windowSize.right = 1200;
	_windowSize.top = 0;

	//サイズの補正
	AdjustWindowRect(&_windowSize, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウ生成
	_windowHandle = CreateWindow(
		window.lpszClassName,
		"DX12_GPU_Particle",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		(_windowSize.right - _windowSize.left),
		(_windowSize.bottom - _windowSize.top),
		nullptr,
		nullptr,
		window.hInstance,
		nullptr);
}

LRESULT Window::WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// ウィンドウが破棄されたとき
	if (msg == WM_DESTROY)
	{
		//OSにアプリケーション終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	// デフォルト処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

Window::Window()
{
	Create();
}


Window::~Window()
{
}
