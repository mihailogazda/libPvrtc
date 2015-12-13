#include "Image.h"

namespace libpvrtc
{
	//
	//	IMAGE
	//
	Image::Image() : m_width(0), m_height(0) {}

	Image::Image(int width, int height) : m_width(width), m_height(height) {}

	int Image::Width() const { return m_width; }

	void Image::SetWidth(int w) { m_width = w; }

	int Image::Height() const { return m_height; }

	void Image::SetHeight(int h) { m_height = h; }
	//	======================

	//
	//	Image RGB
	//
	ImageRGB::ImageRGB() : Image(), m_pixels(NULL) {}

	ImageRGB::ImageRGB(int width, int height) : Image(width, height), m_pixels(NULL)
	{
		m_pixels = new ColorRGB[m_width * m_height];
	}

	ImageRGB::ImageRGB(int width, int height, const ColorRGB * pixels) : Image(width, height)
	{
		m_pixels = new ColorRGB[m_width * m_height];
		memcpy(m_pixels, pixels, m_width * m_height * sizeof(ColorRGB));
	}

	ImageRGB::~ImageRGB()
	{
		delete[] m_pixels;
	}

	Color * ImageRGB::Pixels() const
	{
		return m_pixels;
	}

	void ImageRGB::SetPixels(const Color * pixels)
	{
		m_pixels = (ColorRGB*)(pixels);
	}

	bool ImageRGB::HasAlpha() const { return false; }

	void ImageRGB::SetPixel(const ColorRGB & color, int x, int y)
	{
		unsigned int index = x + m_width * y;
		m_pixels[index] = color;
	}

	ColorRGB ImageRGB::GetPixel(int x, int y) 
	{
		unsigned int index = x + m_width * y;
		return m_pixels[index];
	}

	//	======================

	//
	//	Image RGBA
	//
	ImageRGBA::ImageRGBA() : Image(), m_pixels(NULL) {}

	ImageRGBA::ImageRGBA(int width, int height) : Image(width, height), m_pixels(NULL)
	{
		m_pixels = new ColorRGBA[m_width * m_height];
	}

	ImageRGBA::ImageRGBA(int width, int height, const ColorRGBA * pixels) : Image(width, height)
	{
		m_pixels = new ColorRGBA[m_width * m_height];
		memcpy(m_pixels, pixels, m_width * m_height * sizeof(ColorRGBA));
	}

	ImageRGBA::~ImageRGBA()
	{
		delete[] m_pixels;
	}

	Color * ImageRGBA::Pixels() const
	{
		return m_pixels;
	}

	void ImageRGBA::SetPixels(const Color * pixels)
	{
		delete[] m_pixels;
		m_pixels = (ColorRGBA*)(pixels);
	}

	bool ImageRGBA::HasAlpha() const { return true; }

	inline void ImageRGBA::SetPixel(const ColorRGBA & color, int x, int y) 
	{
		unsigned int index = x + m_width * y;
		m_pixels[index] = color;
	}

	inline ColorRGBA ImageRGBA::GetPixel(int x, int y)
	{
		unsigned int index = x + m_width * y;
		return m_pixels[index];
	}

	//	======================
}