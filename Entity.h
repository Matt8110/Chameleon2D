#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite.h"

#define MAX_ACTIONS 64

typedef void (*ActionFunc)();

class CEntity
{
public:
    CEntity();
    ~CEntity();
    void update();
    void render();
    void queueAction(ActionFunc action);

protected:
    virtual void m_update() {}
    virtual void m_render() {}

    void actionUpdate();

protected:
    sf::Vector2f m_position;
    CSprite* m_sprite = nullptr;
    ActionFunc m_currentAction = nullptr;
    ActionFunc m_actionBuffer[MAX_ACTIONS];
    int m_actionBufferSize = 0;
};