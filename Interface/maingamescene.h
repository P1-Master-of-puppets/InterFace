#pragma once
#pragma once
#ifndef MAINGAMESCENE_H
#define MAINGAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QObject>
#include "pauseMenuRenderer.h"
#include "applicationScene.h"
#include "gameOverRenderer.h"
#include "screenMapper.h"
#include "textRenderer.h"
#include "boardrenderer.h"
#include "pieceRenderer.h"
#include "colorArray2D.h"
#include "piece.h"
#include "assets.h"
#include "gameInformation.h"
#include "keyboard.h"
#include "gameActions.h"
#include "controller.h"
#include "game.h"
#include "gameState.h"
#include "gameDisplay.h"
#include "QTimer"
#include <chrono>
#include <atomic>
#include "sceneManager.h"


using namespace std::chrono;

class MainGameScene : public ApplicationScene, public GameDisplay
{
	Q_OBJECT
public:
	MainGameScene(QSize viewSize, QGraphicsView* parent);
	~MainGameScene();
	void startGame();
public slots:
	void refreshUI(ColorArray2D* board, Piece* piece, Piece* holdPiece, Piece* nextPiece, int score, int tetris, int level);
	void gameFinished();
	void resumeGame();
	void exitGame();

protected:
	void keyPressEvent(QKeyEvent* event);

private:
	TextRenderer* _level;
	TextRenderer* _tetris;
	TextRenderer* _score;
	BoardRenderer* _monBoard;
	PieceRenderer* _gamePiece;
	PieceRenderer* _holdPiece;
	PieceRenderer* _nextPiece;

	QGraphicsView* _gameView;

	PauseMenuRenderer* _pauseMenu;
	GameOverRenderer* _GO;

	std::atomic<bool>  _isPaused = false;
	QTimer _gameTimer;
	Keyboard* _keyboard;
	GameActions* _actions;
	Game _game;
	high_resolution_clock::time_point _lastAutomaticDrop = high_resolution_clock::now();
	void gameLoop();
	int _scoreVal=0;
	int _tetrisVal=0;
	int _levelVal=0;

};

#endif // MAINGAMESCENE_H
