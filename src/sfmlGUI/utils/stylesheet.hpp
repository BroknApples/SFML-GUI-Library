#ifndef STYLESHEET_HPP
#define STYLESHEET_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../utils.hpp"

class Stylesheet {
  /**********************************************************************
   * 
   * 
   *                               Enum Types
   * 
   * 
   **********************************************************************/
 public:
  /**
   * @brief Alignment of the text in the gui element
   */
  enum AlignmentFlag {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
  };

  /**
   * @brief The position of all color elements in the color array stylesheet emmber variable
   */
  enum ColorPosition {
    BACKGROUND,
    TEXT,
    BORDER,
    MAX_COLOR_ELEMENTS
  };

 private:
  // Colors
  std::array<sf::Color, ColorPosition::MAX_COLOR_ELEMENTS> color_arr_;

  // Text
  uint font_size_;
  AlignmentFlag text_alignment_flag_;

  // Margins
  uint margin_size_;

  // Borders
  uint border_radius_;
  uint border_size_;

 public:
  Stylesheet();

  // Colors
  void setColor(ColorPosition element, sf::Color& color);
  void setColor(ColorPosition element, Hex color_code, Hex alpha = Hex("0xff"));
  void setColor(ColorPosition element, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

  const sf::Color& getBackgroundColor() const { return color_arr_[ColorPosition::BACKGROUND]; }
  const sf::Color& getTextColor() const { return color_arr_[ColorPosition::TEXT]; }
  const sf::Color& getBorderColor() const { return color_arr_[ColorPosition::BORDER]; }

  // Text
  void setFontSize(uint new_font_size);
  const uint getFontSize() const { return font_size_; }

  void setTextAlignment(AlignmentFlag new_alignment_flag);
  const AlignmentFlag getTextAlignment() const { return text_alignment_flag_; }
};

#endif // STYLESHEET_HPP