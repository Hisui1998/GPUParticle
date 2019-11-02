#pragma once
#include "d3d12.h"
class Device;
class Command;

class Descriptor
{
protected:
	// ヒープの生成(ヒープの種類とフラグとデスクリプターの数)
	HRESULT CreateHeap(const D3D12_DESCRIPTOR_HEAP_TYPE& type, const D3D12_DESCRIPTOR_HEAP_FLAGS& flag, UINT num = 1);

	Device* _dev;// デバイス
	Command* _list;// コマンドリスト
	ID3D12DescriptorHeap* _heap;// ヒープ
	unsigned int _heapSize;// ヒープのサイズ
public:
	Descriptor();
	virtual ~Descriptor();

	// ヒープの取得関数
	ID3D12DescriptorHeap* GetHeap()
	{
		return _heap;
	}
};

