#pragma once
#ifndef GAMESCENESIGNALS_H
#define GAMESCENESIGNALS_H

#include <QGraphicsScene>

class GameSceneSignals : public QGraphicsScene
{

public slots:

	void exitApplication();
	void goToSplashScreen();
	void goToMainMenu();
	void goToControlSetup();
	void goToMainGame();

};


#endif // !GAMESCENESIGNALS_H

