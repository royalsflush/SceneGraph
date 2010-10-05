#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "group.h"
#include "scene.h"

void Scene::render() 
{ 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f, 1.0f, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Group::setupCamera();
	Group::setupLights();
	Group::render();
	
	glutSwapBuffers();
}

int Scene::setupCamera()
{
	Group::setupCamera();
}

int Scene::setupLights()
{
	Group::setupLights();
}
