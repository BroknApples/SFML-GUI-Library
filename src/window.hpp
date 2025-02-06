#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "sfmlGUI/sfml-gui.hpp"

class Window {
 private:
  sf::RenderWindow render_window_;
  unsigned int window_width_;
  unsigned int window_height_;
  std::string window_title_;
  int window_framerate_limit_;

  bool window_ready_;

  void handleEvents();
  void update();
  void render();

 public:
  Window(sf::String window_title = "SFML Window", unsigned int window_width = 1920u, unsigned int window_height = 1080u, int window_framerate_limit = 60);
  ~Window();

  void init();
  void run();
};


#endif // WINDOW_HPP