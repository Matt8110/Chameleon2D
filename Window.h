#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class CWindow
{
public:
    static CWindow* get();
    void init(int width, int height, const std::string& title);
    void update();
    bool isOpen();
    void setFrameLimit(int limit);
    sf::RenderWindow* getSFMLWindow();
    void setViewPosition(const sf::Vector2f& position);
    void setViewSize(const sf::Vector2f& size);
    sf::Vector2f getViewPosition();
    sf::Vector2f getViewSize();
    void setBackgroundColor(const sf::Color& color);

private:
    static CWindow m_instance;
    sf::RenderWindow* m_sfmlWindow;
    sf::View m_view;
    sf::Color m_backgroundColor = {0, 0, 0};
    sf::Vector2f m_viewSize = {426, 240};
};