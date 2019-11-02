#pragma once
#include "d3dx12.h"
#include <dxgi1_6.h>

class Window;
class Command;

class SwapChain
{
private:
	// �t�@�N�g���[�̐���
	HRESULT CreateFactory();
	// �X���b�v�`�F�C���̐���
	HRESULT CreateSwapChain();

	HRESULT _result;

	Window* _window;// �E�B���h�E
	
	Command* _cmdQue;// �R�}���h�L���[
	
	IDXGIFactory4* _factory;// �t�@�N�g���[
	
	IDXGISwapChain4* _swapChain;// �X���b�v�`�F�C��
	
	unsigned int _bufferNum;// �o�b�N�o�b�t�@��

public:
	SwapChain(Window* winow, Command* cmdQue);
	~SwapChain();

	// �X���b�v�`�F�C���̎擾
	IDXGISwapChain4* GetSwapChain(void) const {
		return _swapChain;
	}

	// �o�b�N�o�b�t�@�̐��擾
	unsigned int GetBuffNum(void) const {
		return _bufferNum;
	}
};

