#include "PNGFileWriter.h"
#include "lodepng.h"

namespace libpvrtc
{
	bool PNGFileWriter::Write(const char* fileName, const ColorType* pixelData, int width, int height, bool hasAlpha)
	{
		unsigned error = lodepng::encode(fileName, pixelData, width, height, hasAlpha ? LCT_RGBA : LCT_RGB);
		return error == 0;
	}
}