CXX=g++
CXXFLAGS=-std=c++11 -Wall -O3
LDFLAGS=
SRC_DIR=../src
TEST_DIR=.

# Name of the executable
EXEC=run_tests

# Source files
SOURCES=$(SRC_DIR)/event.cpp $(SRC_DIR)/eventmanager.cpp $(SRC_DIR)/tourmanager.cpp $(TEST_DIR)/catch2Tests.cpp

# Object files
OBJECTS=$(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)

.PHONY: all clean
