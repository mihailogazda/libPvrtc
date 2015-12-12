#pragma once

namespace LIBPvrtc
{
	typedef char ColorType;

	//	Base color
	struct ColorRGB
	{
		ColorType R;
		ColorType G;
		ColorType B;
	};

	struct ColorRGBA : ColorRGB
	{
		ColorType A;
	};

}