#include "PVRTCFrame.h"
#include "BitScaleLUT.h"

namespace libpvrtc
{
	void PVRTCFrame::SetColorA(const ColorRGB& color)
	{
		int r = BitScaleLUT::BITSCALE_8_TO_5_FLOOR[color.R];
		int g = BitScaleLUT::BITSCALE_8_TO_5_FLOOR[color.G];
		int b = BitScaleLUT::BITSCALE_8_TO_4_FLOOR[color.B];
		ColorA = r << 9 | g << 4 | b;
		ColorAIsOpaque = true;
	}

	void PVRTCFrame::SetColorB(const ColorRGB& color)
	{
		int r = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.R];
		int g = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.G];
		int b = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.B];
		ColorB = r << 10 | g << 5 | b;
		ColorBIsOpaque = true;
	}

	void PVRTCFrame::SetColorA(const ColorRGBA& color)
	{
		int a = BitScaleLUT::BITSCALE_8_TO_3_FLOOR[color.A];
		if (a == 7)
		{
			int r = BitScaleLUT::BITSCALE_8_TO_5_FLOOR[color.R];
			int g = BitScaleLUT::BITSCALE_8_TO_5_FLOOR[color.G];
			int b = BitScaleLUT::BITSCALE_8_TO_4_FLOOR[color.B];
			ColorA = r << 9 | g << 4 | b;
			ColorAIsOpaque = true;
		}
		else
		{
			int r = BitScaleLUT::BITSCALE_8_TO_4_FLOOR[color.R];
			int g = BitScaleLUT::BITSCALE_8_TO_4_FLOOR[color.G];
			int b = BitScaleLUT::BITSCALE_8_TO_3_FLOOR[color.B];
			ColorA = a << 11 | r << 7 | g << 3 | b;
			ColorAIsOpaque = false;
		}
	}

	void PVRTCFrame::SetColorB(const ColorRGBA& color)
	{
		int a = BitScaleLUT::BITSCALE_8_TO_3_CEIL[color.A];
		if (a == 7)
		{
			int r = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.R];
			int g = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.G];
			int b = BitScaleLUT::BITSCALE_8_TO_5_CEIL[color.B];
			ColorB = r << 10 | g << 5 | b;
			ColorBIsOpaque = true;
		}
		else
		{
			int r = BitScaleLUT::BITSCALE_8_TO_4_CEIL[color.R];
			int g = BitScaleLUT::BITSCALE_8_TO_4_CEIL[color.G];
			int b = BitScaleLUT::BITSCALE_8_TO_4_CEIL[color.B];
			ColorB = a << 12 | r << 8 | g << 4 | b;
			ColorBIsOpaque = false;
		}
	}
}