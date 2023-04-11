#pragma once
#ifndef MAINGAMELOOPTHREAD_H
#define MAINGAMELOOPTHREAD_H

#include <chrono>
#include <QObject>
#include <QTimer>
#include "maingamescene.h"
#include "game.h"
#include "gameActions.h"
#include "keyboard.h"

class MainGameLoopThread : public QObject
{

public:
	MainGameLoopThread(MainGameScene* setGameScene);


private slots:
	void mainGameLoop();

private:
	MainGameScene* gameScene;
	//Controller* controller = new Controller(7, 115200);
	Game* game;
	//game.setController(controller);
	Keyboard* keyboard = new Keyboard();
	GameActions* actions = new GameActions(keyboard);
	QTimer* gameTimer;
	bool init = false;

	std::chrono::high_resolution_clock::time_point lastAutomaticDrop = std::chrono::high_resolution_clock::now();

};

#endif // !QtMainGameLoop


