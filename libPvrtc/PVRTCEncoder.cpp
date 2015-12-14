#include "PVRTCEncoder.h"
#include "PVRTCFrame.h"
#include "MortonLUT.h"

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

	template<typename T>
	class Interval
	{
	public:
		T min, max;
		Interval<T> &operator|=(const T &x)
		{
			min.SetMin(x);
			max.SetMax(x);
			return *this;
		}
	};

	//	Bounding box for ColorRGB
	typedef Interval<ColorRGB> ColorRgbBB;


	static void CalculateBoundingBox(int x, int y, ImageRGB* image, ColorRgbBB& cbb)
	{
		ColorRGB center = image->GetPixel(x, y);

		cbb.max = center;
		cbb.min = center;

		//	Right and bottom
		cbb |= image->GetPixel(x + 1, y);
		cbb |= image->GetPixel(x + 1, y + 1);

		//	left and bottom
		cbb |= image->GetPixel(x - 1, y);
		cbb |= image->GetPixel(x - 1, y + 1);

		//	top and right
		cbb |= image->GetPixel(x - 1, y - 1);
		cbb |= image->GetPixel(x + 1, y - 1);

		//	top and bottom
		cbb |= image->GetPixel(x, y - 1);
		cbb |= image->GetPixel(x, y + 1);

		//	xxx  
		//	xcx
		//	xxx
	}


	bool PVRTCEncoder::EncodeRGB(const Image* image, ColorType* &encodedData)
	{
		int blockCount = (image->Width() * image->Height()) / PVRTC_PIXELS_PER_BLOCK;
		PVRTCFrame_RGB* frames = new PVRTCFrame_RGB[blockCount];

		ImageRGB* img = (ImageRGB*)image;

		for (int i = 0; i < image->Width() / 4; ++i)
		{
			for (int j = 0; j < image->Height() / 4; ++j)
			{
				PVRTCFrame_RGB* fr = frames + MortonLUT::GetMortonNumber(i, j);

				ColorRgbBB box;
				CalculateBoundingBox(i * 4 + 2, j * 4 + 2, img, box);

				fr->SetColorA(box.min);
				fr->SetColorB(box.max);
				fr->UsePunchtroughAlpha = 0;
				fr->ModulationData = 0xAAAAAAAA;
			}
		}

		encodedData = (ColorType*)(frames);
		return true;
	}

	bool PVRTCEncoder::EncodeRGBA(const Image* image, ColorType* &encodedData)
	{
		int blockCount = (image->Width() * image->Height()) / PVRTC_PIXELS_PER_BLOCK;
		PVRTCFrame_RGBA* frames = new PVRTCFrame_RGBA[blockCount];
		ImageRGBA* img = (ImageRGBA*)image;

		for (int i = 0; i < image->Width() / 4; ++i)
		{
			for (int j = 0; j < image->Height() / 4; ++j)
			{
				PVRTCFrame_RGBA* fr = frames + MortonLUT::GetMortonNumber(i, j);
				ColorRGBA color = img->GetPixel(i * 4 + 2, j * 4 + 2);

				fr->SetColorA(color);
				fr->SetColorB(color);
				fr->UsePunchtroughAlpha = 0;
				fr->ModulationData = 0xFFFFFFFF;
			}
		}

		encodedData = (ColorType*)(frames);
		return true;
	}

}