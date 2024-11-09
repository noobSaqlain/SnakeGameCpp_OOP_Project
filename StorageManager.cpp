//
// Created by LENOVO on 09/11/2024.
//

#include "StorageManager.h"

#include <fstream>
#include <sstream>
#include <iostream>



std::string StorageManager::getFileName() const {
    return fileName;
}


void StorageManager::saveScore(const std::string& scoreData) {
    //open file in append mode to store new data every time game is over, at the end of the file
    std::ofstream outFile(fileName, std::ios::app);

    if (outFile.is_open()) {
        outFile << scoreData << "\n";  // Append the provided formatted string to the file
        outFile.close();  // Close the file after writing
    } else {
        std::cerr << "Unable to open file for saving score." << std::endl;
    }
}


std::vector<ScoreEntry> StorageManager::loadScore() const {
    std::vector<ScoreEntry> scores;
    std::ifstream inFile(fileName);

    if (inFile.is_open()) {
        std::string line;

        // Read each line from the file
        while (std::getline(inFile, line)) {
            std::istringstream lineStream(line);
            ScoreEntry entry;

            // Parse the score, date, and time fields from each line
            std::getline(lineStream, entry.score, ',');
            std::getline(lineStream, entry.date, ',');
            std::getline(lineStream, entry.time, ',');

            // Add the parsed entry to the scores vector
            scores.push_back(entry);
        }

        inFile.close();
    } else {
        std::cerr << "Unable to open file for loading scores." << std::endl;
    }

    return scores;
}

