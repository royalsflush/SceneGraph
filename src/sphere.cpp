#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "sphere.h"

Sphere::Sphere(float r) : radius(r) { }

void Sphere::draw()
{
	#ifdef _DBG
		printf("Drawing sphere\n");
	#endif

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glScalef(this->radius, this->radius, this->radius);
	glutSolidSphere(1.0f, 64, 64);
	glPopMatrix();
}
