#pragma once
#include "d3dx12.h"

class Device;

// �R�}���h������Ǘ�����N���X
class Command
{
private:
	// �R�}���h�L���[�̐���
	HRESULT CreateQueue();

	// �R�}���h�A���P�[�^�̐���
	HRESULT CreateAlloc();

	// �R�}���h���X�g�̐���
	HRESULT CreateList();

	Device* _dev;// �f�o�C�X�̃|�C���^

	ID3D12CommandQueue* _cmdQue;// �R�}���h�L���[

	ID3D12CommandAllocator* _cmdAlloc; // �R�}���h�A���P�[�^	
	ID3D12GraphicsCommandList* _cmdList;// �R�}���h���X�g

	HRESULT _result;
public:
	Command(Device* dev);
	~Command();

	// �R�}���h�L���[�̎擾
	ID3D12CommandQueue* GetCmdQue() const {
		return _cmdQue;
	}

	// �R�}���h�A���P�[�^�̎擾
	ID3D12CommandAllocator* GetCmdAllocator() const {
		return _cmdAlloc;
	}

	// �R�}���h���X�g�̎擾
	ID3D12GraphicsCommandList* GetCmdList() const {
		return _cmdList;
	}
};
