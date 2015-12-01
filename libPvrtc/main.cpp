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

//  RGB format: [1] -> mode (keep 0), [32bit] modulation
//  [1|R5|G5|B5] [1|R5|G5|B4][1mode][32modulation]

//  [32bit modulation][1 bit mode][15 bit ColorB][16 bit ColorA]

//  [ 32bit modulation ][1| 15b ColorA] [1| 16 bit ColorA]
struct PVRTCFrame
{
    unsigned int ModulationData;
    unsigned UsePunchtroughAlpha : 1;
    unsigned ColorA : 14;
    unsigned  ColorAIsOpaque : 1;
    unsigned ColorB : 15;
    unsigned ColorBIsOpaque : 1;
    
    PVRTCFrame() : UsePunchtroughAlpha(false), ModulationData(0){}
};

struct PVRTCFrame_RGB : PVRTCFrame
{
    PVRTCFrame_RGB() : PVRTCFrame()
    {
        ColorAIsOpaque = 0b1;
        ColorBIsOpaque = 0b1;
    }
};

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
    
    PVRTCFrame* pixels = (PVRTCFrame*) malloc(pixelsSize);
    memset(pixels, 0, pixelsSize);
    
    PVRTCFrame_RGB frame;
    for (int i = 0; i < blockCount; i++)
    {
        //  Single block of 64bit
        frame.ColorAIsOpaque = 1;
        frame.ColorBIsOpaque = 0;
        frame.ColorA = 0;
        frame.ColorB = 0;
        frame.ModulationData = 0b11111111001100110011;
        
        pixels[i] = frame;
    }
    
    WritePVRTC("test.pvr", (unsigned char*) pixels, w, h, false);
    
    free(pixels);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    CreateImageRGB(64, 64);
    
    
    
    return 0;
}
