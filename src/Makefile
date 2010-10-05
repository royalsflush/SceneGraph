CC = g++
CFLAGS=-O2
LIBS = -lm
SRC= main.cpp engine.cpp openglrend.cpp scene.cpp camera.cpp	\
     transform.cpp group.cpp cube.cpp entity.cpp light.cpp	\
     sphere.cpp material.cpp

OUTPUT=out

OBJ=$(SRC:.cpp=.o)

#OBJS =  main.o engine.o openglrend.o scene.o camera.o transform.o group.o 
#OBJS += cube.o entity.o light.o sphere.o material.o

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
# DO NOT DELETE

main.o: /usr/include/stdio.h /usr/include/features.h
main.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
main.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
main.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
main.o: /usr/include/bits/typesizes.h /usr/include/libio.h
main.o: /usr/include/_G_config.h /usr/include/wchar.h
main.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
main.o: /usr/include/stdlib.h /usr/include/sys/types.h /usr/include/time.h
main.o: /usr/include/endian.h /usr/include/bits/endian.h
main.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
main.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
main.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
main.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
main.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
main.o: /usr/include/GL/gl.h /usr/include/GL/glext.h /usr/include/inttypes.h
main.o: /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/GL/glu.h
main.o: engine.h renderer.h openglrend.h scene.h group.h node.h camera.h
main.o: transform.h entity.h cube.h shape.h sphere.h light.h material.h
main.o: property.h appearance.h
engine.o: /usr/include/stdio.h /usr/include/features.h
engine.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
engine.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
engine.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
engine.o: /usr/include/bits/typesizes.h /usr/include/libio.h
engine.o: /usr/include/_G_config.h /usr/include/wchar.h
engine.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
engine.o: engine.h renderer.h scene.h group.h node.h
openglrend.o: /usr/include/stdio.h /usr/include/features.h
openglrend.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
openglrend.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
openglrend.o: /usr/include/gnu/stubs-64.h /usr/include/bits/types.h
openglrend.o: /usr/include/bits/typesizes.h /usr/include/libio.h
openglrend.o: /usr/include/_G_config.h /usr/include/wchar.h
openglrend.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
openglrend.o: /usr/include/stdlib.h /usr/include/sys/types.h
openglrend.o: /usr/include/time.h /usr/include/endian.h
openglrend.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
openglrend.o: /usr/include/sys/select.h /usr/include/bits/select.h
openglrend.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
openglrend.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
openglrend.o: /usr/include/alloca.h /usr/include/GL/glut.h
openglrend.o: /usr/include/GL/freeglut_std.h /usr/include/GL/gl.h
openglrend.o: /usr/include/GL/glext.h /usr/include/inttypes.h
openglrend.o: /usr/include/stdint.h /usr/include/bits/wchar.h
openglrend.o: /usr/include/GL/glu.h openglrend.h renderer.h
scene.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
scene.o: /usr/include/GL/gl.h /usr/include/GL/glext.h /usr/include/inttypes.h
scene.o: /usr/include/features.h /usr/include/bits/predefs.h
scene.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
scene.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
scene.o: /usr/include/stdint.h /usr/include/bits/wchar.h
scene.o: /usr/include/GL/glu.h /usr/include/stdlib.h /usr/include/sys/types.h
scene.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
scene.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
scene.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
scene.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
scene.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
scene.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h group.h
scene.o: node.h scene.h
camera.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
camera.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
camera.o: /usr/include/inttypes.h /usr/include/features.h
camera.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
camera.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
camera.o: /usr/include/gnu/stubs-64.h /usr/include/stdint.h
camera.o: /usr/include/bits/wchar.h /usr/include/GL/glu.h
camera.o: /usr/include/stdlib.h /usr/include/sys/types.h
camera.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
camera.o: /usr/include/time.h /usr/include/endian.h
camera.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
camera.o: /usr/include/sys/select.h /usr/include/bits/select.h
camera.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
camera.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
camera.o: /usr/include/alloca.h camera.h node.h
transform.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
transform.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
transform.o: /usr/include/inttypes.h /usr/include/features.h
transform.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
transform.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
transform.o: /usr/include/gnu/stubs-64.h /usr/include/stdint.h
transform.o: /usr/include/bits/wchar.h /usr/include/GL/glu.h
transform.o: /usr/include/stdlib.h /usr/include/sys/types.h
transform.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
transform.o: /usr/include/time.h /usr/include/endian.h
transform.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
transform.o: /usr/include/sys/select.h /usr/include/bits/select.h
transform.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
transform.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
transform.o: /usr/include/alloca.h transform.h group.h node.h
group.o: group.h node.h
cube.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
cube.o: /usr/include/GL/gl.h /usr/include/GL/glext.h /usr/include/inttypes.h
cube.o: /usr/include/features.h /usr/include/bits/predefs.h
cube.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
cube.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
cube.o: /usr/include/stdint.h /usr/include/bits/wchar.h /usr/include/GL/glu.h
cube.o: /usr/include/stdlib.h /usr/include/sys/types.h
cube.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
cube.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
cube.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
cube.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
cube.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
cube.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h cube.h shape.h
entity.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
entity.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
entity.o: /usr/include/inttypes.h /usr/include/features.h
entity.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
entity.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
entity.o: /usr/include/gnu/stubs-64.h /usr/include/stdint.h
entity.o: /usr/include/bits/wchar.h /usr/include/GL/glu.h
entity.o: /usr/include/stdlib.h /usr/include/sys/types.h
entity.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
entity.o: /usr/include/time.h /usr/include/endian.h
entity.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
entity.o: /usr/include/sys/select.h /usr/include/bits/select.h
entity.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
entity.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
entity.o: /usr/include/alloca.h entity.h node.h shape.h appearance.h
entity.o: property.h
light.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
light.o: /usr/include/GL/gl.h /usr/include/GL/glext.h /usr/include/inttypes.h
light.o: /usr/include/features.h /usr/include/bits/predefs.h
light.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
light.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
light.o: /usr/include/stdint.h /usr/include/bits/wchar.h
light.o: /usr/include/GL/glu.h /usr/include/stdlib.h /usr/include/sys/types.h
light.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
light.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
light.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
light.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
light.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
light.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h light.h
light.o: node.h
sphere.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
sphere.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
sphere.o: /usr/include/inttypes.h /usr/include/features.h
sphere.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
sphere.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
sphere.o: /usr/include/gnu/stubs-64.h /usr/include/stdint.h
sphere.o: /usr/include/bits/wchar.h /usr/include/GL/glu.h
sphere.o: /usr/include/stdlib.h /usr/include/sys/types.h
sphere.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
sphere.o: /usr/include/time.h /usr/include/endian.h
sphere.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
sphere.o: /usr/include/sys/select.h /usr/include/bits/select.h
sphere.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
sphere.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
sphere.o: /usr/include/alloca.h sphere.h shape.h
material.o: /usr/include/GL/glut.h /usr/include/GL/freeglut_std.h
material.o: /usr/include/GL/gl.h /usr/include/GL/glext.h
material.o: /usr/include/inttypes.h /usr/include/features.h
material.o: /usr/include/bits/predefs.h /usr/include/sys/cdefs.h
material.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
material.o: /usr/include/gnu/stubs-64.h /usr/include/stdint.h
material.o: /usr/include/bits/wchar.h /usr/include/GL/glu.h
material.o: /usr/include/stdlib.h /usr/include/sys/types.h
material.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
material.o: /usr/include/time.h /usr/include/endian.h
material.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
material.o: /usr/include/sys/select.h /usr/include/bits/select.h
material.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
material.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
material.o: /usr/include/alloca.h property.h appearance.h material.h
