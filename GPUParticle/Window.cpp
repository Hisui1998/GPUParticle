#include "Window.h"

void Window::Create(void)
{
	// �E�B���h�E�̕ϐ��̍쐬
	WNDCLASSEX window = {};

	// �����̃T�C�Y������
	window.cbSize = sizeof(WNDCLASSEX);

	//�E�B���h�E�v���V�[�W���̎w��
	window.lpfnWndProc = (WNDPROC)WindowProcedure;

	//�E�B���h�E�̖��O���w��
	window.lpszClassName = "DX12_GPU_Particle";

	//�E�B���h�E���j���[�̖��O���w��
	window.lpszMenuName = "DX12_GPU_Particle";

	//�E�B���h�E�̏������������邩
	window.style = CS_HREDRAW | CS_VREDRAW;

	//�E�B���h�E�̓o�^
	RegisterClassEx(&window);

	//�E�B���h�E�T�C�Y�̐ݒ�
	_windowSize.bottom = 800;
	_windowSize.left = 0;
	_windowSize.right = 1200;
	_windowSize.top = 0;

	//�T�C�Y�̕␳
	AdjustWindowRect(&_windowSize, WS_OVERLAPPEDWINDOW, false);

	//�E�B���h�E����
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
	// �E�B���h�E���j�����ꂽ�Ƃ�
	if (msg == WM_DESTROY)
	{
		//OS�ɃA�v���P�[�V�����I����`����
		PostQuitMessage(0);
		return 0;
	}
	// �f�t�H���g�������s��
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

Window::Window()
{
	Create();
}


Window::~Window()
{
}
