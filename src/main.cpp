#include "include/layout.hpp"
#include "include/parser.hpp"
#include "include/utils.hpp"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void usage(const string &programName) {
  cout << "Usage:\n";
  cout << "  " << programName << " layout\n";
  cout << "  " << programName << " check <key>\n";
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    usage(argv[0]);
  }

  string command = argv[1];

  if (command == "layout") {
    vector<string> config_files = get_config_files();

    vector<string> all_super_keys;
    vector<string> all_super_shift_keys;
    vector<string> all_super_control_keys;

    for (const auto &config_file : config_files) {
      auto super_keys = extract_assigned_keys(config_file, "");
      auto super_shift_keys = extract_assigned_keys(config_file, " SHIFT");
      auto super_control_keys = extract_assigned_keys(config_file, " CONTROL");

      all_super_keys.insert(all_super_keys.end(), super_keys.begin(),
                            super_keys.end());
      all_super_shift_keys.insert(all_super_shift_keys.end(),
                                  super_shift_keys.begin(),
                                  super_shift_keys.end());
      all_super_control_keys.insert(all_super_control_keys.end(),
                                    super_control_keys.begin(),
                                    super_control_keys.end());
    }

    cout << "\n\t<---  Super Keys  --->" << endl;
    print_keyboard(all_super_keys);

    cout << "\n\t<---  Super + Shift Keys  --->" << endl;
    print_keyboard(all_super_shift_keys);

    cout << "\n\t<---  Super + Control Keys  --->" << endl;
    print_keyboard(all_super_control_keys);

  } else if (command == "check") {
    if (argc != 3) {
      usage(argv[0]);
    }

    vector<string> config_files = get_config_files();

    // Format the key for consistency
    string key = argv[2];
    transform(key.begin(), key.end(), key.begin(),
              ::toupper); // Make it uppercase

    // For each config file, check the relevant sections and print only if there
    // are commands
    for (const auto &config_file : config_files) {
      // Extract and print relevant commands only if the key is assigned
      vector<string> super_commands = extract_commands("", key, config_file);
      vector<string> super_shift_commands =
          extract_commands(" SHIFT", key, config_file);
      vector<string> super_control_commands =
          extract_commands(" CONTROL", key, config_file);

      // Print the results if any commands exist for the key
      if (!super_commands.empty()) {
        cout << "super commands:" << endl;
        for (vector<string>::iterator it = super_commands.begin();
             it != super_commands.end(); ++it) {
          cout << *it << endl;
        }
      }

      if (!super_shift_commands.empty()) {
        cout << "super+shift commands:" << endl;
        for (vector<string>::iterator it = super_shift_commands.begin();
             it != super_shift_commands.end(); ++it) {
          cout << *it << endl;
        }
      }

      if (!super_control_commands.empty()) {
        cout << "super+control commands:" << endl;
        for (vector<string>::iterator it = super_control_commands.begin();
             it != super_control_commands.end(); ++it) {
          cout << *it << endl;
        }
      }
    }
  } else {
    usage(argv[0]);
  }

  return 0;
}
