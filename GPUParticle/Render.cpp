#include "Render.h"
#include "Device.h"
#include "Command.h"
#include "SwapChain.h"

//�N���A�J���[
const FLOAT color[] = {
   0.5f,
   0.5f,
   0.5f,
   1.0f
};

// �R���X�g���N�^
Render::Render(Device* dev, Command* list, SwapChain* swapchain):
	_swapchain(swapchain)
{
	_dev = dev, _list = list;

	_resources.clear();

	CreateResource();
}

// �f�X�g���N�^
Render::~Render()
{

}

// ���\�[�X�̐���
HRESULT Render::CreateResource(void)
{
	auto result = CreateHeap(D3D12_DESCRIPTOR_HEAP_TYPE_RTV, D3D12_DESCRIPTOR_HEAP_FLAG_NONE, _swapchain->GetBuffNum());
	
	//�z��̃������m��
	_resources.resize(_swapchain->GetBuffNum());
	
	//�����_�[�^�[�Q�b�g�ݒ�p�\����
	D3D12_RENDER_TARGET_VIEW_DESC desc = {};
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
	desc.Texture2D.MipSlice = 0;
	desc.Texture2D.PlaneSlice = 0;

	//�擪�n���h��
	D3D12_CPU_DESCRIPTOR_HANDLE handle = _heap->GetCPUDescriptorHandleForHeapStart();
	for (unsigned int i = 0; i < _resources.size(); ++i)
	{
		result = _swapchain->GetSwapChain()->GetBuffer(i, IID_PPV_ARGS(&_resources[i]));
		//�����_�[�^�[�Q�b�g�̐���
		_dev->GetDevice()->CreateRenderTargetView(_resources[i], &desc, handle);
		//�n���h���ʒu�̍X�V
		handle.ptr += _heapSize;
	}
}
// �����_�[�^�[�Q�b�g�̃Z�b�g
void Render::SetRender(ID3D12DescriptorHeap* depth)
{
	D3D12_CPU_DESCRIPTOR_HANDLE handle = _heap->GetCPUDescriptorHandleForHeapStart();
	handle.ptr += _heapSize * _swapchain->GetSwapChain->GetCurrentBackBufferIndex();
	
	//�����_�[�^�[�Q�b�g�̃Z�b�g
	_list->GetCmdList()->OMSetRenderTargets(1, &handle, false, &depth->GetCPUDescriptorHandleForHeapStart());
	
	//�����_�[�^�[�Q�b�g�̃N���A
	_list->GetCmdList()->ClearRenderTargetView(handle, color, 0, nullptr);
}