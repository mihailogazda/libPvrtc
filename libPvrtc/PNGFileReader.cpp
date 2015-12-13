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

				pixelData = new ColorType[colorData.size()];
				memcpy(pixelData, &colorData[0], colorData.size());
				//std::copy(rawData.begin(), rawData.end(), (const unsigned char*) pixelData);

				return true;
			}
		}

		return false;
	}

}