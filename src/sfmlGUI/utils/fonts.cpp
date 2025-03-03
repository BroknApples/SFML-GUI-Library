#include "fonts.hpp"

/**
 * @brief Initialize predefined fonts
 * 
 * @returns bool: True/False of success
 */
bool initFonts() {
  if (!loadFont("bin/fonts/ARIAL.TTF", font::ARIAL)) return false;
  if (!loadFont("bin/fonts/times.ttf", font::TIMES_NEW_ROMAN)) return false;
  if (!loadFont("bin/fonts/VERDANAI.TTF", font::VERDANA)) return false;

  return true;
}

/**
 * @brief Loads a font file into the gui system's font hashmap
 * 
 * @param font_filepath: path to the font's .ttf file
 * @param font_name: String identifier used to access this font in the font_list variable
 * 
 * @returns bool: True/False of success
 */
bool loadFont(std::string_view font_filepath, const std::string& font_name) {
  namespace fs = std::filesystem;
  fs::path current_path = fs::current_path(); // Path to the current executable, used as the cwd to find the font file

  sf::Font font;
  if (!font.openFromFile(current_path / font_filepath)) {
    return false;
  }
  else {
    font_list[font_name] = std::move(std::make_unique<sf::Font>(font));
    return true;
  }
}

/**
 * @brief Load font from font list
 * 
 * @param font_name: String identifier of the needed font
 * 
 * @returns sf::Font&: Reference to a SFML font type
 */
sf::Font& getFont(const std::string& font_name) {
  try {
    if (font_list.find(font_name) == font_list.end()) {
      throw std::runtime_error("ERROR: Could not find font '" + font_name + "'");
    }

    return *font_list[font_name];    
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}