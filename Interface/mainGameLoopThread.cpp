#include "mainGameLoopThread.h"

MainGameLoopThread::MainGameLoopThread(MainGameScene* setGameScene) {
	gameScene = setGameScene;
	gameTimer = new QTimer();
	connect(gameTimer, &QTimer::timeout, this, &MainGameLoopThread::mainGameLoop);
	gameTimer->start(1);

	game = new Game(0, gameScene);
	keyboard = new Keyboard;
	actions = new GameActions(keyboard);
	actions->initAllActions();

	game->start();
	game->refreshUI();
}

MainGameLoopThread::~MainGameLoopThread()
{
	delete gameTimer;
	delete game;
	delete actions;
	delete keyboard;
}

void MainGameLoopThread::mainGameLoop() {

	if (game->getState() == GameState::OnGoing && init)
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
	else if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > 500 && !init) {
		init = true;
	}
}