#include <SFML/Graphics.hpp>
#include <vector>
#include "apple.hpp"

#define SECOND 1000000

class Snake{
    public:
        Snake(sf::Vector2f cords, int size);
        void updateSnake(sf::RenderWindow &w);
        sf::RectangleShape body;
};

class SnakeManager{
    public:
        SnakeManager(sf::Vector2f middle, int s, int e);
        void snakeControl(sf::Event e); //event.key.code
        void snakeMovement();
        void snakeCollision(Apple &a);
        void updateSnakes(sf::RenderWindow &w);
    private:
        bool alive;
        int size;
        int edges;
        int x, y;
        std::vector<Snake> bodyParts;
        sf::Clock clock;
        sf::Time time;
        int timeToMove;
        void addSnake();
        void death();
        void checkBoundary();
};
