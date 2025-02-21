#include "include/parser.hpp"
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

vector<string> extract_assigned_keys(const string &config_file,
                                     const string &mod) {
  vector<string> keys;
  ifstream file(config_file);
  string line;
  regex pattern("^bind = \\$mainMod" + mod + ", (\\w+)");
  smatch matches;

  while (getline(file, line)) {
    if (regex_search(line, matches, pattern)) {
      keys.push_back(matches[1]);
    }
  }
  file.close();
  return keys;
}

vector<string> extract_commands(const string &mod, const string &key,
                                const string &config_file) {
  vector<string> commands;
  ifstream file(config_file);
  string line;
  regex pattern("^bind = \\$mainMod" + mod + ", " + key + ", (.+)");
  smatch matches;

  while (getline(file, line)) {
    if (regex_search(line, matches, pattern)) {
      commands.push_back(matches[1]);
    }
  }
  file.close();

  return commands;
}
