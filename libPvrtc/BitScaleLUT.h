#pragma once
#include <cstdint>

namespace libpvrtc
{
	class BitScaleLUT
	{
	public:
		static const uint8_t BITSCALE_5_TO_8[32];
		static const uint8_t BITSCALE_4_TO_8[16];
		static const uint8_t BITSCALE_3_TO_8[8];
		static const uint8_t BITSCALE_8_TO_5_FLOOR[256];
		static const uint8_t BITSCALE_8_TO_4_FLOOR[256];
		static const uint8_t BITSCALE_8_TO_3_FLOOR[256];
		static const uint8_t BITSCALE_8_TO_5_CEIL[256];
		static const uint8_t BITSCALE_8_TO_4_CEIL[256];
		static const uint8_t BITSCALE_8_TO_3_CEIL[256];
	};
}