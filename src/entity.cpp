#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

#include "entity.h"
#include "shape.h"
#include "appearance.h"

Entity::Entity(const char* name, Shape* s, Appearance* app) : Node(name, "Entity"), shape(s), appearance(app) { }

void Entity::render() 
{
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

void Entity::changeRenderMode(rend_modes newMode)
{
	shape->setRenderMode(newMode);
}

void Entity::addRenderer(Renderer* r)
{
	shape->setRenderer(r);
}
