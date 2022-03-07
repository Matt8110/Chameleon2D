#include "StateMachine.h"

void CStateMachine::setState(const std::string& state)
{
    m_strState = state;
}

void CStateMachine::setState(int state)
{
    m_intState = state;
}

const std::string& CStateMachine::getState()
{
    return m_strState;
}

int CStateMachine::getIntState()
{
    return m_intState;
}