#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "snake.hpp"

#define WINDOW_SIZE 500
#define GRID_NUMBER 20
#define GRID_SIZE WINDOW_SIZE/GRID_NUMBER

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "kigyo");

    Grid grids(GRID_NUMBER, GRID_SIZE, WINDOW_SIZE);
    Apple apple(GRID_SIZE, GRID_NUMBER);
    SnakeManager snakes(sf::Vector2f(WINDOW_SIZE/2, WINDOW_SIZE/2), GRID_SIZE, WINDOW_SIZE);

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                //std::cout << event.key.code << sf::Keyboard::W << std::endl;
                    snakes.snakeControl(event);
                    break;
                default:
                    break;
            }
        }

        snakes.snakeCollision(apple);
        snakes.snakeMovement();

        window.clear();
        grids.updateGrids(window);
        apple.updateApple(window);
        snakes.updateSnakes(window);
        window.display();
    }

    return 0;
}
