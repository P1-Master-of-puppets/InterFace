#pragma once
#ifndef CONTROLSELECTIONBUTTON_H
#define CONTROLSELECTIONBUTTON_H

#include "toggledbutton.h"
#include "QString"
#include "QPainter"
#include "QApplication"

class ControlSelectionButton : public ToggledButton
{
	Q_OBJECT

public:
	ControlSelectionButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent = nullptr);
	~ControlSelectionButton();
	void setText(QString string);
private:
	QPixmap _originalToggledImg;
	QPixmap _originalUnToggledImg;
};
#endif // !BUTTONGROUP2D_H
