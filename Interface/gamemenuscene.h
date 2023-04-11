#pragma once
#ifndef GAMEMENUSCENE_H
#define GAMEMENUSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QObject>
#include "fullScreenRenderer.h"
#include "assets.h"
#include "toggledbutton.h"
#include "coordinate.h"
#include "rendererhelper.h"

class GameMenuScene : public QGraphicsScene
{
public:
	GameMenuScene(QGraphicsView* mainView);
	~GameMenuScene();

private:
	FullScreenRenderer* _background;
	QGraphicsView* _mainView;
	ToggledButton* _startButton;
};

#endif // GAMEMENUSCENE_H
