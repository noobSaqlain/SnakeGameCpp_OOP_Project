//
// Created by LENOVO on 09/11/2024.
//

#ifndef UIMANAGER_H
#define UIMANAGER_H
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Board.h"
#include "Food.h"
#include "Snake.h"
#include "ScoreManager.h"

class Game; /// to remove circular dependency b/w game and uimanager

class UIManager {
  private:
     bool isScorePageOpened = false;
    Game* game;
    ScoreManager* scoreManager;
    //  rect shape for buttons
    sf::RectangleShape startButton; // main page start button
    sf::RectangleShape scoreButton; // score page history button
    sf::RectangleShape restartButton; // restart button on gameover screen
    sf::RectangleShape backToMenuButton; // back to menu, button in gameover state
    sf::RectangleShape scorePageBackButton; // back button when on score page

    // Texts
    sf::Text startText; /// main start text
    sf::Text scoreText; // score text of snake
    sf::Text gameOverText; // final game over text when collision
    sf::Text restartText; // restart button text
    sf::Text backToMenuText; // back to menu text when gameover
    sf::Text scorePageBacktext; // back text when on score page

    sf::Font font;
  public:
    UIManager(Game* gameInstance);
    ~UIManager();
     void handleInputs(sf::Vector2i& mousePos, Snake& snake, Food& food);
     void initButtons();
     void drawMainMenu(sf::RenderWindow &window);
     void drawGame(sf::RenderWindow &window,Snake& snake, Food& food, Board& board);
     void drawRestart(sf::RenderWindow &window);
     void drawRestartButton(sf::RenderWindow &window);
     void drawScorePage(sf::RenderWindow& window);
    void drawScorePageBackButton(sf::RenderWindow& window);
    void setIsScorePageOpened(bool state);
    bool getIsScorePageOpened() const;
};



#endif //UIMANAGER_H
