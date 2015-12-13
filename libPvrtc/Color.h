#pragma once

namespace libpvrtc
{
	typedef unsigned char ColorType;

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