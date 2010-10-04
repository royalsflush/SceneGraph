#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"

class Sphere : public Shape {
	float radius;

	public:
	Sphere(float r);
	void draw();
};

#endif /* SPHERE_H */
