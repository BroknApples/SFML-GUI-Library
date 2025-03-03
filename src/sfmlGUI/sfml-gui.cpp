#include "sfml-gui.hpp"

/***************************************************************
**************************** PRIVATE ***************************
***************************************************************/

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

/**
 * @brief Create sfmlGUI class instance
 */
sfmlGUI::sfmlGUI() {}

/**
 * @brief Creeat sfmlGUI class instance
 * 
 * @param render_window: Window to draw on
 */
sfmlGUI::sfmlGUI(sf::RenderWindow& render_window) {
  render_window_ = &render_window;
  widget_count_ = 0;
  widget_id_ = 1;
}

/**
 * @brief sfmlGUI destructor -- Clear all dynamic memory
 */
sfmlGUI::~sfmlGUI() {
  // for (int i = 0; i < widget_count_; i++) {
  //   delete widget_list_[i];
  // }
}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

/**
 * @brief Init essential gui variables
 */
void sfmlGUI::init() {
  initFonts();
}

/**
 * @brief Given some flags, do the corresponding events in the gui
 */
void sfmlGUI::guiEvents(std::vector<std::pair<GUI_EVENT_FLAGS, WindowPos>> flags) {

}

void sfmlGUI::updateGUI() {

}

void sfmlGUI::drawGUI() {
  for (int i = widget_count_ - 1; i >= 0; i--) {
    widget_list_[i]->render();
    // TODO: Render the children of these widgets
  }
}

/**
 * @brief Add a guiWidget to a GUI manager (sfmlGUI class)
 */
void sfmlGUI::addWidget(guiWidget* widget) {
  // Set widget properties
  widget->setWidgetID(widget_id_++);
  widget->setRenderWindow(render_window_);

  // Add to widget list
  widget_list_.push_back(widget);
  widget_count_++;
}