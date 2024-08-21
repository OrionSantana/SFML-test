#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int numCells = 100;
int width = 800;
int height = 800;
int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    Grid grid(numCells, width, height);
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            /*if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.toggle(x, y);
                }
            }*/
        }
         //HOLD     HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD
        if (Mouse::isButtonPressed(Mouse::Left)){
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            grid.toggle(x, y);
        }//HOLD     HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD    HOLD
        window.clear();
        grid.update();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}