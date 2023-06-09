#pragma once
#ifndef SCREENMAPPER_H
#define SCREENMAPPER_H

#include "coordinate.h"

class ScreenMapper {

public:
	static Coordinate mapCoords(Coordinate position, Coordinate baseResolution, Coordinate destResolution);

	//Assumes a base resolution of 1920x1080
	static Coordinate mapCoords(Coordinate position, Coordinate destResolution);

	//Assumes a base resolution of 1920x1080
	static Coordinate mapCoords(int posX, int posY, int destX, int destY);

	static Coordinate fitImageInHorizontalMiddle(int imageWidth, int boxWidth);

	static Coordinate fitImageInHorisontalForth(int imageWidth, int boxWidth, int forth);
};
#endif // !SCREENMAPPER_H

