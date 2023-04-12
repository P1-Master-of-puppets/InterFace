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
#include "applicationScene.h"
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
#include <thread>
#include <chrono>
#include <atomic>


using namespace std::chrono;

class MainGameScene : public ApplicationScene
{
	Q_OBJECT
public:
	MainGameScene(QSize viewSize);
	~MainGameScene();
	void startGame();

protected:
	void keyPressEvent(QKeyEvent* event);

public slots:
	void refreshUI(GameInformation information);
signals:
	void sendRefreshUI(GameInformation information);


private:
	TextRenderer* _level;
	TextRenderer* _tetris;
	TextRenderer* _score;
	BoardRenderer* _monBoard;
	PieceRenderer* _gamePiece;
	PieceRenderer* _holdPiece;
	PieceRenderer* _nextPiece;

	std::atomic<bool> _isPaused = false;
	std::atomic<bool> _windowQuit = false;
	std::atomic<int> _gameLevel = 0;
	std::thread _gameThread;
	void gameLoop();

};

#endif // MAINGAMESCENE_H
