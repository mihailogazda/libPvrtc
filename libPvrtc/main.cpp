//
//  main.cpp
//  libPvrtc
//
//  Created by Mihailo Gazda on 26/11/2015.
//  Copyright © 2015 Mihailo Gazda. All rights reserved.
//

#include <iostream>
#include "Color.h"
#include "Image.h"
#include "PVRTCFrame.h"
#include "PVRTCEncoder.h"
#include "PVRTCFileWriter.h"
#include "ImageLoader.h"
#include "PNGFileWriter.h"

using namespace libpvrtc;


int main(int argc, const char * argv[]) 
{
	const char* imageName = "test.png";
	Image* image = NULL;

	if (argc > 1)
	{
		imageName = argv[1];
	}

	ImageLoader loader;
	if (!loader.Load(imageName, image))
	{
		std::cout << "Cannot load input image" << std::endl;
		return 0;
	}

	//	Write back
	/*PNGFileWriter pngWriter;
	pngWriter.Write("test-out.png", (const ColorType*) image->Pixels(), image->Width(), image->Height(), image->HasAlpha());

	ImageRGB* rgb = new ImageRGB(image->Width(), image->Height());
	for (int i = 0; i < image->Width(); ++i)
	{
		for (int j = 0; j < image->Height(); ++j)
		{
			rgb->SetPixel(((ImageRGB*)image)->GetPixel(i, j), i, j);
		}
	}

	pngWriter.Write("test-out-copy.png", (const ColorType*) rgb->Pixels(), rgb->Width(), rgb->Height(), false);
	*/


	PVRTCEncoder encoder;
	PVRTCFileWriter writer;

	ColorType* encodedData = NULL;
	encoder.Encode(image, encodedData);

	writer.Write("test.pvr", encodedData, image->Width(), image->Height(), image->HasAlpha());

	delete[] encodedData;
	delete image;

    return 0;
}
