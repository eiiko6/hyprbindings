#include "include/layout.hpp"
#include "../config.h"
#include <algorithm>
#include <iostream>

using namespace std;

bool is_assigned(const string &key, const vector<string> &key_set) {
  return find(key_set.begin(), key_set.end(), key) != key_set.end();
}

void print_keyboard(const vector<string> &key_set) {
  for (const auto &row : layout) {
    for (const auto &key : row) {
      if (key == string{""})
        continue;
      if (is_assigned(key, key_set)) {
        cout << BLUE << key << RESET << "  ";
      } else {
        cout << RED << key << RESET << "  ";
      }
    }
    cout << endl;
  }
}
