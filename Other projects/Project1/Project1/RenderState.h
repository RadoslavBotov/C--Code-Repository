#pragma once
#include <Windows.h>

struct RenderState
{
private:
	void allocateBitmapInfo();

public:
	void allocateMemory(unsigned width, unsigned height);

	BITMAPINFO m_bitmapInfo;
	void* m_bMemory;		// bufferMemory
	unsigned m_wWidth;		// windowWidth
	unsigned m_wHeight;		// windowHeigth
} my_render_state;