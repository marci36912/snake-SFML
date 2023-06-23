#include <vector>
#include <SFML/Graphics.hpp>

class Grid{
    public:
    //number of grids, distance between grids and maximum distance of the window
        Grid(int g, int d, int m);
        void updateGrids(sf::RenderWindow &w);
    private:
        int i, xy;
        std::vector<sf::VertexArray> points;
};