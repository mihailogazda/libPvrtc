#pragma once
#include "IFileWriter.h"

namespace libpvrtc
{
	class PNGFileWriter : public IFileWriter
	{
	public:

		bool Write(const char* fileName, const ColorType* pixelData, int width, int height, bool hasAlpha) override;

	};

}