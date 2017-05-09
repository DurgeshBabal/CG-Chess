CC=gcc
CXX=g++-5 -std=c++11
CFLAGS=
CXXFLAGES=
LDFLAGES= -lglut -lGL -lGLU
CPPFLAGES=
RM=rm -rf
OUT=chess.app

all: build

build: main.o chessboard.o menu.o piece.o shapes.o text.o
	$(CXX) $(CXXFLAGES) main.cpp chessboard.cpp menu.cpp piece.cpp shapes.cpp text.cpp -o $(OUT) $(LDFLAGES)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

chessboard.o: chessboard.cpp chessboard.h
	$(CXX) $(CXXFLAGES) -c chessboard.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGES) -c main.cpp $(LDFLAGES)

menu.o: menu.cpp menu.h
	$(CXX) $(CXXFLAGES) -c menu.cpp

piece.o: piece.cpp piece.h
	$(CXX) $(CXXFLAGES) -c piece.cpp

shapes.o: shapes.cpp shapes.h
	$(CXX) $(CXXFLAGES) -c shapes.cpp

text.o: text.cpp text.h
	$(CXX) $(CXXFLAGES) -c text.cpp

clean:
	$(RM) *.o $(OUT)
