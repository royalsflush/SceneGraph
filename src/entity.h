#ifndef ENTITY_H
#define ENTITY_H

#include "node.h"

class Shape;
class Appearance;

class Entity : public Node {
	Shape* shape;
	Appearance* appearance;

	public:
	Entity(const char* name, Shape* s, Appearance* app);
	void render();
	int setupCamera();
	int setupLights();
};

#endif /* ENTITY_H */
