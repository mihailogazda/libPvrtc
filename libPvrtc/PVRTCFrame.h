#pragma once
#include "Color.h"

namespace libpvrtc
{
	//  RGB format: [1] -> mode (keep 0), [32bit] modulation
	//  [1|R5|G5|B5] [1|R5|G5|B4][1mode][32modulation]
	//  [32bit modulation][1 bit mode][15 bit ColorB][16 bit ColorA]
	//  [ 32bit modulation ][1| 15b ColorA] [1| 16 bit ColorA]
	struct PVRTCFrame
	{
		unsigned int ModulationData;
		unsigned UsePunchtroughAlpha : 1;
		unsigned ColorA : 14;
		unsigned ColorAIsOpaque : 1;
		unsigned ColorB : 15;
		unsigned ColorBIsOpaque : 1;

		PVRTCFrame() : UsePunchtroughAlpha(false), ModulationData(0) {}

		void SetColorA(const ColorRGB& color);
		void SetColorB(const ColorRGB& color);
		
		void SetColorA(const ColorRGBA& color);
		void SetColorB(const ColorRGBA& color);

	};

	struct PVRTCFrame_RGB : PVRTCFrame
	{
		PVRTCFrame_RGB() : PVRTCFrame()
		{
			ColorAIsOpaque = true;
			ColorBIsOpaque = true;
		}
	};

	struct PVRTCFrame_RGBA : PVRTCFrame
	{
		PVRTCFrame_RGBA() : PVRTCFrame()
		{
			ColorAIsOpaque = false;
			ColorBIsOpaque = false;
		}
	};
}