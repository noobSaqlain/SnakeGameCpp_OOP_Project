#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
using namespace sf;



const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake Game");
    Game game;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

        }

        //game.updateGame();
        window.clear();

        game.draw(window);
        window.display();
    }

    return 0;
}
