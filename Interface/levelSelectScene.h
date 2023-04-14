#pragma once
#ifndef LEVELSELECTSCENE_H
#define LEVELSELECTSCENE_H

#include "applicationScene.h"
#include "selectButton.h"
#include "screenMapper.h"

class LevelSelectScene: public ApplicationScene
{
	Q_OBJECT

public:
	LevelSelectScene(QSize windowSize, QGraphicsView* applicationView);
	~LevelSelectScene();

public slots:
	void keyPressEvent(QKeyEvent* event);
	void levelSelected(int level);

private:
	SelectButton* _levelSelection;

};



#endif // !LEVELSELECTSCENE_H

