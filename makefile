CC=gcc
CXX=g++
CFLAGS=
CXXFLAGES=
LDFLAGES= -lglut -lGL -lGLU
CPPFLAGES=
RM=rm -rf
OUT=chess.app

all: build

build: main.o action.o chessboard.o menu.o mouse.o piece.o shapes.o text.o
	$(CXX) $(CXXFLAGES) main.cpp action.cpp chessboard.cpp menu.cpp mouse.cpp piece.cpp shapes.cpp text.cpp -o $(OUT) $(LDFLAGES)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

action.o: action.cpp action.h
	$(CXX) $(CXXFLAGES) -c action.cpp

chessboard.o: chessboard.cpp chessboard.h
	$(CXX) $(CXXFLAGES) -c chessboard.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGES) -c main.cpp $(LDFLAGES)

menu.o: menu.cpp menu.h
	$(CXX) $(CXXFLAGES) -c menu.cpp

mouse.o: mouse.cpp mouse.h
		$(CXX) $(CXXFLAGES) -c mouse.cpp

piece.o: piece.cpp piece.h
	$(CXX) $(CXXFLAGES) -c piece.cpp

shapes.o: shapes.cpp shapes.h
	$(CXX) $(CXXFLAGES) -c shapes.cpp

text.o: text.cpp text.h
	$(CXX) $(CXXFLAGES) -c text.cpp

clean:
	$(RM) *.o $(OUT)
