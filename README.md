# HyprKeymap

HyprKeymap is a utility for displaying and managing keybindings in Hyprland configurations. It parses the keybinds from your Hyprland configuration files and visually displays them in a keyboard layout. You can also check if a specific key is assigned to any command.

## Installation

```sh
git clone https://github.com/eiiko6/hyprkeymap.git
cd hyprkeymap
sudo make clean install
```

---

## Usage

### Display Keyboard Layout

```sh
hyprkeymap layout
```

### Check Specific Key

```sh
hyprkeymap check <key>
```

Examples:

```sh
hyprkeymap check A
hyprkeymap check h
hyprkeymap check semicolon
```

---

## Configuration

List your config files in `~/.config/hyprkeymap/hyprkeymap.conf`.

Ensure your hyprland config already follows this format:

```conf
bind = $mainMod, A, your-command-here # Some description
bind = $mainMod SHIFT, SEMICOLON, another-command # Some other description
bind = $mainMod CONTROL, L, another-command # Some other description
```
