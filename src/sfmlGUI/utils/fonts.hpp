#ifndef FONTS_HPP
#define FONTS_HPP

#include <iostream>
#include <string_view>
#include <filesystem>
#include <unordered_map>
#include <stdexcept>

#include <SFML/Graphics.hpp>

// Predefined font definitions
namespace font {
  constexpr const char* ARIAL = "Arial";
  constexpr const char* TIMES_NEW_ROMAN = "Times New Roman";
  constexpr const char* VERDANA = "Verdana";
}

// Dictionary of fonts available for use
static std::unordered_map<std::string, std::unique_ptr<sf::Font>> font_list;

bool initFonts();
bool loadFont(std::string_view font_filepath, const std::string& font_name);
sf::Font& getFont(const std::string& font_name);

#endif // FONTS_HPP