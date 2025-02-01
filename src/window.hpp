#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

class Window {
 private:
  sf::RenderWindow window_;
  bool running;

  void handleEvents();
  void update();
  void render();

 public:
  Window();
  Window(unsigned int width, unsigned int height, sf::String title);

  void init();
  void run();
};


#endif // WINDOW_HPP