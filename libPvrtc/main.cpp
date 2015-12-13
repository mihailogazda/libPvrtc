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
	Image* image = NULL;

	ImageLoader loader;
	if (!loader.Load("test.png", image))
	{
		std::cout << "Cannot load input image" << std::endl;
		return 0;
	}

	//	Write back
	PNGFileWriter pngWriter;
	pngWriter.Write("test-out.png", (const ColorType*) image->Pixels(), image->Width(), image->Height(), image->HasAlpha());

	PVRTCEncoder encoder;
	PVRTCFileWriter writer;

	ColorType* encodedData = NULL;
	encoder.Encode(image, encodedData);

	writer.Write("test.pvr", encodedData, image->Width(), image->Height(), image->HasAlpha());

	delete[] encodedData;
	delete image;

    return 0;
}
