#pragma once
#include "IFileWriter.h"

namespace libpvrtc
{

	class PVRTCFileWriter : IFileWriter
	{
	public:

		bool Write(const char* fileName, const ColorType* pixelData, int width, int height, bool hasAlpha);

	};

}