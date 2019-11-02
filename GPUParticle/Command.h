#pragma once
#include "d3dx12.h"

class Device;

// コマンド周りを管理するクラス
class Command
{
private:
	// コマンドキューの生成
	HRESULT CreateQueue();

	// コマンドアロケータの生成
	HRESULT CreateAlloc();

	// コマンドリストの生成
	HRESULT CreateList();

	Device* _dev;// デバイスのポインタ

	ID3D12CommandQueue* _cmdQue;// コマンドキュー

	ID3D12CommandAllocator* _cmdAlloc; // コマンドアロケータ	
	ID3D12GraphicsCommandList* _cmdList;// コマンドリスト

	HRESULT _result;
public:
	Command(Device* dev);
	~Command();

	// コマンドキューの取得
	ID3D12CommandQueue* GetCmdQue() const {
		return _cmdQue;
	}

	// コマンドアロケータの取得
	ID3D12CommandAllocator* GetCmdAllocator() const {
		return _cmdAlloc;
	}

	// コマンドリストの取得
	ID3D12GraphicsCommandList* GetCmdList() const {
		return _cmdList;
	}
};
