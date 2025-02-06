#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <algorithm>
#include <cstdint>
#include <string>

#include <SFML/Graphics.hpp>

#include "../gui-stylesheet.hpp"

class guiWidget {
 protected:
  uint32_t id_;

  float xPos_, yPos_;
  float sizeX_, sizeY_;

  std::string display_text_; // may need to be changed to sf::String idk how text printing works yet on SFML
  Stylesheet stylesheet_;

  std::vector<guiWidget*> children_;
  sf::RenderWindow* render_window_; // initialized when you add a widget to a gui-manager (sfml-gui.hpp & sfml-gui.cpp)

 public:
  guiWidget();
  guiWidget(float xPos, float yPos, float sizeX, float sizeY);

  bool setRenderWindow(sf::RenderWindow* render_window);

  bool setWidgetID(uint32_t id) { id_ = id; }
  uint32_t getWidgetID() { return id_; }

  bool setPosition(float xPos, float yPos);
  std::pair<float, float> getPosition();

  bool setSize(float sizeX, float sizeY);
  std::pair<float, float> getSize();
  
  bool setDisplayText(std::string& s);
  std::string getDisplayText();

  bool setStylesheet(Stylesheet stylesheet);
  Stylesheet& getStylesheet();

  bool addChild(guiWidget& widget);
  bool removeChild(guiWidget& widget);
  
  virtual void checkEvents() {}
  virtual void update() {}
  virtual void render() {}
};

// Widget List
#include "widget-button.hpp"
#include "widget-container.hpp"
#include "widget-toolbar.hpp"

#endif // WIDGETS_HPP