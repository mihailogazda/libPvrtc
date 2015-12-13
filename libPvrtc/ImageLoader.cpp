#include <stdio.h>
#include "ImageLoader.h"
#include "PNGFileReader.h"

namespace libpvrtc
{
	bool ImageLoader::Load(const char* fileName, Image* &image)
	{
		PNGFileReader pngReader;
		ColorType* pixels = NULL;
		int width = 0;
		int height = 0;
		bool hasAlpha = false;

		if (pngReader.Read(fileName, pixels, width, height, hasAlpha))
		{
			if (hasAlpha)
			{
				image = new ImageRGBA(width, height);
				image->SetPixels((ColorRGBA*) pixels);
			}
			else
			{
				image = new ImageRGB(width, height);
				image->SetPixels((ColorRGB*)pixels);
			}
			return true;
		}

		return false;
	}


}