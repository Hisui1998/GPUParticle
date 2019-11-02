#include "Window.h"
#include "Device.h"
#include "Command.h"
#include "SwapChain.h"
#include <memory>

int main()
{
	std::unique_ptr<Window> window;
	std::unique_ptr<Device> dev;
	std::unique_ptr<Command> cmd;
	std::unique_ptr<SwapChain> sc;

	// �E�B���h�E�쐬
	window = std::make_unique<Window>();
	dev = std::make_unique<Device>();
	cmd = std::make_unique<Command>(dev.get());
	sc = std::make_unique<SwapChain>(window.get(), cmd.get());

	ShowWindow(window->GetWindowHandle(),SW_SHOW);

	// OS����̃��b�Z�[�W�����Ă����ϐ�
	MSG msg = {};

	while (msg.message != WM_QUIT)
	{
		//����ŕ\�E���̓���ւ�
		sc->GetSwapChain()->Present(1, 0);

		//�Ăяo�����X���b�h�����L���Ă���E�B���h�E�ɑ��M���ꂽ���b�Z�[�W�ۗ̕�����Ă��镨���擾
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			//���z�L�[���b�Z�[�W�𕶎����b�Z�[�W�ɕϊ�
			TranslateMessage(&msg);
			//1�̃E�B�h�E�v���V�[�W���Ƀ��b�Z�[�W�𑗏o����
			DispatchMessage(&msg);
		}
	}
	return 0;
}