#pragma once
#pragma once
#ifndef BUTTONGROUP2D_H
#define BUTTONGROUP2D_H
#include <QObject>
#include <QWidget>
#include "toggledbutton.h"
#include "coordinate.h"
#include <QMouseEvent>

class ButtonGroup2D : public QWidget
{
public:
	ButtonGroup2D(int height, int width);
	~ButtonGroup2D();
	int setButton(int x, int y, ToggledButton* button);
protected:
	void keyPressEvent(QKeyEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
public slots:
	void buttonToggledByMouse(int id, bool state);

private:
	ToggledButton** _buttons;
	int _height;
	int _width;
	int _currentButton = -1;
};
#endif // !BUTTONGROUP2D_H
