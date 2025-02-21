#include "include/layout.hpp"
#include "include/parser.hpp"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void usage(const string &programName) {
  cout << "Usage:\n";
  cout << "  " << programName << " layout <path-to-config-file>\n";
  cout << "  " << programName << " check <path-to-config-file> <key>\n";
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    usage(argv[0]);
  }

  string command = argv[1];
  string config_file = argv[2];

  if (command == "layout") {
    auto super_keys = extract_assigned_keys(config_file, "");
    auto super_shift_keys = extract_assigned_keys(config_file, " SHIFT");
    auto super_control_keys = extract_assigned_keys(config_file, " CONTROL");

    cout << "\n\t<---  Super Keys  --->" << endl;
    print_keyboard(super_keys);

    cout << "\n\t<---  Super + Shift Keys  --->" << endl;
    print_keyboard(super_shift_keys);

    cout << "\n\t<---  Super + Control Keys  --->" << endl;
    print_keyboard(super_control_keys);

  } else if (command == "check") {
    if (argc != 4) {
      usage(argv[0]);
    }

    string key = argv[3];
    transform(key.begin(), key.end(), key.begin(), ::toupper);

    cout << "super commands:" << endl;
    extract_commands(config_file, "", key);

    cout << "\nsuper + shift commands:" << endl;
    extract_commands(config_file, " SHIFT", key);

    cout << "\nsuper + control commands:" << endl;
    extract_commands(config_file, " CONTROL", key);

  } else {
    usage(argv[0]);
  }

  return 0;
}
