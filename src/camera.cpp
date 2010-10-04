//This camera is implemented using opengl
//(temporarily)

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
	this->angle=alpha;
}

void Camera::setZPlanes(float near, float far)
{
	this->znear=near;
	this->zfar=far;
}

int Camera::setCamera() 
{
	gluLookAt(this->eye[X], this->eye[Y], this->eye[Z],
		this->center[X], this->center[Y], this->center[Z],
		this->up[X], this->up[Y], this->up[Z]);
}

int Camera::setLights() { }
void Camera::render() { }
