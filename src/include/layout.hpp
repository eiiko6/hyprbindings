#ifndef LAYOUT_H
#define LAYOUT_H

#include <string>
#include <vector>

extern std::vector<std::vector<std::string>> layout;

void print_keyboard(const std::vector<std::string> &key_set);
bool is_assigned(const std::string &key,
                 const std::vector<std::string> &key_set);

#endif
