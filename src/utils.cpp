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

// Function to create default config file
void create_default_config() {
  system(("mkdir -p " + expand_tilde(CONFIG_FILE_DIR)).c_str());
  ofstream config_file(expand_tilde(CONFIG_FILE));
  config_file << "~/.config/hypr/hyprland.conf" << endl;
  config_file << "~/.config/hypr/bindings.conf" << endl;
  config_file.close();
  cout << "Default config file created at: " << CONFIG_FILE << endl;
}

// Get and combine all available config files
vector<string> get_config_files() {
  vector<string> config_files;
  string config_path = expand_tilde(CONFIG_FILE);

  if (!file_exists(config_path)) {
    cerr << "Config file not found. Creating default one." << endl;
    create_default_config();
  }

  ifstream config_file(config_path);
  string line;
  bool any_file_found = false;

  while (getline(config_file, line)) {
    string expanded_path = expand_tilde(line);

    if (file_exists(expanded_path)) {
      config_files.push_back(expanded_path);
      cout << "Loaded " << expanded_path << endl;
      any_file_found = true;
    } else {
      cerr << "Error: Config file not found: " << expanded_path << endl;
    }
  }
  config_file.close();

  if (!any_file_found) {
    cerr << "Error: No configuration files found!" << endl;
    exit(1);
  }

  return config_files;
}
