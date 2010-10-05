CC = g++
CFLAGS=-O2
LIBS = -lm
SRC= main.cpp engine.cpp scene.cpp camera.cpp	\
     transform.cpp group.cpp cube.cpp entity.cpp light.cpp	\
     sphere.cpp material.cpp

OUTPUT=out

OBJ=$(SRC:.cpp=.o)

CFLAGS+=$(DEBUG)

ifeq ($(shell uname),Darwin)
	LIBS+= -framework OpenGL -framework GLUT
else
	LIBS+= -lglut -lGLU
endif

.PHONY: matTest glutTest

all: gs

clean:
	rm $(OBJ)
	rm $(OUTPUT)

gs: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $(OUTPUT) $^

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $<

depend:
	makedepend -- $(CFLAGS) -- $(SRC)

# DO NOT DELETE THIS LINE
