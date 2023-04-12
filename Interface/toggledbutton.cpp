#include "toggledbutton.h"

ToggledButton::ToggledButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsScene* scene, QGraphicsItem* parent) : QGraphicsPixmapItem(parent), _scene(scene)
{
	setPixmap(unToggledImg);
	_toggledImg = toggledImg;
	_unToggledImg = unToggledImg;
	scene->addItem(this);
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
	if (value) {
		grabKeyboard();
		setPixmap(_toggledImg);
	}
	else {
		ungrabKeyboard();
		setPixmap(_unToggledImg);
	}
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
	if (event->key() != Qt::Key_Enter &&
		event->key() != Qt::Key_Return)
		return;

	if (_isToggled) {
		emit clicked();
	}
}