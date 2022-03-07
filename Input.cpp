#include "Input.h"

CInput CInput::m_instance;

bool CInput::buttonPressed(unsigned int button)
{
    return sf::Joystick::isButtonPressed(0, button);
}

bool CInput::buttonReleased(unsigned int button)
{
    return false;
}

float CInput::getJoystickX()
{
    return sf::Joystick::getAxisPosition(0, sf::Joystick::X);
}

float CInput::getJoystickY()
{
    return sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
}