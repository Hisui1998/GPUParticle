#include "Device.h"
#include <dxgi1_6.h>

#pragma comment(lib,"d3d12.lib")
#pragma comment(lib,"dxgi.lib")


HRESULT Device::Create()
{
	D3D_FEATURE_LEVEL levels[] = {
	   D3D_FEATURE_LEVEL_12_1,
	   D3D_FEATURE_LEVEL_12_0,
	   D3D_FEATURE_LEVEL_11_1,
	   D3D_FEATURE_LEVEL_11_0
	};
	// �@�\���x���̃`�F�b�N���čŐV�̂��̂��g��
	for (auto lv : levels)
	{
		_result = D3D12CreateDevice(nullptr, lv,IID_PPV_ARGS(&_dev));
		if (_result == S_OK)
		{
			// �g�p�����@�\���x���m�F�p
			_level = lv;
			break;
		}
	}
	return _result;
}

Device::Device():_dev(nullptr)
{
	Create();
}


Device::~Device()
{
	// ���
	if (_dev != nullptr)
	{
		_dev->Release();
		_dev = nullptr;
	}
}
