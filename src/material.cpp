#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "property.h"
#include "appearance.h"
#include "material.h"

enum
{
	R=0, G, B, A
};

Material::Material(float r, float g, float b) 
{
	this->amb[R]=this->dif[R]=r;
	this->amb[G]=this->dif[G]=g;
	this->amb[B]=this->dif[B]=b;
	this->amb[A]=this->dif[A]=1.0f;
	this->spec[A]=1.0f;
}

void Material::setSpecular(float r, float g, float b)
{
	this->spec[R]=r;
	this->spec[G]=g;
	this->spec[B]=b;
}

void Material::setShininess(int sh)
{
	this->shine=sh;
}

void Material::load()
{
	#ifdef _DBG
		printf("Loading material\n");
	#endif

	glPushAttrib(GL_LIGHTING);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, this->amb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, this->dif);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, this->spec);
	glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, this->shine);
}

void Material::unload()
{
	#ifdef _DBG
		printf("Unloading material\n");
	#endif

	glPopAttrib();
}
