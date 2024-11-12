//
// Created by LENOVO on 08/11/2024.
//

#ifndef BOARD_H
#define BOARD_H
#include <vector>

#include "ScoreManager.h"
#include "Snake.h"
#include "Food.h"



class Board {
    private:
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;

    public:
        Board(int width, int height) : SCREEN_WIDTH(width), SCREEN_HEIGHT(height){};
        void drawSnake(Snake& snake, sf::RenderWindow& window);
        void drawFood(Food& food, sf::RenderWindow &window);
        int getScreenWidth();
        int getScreenHeight();
};



#endif //BOARD_H
