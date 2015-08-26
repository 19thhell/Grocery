CXX=g++

all: test.cpp string.cpp
	$(CXX) test.cpp string.cpp -std=c++11
