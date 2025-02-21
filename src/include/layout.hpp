#ifndef LAYOUT_HPP
#define LAYOUT_HPP

#include <string>
#include <vector>

void print_keyboard(const std::vector<std::string> &key_set);
bool is_assigned(const std::string &key,
                 const std::vector<std::string> &key_set);

#endif
