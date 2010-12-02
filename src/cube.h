#ifndef CUBE_H
#define CUBE_H

#include "shape.h"

class Cube : public Shape {
	float dimX, dimY, dimZ;
	int div;
	int nVert, nInd;
	float* vert;
	float* norm;
	unsigned int* ind;

	void buildCube();
	int index(int i, int j);

	public:
	Cube( float x, float y, float z);
	void setDiv(int numDivs);
	void draw();
};

#endif /* CUBE_H */
