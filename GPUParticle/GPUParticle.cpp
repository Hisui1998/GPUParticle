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

	// ウィンドウ作成
	window = std::make_unique<Window>();
	dev = std::make_unique<Device>();
	cmd = std::make_unique<Command>(dev.get());
	sc = std::make_unique<SwapChain>(window.get(), cmd.get());

	ShowWindow(window->GetWindowHandle(),SW_SHOW);

	// OSからのメッセージを入れておく変数
	MSG msg = {};

	while (msg.message != WM_QUIT)
	{
		//これで表・裏の入れ替え
		sc->GetSwapChain()->Present(1, 0);

		//呼び出し側スレッドが所有しているウィンドウに送信されたメッセージの保留されている物を取得
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			//仮想キーメッセージを文字メッセージに変換
			TranslateMessage(&msg);
			//1つのウィドウプロシージャにメッセージを送出する
			DispatchMessage(&msg);
		}
	}
	return 0;
}