//
// Created by LENOVO on 09/11/2024.
//

// UIManager.h

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>

class UIManager {
private:
    sf::Font font;
    sf::RectangleShape startButton, scoreButton, restartButton, backToMenuButton;
    sf::Text startText, scoreText, restartText, backToMenuText;

public:
    UIManager();
    void initButtons();
    void drawMainMenu(sf::RenderWindow &window);
    void drawGameOverMenu(sf::RenderWindow &window);
    bool isStartClicked(const sf::Vector2i &mousePos);
    bool isRestartClicked(const sf::Vector2i &mousePos);
    bool isBackToMenuClicked(const sf::Vector2i &mousePos);
};

#endif // UIMANAGER_H
