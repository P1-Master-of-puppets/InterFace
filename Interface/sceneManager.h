#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "gameSceneSignals.h"
#include "gamestartscene.h"
#include "maingamescene.h"
#include "gamemenuscene.h"

class SceneManager : public QObject
{

public:

	SceneManager(QGraphicsView* setView);

private slots:

	void exitApplication();
	void goToSplashScreen();
	void goToMainMenu();
	void goToControlSetup();
	void goToMainGame();

private:

	QSize viewSize;
	QGraphicsView* mainView;
	GameStartScene* splashScreen;
	MainGameScene* mainGame;
	GameMenuScene* menu;

};

#endif // !SCENEMANAGER_H
