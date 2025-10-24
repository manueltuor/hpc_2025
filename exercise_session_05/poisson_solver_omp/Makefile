CXX = g++     
CXXFLAGS = -O3 -ffast-math -mavx2 -fopenmp
LDFLAGS = -fopenmp

OBJS = init.o io.o jacobi.o

all: main

init.o: init.cpp init.h
	$(CXX) $(CXXFLAGS) -c init.cpp -o init.o

io.o: io.cpp io.h
	$(CXX) $(CXXFLAGS) -c io.cpp -o io.o

jacobi.o: jacobi.cpp jacobi.h
	$(CXX) $(CXXFLAGS) -c jacobi.cpp -o jacobi.o

main: $(OBJS) main.cpp
	$(CXX) $(CXXFLAGS) -o main main.cpp $(OBJS) $(LDFLAGS)

clean:
	rm -f main init.o io.o jacobi.o
