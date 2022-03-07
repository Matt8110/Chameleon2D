#include "Animation.h"

CAnimation::CAnimation()
{

}

void CAnimation::addFrame(int sheetIndex)
{
    m_framedAnimation.push_back(sheetIndex);

    if (m_framedAnimation.size() > m_totalFrames)
        m_totalFrames = m_framedAnimation.size();
}

void CAnimation::addFrameRange(int frameA, int frameB)
{
    int frames = frameB - frameA;
    int finalFrame = 0;

    for (int i = 0; i <= abs(frames); i++)
    {
        finalFrame = frames < 0 ? frameA - i : frameA + i;
        addFrame(finalFrame);
    }
}

void CAnimation::addPosition(const sf::Vector2f& position)
{
    m_positionAnimation.push_back(position);

    if (m_positionAnimation.size() > m_totalFrames)
        m_totalFrames = m_positionAnimation.size();
}

void CAnimation::addInterpPosition(const sf::Vector2f& startPos, const sf::Vector2f& endPos, int frames)
{
    sf::Vector2f posDiff = endPos - startPos;
    sf::Vector2f interpStep;
    sf::Vector2f finalPos;
    interpStep.x = posDiff.x / frames;
    interpStep.y = posDiff.y / frames;

    for (int i = 0; i < frames; i++)
    {
        //Fix for negative numbers
        finalPos.x = interpStep.x < 0 ? (abs(posDiff.x) + (interpStep.x * i)) : finalPos.x = interpStep.x * i;
        finalPos.y = interpStep.y < 0 ? (abs(posDiff.y)  + (interpStep.y * i)) : finalPos.y = interpStep.y * i;

        //If the start is the same as the end...
        if (posDiff.x == 0 && posDiff.y == 0)
            finalPos = startPos;

        addPosition(sf::Vector2f(finalPos.x, finalPos.y));
    }
}

void CAnimation::update()
{
    m_animationFrame += m_animationSpeed;

    if (m_animationFrame >= m_totalFrames)
        m_animationFrame = 0;

    m_intAnimationFrame = (int)m_animationFrame;
}

sf::Vector2f CAnimation::getPositionOffset()
{
    if (hasPositionAnimation())
    {
        return m_positionAnimation[m_intAnimationFrame % m_positionAnimation.size()];
    }

    return {0, 0};
}

int CAnimation::getFramedIndex()
{
    if (hasFramedAnimation())
    {
        return m_framedAnimation[m_intAnimationFrame % m_framedAnimation.size()];
    }

    return 0;
}

void CAnimation::setSpeed(float speed)
{
    m_animationSpeed = speed;
}

float CAnimation::getSpeed()
{
    return m_animationSpeed;
}

bool CAnimation::hasPositionAnimation()
{
    return m_positionAnimation.size() > 0;
}

bool CAnimation::hasFramedAnimation()
{
    return m_framedAnimation.size() > 0;
}