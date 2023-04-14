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
#include "gameSoundPlayer.h"
#include "levelSelectScene.h"

class SceneManager : public QObject
{
	Q_OBJECT
public:

	SceneManager(QGraphicsView* mainView);
	QSize getSize();
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
};

#endif // !SCENEMANAGER_H
