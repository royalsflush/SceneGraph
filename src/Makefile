CC = g++
CLIBS = -lm
DBG = -g

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut
endif

.PHONY: matTest glutTest

matTest: matTest.o
	$(CC) matTest.o $(DBG) -o out

glutTest: main.o engine.o openglrend.o
	$(CC) main.o engine.o openglrend.o -o out $(LIBS)

clean:
	rm *.o
	rm out


main.o: main.cpp engine.h
	$(CC) main.cpp -c

engine.o: engine.cpp engine.h
	$(CC) engine.cpp -c

matTest.o: matrix.h matTest.cpp
	$(CC) matTest.cpp -c $(DBG)

openglrend.o: openglrend.cpp openglrend.h renderer.h
	$(CC) openglrend.cpp -c
