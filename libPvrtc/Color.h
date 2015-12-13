#pragma once

namespace libpvrtc
{
	typedef unsigned char ColorType;

	struct Color
	{
	};

	//	Base color
	struct ColorRGB : Color
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