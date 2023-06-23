#include "snake.hpp"

void Snake::updateSnake(sf::RenderWindow &w)
{
    w.draw(body);
}

Snake::Snake(sf::Vector2f cords, int size)
{
    body.setSize(sf::Vector2f(size, size));
    body.setFillColor(sf::Color::Green);
    body.setPosition(cords);
}
//-------------------------------------------------
SnakeManager::SnakeManager(sf::Vector2f middle, int s, int e)
{
    alive = true;
    size = s;
    x = 0;
    y = 0;
    edges = e;
    time = sf::seconds(0);
    timeToMove = SECOND;
    for(int i = 0; i < 3; i++)  bodyParts.push_back(Snake(middle, size));
}

void SnakeManager::updateSnakes(sf::RenderWindow &w)
{
    for(Snake &s: bodyParts)
    {
        s.updateSnake(w);
    }
}

void SnakeManager::snakeControl(sf::Event e)
{
    switch(e.key.code)
    {
        case sf::Keyboard::W:
            if(y != size)
            {
                x = 0;
                y = -size;
            }
            break;
        case sf::Keyboard::A:
            if(x != size)
            {
                x = -size;
                y = 0;
            }
            break;
        case sf::Keyboard::S:
            if(y != -size)
            {
                x = 0;
                y = size;
            }
            break;
        case sf::Keyboard::D:
            if(x != -size)
            {
                x = size;
                y = 0;
            }
            break;
    }
}

void SnakeManager::checkBoundary()
{
    sf::Vector2f coords = bodyParts[0].body.getPosition();

    if(coords.x > edges)
    {
        coords.x = -size;
        bodyParts[0].body.setPosition(coords);
    }
    else if(coords.x < 0)
    {
        coords.x = edges;
        bodyParts[0].body.setPosition(coords);
    }
    else if(coords.y > edges)
    {
        coords.y = -size;
        bodyParts[0].body.setPosition(coords);
    }
    else if(coords.y < 0)
    {
        coords.y = edges;
        bodyParts[0].body.setPosition(coords);
    }
}

void SnakeManager::snakeMovement()
{
    time = clock.getElapsedTime();

    if(timeToMove <= 0 && alive)
    {
        for(int i = bodyParts.size() -1; i >= 1; i--)
        {
            bodyParts[i].body.setPosition(bodyParts[i-1].body.getPosition());
        }
        checkBoundary();
        bodyParts[0].body.move(x,y); //5 0 jobbra, 0 5 le
        timeToMove = SECOND;
    }
    else
    {
        timeToMove -= time.asMicroseconds();
    }

    clock.restart();
}

void SnakeManager::addSnake()
{
    bodyParts.push_back(Snake(bodyParts[bodyParts.size()-1].body.getPosition(),size));
}

void SnakeManager::death()
{
    for(auto &a:bodyParts)
    {
        a.body.setFillColor(sf::Color(128,128,128));
    }
}

void SnakeManager::snakeCollision(Apple &a)
{
    if(bodyParts[0].body.getGlobalBounds().intersects(a.apple.getGlobalBounds()))
    {
        a.randomPosition();
        addSnake();
    }

    for(int i = 3; i < bodyParts.size(); i++)
    {
        if(bodyParts[0].body.getGlobalBounds().intersects(bodyParts[i].body.getGlobalBounds()))
        {
            alive = false;
            death();
            return;
        }
    }
}
