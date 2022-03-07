#include "Entity.h"

CEntity::CEntity()
{
    
}

CEntity::~CEntity()
{
    
}

void CEntity::callUpdate()
{
    update();

    if (m_sprite != nullptr)
    {
        m_sprite->setPosition(m_position);
        m_sprite->update();
    }
    
}

void CEntity::callRender()
{
    if (m_sprite != nullptr)
    {
        m_sprite->render();
    }
    render();
}