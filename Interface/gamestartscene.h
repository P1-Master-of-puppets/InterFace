#pragma once
#ifndef GAMESTARTSCENE_H
#define GAMESTARTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "gameSceneSignals.h"
#include "flashingTextRenderer.h"
#include "fullScreenRenderer.h"
#include "screenMapper.h"
#include "mainGameLoopThread.h"
#include "assets.h"

class GameStartScene : public GameSceneSignals
{

public:
	GameStartScene(MainGameScene* next, QGraphicsView* view);
	~GameStartScene();

	void keyPressEvent(QKeyEvent* event);

private:
	QGraphicsView* mainView;
	//TODO CHANGER CELA
	MainGameScene* nextScene;
	FlashingTextRenderer* monText;
	FullScreenRenderer* splashScreen;
};

#endif // GAMESTARTSCENE_H
