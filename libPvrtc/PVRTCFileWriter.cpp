#include "PVRTCFileWriter.h"
#include "PVRTextureHeader.h"
#include "PVRTexture.h"

namespace libpvrtc
{
	bool PVRTCFileWriter::Write(const char* fileName, const ColorType* pixelData, int width, int height, bool hasAlpha)
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

		pvrtexture::CPVRTexture pTexture(pvrTexHdr, pixelData);
		bool success = pTexture.saveFile(fileName);

		return success;
	}

}