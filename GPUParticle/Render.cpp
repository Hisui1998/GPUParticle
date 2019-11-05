#include "Render.h"
#include "Device.h"
#include "Command.h"
#include "SwapChain.h"

//クリアカラー
const FLOAT color[] = {
   0.5f,
   0.5f,
   0.5f,
   1.0f
};

// コンストラクタ
Render::Render(Device* dev, Command* list, SwapChain* swapchain):
	_swapchain(swapchain)
{
	_dev = dev, _list = list;

	_resources.clear();

	CreateResource();
}

// デストラクタ
Render::~Render()
{

}

// リソースの生成
HRESULT Render::CreateResource(void)
{
	auto result = CreateHeap(D3D12_DESCRIPTOR_HEAP_TYPE_RTV, D3D12_DESCRIPTOR_HEAP_FLAG_NONE, _swapchain->GetBuffNum());
	
	//配列のメモリ確保
	_resources.resize(_swapchain->GetBuffNum());
	
	//レンダーターゲット設定用構造体
	D3D12_RENDER_TARGET_VIEW_DESC desc = {};
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
	desc.Texture2D.MipSlice = 0;
	desc.Texture2D.PlaneSlice = 0;

	//先頭ハンドル
	D3D12_CPU_DESCRIPTOR_HANDLE handle = _heap->GetCPUDescriptorHandleForHeapStart();
	for (unsigned int i = 0; i < _resources.size(); ++i)
	{
		result = _swapchain->GetSwapChain()->GetBuffer(i, IID_PPV_ARGS(&_resources[i]));
		//レンダーターゲットの生成
		_dev->GetDevice()->CreateRenderTargetView(_resources[i], &desc, handle);
		//ハンドル位置の更新
		handle.ptr += _heapSize;
	}
}
// レンダーターゲットのセット
void Render::SetRender(ID3D12DescriptorHeap* depth)
{
	D3D12_CPU_DESCRIPTOR_HANDLE handle = _heap->GetCPUDescriptorHandleForHeapStart();
	handle.ptr += _heapSize * _swapchain->GetSwapChain->GetCurrentBackBufferIndex();
	
	//レンダーターゲットのセット
	_list->GetCmdList()->OMSetRenderTargets(1, &handle, false, &depth->GetCPUDescriptorHandleForHeapStart());
	
	//レンダーターゲットのクリア
	_list->GetCmdList()->ClearRenderTargetView(handle, color, 0, nullptr);
}