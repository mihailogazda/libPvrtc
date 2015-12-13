#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include "Color.h"

namespace libpvrtc
{
	class Image
	{
	public:

		Image();
		Image(int width, int height);

		virtual bool HasAlpha() const = 0;

		virtual Color* Pixels() const = 0;
		virtual void SetPixels(const Color* pixels) = 0;

		virtual int Width() const;
		virtual void SetWidth(int w);

		virtual int Height() const;
		virtual void SetHeight(int h);

	protected:

		int m_width;
		int m_height;

	};

	class ImageRGB : public Image
	{
	public:

		ImageRGB();
		ImageRGB(int width, int height);
		ImageRGB(int width, int height, const ColorRGB* pixels);
		~ImageRGB();

		virtual Color* Pixels() const override;
		virtual void SetPixels(const Color* pixels) override;
		virtual bool HasAlpha() const override;

		void SetPixel(const ColorRGB& color, int x, int y);
		ColorRGB GetPixel(int x, int y);

	private:

		ColorRGB* m_pixels;

	};

	class ImageRGBA : public Image
	{
	public:

		ImageRGBA();
		ImageRGBA(int width, int height);
		ImageRGBA(int width, int height, const ColorRGBA* pixels);
		~ImageRGBA();

		virtual Color* Pixels() const override;
		virtual void SetPixels(const Color* pixels) override;
		virtual bool HasAlpha() const override;

		void SetPixel(const ColorRGBA& color, int x, int y);
		ColorRGBA GetPixel(int x, int y);

	private:

		ColorRGBA* m_pixels;
	};
}