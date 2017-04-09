CC=g++
CXX=g++
CFLAGS=
CXXFLAGES=
LDFLAGES= -lglut -lGL -lGLU
CPPFLAGES=
RM=rm -rf
OUT=chess.app

all: build

build: main.o
	$(CXX) $(CXXFLAGS) main.cpp shapes.cpp -o $(OUT) $(LDFLAGES)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp $(LDFLAGES)

shapes.o: shapes.cpp shapes.h
	$(CXX) $(CXXFLAGS) -c shapes.cpp

clean:
	$(RM) *.o $(OUT)
