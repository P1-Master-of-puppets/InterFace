#pragma once
#ifndef GAMESOUNDPLAYER_H
#define GAMESOUNDPLAYER_H

#include <QSoundEffect>
#include <QUrl>
#include "assets.h"

class GameSoundPlayer {
public:
	static void playMainTheme(bool stop = false);
	static void playTic();
	static void playSelect();
	static void playBoop();
	static void playTetris();
	static void playDeny();
	static void playGameOver();
	static void playLineComplete();
};


#endif // !GAMESOUNDPLAYER_H

