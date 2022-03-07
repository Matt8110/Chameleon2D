#include "Window.h"

CWindow CWindow::m_instance;

CWindow* CWindow::get()
{
    return &m_instance;
}

void CWindow::init(int width, int height, const std::string& title)
{
    m_sfmlWindow = new sf::RenderWindow(sf::VideoMode(width, height), title);
    setViewPosition({0, 0});
}

void CWindow::setViewPosition(const sf::Vector2f& position)
{
    m_view = sf::View(sf::Vector2f(position.x + VIEW_WIDTH/2, position.y + VIEW_HEIGHT/2), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    m_sfmlWindow->setView(m_view);
}

sf::Vector2f CWindow::getViewPosition()
{
    sf::Vector2f viewCenter = m_view.getCenter();
    return sf::Vector2f(viewCenter.x - VIEW_WIDTH/2, viewCenter.y - VIEW_HEIGHT/2);
}

sf::Vector2f CWindow::getViewSize()
{
    return m_view.getSize();
}

void CWindow::update()
{
    sf::Event event;

    while (m_sfmlWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_sfmlWindow->close();
        }
    }

    m_sfmlWindow->display();
    m_sfmlWindow->clear(m_backgroundColor);
}

bool CWindow::isOpen()
{
    return m_sfmlWindow->isOpen();
}

sf::RenderWindow* CWindow::getSFMLWindow()
{
    return m_sfmlWindow;
}

void CWindow::setFrameLimit(int limit)
{
    m_sfmlWindow->setFramerateLimit(limit);
}

void CWindow::setBackgroundColor(const sf::Color& color)
{
    m_backgroundColor = color;
}