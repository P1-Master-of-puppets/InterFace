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
	void goToControlSetup();
	void goToMainGame();

private:
	void changeView(ApplicationScene* newScene);

	QGraphicsView* _mainView;
	ApplicationScene* _currentScene;
};

#endif // !SCENEMANAGER_H
