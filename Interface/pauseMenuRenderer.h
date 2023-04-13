#pragma once
#ifndef PAUSEMENURENDERER_H
#define PAUSEMENURENDERER_H

#include <QObject>

#include "applicationScene.h"
#include "assets.h"
#include "toggledbutton.h"
#include "coordinate.h"
#include "buttonGroup2D.h"
#include "screenMapper.h"
#include "coordinate.h"


class PauseMenuRenderer : public QObject
{
	Q_OBJECT

public:
	PauseMenuRenderer(ApplicationScene* renderScene);
	~PauseMenuRenderer();
	void dismiss();
	void show();

public slots:
	void exitButtonClickedSlot();
	void resumeButtonClickedSlot();

signals:
	void exitButtonClicked();
	void resumeButtonClicked();

private:
	ApplicationScene* _renderScene;
	ButtonGroup2D* _pauseButtonGroup;
	ToggledButton* _resumeButton;
	ToggledButton* _exitButton;
	QGraphicsPixmapItem _overlayFilterItem;

};



#endif // !PAUSEMENURENDERER_H


