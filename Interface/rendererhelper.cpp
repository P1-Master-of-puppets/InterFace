#include "rendererhelper.h"

Coordinate RendererHelper::fitImageInHorizontalMiddle(int imageWidth, int boxWidth)
{

	int middlePosition = boxWidth / 2;
	int halfImage = imageWidth / 2;
	//Since the position of an image is in its top left corner we remove half the image width to the center of its container

	return Coordinate{ middlePosition - halfImage, 0};
}
