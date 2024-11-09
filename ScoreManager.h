//
// Created by LENOVO on 08/11/2024.
//

#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#include "StorageManager.h"


class ScoreManager : StorageManager{
private:
    int currentScore;
    int highestScore;
public:
    void updateScore();
    void resetScore();
    int getHighestScore();
    void saveScore();
};



#endif //SCOREMANAGER_H
