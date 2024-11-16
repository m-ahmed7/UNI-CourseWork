# Makefile for Wembley Management System

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Isrc

# Target executable
TARGET = WembleyManagementSystem

# Source files here
SOURCES = src/admin.cpp \
          src/adminmanager.cpp \
          src/event.cpp \
          src/eventmanager.cpp \
          src/main.cpp \
          src/ticket.cpp \
          src/ticketmanager.cpp \
          src/tour.cpp \
          src/tourmanager.cpp \
          src/User.cpp \
          src/usermanager.cpp

# Corresponding header files
HEADERS = src/admin.hpp \
          src/adminmanager.hpp \
          src/event.hpp \
          src/eventmanager.hpp \
          src/ticket.hpp \
          src/ticketmanager.hpp \
          src/tour.hpp \
          src/tourmanager.hpp \
          src/User.h \
          src/user.hpp \
          src/usermanager.hpp

# Object files based on source files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Link the target with all objects
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile every source file to an object
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJECTS)

# Phony targets
.PHONY: all clean
