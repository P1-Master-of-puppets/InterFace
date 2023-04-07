#include "consoleDisplay.h"

void displayWithColor(Color color) {
	char wall = '#';
	switch (color)
	{
	case Color::Transparent:
		std::cout << "  ";
		break;
	case Color::Cyan:
		std::cout << "\x1B[36m" << wall << " \033[0m";
		break;
	case Color::Yellow:
		std::cout << "\x1B[33m" << wall << " \033[0m";
		break;
	case Color::Purple:
		std::cout << "\x1B[35m" << wall << " \033[0m";
		break;
	case Color::Green:
		std::cout << "\x1B[32m" << wall << " \033[0m";
		break;
	case Color::Blue:
		std::cout << "\x1B[34m" << wall << " \033[0m";
		break;
	case Color::Red:
		std::cout << "\x1B[31m" << wall << " \033[0m";
		break;
	case Color::Orange:
		std::cout << "\x1B[37m" << wall << " \033[0m";
		break;
	default:
		break;
	}
}

void displayWithoutColor(Color color) {
	switch (color)
	{
	case Color::Transparent:
		std::cout << ". ";
		break;
	case Color::Cyan:	std::cout << "C "; break;
	case Color::Yellow: std::cout << "Y "; break;
	case Color::Purple: std::cout << "P "; break;
	case Color::Green:	std::cout << "G "; break;
	case Color::Blue:	std::cout << "B "; break;
	case Color::Red:	std::cout << "R "; break;
	case Color::Orange: std::cout << "O "; break;
	default:
		std::cout << "# ";
		break;
	}
}


ConsoleDisplay::ConsoleDisplay()
{
}

ConsoleDisplay::~ConsoleDisplay()
{
}

void ConsoleDisplay::display2DArray(ColorArray2D& colorArray)
{
	//display2DArray(colorArray, 0);
}

void ConsoleDisplay::displayBoardWithPiece(ColorArray2D& board, Piece* somePiece) {

	ColorArray2D combinedBoard = ColorArray2D(board);

	somePiece->addToColorArray2D(combinedBoard);

	display2DArray(combinedBoard);
}


void ConsoleDisplay::displayBoardWithPiece(ColorArray2D& board, Piece* somePiece, int startLine)
{
	ColorArray2D combinedBoard = ColorArray2D(board);

	somePiece->addToColorArray2D(combinedBoard);

	display2DArray(combinedBoard, startLine);
}

void ConsoleDisplay::display2DArray(ColorArray2D& colorArray, int startLine)
{
	for (int i = 0; i < colorArray.getWidth() * 2 + 3; i++) {
		std::cout << "#";
	}

	std::cout << "\n" << "#";

	//Change console color only if in windows.
	//Linux might be using a different lib.
	int yo = colorArray.getHeight();
	for (int i = startLine; i < colorArray.getHeight(); i++)
	{
		std::cout << " ";
		for (int j = 0; j < colorArray.getWidth(); j++)
		{
			displayWithColor(colorArray.getGrid()[i][j]);
		}
		std::cout << "#" << "\n" << "#";
	}

	for (int i = 0; i < colorArray.getWidth() * 2 + 2; i++) {
		std::cout << "#";
	}

	std::cout << "\n";

}



void ConsoleDisplay::displayHoldPiece(Piece* holdPiece, ColorArray2D& board)
{
	if (holdPiece == nullptr) {
		displayEmptyHoldPiece(board);
		return;
	}

	displayEmptyHoldPiece(board);
	COORD topLeft = { 0, 26 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), topLeft);
	for (int i = 0; i < holdPiece->getPiece()->getHeight(); i++)
	{
		for (int j = 0; j < 13; j++) {
			std::cout << "#";
		}
		for (int j = 0; j < holdPiece->getPiece()->getWidth(); j++)
		{
			displayWithColor(holdPiece->getPiece()->getGrid()[i][j]);
		}
		std::cout << "\n";
	}

}

void ConsoleDisplay::displayEmptyHoldPiece(ColorArray2D& board)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < board.getWidth() *2 - 7 ; j++)
		{
			std::cout << "#";
		}
		std::cout << "        ##\n";
	}

	for (int i = 0; i < board.getWidth() * 2 + 3; i++) {
		std::cout << "#";
	}

}
