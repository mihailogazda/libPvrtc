#pragma once
#include "Color.h"

namespace libpvrtc
{
	//	Generic image representation
	//	Reserves memory when initialized with dimensions
	template<typename PixelType>
	class Image
	{
	public:

		Image() : m_pixels(NULL), m_width(0), m_height(0)
		{
		}

		Image(int width, int height)
		{
			m_width = width;
			m_height = height;
			m_pixels = new PixelType[width * height];
		}

		Image(const Image& reference)
		{
			CopyPixels(reference);
		}

		Image(const Image* pointer)
		{
			if (pointer != NULL)
				CopyPixels(*pointer);
		}

		Image<PixelType>& operator= (const Image<PixelType>& reference)
		{
			CopyPixels(reference);
			return *this;
		}

		Image<PixelType>& operator= (const Image<PixelType>* pointer)
		{
			if (pointer != NULL)
				CopyPixels(*pointer);
			return this;
		}

		~Image()
		{
			delete[] m_pixels;
		}

		void SetPixels(const PixelType* pixels)
		{
			delete[] m_pixels;
			m_pixels = pixels;
		}

		const PixelType* GetPixels() const { return m_pixels; }

		PixelType ColorAt(int x, int h) const
		{
			return m_pixels[x * h];
		}

		void SetColor(int x, int y, PixelType color)
		{
			m_pixels[x * y] = color;
		}

		int Width() const { return m_width; }
		int Height() const { return m_height; }

		virtual bool HasAlpha() const { return sizeof(PixelType) == sizeof(ColorRGBA); };

	private:

		void CopyPixels(const Image& reference)
		{
			delete[] m_pixels;
			m_width = reference.Width();
			m_height = reference.Height();
			m_pixels = new PixelType[m_width * m_height];
			memcpy(m_pixels, reference.GetPixels(), m_width * m_height * sizeof(PixelType));
		}

		PixelType* m_pixels;

		int m_width;
		int m_height;
	};

	typedef Image<ColorRGB> ImageRGB;
	typedef Image<ColorRGBA> ImageRGBA;
}