#include "testDisplay.h"

void TestDisplay::testDisplayArray()
{
	ColorArray2D board = ColorArray2D(10, 20);
	board.fill(Color::Transparent);
	ConsoleDisplay display = ConsoleDisplay();

	board.getGrid()[19][9] = Color::Cyan;
	board.getGrid()[18][9] = Color::Cyan;
	board.getGrid()[17][9] = Color::Cyan;
	board.getGrid()[16][9] = Color::Cyan;
	board.getGrid()[15][9] = Color::Orange;
	board.getGrid()[3][4] = Color::Blue;
	board.getGrid()[3][6] = Color::Cyan;

	display.display2DArray(board);
}
