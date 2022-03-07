#pragma once

#include <string>

class CStateMachine
{
public:
    void setState(const std::string& state);

    const std::string& getState();
    void setState(int state);
    int getIntState();

private:
    std::string m_strState = "";
    int m_intState = 0;
};