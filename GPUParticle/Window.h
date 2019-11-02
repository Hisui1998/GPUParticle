#pragma once
#include <windows.h>


// ウィンドウ関係のクラス
class Window
{
private:
	// この関数内でウィンドウを作っていく
	void Create();

	//ウィンドウプロシージャ
	static LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND _windowHandle;// windowのハンドル
	RECT _windowSize;// ウィンドウのサイズ
public:
	Window();
	~Window();

	// ウィンドウハンドルの取得
	HWND GetWindowHandle() const {
		return _windowHandle;
	}
	// ウィンドウサイズの取得
	int GetSizeY() const {
		return (_windowSize.bottom - _windowSize.top);
	}
	int GetSizeX() const {		
		return (_windowSize.right - _windowSize.left);
	}
};

