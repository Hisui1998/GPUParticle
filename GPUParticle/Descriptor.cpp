#include "Descriptor.h"
#include <dxgi1_6.h>
#include "Device.h"
#include "Command.h"

HRESULT Descriptor::CreateHeap(const D3D12_DESCRIPTOR_HEAP_TYPE & type, const D3D12_DESCRIPTOR_HEAP_FLAGS & flag, UINT num)
{
	//ヒープ設定用構造体
	D3D12_DESCRIPTOR_HEAP_DESC desc = {};
	desc.Flags			= flag;
	desc.NodeMask		= 0;
	desc.NumDescriptors = num;
	desc.Type			= type;

	//ヒープの生成
	auto result = _dev->GetDevice()->CreateDescriptorHeap(&desc, IID_PPV_ARGS(&_heap));
	
	//ヒープサイズの取得
	_heapSize = _dev->GetDevice()->GetDescriptorHandleIncrementSize(type);

	return result;
}

Descriptor::Descriptor()
{
}


Descriptor::~Descriptor()
{
}
