#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "entity.h"
#include "shape.h"
#include "appearance.h"

Entity::Entity(Shape* s, Appearance* app) : shape(s), appearance(app) { }

void Entity::render() 
{
	glMatrixMode(GL_MODELVIEW);

	this->appearance->load();
	this->shape->draw();
	this->appearance->unload();
}

int Entity::setupCamera() 
{ 
	return 0;
}

int Entity::setupLights() 
{ 
	return 0;
}
