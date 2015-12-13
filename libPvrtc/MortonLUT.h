#pragma once
#include <stdint.h>

namespace libpvrtc
{
	class MortonLUT
	{
	public:
		static const unsigned short MORTON_TABLE[256];

		static unsigned GetMortonNumber(int x, int y);

		uint32_t CalculateOrder(uint16_t xPos, uint16_t yPos);
	};
}