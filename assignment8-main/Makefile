CC = g++	# use g++ for compiling c++ code
CFLAGS = -g -Wall -std=c++17	# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.

all: prog8
SRCS = graph.cpp main.cpp 
DEPS = $(SRCS:.cpp=.d)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

prog8: main.o graph.o
	$(CC) graph.o main.o -o prog8
	
clean:
	rm *.o prog8
