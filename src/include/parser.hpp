#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

std::vector<std::string> extract_assigned_keys(const std::string &config_file,
                                               const std::string &mod);
void extract_commands(const std::string &config_file, const std::string &mod,
                      const std::string &key);

#endif
