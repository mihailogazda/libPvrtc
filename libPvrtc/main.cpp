//
//  main.cpp
//  libPvrtc
//
//  Created by Mihailo Gazda on 26/11/2015.
//  Copyright © 2015 Mihailo Gazda. All rights reserved.
//

#include <iostream>
#include "Color.h"
#include "PVRTCFrame.h"
#include "Image.h"
#include "PVRTCEncoder.h"
#include "PVRTCFileWriter.h"

using namespace libpvrtc;

int main(int argc, const char * argv[]) 
{
	//	Create image
	ImageRGB* rgb128 = new ImageRGB(128, 128);
	PVRTCEncoder encoder;
	PVRTCFileWriter writer;

	ColorType* encodedData = NULL;
	encoder.Encode(rgb128, encodedData);

	writer.Write("test.pvr", encodedData, rgb128->Width(), rgb128->Height(), rgb128->HasAlpha());

	delete[] encodedData;
	delete rgb128;

    return 0;
}
