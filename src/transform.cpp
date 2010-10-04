#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif


#include "transform.h"

void Transform::load()
{
	glPushMatrix();
	glMultMatrixf(this->mat);
}

void Transform::unload()
{
	glPopMatrix();
}

void Transform::loadInv()
{
	glPushMatrix();
	glMultMatrixf(this->inv);
}

void Transform::render()
{
	load();
	Group::render();
	unload();
}

int Transform::setLights()
{
	int numLights;

	load();
	numLights = Group::setLights();
	unload();

	return numLights;	
}

int Transform::setCamera()
{
	int camera;

	load();
	camera = Group::setLights();
	unload();

	return camera;
}

void Transform::loadIdentity()
{
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			if (i==j) mat[4*i+j]=1;
			else mat[4*i+j]=0;
	}
	
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			if (i==j) inv[4*i+j]=1;
			else inv[4*i+j]=0;
	}
}

void Transform::translate(float dx, float dy, float dz)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(dx, dy, dz);
	glGetFloatv(GL_MODELVIEW, this->mat);
	glPopMatrix();
}

void Transform::scale()
{

}

void Transform::rotate()
{
	
}
