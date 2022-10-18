#include "RenderState.h"

void RenderState::allocateBitmapInfo()
{
	m_bitmapInfo.bmiHeader.biSize = sizeof(m_bitmapInfo.bmiHeader);
	m_bitmapInfo.bmiHeader.biWidth = m_wWidth;
	m_bitmapInfo.bmiHeader.biHeight = m_wHeight;
	m_bitmapInfo.bmiHeader.biPlanes = 1;
	m_bitmapInfo.bmiHeader.biBitCount = 32;
	m_bitmapInfo.bmiHeader.biCompression = BI_RGB;
	//m_bitmapInfo.bmiHeader.biSizeImage = ;
	//m_bitmapInfo.bmiHeader.biXPelsPerMeter = ;
	//m_bitmapInfo.bmiHeader.biYPelsPerMeter = ;
	//m_bitmapInfo.bmiHeader.biClrUsed = ;
	//m_bitmapInfo.bmiHeader.biClrImportant = ;
}

void RenderState::allocateMemory(unsigned width, unsigned height)
{
	m_wWidth = width;
	m_wHeight = height;
	unsigned bSize = m_wWidth * m_wHeight * sizeof(unsigned int);

	if (m_bMemory)
		VirtualFree(m_bMemory, 0, MEM_RELEASE);
	m_bMemory = VirtualAlloc(0, bSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

	allocateBitmapInfo();
}
