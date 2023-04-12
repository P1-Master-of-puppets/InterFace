#include "buttonGroup2D.h"

ButtonGroup2D::ButtonGroup2D(int height, int width)
{
	//Minimum of col and row of 1
	_height = height;
	_width = width;
	_buttons = new ToggledButton * [height * width];
	grabKeyboard();
}

ButtonGroup2D::~ButtonGroup2D()
{
	for (int i = 0; i < _height * _width; i++)
	{
		if (_buttons[i] = nullptr)
		{
			delete _buttons[i];
		}
	}
	delete[] _buttons;
}

void ButtonGroup2D::setButton(int col, int row, ToggledButton* button)
{
	QObject::connect(button, &ToggledButton::toggledByMouse,
		this, &ButtonGroup2D::buttonToggledByMouse);

	int id = col + row * _width;
	_buttons[col + row * _width] = button;
	button->setId(col + row * _width);
	button->show();
}

void ButtonGroup2D::keyPressEvent(QKeyEvent* event)
{
	//Navigate trough the option with the keypressed events
	if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
	{
		if (_currentButton >= 0)
			_buttons[_currentButton]->changeToggle(false);
		_currentButton += _width;
		if (_currentButton >= _height * _width)
		{
			_currentButton = 0;
		}
		_buttons[_currentButton]->changeToggle(true);
	}
	else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
	{
		if (_currentButton >= 0)
			_buttons[_currentButton]->changeToggle(false);
		_currentButton -= _width;
		if (_currentButton < 0)
		{
			_currentButton = _height * _width - 1;
		}
		_buttons[_currentButton]->changeToggle(true);
	}
	else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
	{
		if (_currentButton >= 0)
			_buttons[_currentButton]->changeToggle(false);
		_currentButton--;
		if (_currentButton < 0)
		{
			_currentButton = _height * _width - 1;
		}
		_buttons[_currentButton]->changeToggle(true);
	}
	else if (event->key() == Qt::Key_Up || event->key() == Qt::Key_D)
	{
		if (_currentButton >= 0)
			_buttons[_currentButton]->changeToggle(false);
		_currentButton++;
		if (_currentButton >= _height * _width)
		{
			_currentButton = 0;
		}
		_buttons[_currentButton]->changeToggle(true);
	}
}

void ButtonGroup2D::buttonToggledByMouse(int id, bool state)
{
	if (state)
	{
		_currentButton = id;
		//Set all of the buttons untoggled except the one with the mouse
		for (int i = 0; i < _height * _width; i++)
		{
			if (_buttons[i] != nullptr && i != id)
			{
				_buttons[i]->changeToggle(false);
			}
		}
	}
	else
	{
		_currentButton = -1;
	}
}