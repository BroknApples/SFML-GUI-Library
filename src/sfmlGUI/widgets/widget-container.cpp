#include "widget-container.hpp"

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

guiContainer::guiContainer() : guiWidget() {

}

/**
 * @brief Constructor for guiContainer
 * 
 * @param xPos: Bottom left corner's position on the x-plane
 * @param yPos: Bottom left corner's position on the y-plane
 * @param sizeX: Horizontal size of the container
 * @param sizeY: Vertical size of the container
 */
guiContainer::guiContainer(float xPos, float yPos, float minimum_sizeX, float minimum_sizeY) : guiWidget(xPos, yPos, minimum_sizeX, minimum_sizeY) {
  container_.setPosition({xPos_, yPos_});
  container_.setSize({minimum_sizeX_, minimum_sizeY_});
  container_.setFillColor(sf::Color::Green);
}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

void guiContainer::checkEvents() {

}

void guiContainer::update() {

}

void guiContainer::render() {
  sf::Font font = getFont(font::ARIAL);
  sf::Text text(font, "Hello, SFML!", 30);  // "30" is the text size
  text.setFillColor(sf::Color::White);  // Set the text color
  text.setPosition(sf::Vector2f(200.f, 100.f));  // Set the position on the screen
  render_window_->draw(container_);
  render_window_->draw(text);
}