#include <iostream>
#include <chrono>
#include "game.h"
#include "colorArray2D.h"
#include "gameActions.h"
#include "controller.h"

using namespace std::chrono;


int main()
{
	std::cout << "Select starting level from 0 to 9 : ";
	int startingLevel;
	std::cin >> startingLevel;

	Controller* controller = new Controller(7, 115200);
	Game game = Game(startingLevel);
	game.setController(controller);
	game.start();
	//game.refreshUI();
	Keyboard* keyboard = new Keyboard();
	GameActions* actions = new GameActions(keyboard);
	
	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	while (game.getState() == GameState::OnGoing)
	{
		//game.refreshUI();


		if (actions->holdPiece())
		{
			game.swapPiece();
		}

		if (actions->translateLeft())
			game.translatePieceLeft();
		else if (actions->translateRight())
			game.translatePieceRight();

		if (actions->rotateRight())
			game.rotatePieceRight();
		else if (actions->rotateLeft())
			game.rotatePieceLeft();

		if (actions->dropInstant())
		{
			game.instantDrop();
		}
		if (actions->dropFaster()) {
			game.translatePieceDown();
		}

		if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
			if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
				lastAutomaticDrop = high_resolution_clock::now();
				game.translatePieceDown();
			}
		}
	}
	return 0;
}