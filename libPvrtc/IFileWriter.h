#pragma once
#include "Color.h"

namespace libpvrtc
{
	//	Generic file writter
	class IFileWriter
	{
	public:

		virtual bool Write(const char* fileName, const ColorType* pixelData, int width, int height, bool hasAlpha) = 0;

	};

}