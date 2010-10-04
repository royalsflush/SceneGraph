#ifndef CUBE_H
#define CUBE_H

#include "shape.h"

class Cube : public Shape {
	float dimX, dimY, dimZ;

	public:
	Cube(float x, float y, float z);
	void draw();
};

#endif /* CUBE_H */
