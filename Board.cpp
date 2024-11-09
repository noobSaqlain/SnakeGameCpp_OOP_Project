//
// Created by LENOVO on 08/11/2024.
//

#include "Board.h"




 int Board::getScreenHeight() {
     return SCREEN_HEIGHT;
 }
int Board::getScreenWidth() {
     return SCREEN_WIDTH;
 }

void Board::drawSnake(Snake &snake, sf::RenderWindow &window) {
     const auto& segments = snake.getSegments();
     bool isHead = true;  // Track if we're drawing the head

     for (const auto& segment : segments) {
         sf::RectangleShape segmentShape(sf::Vector2f(snake.getTileSize(), snake.getTileSize()));

         if (isHead) {
             segmentShape.setFillColor(sf::Color(0, 100, 0));  // Dark green for the head
             isHead = false;  // Only the first segment is the head
         } else {
             segmentShape.setFillColor(sf::Color::Green);  // Regular green for the body
         }

         segmentShape.setPosition(static_cast<float>(segment.x), static_cast<float>(segment.y));
         window.draw(segmentShape);
     }
 }


void Board::drawFood(Food &food, sf::RenderWindow &window) {
     sf::CircleShape circle(food.getTileSize() / 2); /// snake and food tilesizes are same
     circle.setFillColor(sf::Color::Red);
     circle.setPosition(static_cast<float>(food.getX()), static_cast<float>(food.getY()));
     window.draw(circle);
}

void Board::drawUI(ScoreManager &scoreManager, sf::RenderWindow &window) {

}


