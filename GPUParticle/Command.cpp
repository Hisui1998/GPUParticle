#include "Command.h"
#include "Device.h"


HRESULT Command::CreateQueue()
{
	//�R�}���h�L���[�ݒ�p
	D3D12_COMMAND_QUEUE_DESC desc;
	desc.Flags		= D3D12_COMMAND_QUEUE_FLAG_NONE;
	desc.NodeMask	= 0;
	desc.Priority	= D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
	desc.Type		= D3D12_COMMAND_LIST_TYPE_DIRECT;

	//�R�}���h�L���[����
	_result = _dev->GetDevice()->CreateCommandQueue(&desc, IID_PPV_ARGS(&_cmdQue));

	return _result;
}

HRESULT Command::CreateAlloc(void)
{
	_result = _dev->GetDevice()->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&_cmdAlloc));
	return _result;
}

HRESULT Command::CreateList(void)
{
	_result = _dev->GetDevice()->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT,_cmdAlloc, nullptr, IID_PPV_ARGS(&_cmdList));

	//�R�}���h���X�g���ꎞ�N���[�Y
	_cmdList->Close();

	return _result;
}

Command::Command(Device* dev):
	_dev(dev),_cmdQue(nullptr), _cmdAlloc(nullptr), _cmdList(nullptr)
{
	CreateQueue();
	CreateAlloc();
	CreateList();
}


Command::~Command()
{
	// ���
	if (_cmdQue != nullptr)
	{
		_cmdQue->Release();
		_cmdQue = nullptr;
	}

	if (_cmdList != nullptr)
	{
		_cmdList->Release();
		_cmdList = nullptr;
	}

	if (_cmdAlloc != nullptr)
	{
		_cmdAlloc->Release();
		_cmdAlloc = nullptr;
	}
}
