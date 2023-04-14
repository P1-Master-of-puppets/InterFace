#pragma once
#ifndef SELECTBUTTON_H
#define SELECTBUTTON_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "applicationScene.h"
#include "toggledbutton.h"
#include "textRenderer.h"
#include "coordinate.h"
#include "gameSoundPlayer.h"
#include "screenMapper.h"

class SelectButton: public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	SelectButton(ApplicationScene* renderScene, Coordinate centerCoords, QGraphicsItem* parent = nullptr);
	~SelectButton();

public slots:
	void keyPressEvent(QKeyEvent* event);
signals:
	void levelSelected(int level);

private:
	int _level;
	TextRenderer* _levelText;
};


#endif // !SELECTBUTTON_H


