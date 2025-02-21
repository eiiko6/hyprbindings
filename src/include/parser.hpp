#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <unordered_map>
#include <vector>

// Backend keys to visual keys
const std::unordered_map<std::string, std::string> backend_to_visual = {
    {"SEMICOLON", ";"}, {"BACKSPACE", "󰁮"}, {"ENTER", "󰌑"},
    {"TAB", "TAB"},     {"SPACE", "󱁐"},     {"LEFT", ""},
    {"UP", ""},      {"DOWN", ""},       {"RIGHT", ""},
};

std::vector<std::string> extract_assigned_keys(const std::string &config_file,
                                               const std::string &mod);
std::vector<std::string> extract_commands(const std::string &mod,
                                          const std::string &key,
                                          const std::string &config_file);

#endif
