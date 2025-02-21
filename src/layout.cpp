#include "include/layout.hpp"
#include "../config.h"
#include "include/parser.hpp"
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

bool is_assigned(const string &key, const vector<string> &key_set) {
  return find(key_set.begin(), key_set.end(), key) != key_set.end();
}

void print_keyboard(const vector<string> &key_set) {
  for (const auto &row : layout) {
    for (const auto &key : row) {
      if (key == string{""})
        continue;

      unordered_map<string, string>::const_iterator it =
          backend_to_visual.find(key);

      if (is_assigned(key, key_set)) {
        cout << BLUE << (it == backend_to_visual.end() ? key : it->second)
             << RESET << "  ";
      } else {
        cout << RED << (it == backend_to_visual.end() ? key : it->second)
             << RESET << "  ";
      }
    }
    cout << endl;
  }
}
