#include "Texture.h"

std::map<std::string, sf::Texture*> CTexture::m_textureCache;

CTexture::CTexture(const std::string& textureFile)
{
    if (m_textureCache.contains(textureFile))
    {
        m_sfmlTexture = m_textureCache.at(textureFile);
    }
    else
    {
        m_sfmlTexture = new sf::Texture();
        m_sfmlTexture->loadFromFile(textureFile);
        m_textureCache[textureFile] = m_sfmlTexture;


        m_key = textureFile;
    }
}

CTexture::~CTexture()
{
    m_textureCache.erase(m_key);
    delete m_sfmlTexture;
}

sf::Texture* CTexture::getSFMLTexture()
{
    return m_sfmlTexture;
}