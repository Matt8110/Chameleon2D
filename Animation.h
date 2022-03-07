#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class CAnimation
{
public:
    CAnimation();
    void addFrame(int sheetIndex);
    void addFrameRange(int frameA, int frameB);
    void addPosition(const sf::Vector2f& position);
    void addInterpPosition(const sf::Vector2f& startPos, const sf::Vector2f& endPos, int frames);
    void update();
    sf::Vector2f getPositionOffset();
    int getFramedIndex();
    void setSpeed(float speed);
    float getSpeed();
    bool hasPositionAnimation();
    bool hasFramedAnimation();

public:
    

private:
    std::vector<int> m_framedAnimation;
    std::vector<sf::Vector2f> m_positionAnimation;
    float m_animationSpeed = 1.0f;
    float m_animationFrame = 0;
    int m_intAnimationFrame = 0;
    int m_totalFrames = 0;
};