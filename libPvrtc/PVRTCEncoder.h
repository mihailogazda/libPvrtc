#pragma once
#include "IEncoder.h"

namespace libpvrtc
{
	class PVRTCEncoder : IEncoder
	{
	public:

		virtual bool Encode(const ImageRGB* image, ColorType* &encodedData) override;

		virtual bool Encode(const ImageRGBA* image, ColorType* &encodedData) override;

	};
}