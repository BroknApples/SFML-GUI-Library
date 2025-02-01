#ifndef GUI_EVENT_FLAGS_HPP
#define GUI_EVENT_FLAGS_HPP

// idk this might be deleted later, just a thought

struct WindowPos {
  WindowPos(int x_position, int y_position) : xpos(x_position), ypos(y_position) {}
  
  int xpos;
  int ypos;
};

enum GUI_EVENT_FLAGS {
  IN_TEXT_FIELD,
  MOVE_GUI_WINDOW
};

#endif // GUI_EVENT_FLAGS_HPP