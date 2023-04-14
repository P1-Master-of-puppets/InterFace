#include "game.h"

Game::Game(int level)
{
	_level = level;
	srand(time(0));
	_board.fill(Color::Transparent);
	updateLvlAndGravity();
	setGravity();
	//Fill the queue with random pieces
	// this might be changed for a less rng aproach
	for (int i = 0; i < 8; i++)
	{
		_queue.push(getRandomPiece());
	}
	_state = GameState::Initiated;
}

Game::~Game()
{
}

const ColorArray2D& Game::getBoard()
{
	return _board;
}

Piece* Game::getPiece()
{
	return _currentPiece;
}

int Game::getLevel()
{
	return _level;
}

int Game::getGravitySpeed()
{
	return _gravityspeed_milliseconds;
}

bool Game::rotatePieceLeft()
{
	if (_currentPiece->rotateLeft(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::rotatePieceRight()
{
	if (_currentPiece->rotateRight(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceLeft()
{
	if (_currentPiece->translateLeft(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceRight()
{
	if (_currentPiece->translateRight(_board))
	{
		_isDirty = true;
		return true;
	}
	return false;
}

bool Game::translatePieceDown()
{
	_isDirty = true;

	if (!_currentPiece->translateDown(_board))
	{
		putPieceInBoard();
		delete _currentPiece;
		_currentPiece = _queue.front();
		_queue.pop();
		_queue.push(getRandomPiece());

		int rowAmount = 0;
		int* rows = getFullRows(rowAmount);
		removeRows(rows, rowAmount);
		delete rows;
		if (rowAmount == 4)
			addTetris();

		_score += countLineScore(rowAmount);
		_totalLines += rowAmount;

		updateLvlAndGravity();
		updateThreatAndLines();
		gameLost();
		return false;
	}

	return true;
}

GameState Game::getState()
{
	return _state;
}

void Game::start()
{
	_state = GameState::OnGoing;
	_currentPiece = _queue.front();
	_queue.pop();
}

void Game::setController(Controller* controller)
{
	_controller = controller;
}

Piece* Game::getRandomPiece() {
	switch (rand() % 7)
	{
	case 0:
		return new LeftL();
		break;
	case 1:
		return new LeftS();
		break;
	case 2:
		return new LongBar();
		break;
	case 3:
		return new RightL();
		break;
	case 4:
		return new RightS();
		break;
	case 5:
		return new Square();
		break;
	case 6:
		return new Thomas();
		break;
	}
}

int* Game::getFullRows(int& size)
{
	int* values = new int[4];

	int rowAmount = 0;
	int currentHighest = -1;
	for (int i = 0; i < _board.getHeight(); i++)
	{
		bool isNotFull = false;
		for (int j = 0; j < _board.getWidth(); j++)
		{
			Color couleur = _board.getGrid()[i][j];
			if (couleur == Color::Transparent) {
				isNotFull = true;
			}

			if (currentHighest == -1)
			{
				if (couleur != Color::Transparent)
					currentHighest = i;
			}

			if (j == _board.getWidth() - 1 && !isNotFull)
			{
				values[rowAmount] = i;
				rowAmount++;
			}

		}
	}
	_highestPiece = currentHighest - rowAmount;
	size = rowAmount;
	return values;
}

void Game::removeRows(int* rows, int& size) {
	//remove all rows
	for (int i = 0; i < size; i++)
	{
		delete[] _board.getGrid()[rows[i]];


		for (int j = rows[i] - 1; j >= 0; j--)
		{
			_board.getGrid()[j + 1] = _board.getGrid()[j];
		}
		_board.getGrid()[0] = new Color[_board.getWidth()];

		for (int i = 0; i < _board.getWidth(); i++)
		{
			_board.getGrid()[0][i] = Color::Transparent;
		}
	}
}

void Game::putPieceInBoard()
{
	_currentPiece->addToColorArray2D(_board);
}

bool Game::gameLost()
{
	//Verify if new piece is over a current piece
	if (_currentPiece->isColliding(_currentPiece->getPiece(), _currentPiece->getCoordinate(), _board))
	{
		_state = GameState::Finished;
		return true;
	}

	//Verify if pices are higher than the displayed one
	for (int i = 0; i < _board.getWidth(); i++)
	{
		if (_board.getGrid()[extraRow - 1][i] != Color::Transparent)
		{
			GameState::Finished;
			return true;
		}
	}
	return false;
}

void Game::updateLvlAndGravity()
{
	if ((_level + 1) * 10 <= _totalLines)
	{
		_level++;
		setGravity();
	}
}

void Game::setGravity()
{
	if (_level < 9)
	{
		_gravityspeed_milliseconds = 1000 * (((double)48 - ((double)_level * (double)5)) / (double)60);
	}
	else if (_level == 9)
	{
		_gravityspeed_milliseconds = ((double)6 / (double)60) * 1000;
	}
	else if (_level >= 10 && _level <= 12)
	{
		_gravityspeed_milliseconds = ((double)5 / (double)60) * 1000;
	}
	else if (_level >= 13 && _level <= 15)
	{
		_gravityspeed_milliseconds = ((double)4 / (double)60) * 1000;
	}
	else if (_level >= 16 && _level <= 18)
	{
		_gravityspeed_milliseconds = ((double)3 / (double)60) * 1000;
	}
	else if (_level >= 19 && _level <= 28)
	{
		_gravityspeed_milliseconds = ((double)2 / (double)60) * 1000;
	}
	else
	{
		_gravityspeed_milliseconds = ((double)1 / (double)60) * 1000;
	}
}

int Game::countLineScore(const int& nbLine)
{
	switch (nbLine)
	{
	case 1:
		return 40 * (_level + 1);
	case 2:
		return 100 * (_level + 1);
	case 3:
		return 300 * (_level + 1);
	case 4:
		return 1200 * (_level + 1);
	default:
		return 0;
	}
}

void Game::instantDrop()
{
	while (translatePieceDown()) {
	}
}

// echange la piece en courante avec la piece de reserve
void Game::swapPiece()
{
	if (getHoldPiece()->isColliding(getHoldPiece()->getPiece(), _currentPiece->getCoordinate(), _board)) {
		return;
	}

	_isDirty = true;
	Piece* tmpPiece = _currentPiece;
	_currentPiece = getHoldPiece();
	_holdPiece = tmpPiece;
	_currentPiece->setCoordinate(tmpPiece->getCoordinate());
	_display.displayHoldPiece(_holdPiece, _board);
}

// Recupere la piece en reserve
Piece* Game::getHoldPiece()
{
	if (_holdPiece == nullptr)
	{
		_holdPiece = _queue.front();
		_queue.pop();
		_queue.push(getRandomPiece());
	}

	return _holdPiece;
}

void Game::addTetris()
{
	_totalTetris++;
}

void Game::updateThreatAndLines() {

	if (_controller == nullptr)
		return;

	int lvl = 22 - _highestPiece;
	int threat = 0;
	if (lvl <= 7)
	{
		threat = 1;
	}
	else if (lvl <= 14) {
		threat = 2;
	}
	else {
		threat = 3;
	}

	_controller->updateThreatAndLines(_totalLines, threat);
}

GameInformation Game::getGameInformation()
{
	return GameInformation(&_board, _currentPiece, _holdPiece, _queue.front(), _score, _totalTetris, _level);
}

void Game::refreshUI(GameDisplay* display)
{
	if (_isDirty)
	{
		display->refreshUI(&_board, _currentPiece, _holdPiece, _queue.front(), _score, _totalTetris, _level);
		_isDirty = false;
	}
}