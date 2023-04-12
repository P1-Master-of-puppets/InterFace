#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "gameSceneSignals.h"

class SceneManager {

	Q_OBJECT

public:

	SceneManager(QGraphicsView* setView);

private slots:

	void exitApplication();
	void goToSplashScreen();
	void goToMainMenu();
	void goToControlSetup();
	void goToMainGame();

private:

	QGraphicsView* mainView;

};

#endif // !SCENEMANAGER_H
