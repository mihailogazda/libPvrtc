#pragma once
#include "Image.h"
#include "Color.h"

namespace libpvrtc
{
	//	Generic Encoder interface, converts image to raw pixels in correct format	
	class IEncoder
	{
	public:
		//	Encode RGB data. Free encodedPixels after done.
		virtual bool Encode(const ImageRGB* image, ColorType* &encodedPixels) = 0;

		//	Encode RGBA data. Free encodedPixels after done.
		virtual bool Encode(const ImageRGBA* image, ColorType* &encodedPixels) = 0;

	};
}