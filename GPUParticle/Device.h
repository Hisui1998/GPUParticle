#pragma once
#include "d3dx12.h"

// デバイスを管理するクラス
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

	// デバイスを取得する関数
	ID3D12Device* GetDevice() const {
		return _dev;
	}
};

