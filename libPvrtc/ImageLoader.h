#pragma once
#include "Image.h"
#include "Color.h"

namespace libpvrtc
{
	class ImageLoader
	{
	public:

		bool Load(const char* fileName, ImageRGB& image);

	};
}