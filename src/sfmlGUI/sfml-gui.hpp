#ifndef SFML_GUI_HPP
#define SFML_GUI_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "widgets.hpp"
#include "utils.hpp"

class sfmlGUI {
 private:
  sf::RenderWindow* render_window_;

  std::vector<guiWidget*> widget_list_;
  int widget_count_;
  uint32_t widget_id_;

 public:
  sfmlGUI();
  sfmlGUI(sf::RenderWindow& render_window);
  ~sfmlGUI();
  
  void init();

  void guiEvents(std::vector<std::pair<GUI_EVENT_FLAGS, WindowPos>> flags);
  void updateGUI();
  void drawGUI();
  
  void addWidget(guiWidget* widget);
};

#endif // SFML_GUI_HPP