#pragma once
#ifndef TOGGLEDBUTTON_H
#define TOGGLEDBUTTON_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsScene>
#include "coordinate.h"
#include "rendererhelper.h"
#include <QKeyEvent>
#include <QObject>

class ToggledButton : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	ToggledButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsScene* scene, QGraphicsItem* parent = nullptr);
	~ToggledButton();

protected:
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);

public slots:
	void changeToggle(bool value);
signals:
	void used();

private:
	bool _isToggled;
	QGraphicsScene* _scene;
	QPixmap _toggledImg;
	QPixmap _unToggledImg;
};
#endif // !TOGGLEDBUTTON_H
