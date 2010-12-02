#include <stdio.h>
#include <assert.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "transform.h"
#include "matrix.h"

Transform::Transform(const char* name) : Group(name, "Transform") { }

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
	
	camera = Group::setupCamera();

	if (camera)
		loadInv();

	return camera;
}

void Transform::translate(float dx, float dy, float dz)
{
	Matrix<float> tmp;
	tmp.set(4, 4,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		dx, dy, dz, 1.0f);

	this->mat*=tmp;

	tmp=this->inv;
	this->inv.set(4, 4,
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		-dx, -dy, -dz, 1.0f);

	this->inv*=tmp;

	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", this->mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif
}

void Transform::scale(float dx, float dy, float dz)
{
	Matrix<float> tmp;
	tmp.set(4, 4,
		dx, 0.0f, 0.0f, 0.0f,
		0.0f, dy, 0.0f, 0.0f,
		0.0f, 0.0f, dz, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	this->mat*=tmp;

	assert(dx && dy && dz);

	tmp=this->inv;
	this->inv.set(4, 4,
		1.0f/dx, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f/dy, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f/dz, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);

	this->inv*=tmp;

	#ifdef _DBG
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++)
				printf("%f ", this->mat[i][j]);
			printf("\n");
		}

		printf("\n");
	#endif
}

void Transform::rotate(float angle, float vx, float vy, float vz)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glLoadIdentity();
	glMultMatrixf(this->mat);
	glRotatef(angle, vx, vy, vz);
	glGetFloatv(GL_MODELVIEW_MATRIX, this->mat);

	glLoadIdentity();
	glRotatef(-angle, vx, vy, vz);
	glMultMatrixf(this->inv);
	glGetFloatv(GL_MODELVIEW_MATRIX, this->inv);
	
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

void Transform::identity() 
{
	this->mat.identity();
	this->inv.identity();	
}

void Transform::printMatrix()
{
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			printf("%.2f ", mat[i][j]);
		printf("\n");
	}
}
