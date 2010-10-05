#include <stdio.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "camera.h"

enum 
{
	X=0, Y, Z
};

void Camera::setEye(float x, float y, float z) 
{
	this->eye[X]=x; 
	this->eye[Y]=y;
	this->eye[Z]=z;
}

void Camera::setCenter(float x, float y, float z) 
{
	this->center[X]=x;
	this->center[Y]=y;
	this->center[Z]=z;
}

void Camera::setUp(float x, float y, float z)
{
	this->up[X]=x;
	this->up[Y]=y;
	this->up[Z]=z;
}

void Camera::setAngle(float alpha)
{
	this->fovy=alpha;
}

void Camera::setZPlanes(float near, float far)
{
	this->znear=near;
	this->zfar=far;
}

void Camera::setAspectRatio(float asp)
{
	this->aspect=asp;
}

int Camera::setupCamera() 
{
	#ifdef _DBG
		printf("Camera->setupCamera()\n");
	#endif

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->fovy, this->aspect, this->znear, this->zfar);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(this->eye[X], this->eye[Y], this->eye[Z],
		this->center[X], this->center[Y], this->center[Z],
		this->up[X], this->up[Y], this->up[Z]);

	return 1;
}

int Camera::setupLights() 
{ 
	return 0;
}
void Camera::render() { }
