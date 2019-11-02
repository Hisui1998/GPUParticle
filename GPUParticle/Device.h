#pragma once
#include "d3dx12.h"

// �f�o�C�X���Ǘ�����N���X
class Device
{
private:
	HRESULT Create();

	ID3D12Device* _dev;
	D3D_FEATURE_LEVEL _level;
	HRESULT _result;
public:
	Device();
	~Device();

	// �f�o�C�X���擾����֐�
	ID3D12Device* GetDevice() const {
		return _dev;
	}
};

