#include "../config.h"
#include <cstdlib> // For getenv
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Expand ~ to the user's home directory
string expand_tilde(const string &path) {
  if (path[0] == '~') {
    const char *home = getenv("HOME");
    if (home) {
      return string(home) + path.substr(1);
    }
  }
  return path;
}

// Function to check if a file exists
bool file_exists(const string &path) {
  ifstream file(path);
  return file.good();
}

// Get and combine all available config files
vector<string> get_config_files() {
  vector<string> config_files;
  bool any_file_found = false;

  for (const auto &path : config_paths) {
    string expanded_path = expand_tilde(path);

    if (file_exists(expanded_path)) {
      config_files.push_back(expanded_path);
      cout << "loaded " << expanded_path << endl;
      any_file_found = true;
    } else {
      cerr << "Error: Config file not found: " << expanded_path << endl;
    }
  }

  if (!any_file_found) {
    cerr << "Error: No configuration files found!" << endl;
    exit(1);
  }

  return config_files;
}
