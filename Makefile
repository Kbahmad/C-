CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

SRCS = Long.cpp pi.cpp test.cpp

OBJS = $(SRCS:.cpp=.o)

EXEC_PI = pi
EXEC_TEST = test

all: $(EXEC_PI) $(EXEC_TEST)

$(EXEC_PI): Long.o pi.o
	$(CXX) $(CXXFLAGS) -o $(EXEC_PI) Long.o pi.o

$(EXEC_TEST): Long.o test.o
	$(CXX) $(CXXFLAGS) -o $(EXEC_TEST) Long.o test.o

%.o: %.cpp Long.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC_PI) $(EXEC_TEST)

.PHONY: all clean