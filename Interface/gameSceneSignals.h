#pragma once
#ifndef GAMESCENESIGNALS_H
#define GAMESCENESIGNALS_H

#include <QGraphicsScene>

class GameSceneSignals : public QGraphicsScene
{

signals:

	void exitApplication() {};
	void goToSplashScreen() {};
	void goToMainMenu() {};
	void goToControlSetup() {};
	void goToMainGame() {};

};


#endif // !GAMESCENESIGNALS_H

