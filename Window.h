#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#define VIEW_WIDTH 160
#define VIEW_HEIGHT 120

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
    sf::Vector2f getViewPosition();
    sf::Vector2f getViewSize();
    void setBackgroundColor(const sf::Color& color);

private:
    static CWindow m_instance;
    sf::RenderWindow* m_sfmlWindow;
    sf::View m_view;
    sf::Color m_backgroundColor = {0, 0, 0};
};