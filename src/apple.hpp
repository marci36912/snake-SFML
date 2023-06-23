#include <SFML/Graphics.hpp>

class Apple{
    public:
        Apple(int g, int n);
        void randomPosition();
        void updateApple(sf::RenderWindow &w);
        sf::RectangleShape apple;
    private:
        void makeApple(int s);
        int grids;
        int gridn;
};