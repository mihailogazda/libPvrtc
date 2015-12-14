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

		void SetMin(const ColorRGB &x)
		{
			if (x.R < R) {
				R = x.R;
			}
			if (x.G < G) {
				G = x.G;
			}
			if (x.B < B) {
				B = x.B;
			}
		}

		void SetMax(const ColorRGB &x)
		{
			if (x.R > R) {
				R = x.R;
			}
			if (x.G > G) {
				G = x.G;
			}
			if (x.B > B) {
				B = x.B;
			}
		}

		unsigned int Normalize()
		{
			return (R + G + B) / 3;
		}
	};

	struct ColorRGBA : ColorRGB
	{
		ColorType A;
	};

}