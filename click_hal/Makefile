# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2

# Target name
TARGET = click_hal

# Source files
SRCS = main.cpp ClickHal.cpp

# Object files (generated from the sources)
OBJS = $(SRCS:.cpp=.o)

# Default target to build
all: $(TARGET)

# Linking step: Link object files into the final executable
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJS) -o $(TARGET)
	@echo "Linking successful!"

# Compile each .cpp file into an object (.o) file
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Cleaned up object files and target executable."

