#ifndef ENTITY_H
#define ENTITY_H

#include "node.h"

class Shape;
class Appearance;

class Entity : public Node {
	Shape* shape;
	Appearance* appearance;

	public:
	Entity(Shape* s, Appearance* app);
	void render();
	int setCamera();
	int setLights();
};

#endif /* ENTITY_H */
