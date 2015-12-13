#pragma once
#include "Color.h"

namespace libpvrtc
{
	//	Generic file reader
	class IFileReader
	{
	public:
		virtual bool Read(const char* fileName, ColorType* &pixels, int& width, int& height, bool& hasAlpha) = 0;
	};
}