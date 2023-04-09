#include "mainGameLoopThread.h"

MainGameLoopThread::MainGameLoopThread(MainGameScene* setGameScene) {
	gameScene = setGameScene;
	QTimer* flashTimer = new QTimer();
	connect(flashTimer, &QTimer::timeout, this, &MainGameLoopThread::mainGameLoop);
	flashTimer->start(1);


	game = new Game(0, gameScene);
	keyboard = new Keyboard;
	actions = new GameActions(keyboard);

	game->start();
	game->refreshUI();
}

void MainGameLoopThread::mainGameLoop() {

	if (game->getState() == GameState::OnGoing)
	{
		game->refreshUI();


		if (actions->holdPiece())
		{
			game->swapPiece();
		}

		if (actions->translateLeft())
			game->translatePieceLeft();
		else if (actions->translateRight())
			game->translatePieceRight();

		if (actions->rotateRight())
			game->rotatePieceRight();
		else if (actions->rotateLeft())
			game->rotatePieceLeft();

		if (actions->dropInstant())
		{
			game->instantDrop();
		}
		if (actions->dropFaster()) {
			game->translatePieceDown();
		}

		if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game->getGravitySpeed()) {
			if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game->getGravitySpeed()) {
				lastAutomaticDrop = high_resolution_clock::now();
				game->translatePieceDown();
			}
		}
	}
}