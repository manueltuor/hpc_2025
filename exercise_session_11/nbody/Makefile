CXX = g++

nbody: nbody.cpp Makefile
	$(CXX) -O3 -march=native -ffast-math -fopt-info-vec -g -o nbody nbody.cpp

clean:
	rm -f nbody nbody1 nbody2 nbody3
