#pragma once
#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <QObject>
#include <QString>
#include <QGraphicsTextItem>
#include <QFont>
#include <QFontDatabase>
#include <QGraphicsView>
#include "coordinate.h"

class TextRenderer : public QGraphicsTextItem
{
public:
	//Centers the text in a box with up left corner and dimensions
	TextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate corner, Coordinate dimensions);

	//Places the text's center on centerPosition
	TextRenderer(QString setText, QGraphicsScene* setRenderScene, Coordinate centerPosition);

	~TextRenderer();

	//Update the text
	void updateText(int value);
	void updateText(QString value);

	//Removes the text from showing
	void remove();

protected:
	QString text;
	QGraphicsScene* renderScene;
	Coordinate centerCoords;
};

#endif // TEXTRENDERER_H
