#pragma once
#ifndef TOGGLEDBUTTON_H
#define TOGGLEDBUTTON_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QGraphicsScene>
#include "coordinate.h"
#include "rendererhelper.h"
#include "gameSoundPlayer.h"
#include <QKeyEvent>
#include <QObject>

class ToggledButton :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	ToggledButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent = nullptr);
	virtual ~ToggledButton();	
	void setId(int id);
	void changeToggle(bool value);
	void listen();
protected:
	void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
	void keyPressEvent(QKeyEvent* event);
	void updateImage();
	QPixmap _toggledImg;
	QPixmap _unToggledImg;
public slots:
	void click();
	void secondClick();
signals:
	void clicked();
	void secondClicked();
	void toggledByMouse(int id, bool state);
private:
	int _id;
	bool _isToggled = false;
	
};
#endif // !TOGGLEDBUTTON_H
