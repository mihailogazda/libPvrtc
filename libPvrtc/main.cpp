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
    int blockMemorySize = 64 / 8 / sizeof(unsigned char);
    int pixelsSize = blockMemorySize * blockCount * sizeof(unsigned char);
    
    //std::cout << "Size : " << blockPixelCount << " " << blockCount << " " << blockMemorySize;
    
    unsigned char* currentBlock = (unsigned char*) malloc(blockMemorySize * sizeof(unsigned char));
    unsigned char* pixels = (unsigned char*) malloc(pixelsSize * sizeof(unsigned char));
    memset(pixels, 0, pixelsSize* sizeof(unsigned char));
    
    for (int i = 0; i < blockCount; i++)
    {
        //  Single block of 64bit
        for (int j = 0; j < blockMemorySize; j++)
        {
            /*if (j == 1)
            {
                currentBlock[j] = 0x00;
            }
            else if (j <= 3)
            {
                currentBlock[j] = (unsigned char) 0x00000000;
            }
            else
            {
                currentBlock[j] = (unsigned char) 0xFFFFFFFF;
            }*/
            
            //  RGB format: [1] -> mode (keep 0), [32bit] modulation
            //  [1|R5|G5|B5] [1|R5|G5|B4][1mode][32modulation]
            
            //  [32bit modulation][1 bit mode][15 bit ColorB][16 bit ColorA]
            //  ColorB:
            //  [0][1|B4|G5|R5]
            //  ColorA:
            //  [1|B5|G5|R5]
            
            
            //  Red B:
            //  0 1 1111 00000 00000
            //  or 0111 1100 0000 0000
            //     0x7C        0x00
            
             //           G
            
            
            
            //          Red
            //  1 11111 00000 00000
            //          Black
            //  1 00000 00000 0000 1 <- mode bit
            //          ColorA
            //  0000 0000 0000 0000
            //
            //  0000 0000 0000 0000
            
            
            
            
            //
            //         Modulaton space
            //  0000 0000 0000 0000
            //
            //  0000 0000 0000 0000
            //
            //          Black
            //  1000 0000 0000 0001 <- mode bit
            //          Red
            //  0 00000 0000 11111 1
            
            
            switch (j)
            {
                case 0:
                case 1:
                case 2:
                    currentBlock[j] = 0x00; // fr
                    break;
                case 3:
                    //  Modulation data
                    currentBlock[j] = 0x01; //  0000 ColorA except first 0:0 pixel
                    break;
                case 4:
                    //  ColorB 1 + mod bit
                    currentBlock[j] = 0x80; //1000 0000
                    break;
                case 5:
                    //  ColorB
                    currentBlock[j] = 0x00; //1000 0000
                    break;
                case 6:
                    //  ColorA 2
                    currentBlock[j] = 0x00; // 1111 1111
                case 7:
                    //  ColorA
                    currentBlock[j] = 0x80;
                    break;
            };
                
            
            
        }
        
        memcpy((void*)(pixels + i * blockMemorySize), currentBlock, blockMemorySize * sizeof(unsigned char));
    }
    
    WritePVRTC("test.pvr", pixels, w, h, false);
    
    free(currentBlock);
    free(pixels);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    CreateImageRGB(256, 256);
    
    
    
    return 0;
}
