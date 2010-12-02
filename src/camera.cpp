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

Camera::Camera(const char* name) : Node(name, "Camera"), man(NULL), active(false) { }

void Camera::setEye(float x, float y, float z) 
{
	this->eye[X]=x; 
	this->eye[Y]=y;
	this->eye[Z]=z;

	if (this->man)
		this->man->setEyeCoords(this->eye[X], this->eye[Y], this->eye[Z]);
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

void Camera::setZCenter(float zcent)
{
	if (this->man)
		this->man->setZCenter(zcent);
}

int Camera::setupCamera() 
{
	#ifdef _DBG
		printf("Camera->setupCamera()\n");
	#endif

	if (!this->active) return 0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(this->fovy, this->aspect, this->znear, this->zfar);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (this->man)
		this->man->load();

	gluLookAt(this->eye[X], this->eye[Y], this->eye[Z],
		this->center[X], this->center[Y], this->center[Z],
		this->up[X], this->up[Y], this->up[Z]);

	if (this->man)
		this->man->loadInv();

	return 1;
}

int Camera::setupLights() 
{ 
	return 0;
}

void Camera::render() { }

void Camera::setManipulator(CamMan* m)
{
	this->man = m;
	this->man->setZCenter((this->znear+this->zfar)/2.0);
	this->man->setEyeCoords(this->eye[X], this->eye[Y], this->eye[Z]);
}

bool Camera::isActive()
{
	return this->active;
}

void Camera::activate(bool yes)
{
	this->active = yes;
}
