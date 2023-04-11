#ifndef TESTPIECE_H__
#define TESTPIECE_H__

#include <iostream>
#include "piece.h"
#include "consoleDisplay.h"
#include "colorArray2D.h"
#include "thomas.h"
#include "longBar.h"
#include "rightL.h"
#include "rightS.h"
#include "leftL.h"
#include "leftS.h"
#include "square.h"


class TestPiece
{
public:
	static void testTranslateRight();
	static void testTranslateLeft();
	static void testRotateRight();
	static void testRotateLeft();
	static void testIsColliding();
	static void testTouchBottom();
};

#endif // TESTPIECE_H__