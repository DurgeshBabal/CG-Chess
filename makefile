CC=g++
CFLAGS=
LIBS= -lglut -lGL -lGLU
RM=rm -rf
OUT=chess

all: build

build: main.o
	$(CC) $(CFLAGS) main.cpp -o $(OUT)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp $(LIBS)

clean:
	$(RM) *.o $(OUT)
