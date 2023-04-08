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
