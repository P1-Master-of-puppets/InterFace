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
	int startingLevel = 0;
	//Controller* controller = new Controller(7, 115200);
	Game game = Game(startingLevel, gameScene);
	//game.setController(controller);
	Keyboard* keyboard = new Keyboard();
	GameActions* actions = new GameActions(keyboard);

	high_resolution_clock::time_point lastAutomaticDrop = high_resolution_clock::now();

};

#endif // !QtMainGameLoop


