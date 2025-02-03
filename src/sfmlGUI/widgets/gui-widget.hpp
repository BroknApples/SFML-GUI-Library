#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <algorithm>
#include <cstdint>
#include <string>

#include "../gui-stylesheet.hpp"

class guiWidget {
 private:
  uint32_t id_;

  int xPos_, yPos_;
  int sizeX_, sizeY_;

  std::string display_text_; // may need to be changed to sf::String idk how text printing works yet on SFML
  Stylesheet stylesheet_;

  // get and set children and parent widgets

 public:
  guiWidget();
  guiWidget(int xPos, int yPos, int sizeX, int sizeY);

  bool setWidgetID(uint32_t id) { id_ = id; }
  uint32_t getWidgetID() { return id_; }

  bool setPosition(int xPos, int yPos);
  std::pair<int, int> getPosition();

  bool setSize(int sizeX, int sizeY);
  std::pair<int, int> getSize();
  
  bool setDisplayText(std::string s);
  std::string getDisplayText();

  bool setStylesheet(Stylesheet stylesheet);
  Stylesheet& getStylesheet();

  
  virtual void checkEvents() {}
  virtual void update() {}
  virtual void render() {}
};

// Widget List
#include "widget-button.hpp"
#include "widget-container.hpp"
#include "widget-toolbar.hpp"

#endif // WIDGETS_HPP