#pragma once
#include <windows.h>


// �E�B���h�E�֌W�̃N���X
class Window
{
private:
	// ���̊֐����ŃE�B���h�E������Ă���
	void Create();

	//�E�B���h�E�v���V�[�W��
	static LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND _windowHandle;// window�̃n���h��
	RECT _windowSize;// �E�B���h�E�̃T�C�Y
public:
	Window();
	~Window();

	// �E�B���h�E�n���h���̎擾
	HWND GetWindowHandle() const {
		return _windowHandle;
	}
	// �E�B���h�E�T�C�Y�̎擾
	int GetSizeY() const {
		return (_windowSize.bottom - _windowSize.top);
	}
	int GetSizeX() const {		
		return (_windowSize.right - _windowSize.left);
	}
};

