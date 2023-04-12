#include "maingamescene.h"

MainGameScene::MainGameScene(QSize viewSize) : ApplicationScene(viewSize)
{
	_gameLevel = 3;
	Coordinate dim = ScreenMapper::mapCoords(287, 92, this->width(), this->height());
	//LES CHIFFRES MAGIQUES C'EST PAS BON
	_level = new TextRenderer(QString::number(1), this, ScreenMapper::mapCoords(228, 680, this->width(), this->height()), dim);
	_tetris = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 480, this->width(), this->height()), dim);
	_score = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 278, this->width(), this->height()), dim);

	_monBoard = new BoardRenderer(this);
	_gamePiece = new PieceRenderer(this);

	_holdPiece = new PieceRenderer(this, ScreenMapper::mapCoords(1398, 278, this->width(), this->height()), ScreenMapper::mapCoords(250, 206, this->width(), this->height()));
	_nextPiece = new PieceRenderer(this, ScreenMapper::mapCoords(1398, 697, this->width(), this->height()), ScreenMapper::mapCoords(255, 212, this->width(), this->height()));
	QPixmap background(BACKGROUND_IMAGE_PATH);
	setBackground(background);
}

MainGameScene::~MainGameScene()
{
	delete _level;
	delete _tetris;
	delete _score;
	delete _monBoard;
	delete _gamePiece;
	delete _holdPiece;
	delete _nextPiece;
}

void MainGameScene::refreshUI(GameInformation information)
{
	//Images
	_monBoard->renderBoard(information.board);
	_gamePiece->renderPiece(information.piece);
	if (information.holdPiece != nullptr) {
		_holdPiece->renderPiece(information.holdPiece);
	}
	if (information.nextPiece != nullptr) {
		_nextPiece->renderPiece(information.nextPiece);
	}

	//Text
	_score->updateText(information.score);
	_tetris->updateText(information.tetris);
	_level->updateText(information.level);
}

void MainGameScene::startGame()
{
	_gameThread = std::thread(&MainGameScene::gameLoop, this);
}

void MainGameScene::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_M)
	{
		_isPaused = !_isPaused;
	}
	else if (event->key() == Qt::Key_P)
	{
		_isPaused = true;
		_windowQuit = true;
		_gameThread.join();
		emit goToMainMenu();
	}
}

void MainGameScene::gameLoop()
{
	//TODO: AJOUTER LA MANETTE AU JEUX
	Keyboard* keyboard = new Keyboard();
	GameActions actions = GameActions(keyboard);
	//Controller* controller = new Controller(7, 115200);
	Game game = Game(_gameLevel);
	//game.setController(controller);
	game.start();

	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();


	while (game.getState() == GameState::OnGoing)
	{
		while (_isPaused)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			if (_windowQuit)
			{
				return;
			}
		}

		QObject::connect(this, &MainGameScene::sendRefreshUI,
			this, &MainGameScene::refreshUI);

		emit sendRefreshUI(game.getGameInformation());

		if (actions.holdPiece())
		{
			game.swapPiece();
		}

		if (actions.translateLeft())
			game.translatePieceLeft();
		else if (actions.translateRight())
			game.translatePieceRight();

		if (actions.rotateRight())
			game.rotatePieceRight();
		else if (actions.rotateLeft())
			game.rotatePieceLeft();

		if (actions.dropInstant())
		{
			game.instantDrop();
		}
		if (actions.dropFaster()) {
			game.translatePieceDown();
		}

		if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
			if (duration_cast<milliseconds>(high_resolution_clock::now() - lastAutomaticDrop).count() > game.getGravitySpeed()) {
				lastAutomaticDrop = high_resolution_clock::now();
				game.translatePieceDown();
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	delete keyboard;
}