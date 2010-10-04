CC = g++
CLIBS = -lm
DBG = -g
OBJS =  main.o engine.o openglrend.o scene.o camera.o transform.o group.o 
OBJS += cube.o entity.o light.o sphere.o material.o
 

ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
	LIBS = -lglut
endif

.PHONY: matTest glutTest

matTest: matTest.o
	$(CC) matTest.o $(DBG) -o out

glutTest: $(OBJS)
	$(CC) $(OBJS) -o out $(LIBS)

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

scene.o: scene.cpp scene.h node.h
	$(CC) scene.cpp -c

camera.o: scene.h camera.h node.h camera.cpp
	$(CC) camera.cpp -c

group.o: group.h group.cpp node.h
	$(CC) group.cpp -c

transform.o: transform.h transform.cpp
	$(CC) transform.cpp -c

entity.o: entity.h node.h entity.cpp
	$(CC) entity.cpp -c

cube.o: cube.h shape.h cube.cpp
	$(CC) cube.cpp -c

light.o: light.h node.h light.cpp
	$(CC) light.cpp -c

sphere.o: sphere.h shape.h sphere.cpp
	$(CC) sphere.cpp -c

material.o: material.cpp material.h appearance.h property.h
	$(CC) material.cpp -c
