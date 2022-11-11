CFLAGS = -std=c++17 -O2
LDFLAGS = -lSDL2 -lSDL2main -lglut -lGL -lpthread -lGLU -lGLEW -ldl

GLTest: main.cpp
	g++ $(CFLAGS) -o GLTest main.cpp Screen.cpp Input.cpp glad.c $(LDFLAGS)

.PHONY: test clean

test: GLTest
	./GLTest

clean:
	rm -f GLTest
