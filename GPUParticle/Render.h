#include "Descriptor.h"
#include <vector>
class SwapChain;

class Render :
	public Descriptor
{
private:
	// ���\�[�X�̐���
	HRESULT CreateResource(void);

	// �X���b�v�`�F�C��
	SwapChain* _swapchain;

	// ���\�[�X
	std::vector<ID3D12Resource*>_resources;
public:
	// �R���X�g���N�^
	Render(Device* dev, Command* list, SwapChain* swap);

	// �f�X�g���N�^
	~Render();

	// �����_�[�^�[�Q�b�g�̃Z�b�g
	void SetRender(ID3D12DescriptorHeap* depth);

	// ���\�[�X�̎擾
	ID3D12Resource* GetResource(UINT index) const {
		return _resources[index];
	}
};