#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "cube.h"

Cube::Cube(float x, float y, float z) : dimX(x), dimY(y), dimZ(z) { }

void Cube::draw()
{
	#ifdef _DBG
		printf("Drawing Cube\n");
	#endif

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(this->dimX, this->dimY, this->dimZ);
	glutSolidCube(1.0);
	glPopMatrix();
}
