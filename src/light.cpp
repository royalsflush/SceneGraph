#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "light.h"
#include "switch.h"

enum
{
	X=0, Y, Z, W
};

enum
{
	R=0, G, B, A
};

int Light::lightCount = 0;
Switch* Light::ctrlSwitch = NULL;

Light::Light(float x, float y, float z, float w) 
{
	pos[X]=x;
	pos[Y]=y;
	pos[Z]=z;
	pos[W]=w;	

	this->ind = Light::lightCount;
	Light::lightCount++;
	
	this->spotExp=0;
	this->spotCutoff=180;
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

void Light::setSpotDir(float dirX, float dirY, float dirZ)
{
	spotDir[X]= dirX;
	spotDir[Y]= dirY;
	spotDir[Z]= dirZ;
}

void Light::setSpotExp(int exp)
{
	spotExp=exp;
}

void Light::setSpotCutoff(int cutoff)
{
	spotCutoff=cutoff;
}

int Light::setupLights()
{
	#ifdef _DBG
		printf("Setup light%d\n", this->ind);
	#endif

	int lightind = GL_LIGHT0 + this->ind;
	
	if (Light::ctrlSwitch) {
		if (!Light::ctrlSwitch->isOn(this->ind)) { 
			glDisable(lightind);
			return 0;
		}
	}

	glEnable(lightind);
	glLightfv(lightind, GL_AMBIENT, amb);
	glLightfv(lightind, GL_POSITION, pos);
	glLightfv(lightind, GL_DIFFUSE, dif);
	glLightfv(lightind, GL_SPECULAR, spec);

	if (pos[W]==1.0f) { //essa luz e de spot
		glLightfv(lightind, GL_SPOT_DIRECTION, spotDir);
		glLighti(lightind, GL_SPOT_EXPONENT, spotExp);
		glLighti(lightind, GL_SPOT_CUTOFF, spotCutoff);
	}

	return 1;
}

int Light::setupCamera() 
{ 
	return 0;
}

void Light::render() { }

void Light::setSwitch(Switch* s)
{
	Light::ctrlSwitch=s;
}
