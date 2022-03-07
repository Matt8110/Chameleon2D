#include "Sprite.h"

CSprite::CSprite(const std::string& textureFile, const sf::Vector2i& unitSize, int unitIndex)
{
    m_texture = new CTexture(textureFile);
    m_sfmlSprite = new sf::Sprite(*m_texture->getSFMLTexture());

    m_unitSize = unitSize;
   setUnitIndex(unitIndex);
}

void CSprite::setUnitIndex(int index)
{
    m_unitsPerLine = m_texture->getSFMLTexture()->getSize().x / m_unitSize.x;
    m_unitPos.x = (index % m_unitsPerLine) * m_unitSize.x;
    m_unitPos.y = (index / m_unitsPerLine) * m_unitSize.y;
    m_sfmlSprite->setTextureRect(sf::IntRect(m_unitPos, m_unitSize));
}

void CSprite::update()
{
    m_sfmlSprite->setPosition(m_position - m_offset);
    applyAnimations();
}

void CSprite::applyAnimations()
{
    if (m_animation != nullptr)
    {
        m_animation->update();

        //Position anim
        if (m_animation->hasPositionAnimation())
            m_sfmlSprite->setPosition(m_position + m_animation->getPositionOffset() - m_offset);

        //Framed anim
        if (m_animation->hasFramedAnimation())
        {
            setUnitIndex(m_animation->getFramedIndex());
        }
    }
}

void CSprite::render()
{
    CWindow::get()->getSFMLWindow()->draw(*m_sfmlSprite);
}

CSprite::~CSprite()
{
    delete m_texture;
}

void CSprite::setPosition(const sf::Vector2f& position)
{
    m_position = position;
}

sf::Vector2f CSprite::getPosition()
{
    return m_position;
}

sf::Sprite* CSprite::getSFMLSprite()
{
    return m_sfmlSprite;
}

void CSprite::addAnimation(const std::string& animationName, CAnimation animation)
{
    m_animationList[animationName] = animation;
}

void CSprite::setAnimation(const std::string& animationName)
{
    if (m_animationList.contains(animationName))
        m_animation = &m_animationList[animationName];
}

void CSprite::setAnimation(CAnimation& animation)
{
    m_animation = &animation;
}

void CSprite::setOrigin(const sf::Vector2f& offset)
{
    m_offset.x = offset.x * m_unitSize.x;
    m_offset.y = offset.y * m_unitSize.y;
}

sf::Vector2f CSprite::getOrigin()
{
    return m_offset;
}