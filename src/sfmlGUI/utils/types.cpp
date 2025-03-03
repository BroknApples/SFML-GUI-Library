#include "types.hpp"

Hex::Hex(const std::string hex_string) {
  int starting_idx = 0;

  try {
    if (hex_string[0] == '#') {
      starting_idx = 1;
    }
    else if (hex_string[0] == '0' && hex_string[1] == 'x') {
      starting_idx = 2;
    }
    else {
      throw std::runtime_error("ERROR: Cannot initialize type 'Hex' with '" + hex_string + "'");
    }
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  // No error during initialization, convert to hex number
  const int kLength = hex_string.length();
  for (int i = starting_idx; i < kLength; i++) {
    std::stringstream ss;
    ss << std::hex << hex_string;
    ss >> value;
  }
}