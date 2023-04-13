#include "controlSelectionButton.h"

QString ControllerInputOutputToString(ControllerInputOutput setting) {
	switch (setting)
	{
	case ControllerInputOutput::LeftTrigger:
		return "LT";
	case ControllerInputOutput::RightTrigger:
		return "RT";
	case ControllerInputOutput::JoyStickUp:
		return "JSU";
	case ControllerInputOutput::JoyStickDown:
		return "JSD";
	case ControllerInputOutput::JoyStickLeft:
		return "JSL";
	case ControllerInputOutput::JoyStickRight:
		return "JSR";
	case ControllerInputOutput::JoyStickButton:
		return "JSB";
	case ControllerInputOutput::AButton:
		return "A";
	case ControllerInputOutput::BButton:
		return "B";
	default:
		return "";
	}
}

ControlSelectionButton::ControlSelectionButton(QString optionName, QPixmap toggledImg, QPixmap unToggledImg, Coordinate coordinate, QGraphicsItem* parent)
	: ToggledButton(QPixmap(), QPixmap(), coordinate, parent) {

	QPixmap* toggledimage = new QPixmap(toggledImg);
	QPainter toggledPainter(toggledimage);
	toggledPainter.setFont(getFont());
	toggledPainter.drawText(optionTextPosition.x, optionTextPosition.y, optionName);
	toggledPainter.end();
	_originalToggledImg = toggledimage->copy();
	delete toggledimage;

	QPixmap* unToggledimage = new QPixmap(unToggledImg);
	QPainter untoggledPainter(unToggledimage);
	untoggledPainter.setFont(getFont());
	untoggledPainter.drawText(optionTextPosition.x, optionTextPosition.y, optionName);
	untoggledPainter.end();
	_originalUnToggledImg = unToggledimage->copy();
	delete unToggledimage;


	_unToggledImg = _originalUnToggledImg;
	_toggledImg = _originalToggledImg;
	updateImage();
}

ControlSelectionButton::~ControlSelectionButton() {

}

void ControlSelectionButton::setSettings(std::vector<ControllerInputOutput> settings)
{
	QString text = "";

	for (int i = 0; i < settings.size(); i++)
	{
		text += ControllerInputOutputToString(settings[i]);
		if (i == settings.size() - 2)
		{
			text += ", ";
		}
	}
	//Construct String

	QPixmap* toggledimage = new QPixmap(_originalToggledImg);
	QPainter toggledPainter(toggledimage);
	toggledPainter.setFont(getFont());
	toggledPainter.drawText(mappingTextPosition.x, mappingTextPosition.y, text);
	toggledPainter.end();
	_toggledImg = toggledimage->copy();
	delete toggledimage;

	QPixmap* unToggledimage = new QPixmap(_originalUnToggledImg);
	QPainter untoggledPainter(unToggledimage);
	untoggledPainter.setFont(getFont());
	untoggledPainter.drawText(mappingTextPosition.x, mappingTextPosition.y, text);
	untoggledPainter.end();
	_unToggledImg = unToggledimage->copy();
	delete unToggledimage;
	updateImage();
}

QFont ControlSelectionButton::getFont()
{
	return QFont(qApp->font().family(), 16);
}

