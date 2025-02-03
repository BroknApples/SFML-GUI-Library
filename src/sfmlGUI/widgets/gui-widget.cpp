#include "gui-widget.hpp"

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

guiWidget::guiWidget() 
    : xPos_(0), yPos_(0), sizeX_(0), sizeY_(0) {
  display_text_ = "";
  stylesheet_ = Stylesheet();
}

guiWidget::guiWidget(int xPos, int yPos, int sizeX, int sizeY) 
    : xPos_(xPos), yPos_(yPos), sizeX_(sizeX), sizeY_(sizeY) {
  display_text_ = "";
  stylesheet_ = Stylesheet();
}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

// TODO: Look into changing guiWidget to being initialized with a reference to a sfmlGUI object
// which would disallow changes to a widgetID through conventional means

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
bool guiWidget::setPosition(int xPos, int yPos) {
  xPos_ = xPos;
  yPos_ = yPos;
}

/**
 * @brief Get the position of a guiWidget
 * 
 * @returns std::pair<int, int>: Pair of integers that contains the xPos in .first and yPos in .second
 */
std::pair<int, int> guiWidget::getPosition() {
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
bool guiWidget::setSize(int sizeX, int sizeY) {
  sizeX_ = sizeX;
  sizeY_ = sizeY;
}

/**
 * @brief Get the size of a guiWidget
 * 
 * @returns std::pair<int, int>: Pair of integers that contains the sizeX in .first and sizeY in .second
 */
std::pair<int, int> guiWidget::getSize() {
  return std::make_pair(sizeX_, sizeY_);
}

/**
 * @brief Set the display text of a guiWidget
 * 
 * @param s: New display text
 * 
 * @returns bool: True/False of success
 */
bool guiWidget::setDisplayText(std::string s) {
  display_text_ = s;
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
}

/**
 * @brief Get the Stylesheet of a guiWidget
 * 
 * @returns Stylesheet&: A reference to the object's Stylesheet
 */
Stylesheet& guiWidget::getStylesheet() {
  return stylesheet_;
}