#include "SwapChain.h"
#include "Window.h"
#include "Command.h"


HRESULT SwapChain::CreateFactory()
{
	_result = CreateDXGIFactory1(IID_PPV_ARGS(&_factory));
	return _result;
}

HRESULT SwapChain::CreateSwapChain()
{
	//�X���b�v�`�F�C���ݒ�p�\����
	DXGI_SWAP_CHAIN_DESC1 desc = {};
	desc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
	desc.BufferCount = 2;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.Flags = 0;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.Height = _window->GetSizeY();
	desc.SampleDesc = { 1, 0 };
	desc.Scaling = DXGI_SCALING_STRETCH;
	desc.Stereo = false;
	desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	desc.Width = _window->GetSizeX();

	//�X���b�v�`�F�C������
	_result = _factory->CreateSwapChainForHwnd(_cmdQue->GetCmdQue(), _window->GetWindowHandle(),
		&desc, nullptr, nullptr, (IDXGISwapChain1**)(&_swapChain));
	
	//�o�b�N�o�b�t�@���m��
	_bufferNum = desc.BufferCount;

	return _result;
}


SwapChain::SwapChain(Window* winow, Command* cmdQue):_window(winow), _cmdQue(cmdQue)
{
	CreateFactory();
	CreateSwapChain();
}


SwapChain::~SwapChain()
{
	// ���
	if (_swapChain != nullptr)
	{
		_swapChain->Release();
		_swapChain = nullptr;
	}

	if (_factory != nullptr)
	{
		_factory->Release();
		_factory = nullptr;
	}
}
