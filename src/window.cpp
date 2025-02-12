#include "window.hpp"

/***************************************************************
**************************** PRIVATE ***************************
***************************************************************/

void Window::handleEvents() {
  while (const std::optional event = render_window_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      render_window_.close();
    }
  }
}

void Window::update() {

}

// TODO: add a version of these methods that are only applied if sfmlGUI is defined through a #define

void Window::render() {
  render_window_.clear();

  // gui widget testing -- put the gui creation into its own standalone function and add a member var to window
  sfmlGUI gui(render_window_);
  guiContainer title_box(100.0f, 100.0f, 500.0f, 400.0f);
  gui.addWidget(&title_box);
  gui.drawGUI();

  render_window_.display();
}

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

Window::Window(sf::String window_title, unsigned int window_width, unsigned int window_height, int window_framerate_limit) {
  window_width_ = window_width;
  window_height_ = window_height;
  window_title_ = window_title;
  window_framerate_limit_ = window_framerate_limit;

  window_ready_ = false;
}

Window::~Window() {

}

/***************************************************************
**************************** PUBLIC ****************************
***************************************************************/

/**
 * @brief Initialize a sf::RenderWindow object and set running to true
 */
void Window::init() {
  render_window_ = sf::RenderWindow(sf::VideoMode({window_width_, window_height_}), window_title_);
  render_window_.setFramerateLimit(window_framerate_limit_);
  window_ready_ = true;
}

void Window::run() {
  // if the user did not call the init function, then do not attempt to open the window
  if (!window_ready_) {
    std::cout << "ERROR: Please call \"init()\" before attempting to run." << std::endl;
    return;
  }

  while (render_window_.isOpen()) {
    handleEvents();
    update();
    render();
  }
}