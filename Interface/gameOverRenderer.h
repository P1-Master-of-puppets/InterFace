#pragma once
#ifndef GAMEOVERRENDERER_H
#define GAMEOVERRENDERER_H

#include "applicationScene.h"
#include "assets.h"
#include "coordinate.h"
#include "screenMapper.h"
#include "coordinate.h"
#include "flashingTextRenderer.h"
#include "textRenderer.h"

class GameOverRenderer
{

public:
	GameOverRenderer(ApplicationScene* setRenderScene);
	~GameOverRenderer();
	void show(int score, int tetris, int level);


private:
	ApplicationScene* _renderScene;
	QGraphicsPixmapItem* _overlayFilterItem;
	QGraphicsPixmapItem* _overlayGOItem;

	// Fash text
	FlashingTextRenderer* _textGameOver;
	TextRenderer* _score;
	TextRenderer* _tetris;
	TextRenderer* _level;
};

#endif // !GAMEOVERRENDERER_H