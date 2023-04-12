#pragma once
#ifndef GAMESTARTSCENE_H
#define GAMESTARTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "applicationScene.h"
#include "flashingTextRenderer.h"
#include "screenMapper.h"
#include "mainGameLoopThread.h"
#include "assets.h"

class GameStartScene : public ApplicationScene
{
public:
	GameStartScene(QSize mainView, QObject* parent = nullptr);
	~GameStartScene();
	void keyPressEvent(QKeyEvent* event);

private:
	FlashingTextRenderer* monText;
};

#endif // GAMESTARTSCENE_H
