//
// Created by LENOVO on 08/11/2024.
//

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <string>
#include <vector>


class StorageManager {
private:
    const std::string fileName = "C:/Users/LENOVO/Desktop/snakeGameOOp/scores.txt"; /// put your relative path accordingly
public:
    void saveScore();
    std::vector<std::string> loadScore();
};



#endif //STORAGEMANAGER_H
