#ifndef WIDGETS_HPP
#define WIDGETS_HPP

class GUIWidget {
 private:
  static uint32_t identifier_;
 public:
  // virtual stuff here
  uint32_t getID() { return identifier_; }
};

#endif // WIDGETS_HPP