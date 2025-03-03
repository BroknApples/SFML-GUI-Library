#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * @brief Hex Number type: defined using a string to enforce the hex format
 */
struct Hex {
  Hex(const std::string hex_string);

  uint value;
};

#endif // TYPES_HPP