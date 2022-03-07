#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <math.h>
#include <map>
#include "Animation.h"
#include "Texture.h"
#include "Window.h"

class CSprite
{
public:
    CSprite(const std::string& textureFile, const sf::Vector2i& unitSize, int unitIndex);
    virtual void update();
    virtual void render();
    sf::Sprite* getSFMLSprite();
    ~CSprite();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition();
    void addAnimation(const std::string& animationName, CAnimation animation);
    void setAnimation(const std::string& animationName);
    void setAnimation(CAnimation& animation);
    void setOrigin(const sf::Vector2f& offset);
    sf::Vector2f getOrigin();
    void setUnitIndex(int index);

private:
    void applyAnimations();

private:
    sf::Sprite* m_sfmlSprite;
    CTexture* m_texture;
    sf::Vector2f m_position = sf::Vector2f(0, 0);
    sf::Vector2f m_offset = sf::Vector2f(0, 0);
    int m_unitsPerLine = 0;
    sf::Vector2i m_unitPos;
    sf::Vector2i m_unitSize;
    std::map<std::string, CAnimation> m_animationList;
    CAnimation* m_animation = nullptr;
};