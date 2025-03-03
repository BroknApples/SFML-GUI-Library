cmake_minimum_required(VERSION 3.28)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(sfmlGUI LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.0
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
  SYSTEM
)
FetchContent_MakeAvailable(SFML)

set(SOURCES
  src/main.cpp
  src/window.cpp
  # sfmlGUI
  src/sfmlGUI/sfml-gui.cpp
  # Utils
  src/sfmlGUI/utils/fonts.cpp
  src/sfmlGUI/utils/stylesheet.cpp
  src/sfmlGUI/utils/types.cpp
  # Widgets
  src/sfmlGUI/widgets/gui-widget.cpp
  src/sfmlGUI/widgets/widget-button.cpp
  src/sfmlGUI/widgets/widget-container.cpp
  src/sfmlGUI/widgets/widget-toolbar.cpp
)

add_executable(sfmlGUI ${SOURCES})
target_compile_features(sfmlGUI PRIVATE cxx_std_17)
target_link_libraries(sfmlGUI PRIVATE
  SFML::Graphics
)