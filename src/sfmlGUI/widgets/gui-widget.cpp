#include "gui-widget.hpp"

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

guiWidget::guiWidget() 
    : xPos_(0.0f), yPos_(0.0f), sizeX_(0.0f), sizeY_(0.0f) {
  display_text_ = "";
  stylesheet_ = Stylesheet();
  render_window_ = nullptr;
}

guiWidget::guiWidget(float xPos, float yPos, float sizeX, float sizeY) 
    : xPos_(xPos), yPos_(yPos), sizeX_(sizeX), sizeY_(sizeY) {
  display_text_ = "";
  stylesheet_ = Stylesheet();
  render_window_ = nullptr;
}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

// TODO: Look into changing guiWidget to being initialized with a reference to a sfmlGUI object
// which would disallow changes to a widgetID through conventional means

/**
 * @brief DO NOT USE, FOR USE ONLY BY THE sfmlGUI CLASS...
 *        Set the sf::RenderWindow to draw this guiWidget on
 * 
 * @param render_window: Pointer to a sf::RenderWindow object
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setRenderWindow(sf::RenderWindow* render_window) {
  render_window_ = render_window;
  return true;
}

/**
 * @brief DO NOT USE, FOR USE ONLY BY THE sfmlGUI CLASS...
 *        Set the unique identifier(id) of a widgetID.
 * 
 * @param id: New id of a guiWidget
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setWidgetID(uint32_t id) {
  id_ = id;
  return true;
}

/**
 * @brief Get the unique identifier(id) of a guiWidget
 * 
 * @returns uint32_t: Integer that corresponds to the guiWidget's id
 */
uint32_t guiWidget::getWidgetID() {
  return id_;
}

/**
 * @brief Set the x and y position of a guiWiget
 * 
 * @param xPos: New x position
 * @param yPos: New y position
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setPosition(float xPos, float yPos) {
  xPos_ = xPos;
  yPos_ = yPos;
  return true;
}

/**
 * @brief Get the position of a guiWidget
 * 
 * @returns std::pair<float, float>: Pair of floats that contains the xPos in .first and yPos in .second
 */
std::pair<float, float> guiWidget::getPosition() {
  return std::make_pair(xPos_, yPos_);
}

/**
 * @brief Set the x and y size of a guiWiget
 * 
 * @param xPos: New x size
 * @param yPos: New y size
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setSize(float sizeX, float sizeY) {
  sizeX_ = sizeX;
  sizeY_ = sizeY;
  return true;
}

/**
 * @brief Get the size of a guiWidget
 * 
 * @returns std::pair<float, float>: Pair of floats that contains the sizeX in .first and sizeY in .second
 */
std::pair<float, float> guiWidget::getSize() {
  return std::make_pair(sizeX_, sizeY_);
}

/**
 * @brief Set the display text of a guiWidget
 * 
 * @param s: New display text
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setDisplayText(std::string& s) {
  display_text_ = s;
  return true;
}

/**
 * @brief Get the display text of a guiWidget
 * 
 * @returns std::string: String literal containing a guiWidget's display text
 */
std::string guiWidget::getDisplayText() {
  return display_text_;
}

/**
 * @brief Set the Stylesheet of a guiWidget
 * 
 * @param stylesheet: New Stylesheet
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setStylesheet(Stylesheet stylesheet) {
  stylesheet_ = stylesheet;
  return true;
}

/**
 * @brief Get the Stylesheet of a guiWidget
 * 
 * @returns Stylesheet&: A reference to the object's Stylesheet
 */
Stylesheet& guiWidget::getStylesheet() {
  return stylesheet_;
}

/**
 * @brief Add a child guiWidget
 * 
 * @param widget: Widget to set as a child guiWidget
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::addChild(guiWidget widget) {
  std::shared_ptr<guiWidget> ptr = std::make_shared<guiWidget>(std::move(widget));
  children_.emplace_back(std::move(ptr));

  return true;
}

/**
 * @brief Remove a child guiWidget
 * 
 * @param widget: Widget to remove as a child guiWidget
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::removeChild(guiWidget& widget)  {
  for (int i = 0; i < children_.size(); i++) {
    if (widget == *children_[i]) {
      children_.erase(children_.begin() + i);
      return true;
    }
  }

  // If the loop did not return, the target guiWidget is not a child of the current guiWidget
  return false;
}


/**
 * @brief Remove a child guiWidget
 * 
 * @param widget_id: Widget ID to remove as a child guiWidget
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::removeChild(uint32_t widget_id) {

  for (int i = 0; i < children_.size(); i++) {
    if (widget_id == children_[i]->getWidgetID()) {
      children_.erase(children_.begin() + i);
      return true;
    }
  }

  // If the loop did not return, the target guiWidget is not a child of the current guiWidget
  return false;
}