#ifndef CONFIG_H
#define CONFIG_H

#include <array>

constexpr auto CONFIG_FILE_DIR = "~/.config/hyprkeymap/";
constexpr auto CONFIG_FILE = "~/.config/hyprkeymap/hyprkeymap.conf";

// Text colors
constexpr auto RESET = "\033[0m";
constexpr auto BLUE = "\033[34m";
constexpr auto RED = "\033[31m";

// Layout
constexpr std::array<std::array<const char *, 14>, 7> layout = {
    {{"ESC", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11",
      "F12", ""},
     {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "BACKSPACE",
      ""},
     {"TAB", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "|"},
     {"CAPS", "A", "S", "D", "F", "G", "H", "J", "K", "L", "SEMICOLON", "'",
      "ENTER", ""},
     {"SHIFT", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "SHIFT", "",
      ""},
     {"CTRL", "ALT", "", "SPACE", "", "ALT", "CTRL", "", "", "", "", "", "",
      ""},
     {"", "LEFT", "UP", "DOWN", "RIGHT", "", "", "", "", "", "", "", "", ""}}};

#endif
