#include "include/layout.hpp"
#include "../config.h"
#include <algorithm>
#include <iostream>

using namespace std;

// Keyboard layout definition
vector<vector<string>> layout = {
    {"ESC", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11",
     "F12"},
    {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE"},
    {"TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "|"},
    {"CAPS", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "ENTER"},
    {"SHIFT", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "SHIFT"},
    {"CTRL", "ALT", "SPACE", "ALT", "CTRL"},
    {"LEFT", "UP", "DOWN", "RIGHT"}};

bool is_assigned(const string &key, const vector<string> &key_set) {
  return find(key_set.begin(), key_set.end(), key) != key_set.end();
}

void print_keyboard(const vector<string> &key_set) {
  for (const auto &row : layout) {
    for (const auto &key : row) {
      if (is_assigned(key, key_set)) {
        cout << BLUE << key << RESET << "  ";
      } else {
        cout << RED << key << RESET << "  ";
      }
    }
    cout << endl;
  }
}
