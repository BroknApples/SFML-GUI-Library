#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include <cstdint>

#include "gui-stylesheet.hpp"

class guiWidget {
 private:
  uint32_t id_;

  int xPos_;
  int yPos_;
  std::string display_text_; // may need to be changed to sf::String idk how text printing works yet on SFML
  Stylesheet stylesheet_;

  // get and set children and parent widgets

 public:
  void setWidgetID(uint32_t id) { id_ = id; }
  uint32_t getWidgetID() { return id_; }

  void setStylesheet(Stylesheet stylesheet) { stylesheet_ = stylesheet; }
  
  virtual void init() {}
  virtual void checkEvents() {}
  virtual void update() {}
  virtual void render() {}
};

// Widget List
#include "widget-container.hpp"

#endif // WIDGETS_HPP