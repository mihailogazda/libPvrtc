#pragma once
#include <stdio.h>
#include "Color.h"

namespace libpvrtc
{
	class Image
	{
	public:

		Image() : m_width(0), m_height(0) {}
		Image(int width, int height) : m_width(width), m_height(height) {}

		virtual bool HasAlpha() const = 0;

		virtual Color* Pixels() const = 0;
		virtual void SetPixels(const Color* pixels) = 0;

		virtual int Width() const { return m_width; }
		virtual void SetWidth(int w) { m_width = w; }

		virtual int Height() const { return m_height; }
		virtual void SetHeight(int h) { m_height = h; }

	protected:

		int m_width;
		int m_height;

	};

	class ImageRGB : public Image
	{
	public:

		ImageRGB() : Image(), m_pixels(NULL) {}
		ImageRGB(int width, int height) : Image(width, height), m_pixels(NULL)
		{
			m_pixels = new ColorRGB[m_width * m_height];
		}
		~ImageRGB()
		{
			delete[] m_pixels;
		}

		virtual Color* Pixels() const override
		{
			return m_pixels;
		}

		virtual void SetPixels(const Color* pixels) override
		{
			m_pixels = (ColorRGB*)(pixels);
		}

		virtual bool HasAlpha() const override { return false; }

	private:

		ColorRGB* m_pixels;

	};

	class ImageRGBA : public Image
	{
	public:

		ImageRGBA() : Image(), m_pixels(NULL) {}
		ImageRGBA(int width, int height) : Image(width, height), m_pixels(NULL)
		{
			m_pixels = new ColorRGBA[m_width * m_height];
		}
		~ImageRGBA()
		{
			delete[] m_pixels;
		}

		virtual Color* Pixels() const override
		{
			return m_pixels;
		}

		virtual void SetPixels(const Color* pixels) override
		{
			delete[] m_pixels;
			m_pixels = (ColorRGBA*)(pixels);
		}

		virtual bool HasAlpha() const override { return true; }

	private:

		ColorRGBA* m_pixels;
	};
}