#pragma once
#include <d3d11.h>
class graphics_engine {
public:
	graphics_engine();
	~graphics_engine();
	bool init();
	bool release();
	static graphics_engine* get();
	buffer_swap* create_swap_chain();
private:
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context;
	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
	friend class buffer_swap;
};