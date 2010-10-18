CC = g++
CFLAGS=-O2
LIBS = -lm
SRC= main.cpp engine.cpp scene.cpp camera.cpp	\
     transform.cpp group.cpp cube.cpp entity.cpp light.cpp	\
     sphere.cpp material.cpp manipulator.cpp testScenes.cpp \
     switch.cpp mesh.cpp environ.cpp matrix.cpp 
  
OUTPUT=out

OBJ=$(SRC:.cpp=.o)

CFLAGS+=-g

ifeq ($(shell uname),Darwin)
	LIBS+= -framework OpenGL -framework GLUT
else
	LIBS+= -lglut -lGLU
endif

.PHONY: matTest glutTest

all: gs

matTest: matrix.h matTest.cpp
	$(CC) $(CFLAGS) matTest.cpp -o out $(LIBS)

clean:
	rm $(OBJ)
	rm $(OUTPUT)

gs: $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -D_DBG -o $(OUTPUT) $^

.cpp.o:
	$(CC) $(CFLAGS) -D_DBG -c -o $@ $<

depend:
	makedepend -- $(CFLAGS) -- $(SRC)

# DO NOT DELETE THIS LINE
