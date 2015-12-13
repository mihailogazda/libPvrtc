#include "PNGFileReader.h"
#include "lodepng.h"
#include <vector>

namespace libpvrtc
{
	//	Decode PNG data into our Image
	bool PNGFileReader::Read(const char* fileName, ColorType* &pixelData, int& width, int& height, bool& hasAlpha)
	{
		std::vector<unsigned char> rawData;
		std::vector<unsigned char> colorData;

		unsigned w, h;
		lodepng::State state;
		unsigned error = 0;

		error = lodepng::load_file(rawData, fileName);
		if (error == 0)
		{
			//	No error
			error = lodepng::decode(colorData, w, h, state, rawData);
			if (error == 0)
			{
				//	no error
				width = w;
				height = h;
				hasAlpha = state.info_png.color.colortype == LodePNGColorType::LCT_RGBA;

				if (hasAlpha)
				{
					pixelData = new ColorType[colorData.size()];
					memcpy(pixelData, &colorData[0], colorData.size());
				}
				else
				{
					//	Lode returns RGBA pixels with A=255 in case of RGB
					//	So we need to repack the pixels
					pixelData = new ColorType[w * h * sizeof(ColorRGB)];
					for (unsigned i = 0, j = 0; i < colorData.size(); i += 4, j += 3)
					{
						pixelData[j] = colorData[i];
						pixelData[j + 1] = colorData[i + 1];
						pixelData[j + 2] = colorData[i + 2];
					}
				}

				return true;
			}
		}

		return false;
	}

}