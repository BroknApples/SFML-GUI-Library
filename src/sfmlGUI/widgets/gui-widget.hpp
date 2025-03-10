#ifndef GUI_WIDGET_HPP
#define GUI_WIDGET_HPP

#include <algorithm>
#include <cstdint>
#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "../utils.hpp"

class guiWidget {
 protected:
  uint32_t id_;

  float xPos_; // X-Position of the center of the screen object
  float yPos_; // Y-Position of the center of the screen object
  float minimum_sizeX_; // Minimum width of the widget
  float minimum_sizeY_; // Minimum height of the object

  bool is_visible;

  std::string display_text_; // may need to be changed to sf::String idk how text printing works yet on SFML
  Stylesheet stylesheet_;

  std::vector<std::shared_ptr<guiWidget>> children_;
  sf::RenderWindow* render_window_; // initialized when you add a widget to a Gui Manager (sfml-gui.hpp & sfml-gui.cpp)

 public:
  guiWidget();
  guiWidget(float xPos, float yPos, float minimum_sizeX, float minimum_sizeY);

  bool setRenderWindow(sf::RenderWindow* render_window);

  bool setWidgetID(uint32_t id);
  uint32_t getWidgetID();

  bool setPosition(float xPos, float yPos);
  std::pair<float, float> getPosition();

  bool setMinimumSize(float sizeX, float sizeY);
  std::pair<float, float> getSize();
  
  bool setDisplayText(std::string& s);
  std::string getDisplayText();

  bool setStylesheet(Stylesheet stylesheet);
  Stylesheet& getStylesheet();

  bool addChild(guiWidget widget);
  bool removeChild(guiWidget& widget);
  bool removeChild(uint32_t widget_id);
  
  virtual void checkEvents() {}
  virtual void update() {}
  virtual void render() {}

  bool guiWidget::operator==(const guiWidget& other) const {
    return this == &other;  // Compare memory addresses
  }
};

#endif // GUI_WIDGET_HPP