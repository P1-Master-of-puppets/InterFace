#include "gameOverRenderer.h"

// Constructeur
GameOverRenderer::GameOverRenderer(ApplicationScene* setRenderScene) : _renderScene(setRenderScene)
{
	// Image de Game Over 
	QPixmap overlayFilter(FILTER_IMAGE_PATH);
	_overlayFilterItem = new QGraphicsPixmapItem();
	_overlayFilterItem->setPixmap(overlayFilter.scaled(QSize(_renderScene->width(), _renderScene->height())));

	QPixmap overlayGO(GAME_OVER_POP_UP_PATH);
	_overlayGOItem = new QGraphicsPixmapItem();
	_overlayGOItem->setPixmap(overlayGO.scaled(QSize(_renderScene->width(), _renderScene->height())));
	// Fash text
	_textGameOver = nullptr;
	_score = nullptr;
	_tetris = nullptr;
	_level = nullptr;
}

// Destructeur
GameOverRenderer::~GameOverRenderer()
{
	delete _overlayFilterItem;
	delete _overlayGOItem;
	delete _textGameOver;
}

// Fonction show qui affiche les éléments
void GameOverRenderer::show(int score, int tetris, int level)
{
	GameSoundPlayer::playMainTheme(true);
	_renderScene->addItem(_overlayFilterItem);
	_renderScene->addItem(_overlayGOItem);
	_score = new TextRenderer(QString("bruh"), _renderScene, ScreenMapper::mapCoords(1130, 500, _renderScene->width(), _renderScene->height()));
	_tetris = new TextRenderer(QString("bruh02"), _renderScene, ScreenMapper::mapCoords(1130, 575, _renderScene->width(), _renderScene->height()));
	_level = new TextRenderer(QString("bruh03"), _renderScene, ScreenMapper::mapCoords(1130, 650, _renderScene->width(), _renderScene->height()));
	_score->updateText(score);
	_tetris->updateText(tetris);
	_level->updateText(level);
	_textGameOver = new FlashingTextRenderer(QString("Press any key to restart!"), _renderScene, ScreenMapper::mapCoords(960, 800, _renderScene->width(), _renderScene->height()), 750);
}

