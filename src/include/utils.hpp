#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>

using namespace std;

// Function to check if a file exists
bool file_exists(const string &path);

// Get and combine all available config files
vector<string> get_config_files();

#endif
