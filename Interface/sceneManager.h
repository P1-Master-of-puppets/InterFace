#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSize>
#include "applicationScene.h"
#include "gamestartscene.h"
#include "maingamescene.h"
#include "gamemenuscene.h"
#include "controlSelectionScene.h"
#include "qGameController.h"
#include "controllerEventHandler.h"
#include "gameSoundPlayer.h"
#include "levelSelectScene.h"

class SceneManager : public QObject
{
	Q_OBJECT
public:

	SceneManager(QGraphicsView* mainView);
	~SceneManager();
	QSize getSize();
	static QGameController* controller;
private slots:
	void exitApplication();
	void goToSplashScreen();
	void goToMainMenu();
	void goToLevelSelect();
	void goToControlSetup();
	void goToMainGame(int level);

private:
	void changeView(ApplicationScene* newScene);
	QGraphicsView* _mainView;
	ApplicationScene* _currentScene;
	ControllerEventHandler* _eventHandler;
};

#endif // !SCENEMANAGER_H
