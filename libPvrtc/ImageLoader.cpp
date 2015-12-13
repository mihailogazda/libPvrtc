#include <stdio.h>
#include "ImageLoader.h"
#include "PNGFileReader.h"

namespace libpvrtc
{
	bool ImageLoader::Load(const char* fileName, ImageRGB& image)
	{
		PNGFileReader pngReader;
		ColorType* pixels = NULL;
		int width = 0;
		int height = 0;
		bool hasAlpha = false;

		if (pngReader.Read(fileName, pixels, width, height, hasAlpha))
		{
			
			return true;
		}


		return false;
	}


}