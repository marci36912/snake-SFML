#include "grid.hpp"

Grid::Grid(int g, int d, int m)
{
    sf::Color gray(105, 105, 105);
    for(i = 0, xy = d; i < g; i++)
    {
        points.push_back(sf::VertexArray(sf::Lines, 2));

        points[i][0].position = sf::Vector2f(xy, 0);
        points[i][1].position = sf::Vector2f(xy, m);
        points[i][0].color = gray;
        points[i][1].color = gray;

        xy += d;
    }
    for(xy = d, g += i + 1; i < g; i++)
    {
        points.push_back(sf::VertexArray(sf::Lines, 2));

        points[i][0].position = sf::Vector2f(0, xy);
        points[i][1].position = sf::Vector2f(m, xy);
        points[i][0].color = gray;
        points[i][1].color = gray;

        xy += d;
    }
}

void Grid::updateGrids(sf::RenderWindow &w)
{
    for(auto line : points)
        w.draw(line);
}