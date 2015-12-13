#include <stdio.h>
#include "ImageLoader.h"
#include "PNGFileReader.h"

namespace libpvrtc
{
	bool ImageLoader::Load(const char* fileName, Image& image)
	{
		PNGFileReader pngReader;
		ColorType* pixels = NULL;
		int width = 0;
		int height = 0;
		bool hasAlpha = false;
		Image* returnImage = NULL;

		if (pngReader.Read(fileName, pixels, width, height, hasAlpha))
		{
			if (hasAlpha)
			{
				returnImage = new ImageRGBA(width, height);
				returnImage->SetPixels((ColorRGBA*) pixels);
			}
			else
			{
				returnImage = new ImageRGB(width, height);
				returnImage->SetPixels((ColorRGB*)pixels);
			}
			return true;
		}

		return false;
	}


}