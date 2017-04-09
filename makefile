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
	$(CXX) $(CXXFLAGS) main.cpp -o $(OUT) $(LDFLAGES) 
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp $(LDFLAGES)

clean:
	$(RM) *.o $(OUT)
