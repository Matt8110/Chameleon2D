#pragma once

#include <SFML/Graphics.hpp>

class CInput
{
public:
    static bool buttonPressed(unsigned int button);
    static bool buttonReleased(unsigned int button);
    static float getJoystickX();
    static float getJoystickY();

private:
    CInput& get() { return m_instance; };

private:
    static CInput m_instance;
    bool m_buttons[16];
};