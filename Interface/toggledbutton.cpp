#include "toggledbutton.h"

ToggledButton::ToggledButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
	setPixmap(unToggledImg);
	_toggledImg = toggledImg;
	_unToggledImg = unToggledImg;
	moveBy(coordinate.x, coordinate.y);
	setAcceptHoverEvents(true);
}

ToggledButton::~ToggledButton()
{
}

void ToggledButton::setId(int id)
{
	_id = id;
}

void ToggledButton::changeToggle(bool value)
{
	_isToggled = value;
	updateImage();
}

void ToggledButton::listen()
{

}

void ToggledButton::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	changeToggle(true);
	emit toggledByMouse(_id, true);
}

void ToggledButton::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	changeToggle(false);
	emit toggledByMouse(_id, false);
}

void ToggledButton::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (_isToggled) {
		emit clicked();
	}
}

void ToggledButton::keyPressEvent(QKeyEvent* event) {
	int i = 0;
	if (event->key() != Qt::Key_Enter &&
		event->key() != Qt::Key_Return)
		return;

	if (_isToggled) {
		emit clicked();
	}
}

void ToggledButton::updateImage()
{
	if (_isToggled) {
		setPixmap(_toggledImg);
	}
	else {
		setPixmap(_unToggledImg);
	}
}

void ToggledButton::secondClick()
{
	emit secondClicked();
}

void ToggledButton::click() {
	emit clicked();
}