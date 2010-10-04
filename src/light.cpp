#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "light.h"

enum
{
	X=0, Y, Z, W
};

enum
{
	R=0, G, B, A
};

Light::Light(float x, float y, float z, float w) 
{
	pos[X]=x;
	pos[Y]=y;
	pos[Z]=z;
	pos[W]=w;	
}

void Light::setSpecular(float r, float g, float b, float a)
{
	spec[R]=r;
	spec[G]=g;
	spec[B]=b;
	spec[A]=a;
}

void Light::setAmbient(float r, float g, float b, float a)
{
	amb[R]=r;
	amb[G]=g;
	amb[B]=b;
	amb[A]=a;
}

void Light::setDiffuse(float r, float g, float b, float a)
{
	dif[R]=r;
	dif[G]=g;
	dif[B]=b;
	dif[A]=a;
}

int Light::setLights()
{
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, spec);
}

int Light::setCamera() { }
void Light::render() { }
