#include "maingamescene.h"

MainGameScene::MainGameScene(QSize viewSize, QGraphicsView* parent) : ApplicationScene(viewSize), _game(Game(0)), _gameView(parent)
{
	_keyboard = new Keyboard();
	_controller = new Controller(7, 115200);
	_actions = new GameActions(_keyboard);
	_actions->initAllActions();
	_game.setController(_controller);
	_game.start();
	QPixmap background(BACKGROUND_IMAGE_PATH);
	setBackground(background);

	Coordinate dim = ScreenMapper::mapCoords(287, 92, this->width(), this->height());
	//LES CHIFFRES MAGIQUES C'EST PAS BON
	_level = new TextRenderer(QString::number(1), this, ScreenMapper::mapCoords(228, 680, this->width(), this->height()), dim);
	_tetris = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 480, this->width(), this->height()), dim);
	_score = new TextRenderer(QString::number(0), this, ScreenMapper::mapCoords(228, 278, this->width(), this->height()), dim);

	_monBoard = new BoardRenderer(this);
	_gamePiece = new PieceRenderer(this);

	_holdPiece = new PieceRenderer(this, ScreenMapper::mapCoords(1398, 697, this->width(), this->height()), ScreenMapper::mapCoords(250, 206, this->width(), this->height()));
	_nextPiece = new PieceRenderer(this, ScreenMapper::mapCoords(1398, 278, this->width(), this->height()), ScreenMapper::mapCoords(255, 212, this->width(), this->height()));
	
	_pauseMenu = new PauseMenuRenderer(this);
	_GO = new GameOverRenderer(this);
	
	_gameView->grabKeyboard();
	
	startGame();
}

MainGameScene::~MainGameScene()
{
	_gameView->releaseKeyboard();
	_gameTimer.stop();

	//Ui elements
	delete _level;
	delete _tetris;
	delete _score;
	delete _monBoard;
	delete _gamePiece;
	delete _holdPiece;
	delete _nextPiece;


	//Game Elements
	delete _keyboard;
	delete _actions;
}


void MainGameScene::refreshUI(ColorArray2D* board, Piece* piece, Piece* holdPiece, Piece* nextPiece,
	int score, int tetris, int level) {

	_scoreVal = score;
	_tetrisVal = tetris;
	_levelVal = level;
	//Images
	_monBoard->renderBoard(board);
	_gamePiece->renderPiece(piece);
	if (holdPiece != nullptr) {
		_holdPiece->renderPiece(holdPiece);
	}
	if (nextPiece != nullptr) {
		_nextPiece->renderPiece(nextPiece);
	}

	//Text
	_score->updateText(score);
	_tetris->updateText(tetris);
	_level->updateText(level);
}

void MainGameScene::startGame()
{
	_gameTimer;
	connect(&_gameTimer, &QTimer::timeout, this, &MainGameScene::gameLoop);
	
	connect(_pauseMenu, &PauseMenuRenderer::resumeButtonClicked, this, &MainGameScene::resumeGame);
	connect(_pauseMenu, &PauseMenuRenderer::exitButtonClicked, this, &MainGameScene::exitGame);
	
	_gameTimer.start(1);


}

void MainGameScene::keyPressEvent(QKeyEvent* event)
{
	if (_game.getState() == GameState::Finished) {
		exitGame();
	}


	if (event->key() == Qt::Key_M)
	{
		if (!_isPaused) {
			_gameTimer.stop();
			_pauseMenu->show();
		}
			
		_isPaused = !_isPaused;
	}
	else if (event->key() == Qt::Key_P)
	{
		emit goToMainMenu();
	}
}

void MainGameScene::resumeGame()
{
	_pauseMenu->dismiss();
	_gameView->grabKeyboard();
	_gameTimer.start(1);
	_isPaused = false;
}

void MainGameScene::exitGame()
{
	emit exitApplication();
}

void MainGameScene::gameLoop()
{
	if (_game.getState() == GameState::Finished)
	{
		gameFinished();
	}

	if (_actions->holdPiece())
	{
		_game.swapPiece();
	}

	if (_actions->translateLeft())
		_game.translatePieceLeft();
	else if (_actions->translateRight())
		_game.translatePieceRight();

	if (_actions->rotateRight())
		_game.rotatePieceRight();
	else if (_actions->rotateLeft())
		_game.rotatePieceLeft();

	if (_actions->dropInstant())
	{
		_game.instantDrop();
	}
	if (_actions->dropFaster()) {
		_game.translatePieceDown();
	}

	if (duration_cast<milliseconds>(high_resolution_clock::now() - _lastAutomaticDrop).count() > _game.getGravitySpeed()) {
		if (duration_cast<milliseconds>(high_resolution_clock::now() - _lastAutomaticDrop).count() > _game.getGravitySpeed()) {
			_lastAutomaticDrop = high_resolution_clock::now();
			_game.translatePieceDown();
		}
	}
	_game.refreshUI(this);
}


void MainGameScene::gameFinished() {
	_gameTimer.stop();
	_GO->show(_scoreVal, _tetrisVal, _levelVal);
}
