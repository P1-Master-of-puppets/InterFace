#ifndef KEYBOARD_H__
#define KEYBOARD_H__

#include <Windows.h>
#include "control.h"

class Keyboard : public Control
{
public:
	Keyboard();
	/// <summary>
	/// Rotate Left (Z)
	/// </summary>
	/// <returns></returns>
	bool getLeftTrigger();
	/// <summary>
	/// Rotate Right (X)
	/// </summary>
	/// <returns></returns>
	bool getRightTrigger();
	/// <summary>
	/// Nothing
	/// </summary>
	/// <returns></returns>
	bool getJoyStickUp();
	/// <summary>
	///	 QuickDrop (Down Arrow)
	/// </summary>
	/// <returns></returns>
	bool getJoyStickDown();
	/// <summary>
	/// Translate Left (Left Arrow)
	/// </summary>
	/// <returns></returns>
	bool getJoystickLeft();
	/// <summary>
	/// Translate Right (Right Arrow)
	/// </summary>
	/// <returns></returns>
	bool getJoyStickRight();
	/// <summary>
	/// InstantDrop (Space)
	/// </summary>
	/// <returns></returns>
	bool getJoyStickButton();
	/// <summary>
	/// Qucik Drop (Down arrow)
	/// </summary>
	/// <returns></returns>
	bool getAButton();
	/// <summary>
	/// Hold Piece (C)
	/// </summary>
	/// <returns></returns>
	bool getBButton();
	/// <summary>
	/// Menu (M)
	/// </summary>
	/// <returns></returns>
	bool getMenuButton();
	/// <summary>
	/// InstantDrop (Space)
	/// </summary>
	/// <returns></returns>
	bool getInstantDrop();

	bool keyIsPressed(int key);
};

#endif // KEYBOARD_H__