#pragma once
#include "IEncoder.h"

namespace libpvrtc
{
	class PVRTCEncoder : IEncoder
	{
	public:

		virtual bool Encode(const Image* image, ColorType* &encodedData) override;

	private:

		bool EncodeRGB(const Image* image, ColorType* &encodedData);
		bool EncodeRGBA(const Image* image, ColorType* &encodedData);
	};
}