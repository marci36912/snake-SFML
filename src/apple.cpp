#include "apple.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h> 

void Apple::updateApple(sf::RenderWindow &w)
{
    w.draw(apple);
}

void Apple::randomPosition()
{
    //it can spawn on the snake!
    //TODO fix it
    int x = grids * abs((rand() % gridn));
    int y = grids * abs((rand() % gridn));

    //std::cout << x << " " << y << std::endl;

    apple.setPosition(sf::Vector2f(x, y));
}

void Apple::makeApple(int s)
{
    apple.setSize(sf::Vector2f(s,s));
    apple.setFillColor(sf::Color::Red);
    srand(time(NULL));
    randomPosition();
}

Apple::Apple(int g, int n)
{
    grids = g;
    gridn = n;

    makeApple(grids);
}
