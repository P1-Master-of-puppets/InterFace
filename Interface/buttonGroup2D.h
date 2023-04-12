#pragma once
#pragma once
#ifndef BUTTONGROUP2D_H
#define BUTTONGROUP2D_H
#include <QObject>
#include <QWidget>
#include "toggledbutton.h"
#include "coordinate.h"

class ButtonGroup2D : public QWidget
{
	Q_OBJECT
public:
	ButtonGroup2D(int height, int width);
	~ButtonGroup2D();
	void setButton(int x, int y, ToggledButton* button);
protected:
	void keyPressEvent(QKeyEvent* event);
public slots:
	void buttonToggledByMouse(int id, bool state);

private:
	ToggledButton** _buttons;
	int _height;
	int _width;
	int _currentButton;
};
#endif // !BUTTONGROUP2D_H
