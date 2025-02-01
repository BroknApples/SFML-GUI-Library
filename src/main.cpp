#include <SFML/Graphics.hpp>

#include "window.hpp"

int main() {
  Window app("sfmlGUI Test", 1280u, 720u, 60);
  app.init();
  app.run();

  return 0;
}