#include "PVRTCFrame.h"

namespace libpvrtc
{
	void PVRTCFrame::SetColorA(const ColorRGB& color)
	{
		int r = color.R;
		int g = color.G;
		int b = color.B;
		ColorA = r << 9 | g << 4 | b;
		ColorAIsOpaque = true;
	}

	void PVRTCFrame::SetColorB(const ColorRGB& color)
	{
		int r = color.R;
		int g = color.G;
		int b = color.B;
		ColorB = r << 9 | g << 4 | b;
		ColorBIsOpaque = true;
	}

	void PVRTCFrame::SetColorA(const ColorRGBA& color)
	{
		int a = color.A;
		int b = color.B;
		int r = color.R;
		int g = color.G;
		ColorA = a << 12 | r << 8 | g << 4 | b;
		ColorAIsOpaque = false;
	}

	void PVRTCFrame::SetColorB(const ColorRGBA& color)
	{
		int a = color.A;
		int b = color.B;
		int r = color.R;
		int g = color.G;
		ColorB = a << 12 | r << 8 | g << 4 | b;
		ColorBIsOpaque = false;
	}
}