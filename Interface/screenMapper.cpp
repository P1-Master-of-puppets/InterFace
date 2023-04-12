#include "screenMapper.h"

Coordinate ScreenMapper::mapCoords(Coordinate position, Coordinate baseResolution, Coordinate destResolution)
{
	Coordinate result;
	result.x = position.x * destResolution.x / baseResolution.x;
	result.y = position.y * destResolution.y / baseResolution.y;
	return result;
}

Coordinate ScreenMapper::mapCoords(Coordinate position, Coordinate destResolution)
{
	return mapCoords(position, Coordinate({ 1920, 1080 }), destResolution);
}

Coordinate ScreenMapper::mapCoords(int posX, int posY, int destX, int destY)
{
	return mapCoords(Coordinate({posX, posY}), Coordinate({destX, destY}));
}

Coordinate ScreenMapper::fitImageInHorizontalMiddle(int imageWidth, int boxWidth)
{
	int middlePosition = boxWidth / 2;
	int halfImage = imageWidth / 2;
	//Since the position of an image is in its top left corner we remove half the image width to the center of its container

	return Coordinate{ middlePosition - halfImage, 0 };
}
