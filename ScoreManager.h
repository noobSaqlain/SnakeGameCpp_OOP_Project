//
// Created by LENOVO on 08/11/2024.
//

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>

#include "StorageManager.h"


class ScoreManager{
    int currentScore = 0;
    int highestScore = 0;
    StorageManager* storage;


public:
    ScoreManager();
    ~ScoreManager();
    void updateScore();
    void resetScore();
    int getHighestScore()const ;
    int getCurrScore()const;


    void displayScore(sf::RenderWindow& window);

};



#endif //SCOREMANAGER_H
