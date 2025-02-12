#ifndef WIDGET_CONTAINER_HPP
#define WIDGET_CONTAINER_HPP

#include <SFML/Graphics.hpp>

#include "gui-widget.hpp"

class guiContainer : public guiWidget {
 private:
  sf::RectangleShape container_;

 public:
  guiContainer();
  guiContainer(float xPos, float yPos, float sizeX, float sizeY);

  void checkEvents() override;
  void update() override;
  void render() override;
};

#endif // WIDGET_CONTAINER_HPP