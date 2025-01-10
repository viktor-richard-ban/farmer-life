#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::Vector2<float> m_vector = {320,240};
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");
    
    sf::RectangleShape rectangle(sf::Vector2f({128.0f, 128.0f}));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(m_vector);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                 event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
                window.close();
            
            if (event->is<sf::Event::KeyPressed>()) {
                // Vertical movement
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::W)
                {
                    m_vector += {0,-5};
                    rectangle.setPosition(m_vector);
                }
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S)
                {
                    m_vector += {0,5};
                    rectangle.setPosition(m_vector);
                }
                
                // Horizontal movement
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::A)
                {
                    m_vector += {-5,0};
                    rectangle.setPosition(m_vector);
                }
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::D)
                {
                    m_vector += {+5,0};
                    rectangle.setPosition(m_vector);
                }
            }
        }
        
        window.clear();
        window.draw(rectangle);
        window.display();
    }
}
