CXX := g++
CXXFLAGS := -std=c++14 -Wall -Wextra -O2 -MMD -MP -Wno-unused-parammeter 
INCLUDE := -Iinclude

SRC_DIRS := ./src
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%.cpp=%.o)
DEPS := $(SRCS:%.cpp=%.d)

DUNGEON := dungeon.exe

.PHONY: clean all

all: $(DUNGEON)

$(DUNGEON): $(OBJS)
	$(CXX) -o $@ $(CXXFLAGS) $^ 

%.o: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDE) $< -c 

clean:
	rm -f $(OBJS) $(DUNGEON) $(DEPS)

-include $(SRCS:%.cpp=%.d)