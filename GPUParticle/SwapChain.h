#pragma once
#include "d3dx12.h"
#include <dxgi1_6.h>

class Window;
class Command;

class SwapChain
{
private:
	// ファクトリーの生成
	HRESULT CreateFactory();
	// スワップチェインの生成
	HRESULT CreateSwapChain();

	HRESULT _result;

	Window* _window;// ウィンドウ
	
	Command* _cmdQue;// コマンドキュー
	
	IDXGIFactory4* _factory;// ファクトリー
	
	IDXGISwapChain4* _swapChain;// スワップチェイン
	
	unsigned int _bufferNum;// バックバッファ数

public:
	SwapChain(Window* winow, Command* cmdQue);
	~SwapChain();

	// スワップチェインの取得
	IDXGISwapChain4* GetSwapChain(void) const {
		return _swapChain;
	}

	// バックバッファの数取得
	unsigned int GetBuffNum(void) const {
		return _bufferNum;
	}
};

