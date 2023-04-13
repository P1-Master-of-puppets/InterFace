#pragma once
#ifndef CONTROLSELECTIONBUTTON_H
#define CONTROLSELECTIONBUTTON_H

#include "toggledbutton.h"
#include "QString"
#include "QPainter"
#include "QApplication"
#include "coordinate.h"
#include <Vector>
#include "controllerInputOutput.h"

class ControlSelectionButton : public ToggledButton
{
	Q_OBJECT

public:
	ControlSelectionButton(QString optionName, QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent = nullptr);
	~ControlSelectionButton();
	void setSettings(std::vector<ControllerInputOutput> settings);
	const Coordinate optionTextPosition{ 170,120 };
	const Coordinate mappingTextPosition{ 620,120 };
private:
	QFont getFont();
	QPixmap _originalToggledImg;
	QPixmap _originalUnToggledImg;
};
#endif // !BUTTONGROUP2D_H
