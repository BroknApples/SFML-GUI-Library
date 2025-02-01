#ifndef SFML_GUI_HPP
#define SFML_GUI_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "gui-event-flags.hpp"
#include "gui-widgets.hpp"

class sfmlGUI {
 private:
  sf::RenderWindow* render_window_;

  std::vector<std::unique_ptr<GUIWidget>> widgets_;
  int widget_count_;

 public:
  sfmlGUI(sf::RenderWindow& render_window);
  ~sfmlGUI();

  void guiEvents(std::vector<std::pair<GUI_EVENT_FLAGS, WindowPos>> flags);
  void updateGUI();
  void drawGUI();
};

#endif // SFML_GUI_HPP