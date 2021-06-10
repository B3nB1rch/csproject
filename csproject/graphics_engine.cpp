#include "graphics_engine.h"
#include <d3d11.h>
graphics_engine::graphics_engine() {

}

bool graphics_engine::init() {
	// DRIVER TYPES
	D3D_DRIVER_TYPE driver_types[] = {
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT nm_driver_types = ARRAYSIZE(driver_types);

	// FEATURE LEVELS
	D3D_FEATURE_LEVEL feature_levels[] = {
		D3D_FEATURE_LEVEL_11_0
	};
	UINT num_feature_levels = ARRAYSIZE(feature_levels);

	HRESULT res = 0;
	for (UINT driver_type_index = 0; driver_type_index < nm_driver_types;) {
		res = D3D11CreateDevice(
			NULL,
			driver_types[driver_type_index],
			NULL,
			NULL,
			feature_levels,
			num_feature_levels,
			D3D11_SDK_VERSION,
			&m_d3d_device,
			&m_feature_level,
			&m_imm_context
		);
		if (SUCCEEDED(res)) break;
		++driver_type_index;
	}
		
		if (FAILED(res)) 
			return false;

		
	

	m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
	m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
	m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);

	return true;
}

bool graphics_engine::release() {
	m_imm_context->Release();
	m_d3d_device->Release();
	return true;
}

graphics_engine* graphics_engine::get()
{
	static graphics_engine engine;
	return &engine;
}


graphics_engine::~graphics_engine()
{
}
