#include "sfml-gui.hpp"

/***************************************************************
**************************** PRIVATE ***************************
***************************************************************/

void sfmlGUI::guiEvents(std::vector<std::pair<GUI_EVENT_FLAGS, WindowPos>> flags) {

}

void sfmlGUI::updateGUI() {

}

void sfmlGUI::drawGUI() {
  for (int i = widget_count_ - 1; i > 0; i++) {
    // do stuff with widgets_[i] here;
  }
}

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

sfmlGUI::sfmlGUI(sf::RenderWindow& render_window) {
  render_window_ = &render_window;
  widget_count_ = 0;
}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/