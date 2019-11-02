#pragma once
#include "d3d12.h"
class Device;
class Command;

class Descriptor
{
protected:
	// �q�[�v�̐���(�q�[�v�̎�ނƃt���O�ƃf�X�N���v�^�[�̐�)
	HRESULT CreateHeap(const D3D12_DESCRIPTOR_HEAP_TYPE& type, const D3D12_DESCRIPTOR_HEAP_FLAGS& flag, UINT num = 1);

	Device* _dev;// �f�o�C�X
	Command* _list;// �R�}���h���X�g
	ID3D12DescriptorHeap* _heap;// �q�[�v
	unsigned int _heapSize;// �q�[�v�̃T�C�Y
public:
	Descriptor();
	virtual ~Descriptor();

	// �q�[�v�̎擾�֐�
	ID3D12DescriptorHeap* GetHeap()
	{
		return _heap;
	}
};

