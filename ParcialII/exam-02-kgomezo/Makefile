CXX=g++
CXXFLAGS=-std=c++17 -fsanitize=undefined -fsanitize=signed-integer-overflow -fsanitize=address -g

all : quaternion.x reactors.x
%.x : %.cpp
	$(CXX)  $(CXXFLAGS) $< -o $@

clean:
	rm -rf *.x a.out *.x.* *txt
