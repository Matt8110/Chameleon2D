#pragma once

#include <SFML/Graphics.hpp>
#include "Sprite.h"

class CEntity
{
public:
    CEntity();
    ~CEntity();
    void callUpdate();
    void callRender();

protected:
    virtual void update() {}
    virtual void render() {}

protected:
    sf::Vector2f m_position;
    CSprite* m_sprite = nullptr;
};