#pragma once
#ifndef FULLSCREENRENDERER_H
#define FULLSCREENRENDERER_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>

class FullScreenRenderer : public QGraphicsPixmapItem
{

public:

	FullScreenRenderer(QString filename, QGraphicsScene* setScene, QSize backgroundSize);
	void remove();

private:

    QGraphicsScene* renderScene;
};



#endif // !FULLSCREENRENDERER_H




