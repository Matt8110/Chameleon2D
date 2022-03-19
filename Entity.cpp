#include "Entity.h"

CEntity::CEntity()
{
    
}

CEntity::~CEntity()
{
    
}

void CEntity::queueAction(ActionFunc action)
{
    m_actionBuffer[m_actionBufferSize++] = action;

    if (m_actionBufferSize > MAX_ACTIONS)
    {
        std::cout << "E: action buffer size exceeded." << std::endl;
        exit(-1);
    }
}

void CEntity::actionUpdate()
{
    if (m_currentAction != nullptr)
    {
        m_currentAction();
        m_currentAction = nullptr;
    }

    if (m_actionBufferSize > 0)
        m_currentAction = m_actionBuffer[--m_actionBufferSize];
}

void CEntity::update()
{
    actionUpdate();
    m_update();

    if (m_sprite != nullptr)
    {
        m_sprite->setPosition(m_position);
        m_sprite->update();
    }
    
}

void CEntity::render()
{
    if (m_sprite != nullptr)
    {
        m_sprite->render();
    }
    m_render();
}