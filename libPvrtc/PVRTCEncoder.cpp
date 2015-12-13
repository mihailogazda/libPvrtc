#include "PVRTCEncoder.h"
#include "PVRTCFrame.h"

namespace libpvrtc
{
	static const int PVRTC_PIXELS_PER_BLOCK = 16;

	bool PVRTCEncoder::Encode(const Image* image, ColorType* &encodedData)
	{
		if (image == nullptr)
			return false;

		if (image->Width() != image->Height())
			return false;

		bool success = false;
		if (image->HasAlpha())
		{
			success = EncodeRGBA(image, encodedData);
		}
		else
		{
			success = EncodeRGB(image, encodedData);
		}

		return success;
	}

	bool PVRTCEncoder::EncodeRGB(const Image* image, ColorType* &encodedData)
	{
		int blockCount = (image->Width() * image->Height()) / PVRTC_PIXELS_PER_BLOCK;
		PVRTCFrame_RGB frame;
		PVRTCFrame_RGB* frames = new PVRTCFrame_RGB[blockCount];

		for (int i = 0; i < blockCount; ++i)
		{
			ColorRGB color;
			color.B = 255;
			color.R = 0;
			color.G = 0;

			frame.SetColorA(color);
			frame.SetColorB(color);

			frames[i] = frame;
		}

		encodedData = (ColorType*)(frames);
		return true;
	}

	bool PVRTCEncoder::EncodeRGBA(const Image* image, ColorType* &encodedData)
	{
		int blockCount = (image->Width() * image->Height()) / PVRTC_PIXELS_PER_BLOCK;

		PVRTCFrame_RGBA frame;
		PVRTCFrame_RGBA* frames = new PVRTCFrame_RGBA[blockCount];

		for (int i = 0; i < blockCount; ++i)
		{
			ColorRGBA color;
			color.B = 255;
			color.R = 0;
			color.G = 0;
			color.A = 0;

			frame.SetColorA(color);
			frame.SetColorB(color);

			frames[i] = frame;
		}

		encodedData = (ColorType*)(frames);
		return true;
	}

}