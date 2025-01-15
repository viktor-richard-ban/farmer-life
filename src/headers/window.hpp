#include <SFML/Graphics.hpp>

#ifndef WINDOW_HPP
#define WINDOW_HPP

class Window {
public:
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    bool isOpen();
    void beginDraw();
    void endDraw();
    void update();

    void draw(sf::Drawable& drawable);
    void setCamera(sf::View* newCamera);

private:
    sf::RenderWindow window;
};

#endif