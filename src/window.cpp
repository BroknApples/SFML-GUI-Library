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

  gui_.updateGUI();
}

// TODO: add a version of these methods that are only applied if sfmlGUI is defined through a #define

void Window::render() {
  render_window_.clear();

  guiContainer title_box(100.0f, 100.0f, 500.0f, 50.0f);
  gui_.addWidget(&title_box);
  guiContainer title_box1(400.0f, 700.0f, 200.0f, 150.0f);
  gui_.addWidget(&title_box1);
  guiContainer title_box2(200.0f, 350.0f, 80.0f, 200.0f);
  gui_.addWidget(&title_box2);
  
  gui_.drawGUI();
  render_window_.display();
}

/***************************************************************
******************* CONSTRUCTORS/DESTRUCTORS *******************
***************************************************************/

Window::Window(sf::String window_title, uint window_width, uint window_height, int window_framerate_limit) {
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

  gui_ = sfmlGUI(render_window_);
  gui_.init();
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