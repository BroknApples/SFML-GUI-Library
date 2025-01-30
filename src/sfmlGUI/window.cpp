#include "window.hpp"

/***************************************************************
**************************** PRIVATE ***************************
***************************************************************/

void Window::handleEvents() {

}

void Window::update() {

}

void Window::render() {

}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

Window::Window() {

}

Window::Window(unsigned int width, unsigned int height, sf::String title) {
  
}

void Window::init() {
  window_ = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
}

void Window::run() {
  while(running) {

  }
}