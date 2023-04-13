#include "controlSelectionButton.h"

ControlSelectionButton::ControlSelectionButton(QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent)
	: ToggledButton(toggledImg, unToggledImg, coordinate, parent) {

}

ControlSelectionButton::~ControlSelectionButton() {

}

void ControlSelectionButton::setText(QString string) {
	QFont monospace(qApp->font().family(), 8);
	//QTextItem textItem;
	QPixmap* toggledimage = new QPixmap(_originalToggledImg);
	QPainter toggledPainter(toggledimage);
	toggledPainter.drawText(0, 0, string);
	//Ajouter le texte a l'image
	toggledPainter.end();
	_toggledImg = toggledimage->copy();
	delete toggledimage;

	QPixmap* unToggledimage = new QPixmap(_originalUnToggledImg);
	QPainter untoggledPainter(unToggledimage);

	untoggledPainter.drawText(0, 0, string);
	untoggledPainter.end();
}