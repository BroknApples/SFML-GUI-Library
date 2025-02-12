#include "widget-container.hpp"

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

guiContainer::guiContainer() : guiWidget() {

}

guiContainer::guiContainer(float xPos, float yPos, float sizeX, float sizeY) : guiWidget(xPos, yPos, sizeX, sizeY) {
  container_.setPosition({xPos_, yPos_});
  container_.setSize({sizeX_, sizeY_});
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
  render_window_->draw(container_);
}