#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>


class CTexture
{
public:
    CTexture(const std::string& textureFile);
    ~CTexture();
    sf::Texture* getSFMLTexture();

private:
    static std::map<std::string, sf::Texture*> m_textureCache;
    sf::Texture* m_sfmlTexture;
    std::string m_key;

};
