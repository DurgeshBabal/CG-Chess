CC=gcc
CXX=g++
CFLAGS=
CXXFLAGES=
LDFLAGES= -lglut -lGL -lGLU
CPPFLAGES=
RM=rm -rf
OUT=chess.app

all: build

build: main.o chessboard.o event.o gameplay.o menu.o mouse.o move.o moveset.o piece.o shapes.o text.o
	$(CXX) $(CXXFLAGES) main.cpp event.cpp chessboard.cpp gameplay.cpp menu.cpp mouse.cpp move.cpp moveset.o piece.cpp shapes.cpp text.cpp -o $(OUT) $(LDFLAGES)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

chessboard.o: chessboard.cpp chessboard.h
	$(CXX) $(CXXFLAGES) -c chessboard.cpp

event.o: event.cpp event.h
	$(CXX) $(CXXFLAGES) -c event.cpp

gameplay.o: gameplay.cpp gameplay.h
	$(CXX) $(CXXFLAGES) -c gameplay.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGES) -c main.cpp $(LDFLAGES)

menu.o: menu.cpp menu.h
	$(CXX) $(CXXFLAGES) -c menu.cpp

mouse.o: mouse.cpp mouse.h
		$(CXX) $(CXXFLAGES) -c mouse.cpp

move.o: move.cpp move.h
	$(CXX) $(CXXFLAGES) -c move.cpp

moveset.o: moveset.cpp moveset.h
	$(CXX) $(CXXFLAGES) -c moveset.cpp

piece.o: piece.cpp piece.h
	$(CXX) $(CXXFLAGES) -c piece.cpp

shapes.o: shapes.cpp shapes.h
	$(CXX) $(CXXFLAGES) -c shapes.cpp

text.o: text.cpp text.h
	$(CXX) $(CXXFLAGES) -c text.cpp

clean:
	$(RM) *.o $(OUT)
