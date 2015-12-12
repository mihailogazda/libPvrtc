//
//  main.cpp
//  libPvrtc
//
//  Created by Mihailo Gazda on 26/11/2015.
//  Copyright © 2015 Mihailo Gazda. All rights reserved.
//

#include <iostream>
#include "PVRTextureHeader.h"
#include "PVRTexture.h"
#include "Color.h"
#include "PVRTCFrame.h"

using namespace LIBPvrtc;

void WritePVRTC(const char* filename, const unsigned char* pvrtc, int width, int height, bool hasAlpha = false)
{
    //	PVRTc
    pvrtexture::CPVRTextureHeader pvrTexHdr;
    pvrTexHdr.setPixelFormat(hasAlpha ? EPVRTPixelFormat::ePVRTPF_PVRTCI_4bpp_RGBA : EPVRTPixelFormat::ePVRTPF_PVRTCI_4bpp_RGB);
    pvrTexHdr.setWidth(width);
    pvrTexHdr.setHeight(height);
    pvrTexHdr.setIsFileCompressed(false);
    pvrTexHdr.setColourSpace(ePVRTCSpacelRGB);
    pvrTexHdr.setIsPreMultiplied(false);
    pvrTexHdr.setNumMIPLevels(1);
    pvrTexHdr.setOrientation(ePVRTOrientUp);
    pvrTexHdr.setChannelType(ePVRTVarTypeUnsignedByte);
    //pvrTexHdr.setDepth(4);
    
    pvrtexture::CPVRTexture pTexture(pvrTexHdr, pvrtc);
    pTexture.saveFile(filename);
}

void CreateImageRGB(int w, int h)
{
    int blockPixelCount = 16;
    int blockCount = w * h / blockPixelCount;
    int blockMemorySize = sizeof(PVRTCFrame);
    int pixelsSize = blockMemorySize * blockCount;

	PVRTCFrame_RGB frame;
	PVRTCFrame_RGB* frames = new PVRTCFrame_RGB[pixelsSize];

	for (int i = 0; i < blockCount; ++i)
	{
		ColorRGB color;
		color.B = 0;
		color.R = 0;
		color.G = 255;

		frame.SetColorA(color);
		frame.SetColorB(color);

		frames[i] = frame;
	}

	WritePVRTC("test.pvr", (unsigned char*)frames, w, h, false);
	delete[] frames;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    CreateImageRGB(64, 64);
    
    
    
    return 0;
}
