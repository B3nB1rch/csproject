#pragma once
class buffer_swap
{
public:
	buffer_swap();
	bool init(HWND hwnd, UINT width, UINT height);
	bool release();
	~buffer_swap();
private:
	IDXGISwapChain* m_swap_chain;
};

