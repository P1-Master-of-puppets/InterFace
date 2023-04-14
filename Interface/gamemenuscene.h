#pragma once
#ifndef GAMEMENUSCENE_H
#define GAMEMENUSCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QObject>
#include "applicationScene.h"
#include "assets.h"
#include "toggledbutton.h"
#include "coordinate.h"
#include "buttonGroup2D.h"
#include "sceneManager.h"

class GameMenuScene: public ApplicationScene
{
	Q_OBJECT
public:
	GameMenuScene(QSize windowSize);
	~GameMenuScene();
	
public slots:
	void exitButtonClicked();
	void controlButtonClicked();
	void startButtonClicked();
	void keyPressEvent(QKeyEvent* event);

private:
	QGraphicsView* _mainView;
	ButtonGroup2D* _buttonGroup;
};

#endif // GAMEMENUSCENE_H
