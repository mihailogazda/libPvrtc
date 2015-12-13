#pragma once
#include "Image.h"
#include "Color.h"

namespace libpvrtc
{
	//	Generic Encoder interface, converts image to raw pixels in correct format	
	class IEncoder
	{
	public:
		//	Encode RGB or RGBA data. Free encodedPixels after done.
		virtual bool Encode(const Image* image, ColorType* &encodedPixels) = 0;
	};
}