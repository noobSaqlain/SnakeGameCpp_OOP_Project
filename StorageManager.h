//
// Created by LENOVO on 08/11/2024.
//

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H
#include <string>
#include <vector>

struct ScoreEntry {
    std::string score;
    std::string date;
    std::string time;
};
class StorageManager {


    const std::string fileName = "C:/Users/LENOVO/Desktop/snakeGameOOp/scores.txt"; /// put your relative path accordingly
public:
    void saveScore(const std::string& scoreData);
    std::string getFileName() const;
    std::vector<ScoreEntry> loadScore() const ;
};



#endif //STORAGEMANAGER_H
