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
	this->appearance->load();
	this->shape->draw();
	this->appearance->unload();
}

int Entity::setupCamera() { }
int Entity::setupLights() { }
