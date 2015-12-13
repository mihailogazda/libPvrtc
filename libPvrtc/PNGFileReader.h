#pragma once
#include "IFileReader.h"

namespace libpvrtc
{
	class PNGFileReader : IFileReader
	{
	public:

		bool Read(const char* fileName, ColorType* &pixels, int& widht, int& height, bool& hasAlpha) override;

	};

}