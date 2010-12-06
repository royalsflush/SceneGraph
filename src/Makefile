CC = g++
CFLAGS= #-O2
LIBS = -lm
SRC= main.cpp node.cpp engine.cpp scene.cpp camera.cpp	\
     transform.cpp group.cpp cube.cpp entity.cpp light.cpp	\
     sphere.cpp material.cpp manipulator.cpp testScenes.cpp \
     switch.cpp mesh.cpp environ.cpp matrix.cpp texture.cpp \
     imageloader.cpp fpview.cpp animation.cpp 
  
OUTPUT=out

OBJ=$(SRC:.cpp=.o)

CFLAGS+=-g
DBGFLAGS = -D_FPVIEW #-D_DBG

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
	$(CC) $(CFLAGS) $(LIBS) $(DBGFLAGS) -o $(OUTPUT) $^

.cpp.o:
	$(CC) $(CFLAGS) $(DBGFLAGS) -c -o $@ $<

depend:
	makedepend -- $(CFLAGS) -- $(SRC)

# DO NOT DELETE THIS LINE

main.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
main.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
main.o: /usr/include/secure/_common.h /usr/include/stdlib.h
main.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
main.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
main.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
main.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
main.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
main.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
main.o: /usr/include/libkern/_OSByteOrder.h
main.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/machine/types.h /usr/include/i386/types.h engine.h
main.o: animation.h testScenes.h
node.o: /usr/include/stdlib.h /usr/include/Availability.h
node.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
node.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
node.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
node.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
node.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
node.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
node.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
node.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
node.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
node.o: /usr/include/libkern/_OSByteOrder.h
node.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
node.o: /usr/include/machine/types.h /usr/include/i386/types.h node.h
engine.o: /usr/include/stdio.h /usr/include/_types.h
engine.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
engine.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
engine.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h engine.h
engine.o: scene.h group.h node.h environ.h animation.h
scene.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
scene.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
scene.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
scene.o: /usr/include/secure/_common.h group.h node.h scene.h environ.h
scene.o: camera.h camMan.h animation.h
camera.o: /usr/include/stdio.h /usr/include/_types.h
camera.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
camera.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
camera.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h camera.h
camera.o: node.h camMan.h
transform.o: /usr/include/stdio.h /usr/include/_types.h
transform.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
transform.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
transform.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
transform.o: /usr/include/assert.h transform.h group.h node.h matrix.h
transform.o: /usr/include/stdarg.h
group.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
group.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
group.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
group.o: /usr/include/secure/_common.h group.h node.h
cube.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
cube.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
cube.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
cube.o: /usr/include/secure/_common.h cube.h shape.h
entity.o: entity.h node.h shape.h appearance.h property.h
light.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
light.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
light.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
light.o: /usr/include/secure/_common.h light.h node.h switch.h
sphere.o: /usr/include/stdio.h /usr/include/_types.h
sphere.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
sphere.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
sphere.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h sphere.h
sphere.o: shape.h
material.o: /usr/include/stdio.h /usr/include/_types.h
material.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
material.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
material.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
material.o: property.h appearance.h material.h
manipulator.o: manipulator.h camMan.h vector.h /usr/include/stdio.h
manipulator.o: /usr/include/_types.h /usr/include/sys/_types.h
manipulator.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
manipulator.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
manipulator.o: /usr/include/secure/_common.h /usr/include/math.h
manipulator.o: /usr/include/architecture/i386/math.h /usr/include/stdlib.h
manipulator.o: /usr/include/Availability.h
manipulator.o: /usr/include/AvailabilityInternal.h /usr/include/sys/wait.h
manipulator.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
manipulator.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
manipulator.o: /usr/include/i386/_structs.h /usr/include/sys/_structs.h
manipulator.o: /usr/include/machine/_structs.h /usr/include/sys/resource.h
manipulator.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
manipulator.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
manipulator.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
manipulator.o: /usr/include/machine/types.h /usr/include/i386/types.h
testScenes.o: testScenes.h engine.h animation.h scene.h group.h node.h
testScenes.o: environ.h camera.h camMan.h transform.h matrix.h
testScenes.o: /usr/include/stdarg.h /usr/include/assert.h
testScenes.o: /usr/include/sys/cdefs.h /usr/include/stdio.h
testScenes.o: /usr/include/_types.h /usr/include/sys/_types.h
testScenes.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
testScenes.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
testScenes.o: light.h switch.h manipulator.h fpview.h entity.h sphere.h
testScenes.o: shape.h cube.h mesh.h texture.h appearance.h property.h
testScenes.o: material.h
switch.o: /usr/include/stdlib.h /usr/include/Availability.h
switch.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
switch.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
switch.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
switch.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
switch.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
switch.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
switch.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
switch.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
switch.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
switch.o: /usr/include/libkern/_OSByteOrder.h
switch.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
switch.o: /usr/include/machine/types.h /usr/include/i386/types.h
switch.o: /usr/include/stdio.h /usr/include/secure/_stdio.h
switch.o: /usr/include/secure/_common.h switch.h
mesh.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
mesh.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
mesh.o: /usr/include/i386/_types.h /usr/include/secure/_stdio.h
mesh.o: /usr/include/secure/_common.h /usr/include/stdlib.h
mesh.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
mesh.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
mesh.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
mesh.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
mesh.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
mesh.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
mesh.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
mesh.o: /usr/include/libkern/_OSByteOrder.h
mesh.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
mesh.o: /usr/include/machine/types.h /usr/include/i386/types.h mesh.h shape.h
environ.o: /usr/include/stdio.h /usr/include/_types.h
environ.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
environ.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
environ.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
environ.o: /usr/include/stdlib.h /usr/include/Availability.h
environ.o: /usr/include/AvailabilityInternal.h /usr/include/sys/wait.h
environ.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
environ.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
environ.o: /usr/include/i386/_structs.h /usr/include/sys/_structs.h
environ.o: /usr/include/machine/_structs.h /usr/include/sys/resource.h
environ.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
environ.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
environ.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
environ.o: /usr/include/machine/types.h /usr/include/i386/types.h environ.h
matrix.o: /usr/include/assert.h /usr/include/sys/cdefs.h
matrix.o: /usr/include/stdarg.h matrix.h /usr/include/stdio.h
matrix.o: /usr/include/_types.h /usr/include/sys/_types.h
matrix.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
matrix.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
texture.o: /usr/include/stdio.h /usr/include/_types.h
texture.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
texture.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
texture.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
texture.o: /usr/include/stdlib.h /usr/include/Availability.h
texture.o: /usr/include/AvailabilityInternal.h /usr/include/sys/wait.h
texture.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
texture.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
texture.o: /usr/include/i386/_structs.h /usr/include/sys/_structs.h
texture.o: /usr/include/machine/_structs.h /usr/include/sys/resource.h
texture.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
texture.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
texture.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
texture.o: /usr/include/machine/types.h /usr/include/i386/types.h
texture.o: appearance.h property.h texture.h imageloader.h
imageloader.o: /usr/include/assert.h /usr/include/sys/cdefs.h imageloader.h
fpview.o: /usr/include/math.h /usr/include/architecture/i386/math.h
fpview.o: /usr/include/sys/cdefs.h /usr/include/stdlib.h
fpview.o: /usr/include/Availability.h /usr/include/AvailabilityInternal.h
fpview.o: /usr/include/_types.h /usr/include/sys/_types.h
fpview.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
fpview.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
fpview.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
fpview.o: /usr/include/i386/signal.h /usr/include/i386/_structs.h
fpview.o: /usr/include/sys/_structs.h /usr/include/machine/_structs.h
fpview.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
fpview.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
fpview.o: /usr/include/libkern/_OSByteOrder.h
fpview.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
fpview.o: /usr/include/machine/types.h /usr/include/i386/types.h
fpview.o: /usr/include/stdio.h /usr/include/secure/_stdio.h
fpview.o: /usr/include/secure/_common.h fpview.h camMan.h matrix.h
fpview.o: /usr/include/stdarg.h /usr/include/assert.h
animation.o: /usr/include/stdio.h /usr/include/_types.h
animation.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
animation.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
animation.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
animation.o: animation.h transform.h group.h node.h matrix.h
animation.o: /usr/include/stdarg.h /usr/include/assert.h scene.h environ.h
