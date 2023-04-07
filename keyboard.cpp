#include "keyboard.h"

bool Keyboard::keyIsPressed(int key) {
    return GetAsyncKeyState(key);
}

Keyboard::Keyboard()
{
}

bool Keyboard::getLeftTrigger()
{
    //Z
    return GetAsyncKeyState(0x5A);
}

bool Keyboard::getRightTrigger()
{
    //X
    return GetAsyncKeyState(0x58);
}

bool Keyboard::getJoyStickUp()
{
    return false;
}

bool Keyboard::getJoyStickDown()
{
    //Down arrow
    return GetAsyncKeyState(VK_DOWN);
}

bool Keyboard::getJoystickLeft()
{
    //Left arrow
    return GetAsyncKeyState(VK_LEFT);
}

bool Keyboard::getJoyStickRight()
{
    //Right arrow
    return GetAsyncKeyState(VK_RIGHT);
}

bool Keyboard::getJoyStickButton()
{
    // Space
    return GetAsyncKeyState(VK_SPACE);
}

bool Keyboard::getAButton()
{
    //Down arrow
    return GetAsyncKeyState(VK_DOWN);
}

bool Keyboard::getBButton()
{
    //C
    return GetAsyncKeyState(0x48);
}

bool Keyboard::getMenuButton()
{
    //M
    return GetAsyncKeyState(0x4D);
}

bool Keyboard::getInstantDrop()
{
    // Space
    return GetAsyncKeyState(VK_SPACE);
}
