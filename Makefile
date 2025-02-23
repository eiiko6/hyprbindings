# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I src/include
BUILD_DIR = build
SRC_DIR = src
INSTALL_DIR = /usr/local/bin

# Automatically find all source files and generate corresponding object files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Final executable
TARGET = $(BUILD_DIR)/hyprkeymap

# Default target
all: $(TARGET)

# Linking rule
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule
clean:
	rm -rf $(BUILD_DIR)

# Install rule
install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_DIR)"
	install -m 755 $(TARGET) $(INSTALL_DIR)

# Uninstall rule
uninstall:
	@echo "Removing $(INSTALL_DIR)/my_program"
	rm -f $(INSTALL_DIR)/my_program

# Phony targets
.PHONY: all clean install uninstall
