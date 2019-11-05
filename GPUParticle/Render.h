#include "Descriptor.h"
#include <vector>
class SwapChain;

class Render :
	public Descriptor
{
private:
	// リソースの生成
	HRESULT CreateResource(void);

	// スワップチェイン
	SwapChain* _swapchain;

	// リソース
	std::vector<ID3D12Resource*>_resources;
public:
	// コンストラクタ
	Render(Device* dev, Command* list, SwapChain* swap);

	// デストラクタ
	~Render();

	// レンダーターゲットのセット
	void SetRender(ID3D12DescriptorHeap* depth);

	// リソースの取得
	ID3D12Resource* GetResource(UINT index) const {
		return _resources[index];
	}
};