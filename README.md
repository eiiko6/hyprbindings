# HyprBindings

HyprBindings is a utility for displaying keybindings in Hyprland configurations. It parses the keybinds from your Hyprland configuration files and visually displays them in a keyboard layout. You can also check if a specific key is assigned to any command.

## Installation

```sh
git clone https://github.com/eiiko6/hyprbindings.git
cd hyprbindings
sudo make clean install
```

---

## Usage

### Display Keyboard Layout

```sh
hyprbindings layout
```

### Check Specific Key

```sh
hyprbindings check <key>
```

Examples:

```sh
hyprbindings check A
hyprbindings check h
hyprbindings check semicolon
```

---

## Configuration

List your config files in `~/.config/hyprbindings/hyprbindings.conf`.

Ensure your hyprland config already follows this format:

```conf
bind = $mainMod, A, your-command-here # Some description
bind = $mainMod SHIFT, SEMICOLON, another-command # Some other description
bind = $mainMod CONTROL, L, another-command # Some other description
```
