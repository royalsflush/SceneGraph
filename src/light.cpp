#include <stdio.h>

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

int Light::lightCount = 0;

Light::Light(float x, float y, float z, float w) 
{
	pos[X]=x;
	pos[Y]=y;
	pos[Z]=z;
	pos[W]=w;	

	this->ind = Light::lightCount;
	Light::lightCount++;
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

int Light::setupLights()
{
	#ifdef _DBG
		printf("Setup light%d\n", this->ind);
	#endif

	glEnable(this->ind);
	glLightfv(this->ind, GL_AMBIENT, amb);
	glLightfv(this->ind, GL_POSITION, pos);
	glLightfv(this->ind, GL_DIFFUSE, dif);
	glLightfv(this->ind, GL_SPECULAR, spec);

	return 1;
}

int Light::setupCamera() 
{ 
	return 0;
}

void Light::render() { }
