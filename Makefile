CXX=g++

all: test.cpp string.cpp primer.cpp
	$(CXX) test.cpp string.cpp primer.cpp -std=c++11
