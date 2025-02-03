#include "sfml-gui.hpp"

/***************************************************************
**************************** PRIVATE ***************************
***************************************************************/

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

sfmlGUI::sfmlGUI(sf::RenderWindow& render_window) {
  render_window_ = &render_window;
  widget_count_ = 0;
  widget_id_ = 0;
}

sfmlGUI::~sfmlGUI() {

}

/***************************************************************
**************************** PUBLIC ****************************
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

/**
 * @brief Add a widget to an instance of widget
 */
void sfmlGUI::addWidget(guiWidget& widget) {
  widget.setWidgetID(widget_id_++);
  widget_list_.push_back(std::make_unique<guiWidget>(std::move(widget)));
}