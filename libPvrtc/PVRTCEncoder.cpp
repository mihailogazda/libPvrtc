#include "PVRTCEncoder.h"
#include "PVRTCFrame.h"

namespace libpvrtc
{
	static const int PVRTC_PIXELS_PER_BLOCK = 16;

	bool PVRTCEncoder::Encode(const ImageRGB* image, ColorType* &encodedData)
	{
		if (image == nullptr)
			return false;

		if (image->Width() != image->Height())
			return false;

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


	bool PVRTCEncoder::Encode(const ImageRGBA* image, ColorType* &encodedData)
	{


		return false;
	}

}