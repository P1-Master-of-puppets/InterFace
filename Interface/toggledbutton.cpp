#include "toggledbutton.h"

ToggledButton::ToggledButton(int id,QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsScene* scene, QGraphicsItem* parent) : QGraphicsPixmapItem(parent), _scene(scene)
{
	_id = id;
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
}

void ToggledButton::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	changeToggle(false);
}

void ToggledButton::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	if (_isToggled) {
		emit used(_id);
	}
}

void ToggledButton::keyPressEvent(QKeyEvent* event) {
	if (event->key() != Qt::Key_Enter &&
		event->key() != Qt::Key_Return)
		return;

	if (_isToggled) {
		emit used(_id);
	}
}