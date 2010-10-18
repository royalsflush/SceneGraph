#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "transform.h"
#include "matrix.h"

void Transform::load()
{
	glPushMatrix();
	glMultMatrixf(this->mat);

	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif
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

int Transform::setupLights()
{
	int numLights;

	load();
	numLights = Group::setupLights();
	unload();

	return numLights;	
}

int Transform::setupCamera()
{
	int camera;
	
	load();
	camera = Group::setupCamera();
	unload();

	//loadInv();

	return camera;
}

void Transform::translate(float dx, float dy, float dz)
{
/*	Matrix<float> tmp;
	tmp.set(4, 4,
		1, 0, 0, dx,
		0, 1, 0, dy,
		0, 0, 1, dz,
		0, 0, 0, 1);

	this->mat*=tmp;
	tmp=this->inv;

	this->inv.set(4, 4,
		1, 0, 0, -dx,
		0, 1, 0, -dy,
		0, 0, 1, -dz,
		0, 0, 0, 1);

	this->inv*=tmp; */

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glMultMatrixf(this->mat);
	glTranslatef(dx, dy, dz);
	glGetFloatv(GL_MODELVIEW_MATRIX, this->mat);


	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", this->mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif

	glPopMatrix();
}

void Transform::scale(float dx, float dy, float dz)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glMultMatrixf(this->mat);
	glScalef(dx, dy, dz);
	glGetFloatv(GL_MODELVIEW_MATRIX, this->mat);

	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", this->mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif

	glPopMatrix();
}

void Transform::rotate(float angle, float vx, float vy, float vz)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glMultMatrixf(this->mat);
	glRotatef(angle, vx, vy, vz);
	glGetFloatv(GL_MODELVIEW_MATRIX, this->mat);

	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif

	glPopMatrix();
}
