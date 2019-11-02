#include "Descriptor.h"
#include <dxgi1_6.h>
#include "Device.h"
#include "Command.h"



HRESULT Descriptor::CreateHeap(const D3D12_DESCRIPTOR_HEAP_TYPE & type, const D3D12_DESCRIPTOR_HEAP_FLAGS & flag, UINT num)
{
	D3D12_DESCRIPTOR_HEAP_DESC desc;

	return E_NOTIMPL;
}

Descriptor::Descriptor()
{
}


Descriptor::~Descriptor()
{
}
